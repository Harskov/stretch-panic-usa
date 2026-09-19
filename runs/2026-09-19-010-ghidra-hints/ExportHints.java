// Export Ghidra analysis of a PS2 ELF as JSON hints for the dps2 project (S5).
// Writes functions.json, xrefs.json, strings.json and decomp/<addr>.c under -out <dir>.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.*;
import ghidra.program.util.DefinedDataIterator;
import ghidra.program.model.data.AbstractStringDataType;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ExportHints extends GhidraScript {

    static String esc(String s) {
        if (s == null) return "";
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            switch (c) {
                case '"': b.append("\\\""); break;
                case '\\': b.append("\\\\"); break;
                case '\n': b.append("\\n"); break;
                case '\r': b.append("\\r"); break;
                case '\t': b.append("\\t"); break;
                default:
                    if (c < 0x20 || c > 0x7e) b.append(String.format("\\u%04x", (int) c));
                    else b.append(c);
            }
        }
        return b.toString();
    }

    static String hex(Address a) { return String.format("0x%08X", a.getOffset()); }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outDir = new File(args.length > 0 ? args[0] : "/tmp/ghidra-out");
        outDir.mkdirs();
        File decompDir = new File(outDir, "decomp");
        decompDir.mkdirs();

        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();
        ReferenceManager rm = currentProgram.getReferenceManager();

        // ---- functions.json -------------------------------------------------
        List<Function> funcs = new ArrayList<>();
        for (Function f : fm.getFunctions(true)) funcs.add(f);
        println("EXPORT: functions = " + funcs.size());

        try (PrintWriter w = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream(new File(outDir, "functions.json")), StandardCharsets.UTF_8))) {
            w.println("[");
            for (int i = 0; i < funcs.size(); i++) {
                Function f = funcs.get(i);
                long size = f.getBody().getNumAddresses();
                w.printf("  {\"address\": \"%s\", \"size\": %d, \"name\": \"%s\", \"thunk\": %s, \"signature\": \"%s\"}%s%n",
                        hex(f.getEntryPoint()), size, esc(f.getName()), f.isThunk() ? "true" : "false",
                        esc(f.getPrototypeString(false, false)), (i == funcs.size() - 1 ? "" : ","));
            }
            w.println("]");
        }

        // ---- xrefs.json -----------------------------------------------------
        int nref = 0;
        try (PrintWriter w = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream(new File(outDir, "xrefs.json")), StandardCharsets.UTF_8))) {
            w.println("[");
            boolean first = true;
            AddressIterator it = rm.getReferenceSourceIterator(currentProgram.getMemory(), true);
            while (it.hasNext() && !monitor.isCancelled()) {
                Address from = it.next();
                for (Reference r : rm.getReferencesFrom(from)) {
                    Function ff = fm.getFunctionContaining(from);
                    Function tf = fm.getFunctionAt(r.getToAddress());
                    if (!first) w.println(",");
                    first = false;
                    w.printf("  {\"from\": \"%s\", \"to\": \"%s\", \"kind\": \"%s\", \"from_function\": \"%s\", \"to_function\": \"%s\"}",
                            hex(from), hex(r.getToAddress()), esc(r.getReferenceType().getName()),
                            ff == null ? "" : esc(ff.getName()), tf == null ? "" : esc(tf.getName()));
                    nref++;
                }
            }
            w.println();
            w.println("]");
        }
        println("EXPORT: xrefs = " + nref);

        // ---- strings.json ---------------------------------------------------
        int nstr = 0;
        try (PrintWriter w = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream(new File(outDir, "strings.json")), StandardCharsets.UTF_8))) {
            w.println("[");
            boolean first = true;
            for (Data d : DefinedDataIterator.byDataInstance(currentProgram,
                    dd -> dd.getBaseDataType() instanceof AbstractStringDataType)) {
                if (monitor.isCancelled()) break;
                Object v = d.getValue();
                if (v == null) continue;
                String text = v.toString();
                LinkedHashSet<String> refs = new LinkedHashSet<>();
                for (Reference r : rm.getReferencesTo(d.getAddress())) {
                    Function ff = fm.getFunctionContaining(r.getFromAddress());
                    refs.add(ff == null ? hex(r.getFromAddress()) : ff.getName());
                }
                StringBuilder rb = new StringBuilder();
                int k = 0;
                for (String s : refs) { if (k++ > 0) rb.append(", "); rb.append('"').append(esc(s)).append('"'); }
                if (!first) w.println(",");
                first = false;
                w.printf("  {\"address\": \"%s\", \"length\": %d, \"text\": \"%s\", \"referencing_functions\": [%s]}",
                        hex(d.getAddress()), d.getLength(), esc(text), rb.toString());
                nstr++;
            }
            w.println();
            w.println("]");
        }
        println("EXPORT: strings = " + nstr);

        // ---- decomp/<addr>.c ------------------------------------------------
        DecompInterface di = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        di.setOptions(opts);
        di.toggleCCode(true);
        di.toggleSyntaxTree(false);
        di.setSimplificationStyle("decompile");
        if (!di.openProgram(currentProgram)) {
            println("EXPORT: DECOMPILER FAILED TO OPEN: " + di.getLastMessage());
        } else {
            int ok = 0, fail = 0;
            for (int i = 0; i < funcs.size(); i++) {
                if (monitor.isCancelled()) break;
                Function f = funcs.get(i);
                if (f.isThunk()) continue;
                String addr = hex(f.getEntryPoint());
                try {
                    DecompileResults res = di.decompileFunction(f, 30, monitor);
                    if (res != null && res.decompileCompleted() && res.getDecompiledFunction() != null) {
                        String c = res.getDecompiledFunction().getC();
                        File cf = new File(decompDir, addr + ".c");
                        try (Writer cw = new OutputStreamWriter(new FileOutputStream(cf), StandardCharsets.UTF_8)) {
                            cw.write("// ghidra decompiler output for " + f.getName() + " at " + addr + "\n");
                            cw.write("// hint only - never source (dps2 S5)\n\n");
                            cw.write(c);
                        }
                        ok++;
                    } else {
                        fail++;
                    }
                } catch (Exception e) {
                    fail++;
                }
                if ((i % 100) == 0) { println("EXPORT: decomp progress " + i + "/" + funcs.size() + " ok=" + ok + " fail=" + fail); }
            }
            di.dispose();
            println("EXPORT: decomp done ok=" + ok + " fail=" + fail);
        }

        // ---- counts.json ----------------------------------------------------
        try (PrintWriter w = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream(new File(outDir, "counts.json")), StandardCharsets.UTF_8))) {
            w.printf("{\"functions\": %d, \"xrefs\": %d, \"strings\": %d, \"decomp_files\": %d}%n",
                    funcs.size(), nref, nstr, decompDir.list() == null ? 0 : decompDir.list().length);
        }
        println("EXPORT: COMPLETE");
    }
}

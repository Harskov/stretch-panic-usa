# Exemplars for func_0016DC80 — the 3 matched functions nearest by address

## func_0016DC30 @ 0x0016DC30 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct {
    unsigned char pad[0x134];
    int field134;
} Obj;

void func_0016DC40(Obj *arg0, int arg1);

void func_0016DC30(Obj *arg0) {
    func_0016DC40(arg0, arg0->field134);
}

```

## func_0016D900 @ 0x0016D900 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
int func_0016D900(void) {
    return 0;
}

```

## func_0016D690 @ 0x0016D690 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct {
    unsigned char pad[0x60];
    int flags;
    unsigned char pad2[0x108];
    int field16C;
} Obj;

void func_0016D690(Obj *arg0) {
    arg0->field16C = 0;
    arg0->flags |= 0x10000;
}

```

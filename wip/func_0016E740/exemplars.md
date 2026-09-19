# Exemplars for func_0016E740 — the 3 matched functions nearest by address

## func_0016E390 @ 0x0016E390 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_0016FBE0();

void func_0016E390(int a0, int a1, int a2) {
    func_0016FBE0(a1, a2);
}

```

## func_0016DCD0 @ 0x0016DCD0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct {
    unsigned char pad[0x164];
    int field164;
    int field168;
} Obj;

void func_0016DCD0(Obj *arg0, Obj *arg1) {
    arg0->field164 = arg1->field164;
    arg0->field168 = arg1->field168;
}

```

## func_0016DC80 @ 0x0016DC80 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct {
    unsigned char pad[0x60];
    int flags;
    unsigned char pad2[0x100];
    int field164;
    int field168;
} Obj;

int func_0016DC80(Obj *arg0) {
    int v = arg0->field168;
    if (v != 0) {
        arg0->field168 = v - 1;
        if (arg0->field168 == 0) {
            arg0->flags &= 0xFBFFFFFF;
            arg0->field164 = 0;
        }
        return 1;
    }
    return 0;
}

```

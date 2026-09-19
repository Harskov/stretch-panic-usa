typedef float f32;

int func_00119AB0();

void func_0016B6B0(f32 fparg0, f32 fparg1) {
    f32 t;
    f32 a;
    f32 b;

    a = fparg0;
    b = fparg1;
    t = (f32)func_00119AB0();
    t = 1.0f - 0.25f * t;
    t = 1.0f + t;
    t = t / 2.0f;
    t = t * (b - a);
    t = a + t;
}

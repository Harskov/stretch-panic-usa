typedef float f32;

int func_00119AB0();

f32 func_0016B6B0(f32 fparg0, f32 fparg1) {
    f32 a;
    f32 b;
    f32 t;
    f32 c;

    a = fparg0;
    b = fparg1;
    t = (f32)func_00119AB0();
    c = 1.0f - (0.25f * t);
    c = c + 1.0f;
    c = c / 2.0f;
    c = a + (c * (b - a));
    return c;
}

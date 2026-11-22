extern "C" {
extern unsigned long lbl_803775F4;
void fn_80036384();
void fn_800363A4(void*);
void fn_80036430(void*, short);
void fn_80036348()
{
    unsigned long object[0x88 / 4];
    lbl_803775F4 = 0;
    fn_80036384();
    fn_800363A4(object);
    fn_80036430(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_80036384() { fn_8003522C(); }
}

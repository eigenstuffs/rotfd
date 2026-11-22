extern "C" {
extern unsigned long lbl_803775EC;
void fn_80035B0C();
void fn_80035B2C(void*);
void fn_80035BB8(void*, short);
void fn_80035AD0()
{
    unsigned long object[0x88 / 4];
    lbl_803775EC = 0;
    fn_80035B0C();
    fn_80035B2C(object);
    fn_80035BB8(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_80035B0C() { fn_8003522C(); }
}

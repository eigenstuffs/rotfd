extern "C" {
extern unsigned long lbl_8037760C;
void fn_80039DD8();
void fn_80039DF8(void*);
void fn_80039E84(void*, short);
void fn_80039D9C()
{
    unsigned long object[0x88 / 4];
    lbl_8037760C = 0;
    fn_80039DD8();
    fn_80039DF8(object);
    fn_80039E84(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_80039DD8() { fn_8003522C(); }
}

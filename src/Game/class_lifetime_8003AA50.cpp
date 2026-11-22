extern "C" {
extern unsigned long lbl_80377618;
void fn_8003AA8C();
void fn_8003AAAC(void*);
void fn_8003AB38(void*, short);
void fn_8003AA50()
{
    unsigned long object[0x88 / 4];
    lbl_80377618 = 0;
    fn_8003AA8C();
    fn_8003AAAC(object);
    fn_8003AB38(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_8003AA8C() { fn_8003522C(); }
}

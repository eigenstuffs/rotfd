extern "C" {
extern unsigned long lbl_8037761C;
void fn_8003AEC8();
void fn_8003AEE8(void*);
void fn_8003AF74(void*, short);
void fn_8003AE8C()
{
    unsigned long object[0x88 / 4];
    lbl_8037761C = 0;
    fn_8003AEC8();
    fn_8003AEE8(object);
    fn_8003AF74(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_8003AEC8() { fn_8003522C(); }
}

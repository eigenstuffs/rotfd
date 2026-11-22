extern "C" {
extern unsigned long lbl_803775F0;
void fn_80035F48();
void fn_80035F68(void*);
void fn_80035FF4(void*, short);
void fn_80035F0C()
{
    unsigned long object[0x88 / 4];
    lbl_803775F0 = 0;
    fn_80035F48();
    fn_80035F68(object);
    fn_80035FF4(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_80035F48() { fn_8003522C(); }
}

extern "C" {
    void fn_8025ED38(void*, void*, void*);
    extern void* lbl_80377820;
    extern void* lbl_80377824;
    extern void* lbl_80378018;
}

extern "C" void fn_800C06FC(void* self, void* value) {
    fn_8025ED38(self, value, lbl_80377824);
    fn_8025ED38(self, value, lbl_80377820);
    fn_8025ED38(self, value, lbl_80378018);
}

extern "C" {
    void fn_8025ED38(void*, void*, void*);
    extern void* lbl_80377748;
    extern void* lbl_80378028;
    extern void* lbl_80378078;
}

extern "C" void fn_80072BB4(void* self, void* value) {
    fn_8025ED38(self, value, lbl_80377748);
    fn_8025ED38(self, value, lbl_80378078);
    fn_8025ED38(self, value, lbl_80378028);
}

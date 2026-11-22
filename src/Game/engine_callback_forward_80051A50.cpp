extern "C" {
    void fn_8025ED38(void*, void*, void*);
    extern void* lbl_8037766C;
    extern void* lbl_80378028;
    extern void* lbl_80378078;
}

extern "C" void fn_80051A50(void* self, void* value) {
    fn_8025ED38(self, value, lbl_8037766C);
    fn_8025ED38(self, value, lbl_80378078);
    fn_8025ED38(self, value, lbl_80378028);
}

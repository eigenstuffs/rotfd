extern "C" {
    void fn_8025ED38(void*, void*, void*);
    extern void* lbl_80377620;
    extern void* lbl_80378028;
    extern void* lbl_80378070;
    extern void* lbl_80378080;
}

extern "C" void fn_8003DBBC(void* self, void* value) {
    fn_8025ED38(self, value, lbl_80377620);
    fn_8025ED38(self, value, lbl_80378070);
    fn_8025ED38(self, value, lbl_80378080);
    fn_8025ED38(self, value, lbl_80378028);
}

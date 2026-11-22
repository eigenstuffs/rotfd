extern "C" {
    void fn_8025ED38(void*, void*, void*);
    extern void* lbl_803775D8;
    extern void* lbl_80378028;
    extern void* lbl_80378068;
}

extern "C" void fn_8002D950(void* self, void* value) {
    fn_8025ED38(self, value, lbl_803775D8);
    fn_8025ED38(self, value, lbl_80378068);
    fn_8025ED38(self, value, lbl_80378028);
}

extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_80377620;
    extern void* lbl_80378028;
    extern void* lbl_80378070;
    extern void* lbl_80378080;
}

extern "C" int fn_8003DC20(void* self, void* value) {
    int result;
    result = fn_8025E70C(self, value, lbl_80377620);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378070);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378080);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378028);
    if (result != -1) return result;
    return -1;
}

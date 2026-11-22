extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_80377580;
    extern void* lbl_80378028;
    extern void* lbl_80378030;
    extern void* lbl_80378040;
    extern void* lbl_80378050;
    extern void* lbl_80378060;
    extern void* lbl_80378080;
}

extern "C" int fn_80025D14(void* self, void* value) {
    int result;
    result = fn_8025E70C(self, value, lbl_80377580);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378040);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378060);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378050);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378030);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378080);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378028);
    if (result != -1) return result;
    return -1;
}

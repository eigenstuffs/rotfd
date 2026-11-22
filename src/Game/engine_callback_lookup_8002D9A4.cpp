extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_803775D8;
    extern void* lbl_80378028;
    extern void* lbl_80378068;
}

extern "C" int fn_8002D9A4(void* self, void* value) {
    int result;
    result = fn_8025E70C(self, value, lbl_803775D8);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378068);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378028);
    if (result != -1) return result;
    return -1;
}

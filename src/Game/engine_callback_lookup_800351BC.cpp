extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_803775E0;
    extern void* lbl_80378028;
}

extern "C" int fn_800351BC(void* self, void* value) {
    int result;
    result = fn_8025E70C(self, value, lbl_803775E0);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378028);
    if (result != -1) return result;
    return -1;
}

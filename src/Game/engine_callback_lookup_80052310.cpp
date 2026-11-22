extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_80377648;
    extern void* lbl_8037764C;
    extern void* lbl_80378028;
    extern void* lbl_80378078;
}

extern "C" int fn_80052310(void* self, void* value) {
    int result;
    result = fn_8025E70C(self, value, lbl_8037764C);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80377648);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378078);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378028);
    if (result != -1) return result;
    return -1;
}

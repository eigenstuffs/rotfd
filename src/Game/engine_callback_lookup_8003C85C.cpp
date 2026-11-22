extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_803775E8;
    extern void* lbl_803775EC;
    extern void* lbl_80378028;
    extern void* lbl_80378030;
    extern void* lbl_80378050;
    extern void* lbl_80378060;
    extern void* lbl_80378080;
}

extern "C" int fn_8003C85C(void* self, void* value) {
    int result;
    result = fn_8025E70C(self, value, lbl_803775EC);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_803775E8);
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

extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_803775C0;
    extern void* lbl_803777E8;
    extern void* lbl_80378028;
    extern void* lbl_80378030;
    extern void* lbl_80378050;
    extern void* lbl_80378080;
}

extern "C" int fn_800C1374(void* self, void* value) {
    int result;
    result = fn_8025E70C(self, value, lbl_803777E8);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_803775C0);
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

/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-callback-lookup.md. */
extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_80377588;
    extern void* lbl_80377594;
    extern void* lbl_803775C0;
    extern void* lbl_80378028;
    extern void* lbl_80378030;
    extern void* lbl_80378050;
    extern void* lbl_80378080;
}

extern "C" int fn_800298B4(void* self, void* value) {
    int result;
    result = fn_8025E70C(self, value, lbl_80377594);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80377588);
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

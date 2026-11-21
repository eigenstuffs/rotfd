/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-callback-lookup.md. */
extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_80377648;
    extern void* lbl_80377664;
    extern void* lbl_80378028;
    extern void* lbl_80378078;
}

extern "C" int fn_80051CB0(void* self, void* value) {
    int result;
    result = fn_8025E70C(self, value, lbl_80377664);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80377648);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378078);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378028);
    if (result != -1) return result;
    return -1;
}

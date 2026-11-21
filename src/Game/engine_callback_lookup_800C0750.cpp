/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-callback-lookup.md. */
extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_80377820;
    extern void* lbl_80377824;
    extern void* lbl_80378018;
}

extern "C" int fn_800C0750(void* self, void* value) {
    int result;
    result = fn_8025E70C(self, value, lbl_80377824);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80377820);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378018);
    if (result != -1) return result;
    return -1;
}

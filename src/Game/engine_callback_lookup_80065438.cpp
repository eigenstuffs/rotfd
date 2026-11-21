/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-callback-lookup.md. */
extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_80377710;
    extern void* lbl_80377714;
    extern void* lbl_80378028;
    extern void* lbl_80378030;
    extern void* lbl_80378080;
}

extern "C" int fn_80065438(void* self, void* value) {
    int result;
    result = fn_8025E70C(self, value, lbl_80377714);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80377710);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378030);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378080);
    if (result != -1) return result;
    result = fn_8025E70C(self, value, lbl_80378028);
    if (result != -1) return result;
    return -1;
}

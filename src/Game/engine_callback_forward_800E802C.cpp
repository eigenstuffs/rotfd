/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-callback-forward.md. */
extern "C" {
    void fn_8025ED38(void*, void*, void*);
    extern void* lbl_80377648;
    extern void* lbl_803778B0;
    extern void* lbl_80378028;
    extern void* lbl_80378078;
}

extern "C" void fn_800E802C(void* self, void* value) {
    fn_8025ED38(self, value, lbl_803778B0);
    fn_8025ED38(self, value, lbl_80377648);
    fn_8025ED38(self, value, lbl_80378078);
    fn_8025ED38(self, value, lbl_80378028);
}

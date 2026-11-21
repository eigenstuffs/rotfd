/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-callback-forward.md. */
extern "C" {
    void fn_8025ED38(void*, void*, void*);
    extern void* lbl_803777F8;
    extern void* lbl_80378020;
    extern void* lbl_80378028;
}

extern "C" void fn_800C4D30(void* self, void* value) {
    fn_8025ED38(self, value, lbl_803777F8);
    fn_8025ED38(self, value, lbl_80378020);
    fn_8025ED38(self, value, lbl_80378028);
}

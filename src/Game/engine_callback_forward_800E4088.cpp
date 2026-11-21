/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-callback-forward.md. */
extern "C" {
    void fn_8025ED38(void*, void*, void*);
    extern void* lbl_803778A8;
    extern void* lbl_80378028;
    extern void* lbl_80378030;
    extern void* lbl_80378050;
    extern void* lbl_80378080;
}

extern "C" void fn_800E4088(void* self, void* value) {
    fn_8025ED38(self, value, lbl_803778A8);
    fn_8025ED38(self, value, lbl_80378050);
    fn_8025ED38(self, value, lbl_80378030);
    fn_8025ED38(self, value, lbl_80378080);
    fn_8025ED38(self, value, lbl_80378028);
}

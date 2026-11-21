/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-callback-forward.md. */
extern "C" {
    void fn_8025ED38(void*, void*, void*);
    extern void* lbl_80377558;
    extern void* lbl_8037756C;
    extern void* lbl_80378028;
    extern void* lbl_80378030;
    extern void* lbl_80378038;
    extern void* lbl_80378050;
    extern void* lbl_80378060;
    extern void* lbl_80378080;
}

extern "C" void fn_80023968(void* self, void* value) {
    fn_8025ED38(self, value, lbl_8037756C);
    fn_8025ED38(self, value, lbl_80377558);
    fn_8025ED38(self, value, lbl_80378038);
    fn_8025ED38(self, value, lbl_80378060);
    fn_8025ED38(self, value, lbl_80378050);
    fn_8025ED38(self, value, lbl_80378030);
    fn_8025ED38(self, value, lbl_80378080);
    fn_8025ED38(self, value, lbl_80378028);
}

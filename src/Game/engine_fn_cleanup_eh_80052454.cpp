/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-cleanup-eh.md. */
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
struct View {
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_80052454(View*self,int flag) {
    if(self) {
        if((short)flag>0)dispose(self);
    }
    return self;
}

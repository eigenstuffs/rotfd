/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-cleanup-eh.md. */
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B92D0[];
    void fn_801EF610(void*,void*);
}
struct View {
    void*vtable;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_8009009C(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802B92D0;
        if((short)flag>0)dispose(self);
    }
    return self;
}

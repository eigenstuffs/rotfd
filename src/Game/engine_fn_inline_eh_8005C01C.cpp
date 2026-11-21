/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-inline-eh.md. */
extern "C" {
    extern char lbl_801EF5C8[], lbl_802B4ECC[];
    void fn_801EF610(void*,void*);
    void __dt__14Agent_8002B5F4Fv(void*,int);
}
extern "C" unsigned int lbl_80377694[2];
struct View {
    char unknown00[8];
    void*vtable;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_8005C01C(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802B4ECC;
        lbl_80377694[0]=0;
        lbl_80377694[1]=0;
        __dt__14Agent_8002B5F4Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

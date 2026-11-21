/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-final-cleanup-eh.md. */
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" {
    extern char lbl_802BF2C8[],lbl_802BF458[];
    void __dt__15Object_8007F578Fv(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
    char unknown0C[0x30C];
    void*secondary;
    ~View() {
        vtable=lbl_802BF458;
        secondary=lbl_802BF458+0x170;
        __dt__15Object_8007F578Fv(this,0);
    }
};
extern "C" void*fn_800C14A8(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802BF458;
        self->secondary=lbl_802BF458+0x170;
        __dt__15Object_8007F578Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

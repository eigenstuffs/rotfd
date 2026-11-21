/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-protected-eh.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802EC8A8[];
    void fn_801EF610(void*,void*);
    void fn_80020FE8(void*,int);
}
inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
struct Object {
    u32 unknown00[2];
    void*vtable;
};
extern "C" void*dtor_80024E50(Object*self,int flag) {
    if(self) {
        self->vtable=lbl_802EC8A8;
        fn_80020FE8(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

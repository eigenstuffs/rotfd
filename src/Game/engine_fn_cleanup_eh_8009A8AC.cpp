extern "C" {
    extern char lbl_801EF5C8[],__vt__8CNPCMove[];
    void fn_801EF610(void*,void*);
    void __dt__10CActorMoveFv(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
    char unknown0C[780];
    void*secondary;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_8009A8AC(View*self,int flag) {
    if(self) {
        self->vtable=__vt__8CNPCMove;
        self->secondary=__vt__8CNPCMove+368;
        __dt__10CActorMoveFv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

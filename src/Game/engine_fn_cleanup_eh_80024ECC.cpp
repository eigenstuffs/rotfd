extern "C" {
    extern char lbl_801EF5C8[],lbl_802B0510[];
    void fn_801EF610(void*,void*);
    void __dt__17LodAgent_802EC8A8Fv(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
    char unknown0C[0x74];
    unsigned int value80;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_80024ECC(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802B0510;
        self->value80=0;
        __dt__17LodAgent_802EC8A8Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

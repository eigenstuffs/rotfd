extern "C" {
    extern char lbl_801EF5C8[],lbl_802BAE04[];
    void fn_801EF610(void*,void*);
    void __dt__15Object_8009AA98Fv(void*,int);
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
        self->vtable=lbl_802BAE04;
        self->secondary=lbl_802BAE04+368;
        __dt__15Object_8009AA98Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

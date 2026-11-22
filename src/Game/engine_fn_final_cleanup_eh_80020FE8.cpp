extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" {
    extern char lbl_802ECC00[];
    void __dt__15Object_80021064Fv(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
};
extern "C" void*fn_80020FE8(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802ECC00;
        __dt__15Object_80021064Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

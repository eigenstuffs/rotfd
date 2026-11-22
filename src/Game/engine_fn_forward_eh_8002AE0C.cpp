extern "C" {
    extern char lbl_801EF5C8[],lbl_802B14E0[];
    void fn_801EF610(void*,void*);
    void __dt__15Object_80021064Fv(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void* fn_8002AE0C(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802B14E0;
        __dt__15Object_80021064Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

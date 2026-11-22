extern "C" {
    extern char lbl_801EF5C8[],lbl_802B9730[];
    void fn_801EF610(void*,void*);
    void __dt__15Object_80094A2CFv(void*,int);
}
struct View {
    void*vtable;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void* fn_80095D1C(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802B9730;
        __dt__15Object_80094A2CFv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

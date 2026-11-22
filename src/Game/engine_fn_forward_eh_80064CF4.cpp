extern "C" {
    extern char lbl_801EF5C8[],lbl_802B66F4[];
    void fn_801EF610(void*,void*);
    void __dt__14Agent_80064744Fv(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void* fn_80064CF4(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802B66F4;
        __dt__14Agent_80064744Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

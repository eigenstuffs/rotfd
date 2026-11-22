extern "C" {
    extern char lbl_801EF5C8[],lbl_802B780C[];
    void fn_801EF610(void*,void*);
    void __dt__14Agent_8002B5F4Fv(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void* fn_8006F2E0(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802B780C;
        __dt__14Agent_8002B5F4Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

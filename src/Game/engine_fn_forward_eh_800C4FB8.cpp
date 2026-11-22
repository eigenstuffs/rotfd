extern "C" {
    extern char lbl_801EF5C8[],lbl_802BFB7C[];
    void fn_801EF610(void*,void*);
    void fn_8002AE0C(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void* fn_800C4FB8(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802BFB7C;
        fn_8002AE0C(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

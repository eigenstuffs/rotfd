extern "C" {
    extern char lbl_801EF5C8[],lbl_802B852C[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct View {
    void*vtable;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void* fn_80080174(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802B852C;
        fn_8009009C(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

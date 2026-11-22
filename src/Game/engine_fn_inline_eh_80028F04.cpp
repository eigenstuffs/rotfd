extern "C" {
    extern char lbl_801EF5C8[], lbl_802B0AE0[], lbl_802B10DC[];
    void fn_801EF610(void*,void*);
    void fn_8002AE0C(void*,int);
}
struct InlineBase {
    char unknown00[8];
    void*vtable;
    ~InlineBase() {
        vtable=lbl_802B10DC;
        fn_8002AE0C(this,0);
    }
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_80028F04(InlineBase*self,int flag) {
    if(self) {
        self->vtable=lbl_802B0AE0;
        self->~InlineBase();
        if((short)flag>0)dispose(self);
    }
    return self;
}

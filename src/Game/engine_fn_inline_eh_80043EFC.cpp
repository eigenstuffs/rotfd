extern "C" {
    extern char lbl_801EF5C8[], lbl_802B34F8[], lbl_802B3168[];
    void fn_801EF610(void*,void*);
    void __dt__14Agent_8002B5F4Fv(void*,int);
}
struct InlineBase {
    char unknown00[8];
    void*vtable;
    ~InlineBase() {
        vtable=lbl_802B3168;
        __dt__14Agent_8002B5F4Fv(this,0);
    }
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_80043EFC(InlineBase*self,int flag) {
    if(self) {
        self->vtable=lbl_802B34F8;
        self->~InlineBase();
        if((short)flag>0)dispose(self);
    }
    return self;
}

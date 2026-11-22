extern "C" {
    extern char lbl_801EF5C8[], lbl_802B5EC0[], lbl_802B5F74[];
    void fn_801EF610(void*,void*);
    void __dt__14Agent_8002B5F4Fv(void*,int);
}
struct InlineBase {
    char unknown00[8];
    void*vtable;
    ~InlineBase() {
        vtable=lbl_802B5F74;
        __dt__14Agent_8002B5F4Fv(this,0);
    }
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_800614C0(InlineBase*self,int flag) {
    if(self) {
        self->vtable=lbl_802B5EC0;
        self->~InlineBase();
        if((short)flag>0)dispose(self);
    }
    return self;
}

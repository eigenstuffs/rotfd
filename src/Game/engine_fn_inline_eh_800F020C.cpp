extern "C" {
    extern char lbl_801EF5C8[], lbl_802C959C[], lbl_802C95B4[], lbl_802C967C[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct InlineRoot {
    void*vtable;
    ~InlineRoot() {
        vtable=lbl_802C967C;
        fn_8009009C(this,0);
    }
};
struct InlineBase:InlineRoot {
    ~InlineBase() {
        vtable=lbl_802C95B4;
    }
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_800F020C(InlineBase*self,int flag) {
    if(self) {
        self->vtable=lbl_802C959C;
        self->~InlineBase();
        if((short)flag>0)dispose(self);
    }
    return self;
}

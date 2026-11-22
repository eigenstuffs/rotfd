extern "C" {
    extern char lbl_801EF5C8[],lbl_802B69E8[];
    void fn_801EF610(void*,void*);
    void __dt__14Agent_80062E18Fv(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
    char unknown0C[136];
    void*secondary;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_800656AC(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802B69E8;
        self->secondary=lbl_802B69E8+180;
        __dt__14Agent_80062E18Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

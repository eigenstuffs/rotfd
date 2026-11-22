extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" char lbl_802B60F0[];
struct View {
    void*vtable;
    char unknown04[9];
    unsigned char count0D;
    char unknown0E[2];
    void*entries10[1];
};
extern "C" void*fn_80061D18(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802B60F0;
        for(unsigned char i=0; i<self->count0D; i++) {
            dispose(self->entries10[i]);
            self->entries10[i]=0;
        }
        if((short)flag>0)dispose(self);
    }
    return self;
}

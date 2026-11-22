extern "C" {
    extern char lbl_801EF5C8[],lbl_802BE79C[];
    void fn_801EF610(void*,void*);
    void __dt__14Agent_800C61B8Fv(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void* fn_800BFE58(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802BE79C;
        __dt__14Agent_800C61B8Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

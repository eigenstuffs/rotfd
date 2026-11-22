extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" {
    extern char lbl_802BF2C8[],lbl_802BF458[];
    void __dt__15CProjectileMoveFv(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
    char unknown0C[0x30C];
    void*secondary;
    ~View() {
        vtable=lbl_802BF458;
        secondary=lbl_802BF458+0x170;
        __dt__15CProjectileMoveFv(this,0);
    }
};
extern "C" void*__dt__10CDBombMoveFv(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802BF2C8;
        self->secondary=lbl_802BF2C8+0x170;
        self->~View();
        if((short)flag>0)dispose(self);
    }
    return self;
}

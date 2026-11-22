extern "C" {
    void __ct__22ContainerBase_802563CCFv(void*);
    extern char lbl_802B44B8[];
    extern char __vt__23ContainerLayer_80044168[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x59];
    unsigned char field65;
    unsigned char field66;
    char unknown67[0x1];
    unsigned int field68;
    unsigned int field6C;
};

extern "C" View* fn_8004C9A0(View* self) {
    __ct__22ContainerBase_802563CCFv(self);
    self->field08 = __vt__23ContainerLayer_80044168;
    self->field08 = lbl_802B44B8;
    self->field65 = 0;
    self->field66 = 0;
    self->field68 = 0;
    self->field6C = 0;
    return self;
}

/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-construct.md. */
extern "C" {
    void __ct__22ContainerBase_802563CCFv(void*);
    extern char lbl_802B42A8[];
    extern char lbl_802B4B50[];
    extern char __vt__23ContainerLayer_80044168[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x5C];
    unsigned char field68;
};

extern "C" View* fn_8004F2BC(View* self) {
    __ct__22ContainerBase_802563CCFv(self);
    self->field08 = __vt__23ContainerLayer_80044168;
    self->field08 = lbl_802B4B50;
    self->field68 = 1;
    self->field08 = lbl_802B42A8;
    return self;
}

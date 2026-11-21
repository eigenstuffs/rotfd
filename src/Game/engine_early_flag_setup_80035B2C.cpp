/* Original engine flag setup fragments with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-flag-setup.md. */
extern "C" {
    void __ct__24CallbackControl_802ECC00Fv(void*);
    extern char lbl_802B2934[];
    extern char lbl_802B29D0[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x2C];
    unsigned long long field38;
    char unknown40[0x46];
    unsigned short field86;
};

extern "C" View* fn_80035B2C(View* self) {
    __ct__24CallbackControl_802ECC00Fv(self);
    self->field08 = lbl_802B29D0;
    self->field86 = 1;
    self->field38 &= 0xFFFFFFFFFFFFFFFBULL;
    self->field38 |= 0x0000000020000000ULL;
    self->field38 |= 0x0000080000000000ULL;
    self->field08 = lbl_802B2934;
    return self;
}

extern "C" {
    void __ct__17LodAgent_802EC8A8Fv(void*);
    extern char lbl_802B0510[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x74];
    unsigned int field80;
};

extern "C" View* fn_80024E0C(View* self) {
    __ct__17LodAgent_802EC8A8Fv(self);
    self->field08 = lbl_802B0510;
    self->field80 = 0;
    return self;
}

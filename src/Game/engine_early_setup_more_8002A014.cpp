extern "C" {
    void __ct__23CallbackSingle_802ECA18Fv(void*);
    extern char lbl_802B1220[];
}

struct View {
    char unknown00[0x8];
    void* field08;
};

extern "C" View* fn_8002A014(View* self) {
    __ct__23CallbackSingle_802ECA18Fv(self);
    self->field08 = lbl_802B1220;
    return self;
}

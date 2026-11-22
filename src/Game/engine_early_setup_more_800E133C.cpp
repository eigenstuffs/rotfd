extern "C" {
    void __ct__23CallbackSingle_802ECA18Fv(void*);
    extern char lbl_802C8530[];
}

struct View {
    char unknown00[0x8];
    void* field08;
};

extern "C" View* fn_800E133C(View* self) {
    __ct__23CallbackSingle_802ECA18Fv(self);
    self->field08 = lbl_802C8530;
    return self;
}

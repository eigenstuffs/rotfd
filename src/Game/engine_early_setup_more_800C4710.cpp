extern "C" {
    void __ct__15Object_8002AD98Fv(void*);
    extern char lbl_802BF91C[];
}

struct View {
    char unknown00[0x8];
    void* field08;
};

extern "C" View* fn_800C4710(View* self) {
    __ct__15Object_8002AD98Fv(self);
    self->field08 = lbl_802BF91C;
    return self;
}

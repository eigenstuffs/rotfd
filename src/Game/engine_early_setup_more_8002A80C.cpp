extern "C" {
    void __ct__15Object_8002AD98Fv(void*);
    extern char lbl_802B139C[];
}

struct View {
    char unknown00[0x8];
    void* field08;
};

extern "C" View* fn_8002A80C(View* self) {
    __ct__15Object_8002AD98Fv(self);
    self->field08 = lbl_802B139C;
    return self;
}

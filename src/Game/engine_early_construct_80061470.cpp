extern "C" {
    void __ct__14Agent_8002B5F4Fv(void*);
    extern char lbl_802B5EC0[];
    extern char lbl_802B5F74[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x84];
    unsigned int field90;
};

extern "C" View* fn_80061470(View* self) {
    __ct__14Agent_8002B5F4Fv(self);
    self->field08 = lbl_802B5F74;
    self->field90 = -1;
    self->field08 = lbl_802B5EC0;
    return self;
}

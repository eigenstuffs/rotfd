extern "C" {
    void fn_80090084(void*);
    extern char lbl_802C9638[];
    extern char lbl_802C967C[];
}

struct View {
    void* field00;
    char unknown04[0x4];
    unsigned int field08;
    unsigned int field0C;
};

extern "C" View* fn_800E9648(View* self, unsigned int value1) {
    fn_80090084(self);
    self->field00 = lbl_802C967C;
    self->field08 = 0;
    self->field0C = 0;
    self->field08 = value1;
    self->field00 = lbl_802C9638;
    return self;
}

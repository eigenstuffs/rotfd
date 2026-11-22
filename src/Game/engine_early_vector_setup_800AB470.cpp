extern "C" {
    void fn_80090084(void*);
    extern char lbl_802BCF20[];
    extern char lbl_802BCF9C[];
    extern const float lbl_80379048;
}

struct View {
    void* field00;
    unsigned char field04;
    char unknown05[0x3];
    unsigned int field08;
    unsigned int field0C;
    float field10;
    float field14;
    float field18;
};

extern "C" View* fn_800AB470(View* self, unsigned int value1) {
    fn_80090084(self);
    self->field00 = lbl_802BCF9C;
    self->field08 = 0;
    self->field0C = 0;
    self->field10 = lbl_80379048;
    self->field08 = value1;
    self->field00 = lbl_802BCF20;
    self->field14 = lbl_80379048;
    self->field18 = lbl_80379048;
    self->field04 = 1;
    self->field18 = lbl_80379048;
    return self;
}

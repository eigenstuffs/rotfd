extern "C" {
    void fn_80090084(void*);
    extern char lbl_802B7F28[];
    extern char lbl_802B7F74[];
    extern const float lbl_80378958;
}

struct View {
    void* field00;
    unsigned char field04;
    char unknown05[0x3];
    unsigned int field08;
    float field0C;
    float field10;
    float field14;
    float field18;
};

extern "C" View* fn_80074638(View* self, unsigned int value1) {
    fn_80090084(self);
    self->field00 = lbl_802B7F74;
    self->field08 = 0;
    self->field08 = value1;
    self->field00 = lbl_802B7F28;
    self->field0C = lbl_80378958;
    self->field10 = lbl_80378958;
    self->field14 = lbl_80378958;
    self->field18 = lbl_80378958;
    self->field04 = 1;
    return self;
}

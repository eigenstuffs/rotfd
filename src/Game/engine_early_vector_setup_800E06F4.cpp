extern "C" {
    void fn_80090084(void*);
    extern char lbl_802C8260[];
    extern char lbl_802C82AC[];
    extern const float lbl_80379750;
    extern const float lbl_80379754;
    extern const float lbl_80379758;
    extern float game_vec3_zero[3];
}

struct View {
    void* field00;
    unsigned char field04;
    char unknown05[0x3];
    unsigned int field08;
    unsigned int field0C;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    float field1C;
    float field20;
    float field24;
};

extern "C" View* fn_800E06F4(View* self, unsigned int value1, unsigned int value2) {
    fn_80090084(self);
    self->field00 = lbl_802C82AC;
    self->field08 = value1;
    self->field0C = value2;
    self->field00 = lbl_802C8260;
    self->field10 = 0;
    self->field14 = 0;
    self->field18 = 0;
    self->field1C = game_vec3_zero[0];
    self->field20 = game_vec3_zero[1];
    self->field24 = game_vec3_zero[2];
    self->field04 = 1;
    self->field1C = lbl_80379750;
    self->field20 = lbl_80379754;
    self->field24 = lbl_80379758;
    return self;
}

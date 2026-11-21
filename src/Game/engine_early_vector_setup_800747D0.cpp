/* Original engine vector and scalar initialization with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-vector-setup.md. */
extern "C" {
    void fn_80090084(void*);
    extern char lbl_802B7EF8[];
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
    float field1C;
    float field20;
};

extern "C" View* fn_800747D0(View* self, unsigned int value1) {
    fn_80090084(self);
    self->field00 = lbl_802B7F74;
    self->field08 = 0;
    self->field08 = value1;
    self->field00 = lbl_802B7EF8;
    self->field0C = lbl_80378958;
    self->field10 = lbl_80378958;
    self->field14 = lbl_80378958;
    self->field18 = lbl_80378958;
    self->field1C = lbl_80378958;
    self->field20 = lbl_80378958;
    self->field04 = 1;
    return self;
}

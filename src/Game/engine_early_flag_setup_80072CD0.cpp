/* Original engine flag setup fragments with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-flag-setup.md. */
extern "C" {
    void __ct__14Agent_8002B5F4Fv(void*);
    extern char lbl_802B7C24[];
    extern const float lbl_80378928;
    extern float game_vec3_zero[3];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x2C];
    unsigned long long field38;
    char unknown40[0x50];
    short field90;
    short field92;
    unsigned int field94;
    unsigned char field98;
    char unknown99[0x3];
    float field9C;
    float fieldA0;
    float fieldA4;
    float fieldA8;
};

extern "C" View* fn_80072CD0(View* self) {
    __ct__14Agent_8002B5F4Fv(self);
    self->field08 = lbl_802B7C24;
    self->field90 = -1;
    self->field92 = -1;
    self->field94 = 0;
    self->field98 = 0;
    self->field9C = game_vec3_zero[0];
    self->fieldA0 = game_vec3_zero[1];
    self->fieldA4 = game_vec3_zero[2];
    self->fieldA8 = lbl_80378928;
    self->field38 &= 0xFFFFFFFFFFFFFFF7ULL;
    self->field38 |= 0x0000000100000000ULL;
    return self;
}

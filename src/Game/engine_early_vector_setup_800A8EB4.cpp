/* Original engine vector and scalar initialization with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-vector-setup.md. */
extern "C" {
    void __ct__15Object_8009A9D8Fv(void*);
    extern char lbl_802BCB24[];
    extern const float lbl_80379000;
    extern const float lbl_80379004;
    extern float game_vec3_zero[3];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x138];
    float field144;
    float field148;
    float field14C;
    char unknown150[0xC];
    float field15C;
    float field160;
    float field164;
    char unknown168[0x50];
    float field1B8;
    float field1BC;
    float field1C0;
    char unknown1C4[0x154];
    void* field318;
    char unknown31C[0x28];
    unsigned int field344;
    char unknown348[0x48];
    float field390;
    float field394;
    float field398;
    float field39C;
    float field3A0;
    float field3A4;
    float field3A8;
    float field3AC;
};

extern "C" View* fn_800A8EB4(View* self) {
    __ct__15Object_8009A9D8Fv(self);
    self->field08 = lbl_802BCB24;
    self->field318 = lbl_802BCB24 + 0x170;
    self->field390 = game_vec3_zero[0];
    self->field394 = game_vec3_zero[1];
    self->field398 = game_vec3_zero[2];
    self->field39C = lbl_80379000;
    self->field3A0 = lbl_80379004;
    self->field3A4 = game_vec3_zero[0];
    self->field3A8 = game_vec3_zero[1];
    self->field3AC = game_vec3_zero[2];
    self->field344 = 0;
    self->field144 = game_vec3_zero[0];
    self->field148 = game_vec3_zero[1];
    self->field14C = game_vec3_zero[2];
    self->field15C = game_vec3_zero[0];
    self->field160 = game_vec3_zero[1];
    self->field164 = game_vec3_zero[2];
    self->field1B8 = game_vec3_zero[0];
    self->field1BC = game_vec3_zero[1];
    self->field1C0 = game_vec3_zero[2];
    return self;
}

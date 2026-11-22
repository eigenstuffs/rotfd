extern "C" {
    void fn_8009A844(void*);
    extern char lbl_802BAB50[];
    extern const float lbl_80378D10;
    extern const float lbl_80378D14;
    extern const float lbl_80378D18;
    extern float game_vec3_zero[3];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x30C];
    void* field318;
    char unknown31C[0x38];
    float field354;
    char unknown358[0xC];
    float field364;
    float field368;
    char unknown36C[0x44];
    float field3B0;
    float field3B4;
    float field3B8;
    float field3BC;
    float field3C0;
    float field3C4;
    float field3C8;
    float field3CC;
    float field3D0;
    float field3D4;
    float field3D8;
    float field3DC;
    float field3E0;
};

extern "C" View* fn_800989C0(View* self) {
    fn_8009A844(self);
    self->field08 = lbl_802BAB50;
    self->field318 = lbl_802BAB50 + 0x170;
    self->field3B0 = lbl_80378D10;
    self->field3B4 = lbl_80378D10;
    self->field3B8 = game_vec3_zero[0];
    self->field3BC = game_vec3_zero[1];
    self->field3C0 = game_vec3_zero[2];
    self->field3C4 = game_vec3_zero[0];
    self->field3C8 = game_vec3_zero[1];
    self->field3CC = game_vec3_zero[2];
    self->field3D0 = lbl_80378D10;
    self->field3D4 = lbl_80378D10;
    self->field3D8 = lbl_80378D10;
    self->field3DC = lbl_80378D10;
    self->field3E0 = lbl_80378D10;
    self->field354 = lbl_80378D14;
    self->field364 = lbl_80378D18;
    self->field368 = lbl_80378D14;
    return self;
}

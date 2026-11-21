#include "Game/state_native_operation_records_selected.h"
/* Original engine vector and scalar initialization with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-vector-setup.md. */
extern "C" {
    void fn_80090084(void*);
    
    extern char lbl_802B92B0[];
    extern const float lbl_80378AD0;
    extern const float lbl_80378ADC;
    extern float game_vec3_zero[3];
}

struct View {
    void* field00;
    unsigned char field04;
    char unknown05[0x3];
    unsigned int field08;
    unsigned int field0C;
    char unknown10[0x30];
    float field40;
    float field44;
    float field48;
    float field4C;
    float field50;
    float field54;
    float field58;
};

extern "C" View* fn_80088B80(View* self, unsigned int value1, unsigned int value2) {
    fn_80090084(self);
    self->field00 = lbl_802B92B0;
    self->field08 = 0;
    self->field0C = 0;
    self->field08 = value1;
    self->field0C = value2;
    self->field00 = &lbl_802B8BD4;
    self->field40 = lbl_80378AD0;
    self->field44 = game_vec3_zero[0];
    self->field48 = game_vec3_zero[1];
    self->field4C = game_vec3_zero[2];
    self->field50 = game_vec3_zero[0];
    self->field54 = game_vec3_zero[1];
    self->field58 = game_vec3_zero[2];
    self->field04 = 1;
    self->field40 = lbl_80378ADC;
    return self;
}

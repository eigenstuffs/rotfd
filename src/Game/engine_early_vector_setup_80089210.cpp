#include "Game/state_native_operation_records_selected.h"
extern "C" {
    void fn_80090084(void*);
    
    extern char lbl_802B92B0[];
    extern const float lbl_80378AD0;
    extern const float lbl_80378B3C;
    extern const float lbl_80378B40;
}

struct View {
    void* field00;
    unsigned char field04;
    char unknown05[0x3];
    unsigned int field08;
    unsigned int field0C;
    char unknown10[0x30];
    unsigned int field40;
    unsigned int field44;
    float field48;
    float field4C;
};

extern "C" View* fn_80089210(View* self, unsigned int value1, unsigned int value2) {
    fn_80090084(self);
    self->field00 = lbl_802B92B0;
    self->field08 = 0;
    self->field0C = 0;
    self->field08 = value1;
    self->field0C = value2;
    self->field00 = &lbl_802B8B74;
    self->field40 = 0;
    self->field44 = 0;
    self->field48 = lbl_80378AD0;
    self->field4C = lbl_80378AD0;
    self->field04 = 0;
    self->field48 = lbl_80378B3C;
    self->field4C = lbl_80378B40;
    return self;
}

#include "Game/costume_native_operation_records.h"
extern "C" {
void fn_80090084(void*);
extern char lbl_802B92B0[];
extern const float lbl_80378B44;
}
struct SceneConstructOwner {
    void* table;
    unsigned char enabled;
    char unknown05[3];
    void* actor;
    void* controller;
    char unknown10[0x30];
    unsigned long fields[6];
    unsigned char first,second,flags[3];
    char unknown5D[3];
    float values[3];
};
extern "C" SceneConstructOwner* fn_8008A758(SceneConstructOwner* self, void* actor, void* controller) {
    fn_80090084(self);
    self->table = lbl_802B92B0;
    self->actor = 0;
    self->controller = 0;
    self->actor = actor;
    self->controller = controller;
    self->table = &lbl_802B8A6C;
    self->fields[0] = 0;
    self->fields[1] = 0;
    self->fields[2] = 0;
    self->fields[3] = 0;
    self->fields[4] = 0;
    self->fields[5] = 0;
    self->first = 0;
    self->second = 0;
    self->enabled = 0;
    for (int i = 0; i < 3; ++i) {
        self->flags[i] = 0;
        self->values[i] = float(i) * lbl_80378B44;
    }
    return self;
}

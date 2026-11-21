#include "Game/platform_resource_initializers.h"

struct PlatformByteBufferInit {
    char unknown00[8];
    void* table;
    char unknown0C[0xB4];
    int count, capacity;
    void* data;
};
extern "C" {
void* fn_80249CDC(void*);
extern char lbl_802ED348[];
}

extern "C" PlatformByteBufferInit* fn_8026EF64(PlatformByteBufferInit* self) {
    fn_80249CDC(self);
    self->table = lbl_802ED348;
    self->count = 0;
    self->capacity = 0;
    self->data = 0;
    return self;
}

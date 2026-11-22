#include "Game/texture_payload_stream.h"

extern "C" {
    extern char lbl_801EF5C8[];
    extern const char lbl_802ACC58[];
    void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
    void* fn_801E9F40(void*, const void*, int);
}

inline void* operator new(unsigned long size, const char* type, const char* file, int line, int alignment)
{
    return fn_801EFA1C(lbl_801EF5C8, size, type, file, line, alignment);
}

typedef char TexturePayloadRecordSize[sizeof(TexturePayloadRecord) == 20 ? 1 : -1];
typedef char TexturePayloadBundleSize[sizeof(TexturePayloadBundle) == 0xB4C ? 1 : -1];
typedef char TexturePayloadOwnerSize[sizeof(TexturePayloadOwner) == 0x48 ? 1 : -1];

extern "C" void fn_801C9474(TexturePayloadOwner* self, void** stream)
{
    const char* pool = lbl_802ACC58;
    self->BaseObject_Z::slot0C((TexturePayloadWord)stream);
    *stream = fn_801E9F40(&self->width, *stream,
        (char*)&self->last - (char*)&self->width + 1);
    int bytes = self->width * self->height;
    int palette = 0;
    switch (self->format) {
    case 12:
        bytes *= 4;
        break;
    case 13:
        bytes *= 3;
        break;
    case 1:
        bytes /= 2;
        palette = 16;
        break;
    case 2:
        palette = 256;
        break;
    case 7:
    case 8:
    case 10:
    case 11:
        bytes *= 2;
        break;
    }
    if (self->packedBytes) {
        self->data = fn_801EFA1C(lbl_801EF5C8, self->packedBytes,
            pool + 0x1C, pool + 0x2C, 0x27, 32);
        *stream = fn_801E9F40(self->data, *stream, self->packedBytes);
    } else {
        self->data = fn_801EFA1C(lbl_801EF5C8, bytes,
            pool + 0x1C, pool + 0x2C, 0x2A, 32);
        *stream = fn_801E9F40(self->data, *stream, bytes);
    }
    if (palette) {
        self->palette = fn_801EFA1C(lbl_801EF5C8, palette * 4,
            pool + 0x1C, pool + 0x2C, 0x31, 32);
        *stream = fn_801E9F40(self->palette, *stream, palette * 4);
    }
    bytes >>= 2;
    for (int i = 0; i < self->levels; ++i) {
        if (!bytes)
            bytes = 1;
        self->mips[i] = fn_801EFA1C(lbl_801EF5C8, bytes,
            pool + 0x1C, pool + 0x2C, 0x3A, 32);
        *stream = fn_801E9F40(self->mips[i], *stream, bytes);
        bytes >>= 2;
    }
    *stream = fn_801E9F40(&self->extra, *stream, 4);
    if (self->extra) {
        self->extra = new(pool + 0x40, pool + 0x2C, 0x42, 4) TexturePayloadBundle;
        *stream = fn_801E9F40(self->extra, *stream, sizeof(TexturePayloadBundle));
    }
}

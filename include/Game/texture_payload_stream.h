#ifndef GAME_TEXTURE_PAYLOAD_STREAM_H
#define GAME_TEXTURE_PAYLOAD_STREAM_H

typedef unsigned long TexturePayloadWord;

struct BaseObject_Z {
    TexturePayloadWord unknown00[3];
    void slot0C(TexturePayloadWord);
};

struct TexturePayloadRecord {
    char unknown00[16];
    float value;
    TexturePayloadRecord();
};

struct TexturePayloadBundle {
    char unknown00[12];
    TexturePayloadRecord records[144];
};

struct TexturePayloadOwner : BaseObject_Z {
    void* data;
    void* palette;
    void* mips[7];
    int width;
    int height;
    int packedBytes;
    unsigned char format;
    char unknown3D[3];
    unsigned char levels;
    unsigned char last;
    char unknown42[2];
    TexturePayloadBundle* extra;
};

extern "C" void fn_801C9474(TexturePayloadOwner*, void**);

#endif

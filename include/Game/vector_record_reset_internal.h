#ifndef GAME_VECTOR_RECORD_RESET_INTERNAL_H
#define GAME_VECTOR_RECORD_RESET_INTERNAL_H

struct ResetVector {
    float x, y, z;
    void assign(const ResetVector& v) {
        x = v.x;
        y = v.y;
        z = v.z;
    }
};
struct ResetRecord {
    char unknown00[0x20];
    ResetVector a, b, c, d;
    char unknown50[0x40];
};
struct ResetFlags { unsigned short state, unknown02; };
struct ResetView {
    char unknown00[0xA4];
    int count;
    int unknownA8;
    ResetRecord* records;
    char unknownB0[0x54];
    ResetFlags* flags;
};

typedef char CheckResetRecord[sizeof(ResetRecord) == 0x90 ? 1 : -1];
typedef char CheckResetFlags[sizeof(ResetFlags) == 4 ? 1 : -1];
#endif

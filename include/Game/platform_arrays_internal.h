#ifndef GAME_PLATFORM_ARRAYS_INTERNAL_H
#define GAME_PLATFORM_ARRAYS_INTERNAL_H
#include "world_curve_arrays_internal.h"
struct PlatformIndexList {short first,last,count;};
// The link initializer at 801ECA54 writes two signed 16-bit neighbors.
struct PlatformLinkFields {short previous,next;~PlatformLinkFields(){}};
struct PlatformLink : PlatformLinkFields {~PlatformLink(){}};
struct PlatformRecord18 {
    unsigned long unknown00;
    int status;
    short unknown08,unknown0A,count0C,unknown0E,unknown10,count12;
    float value14;
};
extern "C" {
extern char __vt__23PlatformArrays_802EA884[];
extern char __vt__23PlatformArrays_802EA874[];
}
// Explicit vptr view keeps the shared original table group outside this split.
struct PlatformArrays_802EA884 {
    PlatformArrays_802EA884(int);
    ~PlatformArrays_802EA884();
    void* vtable;
    void advance(float amount);
    int unknown04;
    PlatformIndexList freeIndices;
    short unknown0E;
    float value10;
    float value14;
    short unknown18;
    signed char flag1A;
    char unknown1B;
    WorldCurveArray<PlatformRecord18> records;
    WorldCurveArray<PlatformLink> indices;
    static void operator delete(void* p){fn_801EF610(lbl_801EF5C8,p);}
};
struct PlatformArrays_802EA874 : PlatformArrays_802EA884 {
    ~PlatformArrays_802EA874();
};
typedef char CheckPlatformLink[sizeof(PlatformLink)==4?1:-1];
typedef char CheckPlatformRecord[sizeof(PlatformRecord18)==24?1:-1];
typedef char CheckPlatformArrays[sizeof(PlatformArrays_802EA884)==0x34?1:-1];
#endif

#ifndef GAME_ENGINE_OWNER_SMALL_LOOPS_H
#define GAME_ENGINE_OWNER_SMALL_LOOPS_H

struct CurveSegmentFindEntry {
    char unknown00[0x14];
    float length;
    char unknown18[0xE0];
};
struct CurveSegmentFindOwner {
    char unknown00[0x80];
    int count, capacity;
    CurveSegmentFindEntry* entries;
    char unknown8C[0x10];
    float scale;
};
struct OwnerEmptyScanOwner {
    char unknown00[0x64];
    int count;
};
typedef char CurveSegmentFindEntrySize[sizeof(CurveSegmentFindEntry)==248?1:-1];
extern "C" {
    extern const float lbl_8037B44C;
    int fn_8024D9FC(CurveSegmentFindOwner*, float);
    signed char fn_8024A040(OwnerEmptyScanOwner*);
}
#endif

#ifndef GAME_SPHERE_BOX_HIT_COLLECT_801DFE90_H
#define GAME_SPHERE_BOX_HIT_COLLECT_801DFE90_H

#include "Game/sphere_box_first_hit_801dfbc4.h"

inline void* operator new(unsigned long, void* p) { return p; }
struct SphereBoxRecord {
    SphereBoxPoint point; float distance; SphereBoxPoint normal;
    void* object; SphereBoxMask flags;
    SphereBoxRecord() { object = 0; }
};
struct SphereBoxCollection {
    SphereBoxRecord records[256]; int count;
    int append() {
        if (count >= 256) { new (&records[255]) SphereBoxRecord; return 255; }
        new (&records[count++]) SphereBoxRecord; return count - 1;
    }
};
typedef char HitRecordSize[sizeof(SphereBoxRecord) == 40 ? 1 : -1];

extern "C" signed char fn_801DFE90(void*,const SphereBoxMatrix*,SphereBoxCollection*,SphereBoxMask);
#endif

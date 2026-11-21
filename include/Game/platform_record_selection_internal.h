#ifndef GAME_PLATFORM_RECORD_SELECTION_INTERNAL_H
#define GAME_PLATFORM_RECORD_SELECTION_INTERNAL_H
#include "Game/platform_arrays_internal.h"
// Native one-word result returned through the hidden structure-result pointer.
struct PlatformRecordIndex {
    int index;
    PlatformRecordIndex():index(-1){}
    PlatformRecordIndex(int i):index(i){}
};
inline PlatformRecord18* platformRecordAt(PlatformArrays_802EA884* self,int i) {
    PlatformRecord18* base=self->records.data;
    return base+i;
}
extern "C" {
PlatformRecordIndex fn_80283DE4(PlatformArrays_802EA884*,float);
void fn_8026EB34(PlatformArrays_802EA884*,PlatformRecord18*,int);
void fn_80283D5C(PlatformArrays_802EA884*,short);
}
typedef char CheckPlatformRecordIndex[sizeof(PlatformRecordIndex)==4?1:-1];
#endif

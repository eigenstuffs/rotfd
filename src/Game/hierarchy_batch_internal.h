// Private layouts for the recovered hierarchy batch actions.
#ifndef ROTFD_HIERARCHY_BATCH_INTERNAL_H
#define ROTFD_HIERARCHY_BATCH_INTERNAL_H

#include "group_runtime_internal.h"
struct HierarchyBatch {
    char unknown00[0x0C];
    Handle owner;
    char unknown10[0x80];
    HandleList primary;
    char unknown9C[0x0C];
    HandleList secondary;
    HandleList assigned;
    Handle related;
    char unknownC4[0x0C];
    HandleList third;
    int count, activeCount, offset;
};

#endif

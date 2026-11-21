#include "Game/typed_cleanup_tables.h"
extern struct SnapshotOwner *fn_8025F6F4(struct SnapshotOwner *, int);
SnapshotCleanupTable lbl_802ED0B0 = { 0, 0, fn_8025F6F4 };
typedef char CheckTableSize[sizeof(SnapshotCleanupTable) == 12 ? 1 : -1];

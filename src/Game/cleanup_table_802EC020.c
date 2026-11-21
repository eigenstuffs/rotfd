#include "Game/typed_cleanup_tables.h"
extern struct EngineArrayOwnerHandles *fn_8023AC94(struct EngineArrayOwnerHandles *, short);
HandleArrayCleanupTable lbl_802EC020 = { 0, 0, fn_8023AC94 };
typedef char CheckTableSize[sizeof(HandleArrayCleanupTable) == 12 ? 1 : -1];

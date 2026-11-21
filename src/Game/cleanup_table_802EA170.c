#include "Game/typed_cleanup_tables.h"
extern struct Object *fn_801C9F00(struct Object *, short);
ObjectCleanupTable lbl_802EA170 = { 0, 0, fn_801C9F00 };
typedef char CheckTableSize[sizeof(ObjectCleanupTable) == 12 ? 1 : -1];

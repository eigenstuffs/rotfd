/* Complete native ABI cleanup tables. Header words are null RTTI and offset. */
#include "Game/native_cleanup_table.h"
extern void *fn_801ECC44(void *, short);
NativeCleanupTable lbl_802EA8A0 = { 0, 0, fn_801ECC44 };
typedef char NativeCleanupTableSize[sizeof(NativeCleanupTable) == 12 ? 1 : -1];

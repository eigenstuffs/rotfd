#include "Game/typed_cleanup_tables.h"
extern struct SparseDestroySelf *fn_8026BD48(struct SparseDestroySelf *, int);
SparsePoolCleanupTable lbl_802ED168 = { 0, 0, fn_8026BD48 };
typedef char CheckTableSize[sizeof(SparsePoolCleanupTable) == 12 ? 1 : -1];

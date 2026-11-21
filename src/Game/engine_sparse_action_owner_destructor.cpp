#include "Game/engine_sparse_action_owner_destructor.h"

typedef char SparseActionRecordSize[sizeof(SparseActionRecord) == 12 ? 1 : -1];
typedef char SparseActionPoolSize[sizeof(SparseActionPool) == 36 ? 1 : -1];
typedef char SparseActionOwnerSize[sizeof(SparseActionOwner) == 0x290 ? 1 : -1];

extern "C" SparseActionOwner* fn_80263B08(SparseActionOwner* self, short deleting)
{
    if (self) {
        self->h28C.~SparseActionHandle3();
        self->h288.~SparseActionHandle2();
        self->h284.~SparseActionHandle2();
        self->h280.~SparseActionHandle2();
        self->fixed.~WorldHandleArray_801E55C4();
        self->records.~SparseActionPool();
        self->scalar.~SparseActionHandle2();
        self->second.~SparseActionArray<SparseActionHandle2>();
        self->first.~SparseActionArray<SparseActionHandle2>();
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}

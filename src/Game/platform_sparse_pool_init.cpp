#include "Game/platform_resource_initializers.h"
#include "Game/bitset_internal.h"

struct PlatformSparsePoolInit {
    int count, capacity;
    void* items;
    BitSet_80207EE8 occupied;
    int limit, used;
    void* table;
};
#include "Game/typed_cleanup_tables.h"

extern "C" PlatformSparsePoolInit* fn_8026BE78(PlatformSparsePoolInit* self) {
    self->table = &lbl_802ED168;
    self->count = 0;
    self->capacity = 0;
    self->items = 0;
    __ct__15BitSet_80207EE8Fv(&self->occupied);
    self->limit = 0;
    self->used = 0;
    return self;
}

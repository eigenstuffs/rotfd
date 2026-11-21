struct ChainIdentity {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct ChainOwner { unsigned long unknown00; ChainIdentity identity; unsigned long unknown08; ChainIdentity parent; };
struct ChainEntry { ChainOwner* object; unsigned long name, unknown08; signed char generation; char unknown0D[3]; };
struct ChainManager { int count, capacity; ChainEntry* entries; };
extern "C" struct { char unknown00[0x118]; ChainManager* manager; } lbl_801E9D24;
static inline ChainOwner* resolveChain(const ChainIdentity& handle)
{
    ChainEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->generation == handle.bits.generation)
        return entry->object;
    return 0;
}
extern "C" ChainIdentity* fn_80240F28(ChainOwner* self)
{
    ChainOwner* parent = resolveChain(self->parent);
    while (parent) {
        self = parent;
        parent = resolveChain(parent->parent);
    }
    return &self->identity;
}

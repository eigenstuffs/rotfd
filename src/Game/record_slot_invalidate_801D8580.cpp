// Bounded storage views for the original C-entry slot invalidation routine.
typedef unsigned short SlotInvalidationId;
typedef unsigned int SlotInvalidationWord;

struct SlotInvalidationRecord {
    SlotInvalidationWord unknown00;
    SlotInvalidationId owner;
    char unknown06[6];
};
struct SlotInvalidationPrimary {
    int count, capacity;
    char* records;
};
struct SlotInvalidationSecondary {
    int unknown00, count, capacity;
    char* records;
};
struct SlotInvalidationGlobals {
    char unknown00[0x12C];
    SlotInvalidationSecondary* secondary;
    SlotInvalidationPrimary* primary;
};
extern "C" SlotInvalidationGlobals lbl_801E9D24;

struct SlotInvalidationChild {
    char unknown00[0x60];
    SlotInvalidationId slot;
    char unknown62[6];
};
struct SlotInvalidationChildren {
    int count, capacity;
    SlotInvalidationChild* items;
    SlotInvalidationChild& operator[](int i) { return items[i]; }
};
struct SlotInvalidationOwner {
    char unknown00[0x20];
    SlotInvalidationId slot;
    char unknown22[2];
    SlotInvalidationChildren children;
};

// A read-only borrow of the child while its registry entry is invalidated.
// The child write below resolves the array element again after that registry
// write, preserving the original alias-sensitive access order.
struct SlotInvalidationReadView_801D8580 {
    const SlotInvalidationChild& value;
    SlotInvalidationReadView_801D8580(const SlotInvalidationChild& v) : value(v) {}
    ~SlotInvalidationReadView_801D8580() {}
    unsigned int get() const { return value.slot; }
};

typedef char SlotInvalidationRecordSizeCheck[sizeof(SlotInvalidationRecord) == 12 ? 1 : -1];
typedef char SlotInvalidationChildSizeCheck[sizeof(SlotInvalidationChild) == 0x68 ? 1 : -1];
typedef char SlotInvalidationOwnerSizeCheck[sizeof(SlotInvalidationOwner) == 0x30 ? 1 : -1];

extern "C" void fn_801D8580(void* memory)
{
    SlotInvalidationOwner* self = (SlotInvalidationOwner*)memory;
    if (self->slot != 0xFFFF)
        ((SlotInvalidationRecord*)(lbl_801E9D24.primary->records
            + (self->slot + 1) * sizeof(SlotInvalidationRecord)))->owner = 0xFFFF;
    self->slot = 0xFFFF;
    for (int i = 0; i < self->children.count; ++i) {
        SlotInvalidationReadView_801D8580 child(self->children[i]);
        if (child.get() != 0xFFFF)
            ((SlotInvalidationRecord*)(lbl_801E9D24.secondary->records
                + (child.get() + 1) * sizeof(SlotInvalidationRecord)))->owner = 0xFFFF;
        self->children[i].slot = 0xFFFF;
    }
}

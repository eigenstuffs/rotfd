// Exchange the selected record's node with a supplied node's previous slot.
struct SlotExchangeNode;
struct SlotExchangeHandle {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct SlotExchangeEntry {
    SlotExchangeNode* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct SlotExchangeManager {
    int count, capacity;
    SlotExchangeEntry* entries;
};
struct BorrowedSlotExchangeManager {
    SlotExchangeManager* value;
    BorrowedSlotExchangeManager(SlotExchangeManager* manager) : value(manager) {}
    SlotExchangeManager* operator->() const { return value; }
};
struct SlotExchangeContext {
    char unknown00[0x118];
    SlotExchangeManager* manager;
    BorrowedSlotExchangeManager getManager() {
        return BorrowedSlotExchangeManager(manager);
    }
};
extern "C" SlotExchangeContext lbl_801E9D24;

struct SlotExchangeVector {
    float x, y, z;
    SlotExchangeVector& operator=(const SlotExchangeVector& other) {
        x = other.x; y = other.y; z = other.z;
        return *this;
    }
};
struct SlotExchangeNode {
    char unknown00[0x70];
    SlotExchangeHandle controller;
    char unknown74[0x1E];
    short slot;
    char unknown94[0xD4];
    char operations[0x34];
    SlotExchangeVector position;
};
inline SlotExchangeNode* resolveSlotExchange(const SlotExchangeHandle& handle) {
    SlotExchangeEntry* entry =
        &lbl_801E9D24.getManager()->entries[handle.bits.index];
    if (entry->generation == handle.bits.generation) return entry->object;
    return 0;
}
struct SlotExchangeRecord {
    short id;
    SlotExchangeNode* node;
    SlotExchangeVector position;
    void setNode(SlotExchangeNode* next) { node = next; node->slot = id; }
};
struct SlotExchangeOwner {
    char unknown00[0x68];
    short index;
    short unknown6A;
    int mode;
    signed char busy;
    char unknown71[3];
    SlotExchangeRecord records[9];
};
struct BorrowedSlotExchangeNode {
    SlotExchangeNode* value;
    BorrowedSlotExchangeNode(SlotExchangeNode* node) : value(node) {}
    operator SlotExchangeNode*() const { return value; }
};
extern "C" {
void fn_8007340C(SlotExchangeNode*, SlotExchangeRecord*);
signed char fn_8007D6A0(void*, int);
}

extern "C" signed char fn_80071904(SlotExchangeOwner* self, SlotExchangeNode* node) {
    if (!self->busy) {
        short oldSlot = node->slot;
        SlotExchangeRecord& record = self->records[self->index];
        BorrowedSlotExchangeNode old(record.node);
        resolveSlotExchange(node->controller)->position = record.position;
        fn_8007340C(node, &self->records[self->index]);
        fn_8007D6A0(resolveSlotExchange(node->controller)->operations, 1);
        self->records[self->index].setNode(node);
        self->records[oldSlot].setNode(old);
        self->busy = 1;
        return 1;
    }
    return 0;
}

typedef char CheckExchangeHandle[sizeof(SlotExchangeHandle) == 4 ? 1 : -1];
typedef char CheckExchangeEntry[sizeof(SlotExchangeEntry) == 16 ? 1 : -1];
typedef char CheckExchangeManager[sizeof(SlotExchangeManager) == 12 ? 1 : -1];
typedef char CheckExchangeBorrowedManager[sizeof(BorrowedSlotExchangeManager) == 4 ? 1 : -1];
typedef char CheckExchangeBorrowedNode[sizeof(BorrowedSlotExchangeNode) == 4 ? 1 : -1];
typedef char CheckExchangeRecord[sizeof(SlotExchangeRecord) == 20 ? 1 : -1];
typedef char CheckExchangeOwner[sizeof(SlotExchangeOwner) == 0x128 ? 1 : -1];
typedef char CheckExchangeNode[sizeof(SlotExchangeNode) == 0x1A8 ? 1 : -1];

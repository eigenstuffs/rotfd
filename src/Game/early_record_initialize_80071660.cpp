// Initialize the owner's nine indexed records from related object handles.
struct SlotInitNode;
struct SlotInitOwner;

struct SlotInitHandle {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct SlotInitEntry {
    SlotInitNode* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct SlotInitManager {
    int count, capacity;
    SlotInitEntry* entries;
};
struct SlotInitBorrowedManager {
    SlotInitManager* value;
    SlotInitBorrowedManager(SlotInitManager* manager) : value(manager) {}
    SlotInitManager* operator->() const { return value; }
};
struct SlotInitContext {
    char unknown00[0x118];
    SlotInitManager* manager;
    SlotInitBorrowedManager getManager() { return SlotInitBorrowedManager(manager); }
};
extern "C" SlotInitContext lbl_801E9D24;

struct SlotInitVector {
    float x, y, z;
    SlotInitVector& operator=(const SlotInitVector& other) {
        x = other.x; y = other.y; z = other.z;
        return *this;
    }
};
struct SlotInitNode {
    char unknown00[0x130];
    SlotInitHandle target;
};
inline SlotInitNode* resolveInitSlot(const SlotInitHandle& handle) {
    SlotInitEntry* entry = &lbl_801E9D24.getManager()->entries[handle.bits.index];
    if (entry->generation == handle.bits.generation) return entry->object;
    return 0;
}
struct SlotInitRecord {
    short id;
    SlotInitNode* node;
    SlotInitVector position;
    SlotInitRecord& operator=(const SlotInitRecord& other) {
        id = other.id;
        node = other.node;
        position = other.position;
        return *this;
    }
};
struct SlotInitOwner {
    char unknown00[0x68];
    short index;
    short unknown6A;
    int mode;
    signed char busy;
    char unknown71[3];
    SlotInitRecord records[9];
    void setRecord(int index, const SlotInitRecord& record) { records[index] = record; }
};

extern "C" {
float fn_801F45D8();
void fn_801F129C(int);
float fn_8025E268(SlotInitOwner*, int);
int fn_801F1224(int, int);
const SlotInitHandle* fn_8025E1D4(SlotInitOwner*, int);
// The provider initializes this output record and stores the owner pointer.
void fn_80072B28(void*, short, void*, void*);
void fn_80071F48(SlotInitOwner*);
extern const float lbl_803788F8;
}

extern "C" void fn_80071660(SlotInitOwner* self) {
    fn_801F129C((int)(lbl_803788F8 * fn_801F45D8()));
    switch ((int)fn_8025E268(self, 0)) {
    case 0:
    case 1:
    case 2:
        self->mode = fn_801F1224(0, 2);
        break;
    }
    for (short i = 0; i < 9; ++i) {
        SlotInitRecord record;
        fn_80072B28(&record, i, self,
            resolveInitSlot(resolveInitSlot(*fn_8025E1D4(self, i))->target));
        self->setRecord(i, record);
    }
    fn_80071F48(self);
}

typedef char CheckSlotInitHandle[sizeof(SlotInitHandle) == 4 ? 1 : -1];
typedef char CheckSlotInitEntry[sizeof(SlotInitEntry) == 16 ? 1 : -1];
typedef char CheckSlotInitManager[sizeof(SlotInitManager) == 12 ? 1 : -1];
typedef char CheckSlotInitBorrowedManager[sizeof(SlotInitBorrowedManager) == 4 ? 1 : -1];
typedef char CheckSlotInitRecord[sizeof(SlotInitRecord) == 20 ? 1 : -1];
typedef char CheckSlotInitOwner[sizeof(SlotInitOwner) == 0x128 ? 1 : -1];

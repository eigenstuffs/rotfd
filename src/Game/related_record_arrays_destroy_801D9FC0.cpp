// Bounded storage views for the original C-entry destruction routine.
// The original vtables and the remaining owner methods stay in their providers.
typedef unsigned long RelatedRecordDestroyWord;

extern "C" {
extern char lbl_8028F698[], lbl_801EF5C8[], lbl_802EA660[], lbl_802EA498[];
void fn_8028FD50(void*, void*, RelatedRecordDestroyWord);
void fn_801EF610(void*, void*);
void fn_80243E90(void*, int);
}

struct Handle_801F7F10 {
    RelatedRecordDestroyWord value;
    ~Handle_801F7F10();
};
struct RelatedRecordDestroyZero : Handle_801F7F10 {
    ~RelatedRecordDestroyZero() {}
};
struct RelatedRecordDestroyHandle : RelatedRecordDestroyZero {
    ~RelatedRecordDestroyHandle() {}
};

template<int N> struct RelatedRecordDestroyElement {
    char bytes[N];
    ~RelatedRecordDestroyElement() {}
};

template<class T> struct RelatedRecordDestroyArray {
    int count, capacity;
    T* items;

    T& operator[](int i) { return items[i]; }
    void release() {
        if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
            items = 0;
        }
    }
    ~RelatedRecordDestroyArray() {
        if (items) {
            for (int i = 0; i < count; ++i)
                items[i].~T();
            release();
            items = 0;
        }
    }
};

struct BitSet_80207EE8 {
    int count, capacity;
    RelatedRecordDestroyWord* words;
    int bits;
    ~BitSet_80207EE8();
};
struct RelatedRecordDestroyBlock
    : RelatedRecordDestroyArray<RelatedRecordDestroyElement<6> > {
    RelatedRecordDestroyArray<RelatedRecordDestroyElement<2> > second;
    RelatedRecordDestroyWord unknown18;
    BitSet_80207EE8 occupied;

    ~RelatedRecordDestroyBlock() {}
    static void operator delete(void* memory) {
        fn_801EF610(lbl_801EF5C8, memory);
    }
};

struct RelatedRecordDestroyRetained {
    char unknown00[0x88];
    RelatedRecordDestroyHandle handle;
    RelatedRecordDestroyWord unknown8C;
    ~RelatedRecordDestroyRetained() {}
};
struct RelatedRecordDestroyId {
    char unknown00[0x60];
    unsigned short id;
    char unknown62[6];
    ~RelatedRecordDestroyId() {}
};
struct RelatedRecordDestroySlot {
    RelatedRecordDestroyWord unknown00;
    unsigned short id;
    char unknown06[6];
};

// The record is borrowed only during its slot-release operation. It remains
// alive until the owner destroys the ID array later in this routine.
struct RelatedRecordIdView_801D9FC0 {
    const RelatedRecordDestroyId& value;
    RelatedRecordIdView_801D9FC0(const RelatedRecordDestroyId& v) : value(v) {}
    ~RelatedRecordIdView_801D9FC0() {}
    unsigned int get() const { return value.id; }
};
struct RelatedRecordDestroyService {
    char unknown00[12];
    RelatedRecordDestroySlot* slots;
    RelatedRecordDestroySlot& operator[](unsigned int id) {
        return slots[id + 1];
    }
};
struct RelatedRecordDestroyGlobals {
    char unknown00[0x128];
    RelatedRecordDestroyService* service;
};
extern "C" RelatedRecordDestroyGlobals lbl_801E9D24;

struct RelatedRecordDestroyOwner {
    char unknown00[8];
    void* table;
    char unknown0C[0x68];
    RelatedRecordDestroyArray<RelatedRecordDestroyElement<12> > first;
    RelatedRecordDestroyArray<RelatedRecordDestroyElement<4> > second;
    RelatedRecordDestroyArray<RelatedRecordDestroyElement<24> > third;
    RelatedRecordDestroyArray<RelatedRecordDestroyElement<24> > fourth;
    RelatedRecordDestroyArray<RelatedRecordDestroyRetained> retained;
    RelatedRecordDestroyArray<RelatedRecordDestroyElement<8> > sixth;
    RelatedRecordDestroyArray<RelatedRecordDestroyElement<12> > seventh;
    RelatedRecordDestroyArray<RelatedRecordDestroyId> ids;
    RelatedRecordDestroyArray<RelatedRecordDestroyElement<2> > ninth;
    RelatedRecordDestroyArray<RelatedRecordDestroyElement<192> > tenth;
    RelatedRecordDestroyArray<RelatedRecordDestroyElement<24> > eleventh;
    RelatedRecordDestroyBlock* block;
};

typedef char RelatedRecordIdSizeCheck[sizeof(RelatedRecordDestroyId) == 0x68 ? 1 : -1];
typedef char RelatedRecordRetainedSizeCheck[sizeof(RelatedRecordDestroyRetained) == 0x90 ? 1 : -1];
typedef char RelatedRecordBlockSizeCheck[sizeof(RelatedRecordDestroyBlock) == 0x2C ? 1 : -1];
typedef char RelatedRecordOwnerSizeCheck[sizeof(RelatedRecordDestroyOwner) == 0xFC ? 1 : -1];

extern "C" void* fn_801D9FC0(void* memory, int deleting)
{
    RelatedRecordDestroyOwner* self = (RelatedRecordDestroyOwner*)memory;
    if (self) {
        self->table = lbl_802EA660;
        if (self->block)
            delete self->block;
        if (lbl_801E9D24.service) {
            for (int i = 0; i < self->ids.count; ++i) {
                RelatedRecordIdView_801D9FC0 record(self->ids[i]);
                if (record.get() != 65535)
                    (*lbl_801E9D24.service)[record.get()].id = 65535;
            }
        }
        self->eleventh.~RelatedRecordDestroyArray<RelatedRecordDestroyElement<24> >();
        self->tenth.~RelatedRecordDestroyArray<RelatedRecordDestroyElement<192> >();
        self->ninth.~RelatedRecordDestroyArray<RelatedRecordDestroyElement<2> >();
        self->ids.~RelatedRecordDestroyArray<RelatedRecordDestroyId>();
        self->seventh.~RelatedRecordDestroyArray<RelatedRecordDestroyElement<12> >();
        self->sixth.~RelatedRecordDestroyArray<RelatedRecordDestroyElement<8> >();
        self->retained.~RelatedRecordDestroyArray<RelatedRecordDestroyRetained>();
        self->fourth.~RelatedRecordDestroyArray<RelatedRecordDestroyElement<24> >();
        self->third.~RelatedRecordDestroyArray<RelatedRecordDestroyElement<24> >();
        if (self) {
            self->table = lbl_802EA498;
            self->second.~RelatedRecordDestroyArray<RelatedRecordDestroyElement<4> >();
            self->first.~RelatedRecordDestroyArray<RelatedRecordDestroyElement<12> >();
            fn_80243E90(self, 0);
        }
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}

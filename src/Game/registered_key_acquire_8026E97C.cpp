/* Registered-key acquisition (fn_8026E97C; called by fn_8026E8D4 in
 * registered_key_init.cpp): returns -1 for key 0; otherwise builds a record
 * (state 2, second.count = key; other fields left unset as in the original),
 * reuses the first free record (state 1) or appends it, growing the record
 * array by 16, and returns its index through the hidden RangeAllocateIndex
 * result. Code-identical twin of fn_80252E1C.
 *
 * Matching note: the free-slot test reads the state through an inline helper
 * whose pointer parameter is self-assigned. That makes the inliner keep the
 * element address as a temporary (add + lwz 4) like the original inline
 * member call, instead of folding the member offset into the strength-
 * reduced index (addi + lwzx). Layouts follow include/Game/engine_range_allocate.h. */
struct RangeAllocateRange { short first, last, count; };
struct RangeAllocateRecord {
    int value, state;
    RangeAllocateRange first, second;
    float stamp;
};
struct RangeAllocateItem140 { char bytes[140]; };
struct RangeAllocateArray140 { int count, capacity; RangeAllocateItem140* items; };
struct RangeAllocateOwner {
    char unknown00[8];
    RangeAllocateRange range;
    short unknown0E;
    float stamp, threshold;
    char unknown18[4];
    int count, capacity;
    RangeAllocateRecord* records;
    RangeAllocateArray140 entries;
};
struct RangeAllocateIndex {
    int value;
    RangeAllocateIndex() : value(-1) {}
    RangeAllocateIndex(int v) : value(v) {}
    RangeAllocateIndex(const RangeAllocateIndex& other) : value(other.value) {}
};

extern "C" {
    extern unsigned char lbl_8028F698[];
    void* fn_8028FAF4(void*, void*, int, int);
    void* fn_8028FF24(void*, int);
    void fn_8028FD50(void*, void*, int);
}

inline void* operator new(unsigned long, void* place) { return place; }

inline int recordState(const RangeAllocateRecord* record)
{
    record = record; /* inline member `this` temporary */
    return record->state;
}

inline void growCallbackRecords(RangeAllocateOwner* self, int capacity)
{
    if (capacity) {
        if (self->records)
            self->records = (RangeAllocateRecord*)fn_8028FAF4(lbl_8028F698, self->records,
                self->capacity * sizeof(RangeAllocateRecord), capacity * sizeof(RangeAllocateRecord));
        else
            self->records = (RangeAllocateRecord*)fn_8028FF24(lbl_8028F698,
                capacity * sizeof(RangeAllocateRecord));
    } else if (self->records) {
        fn_8028FD50(lbl_8028F698, self->records, self->capacity * sizeof(RangeAllocateRecord));
        self->records = 0;
    }
}

extern "C" RangeAllocateIndex fn_8026E97C(RangeAllocateOwner* self, short key)
{
    if (!key) return RangeAllocateIndex();
    RangeAllocateRecord record;
    record.first.count = 0;
    record.state = 2;
    record.second.count = key;
    for (int i = 0; i < self->count; i++) {
        if (recordState(&self->records[i]) == 1) {
            self->records[i] = record;
            return RangeAllocateIndex(i);
        }
    }
    if (self->count + 1 > self->capacity) {
        growCallbackRecords(self, self->capacity + 16);
        self->capacity += 16;
    }
    new (&self->records[self->count++]) RangeAllocateRecord(record);
    return RangeAllocateIndex(self->count - 1);
}

typedef char RecordSize[sizeof(RangeAllocateRecord) == 0x18 ? 1 : -1];

/* Record-service handle removal: erase the first handle in records[ri]->arrays[ai]
 * that resolves to the same object as *handle.  The record accessor takes a
 * const int& while the record index is unsigned, so every access binds a fresh
 * temporary (no loop-invariant hoisting of the record chain); the count is
 * cached before the loop (CTR loop). */
typedef unsigned long u32;

struct Handle_801F7F10 {
    union {
        u32 value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct Entry {
    void* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};
struct Manager { char unknown00[8]; Entry* entries; };
struct Context { char unknown00[0x118]; Manager* manager; };

extern "C" {
void* memcpy(void*, const void*, u32);
extern Context lbl_801E9D24;
}

inline void* resolve(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}

struct RetainedHandle : Handle_801F7F10 {};

struct HandleArray {
    int count, capacity;
    RetainedHandle* data;
    int getCount() const { return count; }
    RetainedHandle& at(int i) { return data[i]; }
    void erase(int i)
    {
        at(i).~RetainedHandle();
        memcpy(&at(i), &at(i) + 1, (--count - i) * sizeof(RetainedHandle));
    }
};

struct Record { char unknown00[8]; HandleArray* arrays; HandleArray& at(int i) { return arrays[i]; } };
struct RecordArray { int count, capacity; Record** data; Record*& at(const int& i) { return data[i]; } };
struct RecordService { char unknown00[0x20]; RecordArray records; };

extern "C" void fn_800B6F70(RecordService* self, u32 ri, int ai, const Handle_801F7F10* handle)
{
    int count = self->records.at(ri)->at(ai).getCount();
    for (int i = 0; i < count; ++i) {
        void* current = resolve(self->records.at(ri)->at(ai).at(i));
        if (current == resolve(*handle)) {
            self->records.at(ri)->at(ai).erase(i);
            break;
        }
    }
}

#include "Game/cache_record_array_destroy.h"
// Bounded storage views for the original C-entry cached-record destructor.
extern "C" {
#include "Game/engine_array_cleanup.h"
extern char lbl_802EA608[];
}

struct CacheRecordDestroyRecord {
    char unknown00[0x60];
    unsigned short index;
    char unknown62[6];
    ~CacheRecordDestroyRecord() {}
};
template<class T> struct CacheRecordDestroyArray {
    int count, capacity;
    T* data;
    T& operator[](int i) { return data[i]; }
    ~CacheRecordDestroyArray() {
        if (data) {
            for (int i = 0; i < count; ++i)
                data[i].~T();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
                data = 0;
            }
            data = 0;
        }
    }
};

// This view borrows the record for its registry-slot release. The actual
// record array remains alive until the subsequent array destruction.
struct CacheRecordIndexView_801D87AC {
    const CacheRecordDestroyRecord& value;
    CacheRecordIndexView_801D87AC(const CacheRecordDestroyRecord& v) : value(v) {}
    ~CacheRecordIndexView_801D87AC() {}
    unsigned int get() const { return value.index; }
};
struct CacheRecordDestroyNode {
    unsigned int handle;
    unsigned short owner, unknown06, previous, next;
};
struct CacheRecordDestroyCache {
    char unknown00[0xC];
    CacheRecordDestroyNode* data;
    CacheRecordDestroyNode& slot(int i) { return data[i + 1]; }
};
struct CacheRecordDestroyGlobals {
    char unknown00[0x12C];
    CacheRecordDestroyCache* cache;
};
extern "C" CacheRecordDestroyGlobals lbl_801E9D24;

struct CacheRecordDestroyOwner {
    char unknown00[8];
    void* table;
    char unknown0C[0x18];
    CacheRecordDestroyArray<CacheRecordDestroyRecord> records;
};
typedef char CacheRecordDestroyRecordSizeCheck[sizeof(CacheRecordDestroyRecord) == 0x68 ? 1 : -1];
typedef char CacheRecordDestroyOwnerSizeCheck[sizeof(CacheRecordDestroyOwner) == 0x30 ? 1 : -1];

extern "C" CacheRecordDestroyOwner* fn_801D87AC(CacheRecordDestroyOwner* self, int deleting)
{
    if (self) {
        self->table = lbl_802EA608;
        if (lbl_801E9D24.cache) {
            for (int i = 0; i < self->records.count; ++i) {
                CacheRecordIndexView_801D87AC record(self->records[i]);
                if (record.get() != 0xFFFF)
                    lbl_801E9D24.cache->slot(record.get()).owner = 0xFFFF;
            }
        }
        self->records.~CacheRecordDestroyArray();
        // Established native base-cleanup entry: flag0 retains the owner.
        __dt__22SpatialRecord_802EA440Fv((EngineCleanupOwner*)self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}

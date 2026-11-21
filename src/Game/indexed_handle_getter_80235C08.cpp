// Return the handle in the owner's indexed 0x4C-byte context record.
typedef unsigned long Word;
struct IndexedHandle { Word word; };
struct IndexedRecord {
    char unknown00[0x10];
    IndexedHandle handle;
    char unknown14[0x38];
};
struct IndexedContext {
    char unknown00[0x114];
    IndexedRecord* records;
};
struct IndexedOwner {
    char unknown00[0x20];
    int index;
};
extern "C" IndexedContext lbl_801E9D24;
extern "C" const IndexedHandle* fn_80235C08(const IndexedOwner* self) {
    return &lbl_801E9D24.records[self->index].handle;
}

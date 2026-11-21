// Release the handle in every key/handle pair. See the unit note.
struct PairReleaseRecord {
    unsigned long key, handle;
};
struct PairReleaseOwner {
    unsigned long unknown00;
    int count, capacity;
    PairReleaseRecord* items;
};
extern "C" {
extern struct { char unknown00[0x118]; void* manager; } lbl_801E9D24;
void fn_801B3E54(void*, unsigned long*);
}
extern "C" void fn_801B13C4(PairReleaseOwner* self) {
    int offset;
    int i;
    for (i = 0, offset = 0; i < self->count; offset += 8, ++i) {
        PairReleaseRecord* pair = reinterpret_cast<PairReleaseRecord*>(
            reinterpret_cast<char*>(self->items) + offset);
        fn_801B3E54(lbl_801E9D24.manager, &pair->handle);
    }
}

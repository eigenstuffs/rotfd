static inline unsigned short lastSortedIndex_80271BD8(const unsigned short* indices,
                                                       unsigned long count) {
    return indices[count - 1];
}
struct SortedCursor_80271BD8 {
    unsigned short* position;
    SortedCursor_80271BD8(unsigned short* p) : position(p) {}
    unsigned short operator*() const { return *position; }
    unsigned short operator[](int offset) const { return position[offset]; }
    void operator--() { --position; }
};
struct SortedRenderRecord_80271BD8 {
    unsigned short flags, next;
    char unknown04[0xA4];
};
struct SortedRenderOwner_80271BD8 {
    char unknown00[0x3AC];
    SortedRenderRecord_80271BD8* records;
    unsigned long count;
};
extern "C" void fn_80271D74(SortedRenderOwner_80271BD8*, unsigned short*, int, int);
extern "C" unsigned short fn_80271BD8(SortedRenderOwner_80271BD8* self)
{
    unsigned short indices[512];
    for (unsigned long i = 0; i < self->count; ++i)
        indices[i] = i;
    fn_80271D74(self, indices, 0, self->count - 1);
    unsigned long remaining = self->count - 1;
    SortedCursor_80271BD8 cursor = indices + remaining;
    while (remaining--) {
        self->records[*cursor].next = cursor[-1];
        --cursor;
    }
    self->records[indices[0]].next = 0xFFFF;
    return lastSortedIndex_80271BD8(indices,self->count);
}

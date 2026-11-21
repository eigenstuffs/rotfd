/* Search observed 0xD4-byte records by the identity word at offset4.
 * Key comparison as an inline value operation preserves the native lifetimes. */
struct RecordKey_800A78E4 {
    unsigned int value;
    bool operator==(const RecordKey_800A78E4& other) const {
        return value == other.value;
    }
};
struct SearchRecord_800A78E4 {
    char unknown00[4];
    RecordKey_800A78E4 key;
    char unknown08[0xCC];
};
struct SearchOwner_800A78E4 {
    char unknown00[0x20];
    int count;
    char unknown24[4];
    SearchRecord_800A78E4* records;
};
extern "C" int fn_800A78E4(const SearchOwner_800A78E4* self,
    const RecordKey_800A78E4* needle)
{
    for (int i = 0; i < self->count; ++i) {
        if (self->records[i].key == *needle) return i;
    }
    return -1;
}
typedef char CheckSearchRecordSize[sizeof(SearchRecord_800A78E4) == 0xD4 ? 1 : -1];

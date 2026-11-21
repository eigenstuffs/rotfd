/* Return the byte-sized index of an observed 12-byte key record. */
struct RecordIdentity_80262AB4 {
    unsigned int value;
    bool operator==(const RecordIdentity_80262AB4& other) const {
        return value == other.value;
    }
};
struct IdentityRecord_80262AB4 {
    RecordIdentity_80262AB4 key;
    char unknown04[8];
};
struct IdentityOwner_80262AB4 {
    char unknown00[0x24];
    IdentityRecord_80262AB4* records;
    char unknown28[0x10];
    int count;
};
extern "C" unsigned char fn_80262AB4(const IdentityOwner_80262AB4* self,
    const RecordIdentity_80262AB4* key)
{
    for (int i = 0; i < self->count; ++i) {
        if (self->records[i].key == *key) return i;
    }
    return 255;
}
typedef char IdentityRecordSizeCheck[sizeof(IdentityRecord_80262AB4) == 12 ? 1 : -1];

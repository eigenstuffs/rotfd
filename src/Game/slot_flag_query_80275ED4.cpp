/* Query one of sixteen flag bytes in each observed 64-byte record. */
struct SlotFlagRecord_80275ED4 {
    char unknown00[0x1C];
    unsigned char flags[16];
    char unknown2C[0x14];
    unsigned char get(unsigned int slot) const { return flags[slot]; }
};
struct SlotFlagOwner_80275ED4 {
    int count;
    char unknown04[4];
    SlotFlagRecord_80275ED4* records;
    SlotFlagRecord_80275ED4& get(int index) const { return records[index]; }
};
extern "C" bool fn_80275ED4(const SlotFlagOwner_80275ED4* self,
    unsigned char slot)
{
    if (slot < 16) {
        for (int i = 0; i < self->count; ++i) {
            if (self->get(i).get(slot)) return true;
        }
    }
    return false;
}
typedef char SlotFlagRecordSizeCheck[sizeof(SlotFlagRecord_80275ED4) == 64 ? 1 : -1];

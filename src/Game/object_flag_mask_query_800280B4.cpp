struct ObjectFlags_800280B4 {
    unsigned char prefix[0x30];
    unsigned long long flags;
};
extern "C" bool fn_800280B4(const ObjectFlags_800280B4* self, unsigned long long mask) {
    if (self->flags & mask) return 1;
    return 0;
}

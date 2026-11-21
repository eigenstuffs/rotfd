// Test the inherited 64-bit flag field against a caller-supplied mask.
// Text-only split; class names and surrounding data remain provisional.
struct ObjectFlags_800280B4 {
    unsigned char prefix[0x30];
    unsigned long long flags;
};
extern "C" bool fn_800280B4(const ObjectFlags_800280B4* self, unsigned long long mask) {
    if (self->flags & mask) return 1;
    return 0;
}

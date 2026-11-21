// Native virtual-only callback descriptors used by registration/dispatch helpers.
struct NativeCallbackMemberRecord {
    long thisAdjustment;
    unsigned long virtualSlot;
    unsigned long vtableOffset;
};
typedef char NativeCallbackMemberRecord_size_is_12[sizeof(NativeCallbackMemberRecord) == 12 ? 1 : -1];
extern "C" NativeCallbackMemberRecord lbl_802B3DA0[8] = {
    { 0x0, 0x78, 0x8 },
    { 0x0, 0x7C, 0x8 },
    { 0x0, 0x80, 0x8 },
    { 0x0, 0x80, 0x8 },
    { 0x0, 0x80, 0x8 },
    { 0x0, 0x80, 0x8 },
    { 0x0, 0x80, 0x8 },
    { 0x0, 0x80, 0x8 },
};

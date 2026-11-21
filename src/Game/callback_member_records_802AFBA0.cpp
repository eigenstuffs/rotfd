// Native virtual-only callback descriptors used by registration/dispatch helpers.
struct NativeCallbackMemberRecord {
    long thisAdjustment;
    unsigned long virtualSlot;
    unsigned long vtableOffset;
};
typedef char NativeCallbackMemberRecord_size_is_12[sizeof(NativeCallbackMemberRecord) == 12 ? 1 : -1];
extern "C" NativeCallbackMemberRecord lbl_802AFBA0 = { 0x0, 0x98, 0x8 };
extern "C" NativeCallbackMemberRecord lbl_802AFBAC = { 0x0, 0x9C, 0x8 };

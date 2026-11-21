// Native member-pointer records: one registration record and five dispatch records.
struct NativeCallbackMemberRecord {
    long thisAdjustment;
    unsigned long virtualSlot;
    unsigned long vtableOffset;
};
typedef char NativeCallbackMemberRecord_size_is_12[sizeof(NativeCallbackMemberRecord) == 12 ? 1 : -1];
extern "C" NativeCallbackMemberRecord lbl_802C8A78[6] = {
    { 0, 0x7C, 8 },
    { 0, 0x7C, 8 },
    { 0, 0x7C, 8 },
    { 0, 0x7C, 8 },
    { 0, 0x7C, 8 },
    { 0, 0x7C, 8 },
};

// The original eight 12-byte virtual member-function pointer records.
typedef unsigned long u32;

struct MemberPointer {
    u32 delta;
    u32 virtualSlot;
    u32 tableOffset;
};

extern "C" __declspec(section ".data") const MemberPointer lbl_802C1590[8] = {
    {0, 0x7C, 8}, {0, 0x80, 8}, {0, 0x84, 8}, {0, 0x84, 8},
    {0, 0x84, 8}, {0, 0x84, 8}, {0, 0x84, 8}, {0, 0x84, 8},
};

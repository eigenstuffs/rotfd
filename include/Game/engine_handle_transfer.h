#ifndef GAME_ENGINE_HANDLE_TRANSFER_H
#define GAME_ENGINE_HANDLE_TRANSFER_H

struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct TransferEntry {
    void *object;
    unsigned long key;
    int unknown08;
    signed char tag;
    char unknown0D[3];
};
struct TransferManager { int count, capacity; TransferEntry *entries; };
struct TransferContext { char unknown00[0x118]; TransferManager *manager; };
extern "C" {
extern TransferContext lbl_801E9D24;
void fn_801F86C8(TransferManager *, const Handle_801F7F10 *, short);
void fn_8023297C(void *, const Handle_801F7F10 &, void *, unsigned char);
}
struct TransferZeroHandle : Handle_801F7F10 {
    TransferZeroHandle() { value = 0; }
};
struct TransferTwiceZeroHandle : TransferZeroHandle {
    TransferTwiceZeroHandle() { value = 0; }
};
struct TransferOwnerHandle : TransferTwiceZeroHandle {
    TransferOwnerHandle(const Handle_801F7F10 &handle) {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};
struct TransferTempHandle : TransferZeroHandle {
    TransferTempHandle(const Handle_801F7F10 &handle) {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};
struct TransferHandle : TransferZeroHandle {
    TransferHandle(const TransferTempHandle &handle) {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};
struct TransferOwner {
    char unknown00[12];
    Handle_801F7F10 handle;
    char unknown10[0x5E - 0x10];
    unsigned char flag;
};

extern "C" void fn_80230A34(TransferOwner *, const Handle_801F7F10 *, void *);

#endif

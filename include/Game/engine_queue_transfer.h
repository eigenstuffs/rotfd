#ifndef GAME_ENGINE_QUEUE_TRANSFER_H
#define GAME_ENGINE_QUEUE_TRANSFER_H

struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct QueueTransferEntry {
    void *object;
    unsigned long key;
    int unknown08;
    signed char tag;
    char unknown0D[3];
};
struct QueueTransferManager { int count, capacity; QueueTransferEntry *entries; };
struct QueueTransferContext { char unknown00[0x118]; QueueTransferManager *manager; };
extern "C" {
extern QueueTransferContext lbl_801E9D24;
void fn_801F86C8(QueueTransferManager *, const Handle_801F7F10 *, short);
void fn_8023297C(void *, const Handle_801F7F10 &, int, unsigned char);
}
struct QueueTransferZeroHandle : Handle_801F7F10 {
    QueueTransferZeroHandle() { value = 0; }
};
struct QueueTransferTwiceZeroHandle : QueueTransferZeroHandle {
    QueueTransferTwiceZeroHandle() { value = 0; }
};
struct QueueTransferOwnerHandle : QueueTransferTwiceZeroHandle {
    QueueTransferOwnerHandle(const Handle_801F7F10 &handle) {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};
struct QueueTransferTempHandle : QueueTransferZeroHandle {
    QueueTransferTempHandle(const Handle_801F7F10 &handle) {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};
struct QueueTransferHandle : QueueTransferZeroHandle {
    QueueTransferHandle(const QueueTransferTempHandle &handle) {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};
struct QueueTransferOwner {
    char unknown00[12];
    Handle_801F7F10 handle;
    char unknown10[0x5E - 0x10];
    unsigned char flag;
};

extern "C" void fn_802316F8(QueueTransferOwner *, const Handle_801F7F10 *, int);

#endif

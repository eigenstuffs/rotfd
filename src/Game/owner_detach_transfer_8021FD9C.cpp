// Bounded owner transfer; all manager storage and native Handle providers remain external.
typedef unsigned long TransferWord;
struct Handle_801F7F10 {
    union {
        TransferWord value;
        struct { signed int generation : 8, index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct DetachTransferObject {
    char unknown00[0x120];
    TransferWord flags;
};
struct DetachTransferEntry {
    DetachTransferObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getTag() const { return generation; }
};
struct DetachTransferManager {
    char unknown00[8];
    DetachTransferEntry* entries;
};
struct DetachTransferContext {
    char unknown00[0x118];
    DetachTransferManager* manager;
};
extern "C" {
extern DetachTransferContext lbl_801E9D24;
void fn_801F86C8(DetachTransferManager*, const Handle_801F7F10*, short);
void fn_80240120(void*, int);
void fn_802408BC(void*, const void*, int);
void fn_8023DE28(void*);
}
inline DetachTransferObject* resolveDetachTransfer(const Handle_801F7F10& handle) {
    int index = handle.bits.index;
    DetachTransferManager* manager = lbl_801E9D24.manager;
    int tag = manager->entries[index].getTag();
    return tag == handle.bits.generation ? manager->entries[index].object : 0;
}
struct DetachTransferZero_8021FD9C : Handle_801F7F10 {
    DetachTransferZero_8021FD9C() { value = 0; }
};
struct DetachTransferHandle_8021FD9C : DetachTransferZero_8021FD9C {
    DetachTransferHandle_8021FD9C(const Handle_801F7F10& input) {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
};
extern "C" void fn_8021FD9C(void*, const Handle_801F7F10* handle,
                           void* owner, signed char remove) {
    DetachTransferObject* object = resolveDetachTransfer(*handle);
    if (!(object->flags & 0x20000)) {
        fn_80240120(object, 0);
        {
            DetachTransferHandle_8021FD9C retained(*handle);
            fn_802408BC(owner, &retained, 1);
        }
        if (remove) fn_8023DE28(object);
    }
}

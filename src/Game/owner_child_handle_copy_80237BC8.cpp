/* Retained child-handle return; observed eight-entry owner array. */
typedef unsigned long ChildCopyWord;

struct Handle_801F7F10 {
    ChildCopyWord value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
extern "C" {
extern struct {
    char unknown00[0x118];
    void* manager;
} lbl_801E9D24;
void fn_801F86C8(void*, const Handle_801F7F10*, short);
}

struct ChildResetHandle1 : Handle_801F7F10 {
    ChildResetHandle1() { value = 0; }
};
struct ChildResetHandle2 : ChildResetHandle1 {
    ChildResetHandle2() { value = 0; }
};
struct ChildResetHandle3 : ChildResetHandle2 {
    ChildResetHandle3() { value = 0; }
};
struct ChildResetHandle4 : ChildResetHandle3 {
    ChildResetHandle4(const ChildResetHandle4& handle) {
        value = 0;
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};
struct ChildCopyOwner {
    char unknown00[0xC110];
    ChildResetHandle4 handles[8];
    int count;
};
typedef char ChildCopyHandleSize[sizeof(ChildResetHandle4) == 4 ? 1 : -1];
typedef char ChildCopyOwnerSize[sizeof(ChildCopyOwner) == 0xC134 ? 1 : -1];

static inline const ChildResetHandle4* childHandles(const ChildCopyOwner* self)
{
    return self->handles;
}

extern "C" ChildResetHandle4 fn_80237BC8(const ChildCopyOwner* self, int index)
{
    return ChildResetHandle4(childHandles(self)[index]);
}

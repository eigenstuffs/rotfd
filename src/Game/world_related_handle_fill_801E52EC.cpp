// Fill valid mapped handles for the model linked by a world entity.
#include "objects_owner_internal.h"

struct FillHandle2 : OwnerHandle {
    FillHandle2() { value = 0; }
    ~FillHandle2() {}
};
struct FillHandle3 : FillHandle2 {
    FillHandle3() { value = 0; }
    ~FillHandle3() {}
};
struct FillCopy2 : FillHandle2 {
    FillCopy2(const OwnerHandle& other) {
        value = other.value;
        fn_801F86C8(lbl_801E9D24.manager, &other, 1);
    }
    ~FillCopy2() {}
};
struct FillCopy3 : FillHandle3 {
    FillCopy3(const OwnerHandle& other) {
        value = other.value;
        fn_801F86C8(lbl_801E9D24.manager, &other, 1);
    }
    ~FillCopy3() {}
};
struct FillEntity : Activable_Z {
    OwnerHandle handle1C, handle20;
    const OwnerHandle& first() { return handle1C; }
    const OwnerHandle& second() { return handle20; }
};
struct FillGroup : Activable_Z {
    char unknown1C[0x50];
    unsigned short kind;
    char unknown6E[0x5A];
    OwnerHandle* links;
};
struct FillSkeleton : Activable_Z {
    char unknown1C[4];
    int count, capacity;
    OwnerHandle* entries;
    char unknown2C[0x5C];
    OwnerHandle* mapped;
    const OwnerHandle& at(int index) { return mapped[index]; }
};
// This pointer view borrows the resolved group without retaining its handle.
struct BorrowedFillGroup {
    FillGroup* value;
    BorrowedFillGroup(FillGroup* group) : value(group) {}
    FillGroup* operator->() const { return value; }
};
extern "C" int fn_8024A800(FillSkeleton*, int);

extern "C" void fn_801E52EC(OwnerHandle* output, const OwnerHandle* handle) {
    OwnerHandle* dest;
    FillEntity* entity = static_cast<FillEntity*>(handle->get());
    if (entity && fn_801F7EB8(&entity->handle1C) &&
        static_cast<FillGroup*>(entity->handle1C.get())->kind == 5) {
        BorrowedFillGroup group(
            static_cast<FillGroup*>(FillCopy2(entity->first()).get()));
        (void)FillCopy2(entity->second());
        FillSkeleton* mapped = static_cast<FillSkeleton*>(group->links[0].get());
        FillSkeleton* skeleton = static_cast<FillSkeleton*>(group->links[0].get());
        dest = output;
        for (int i = 0; i < skeleton->count; ++i) {
            if (fn_801F7EB8(&skeleton->entries[i])) {
                int index = fn_8024A800(skeleton, i);
                if (index >= 0) *dest = FillCopy3(mapped->at(index));
                ++dest;
            }
        }
    }
}

typedef char CheckFillHandle[sizeof(OwnerHandle) == 4 ? 1 : -1];
typedef char CheckFillEntity[sizeof(FillEntity) == 0x24 ? 1 : -1];
typedef char CheckFillGroup[sizeof(FillGroup) == 0xCC ? 1 : -1];
typedef char CheckFillSkeleton[sizeof(FillSkeleton) == 0x8C ? 1 : -1];
typedef char CheckBorrowedFillGroup[sizeof(BorrowedFillGroup) == 4 ? 1 : -1];

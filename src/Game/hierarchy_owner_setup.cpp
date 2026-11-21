// Reconstructed from the original GSQE78 instructions.
#include "hierarchy_lifecycle_internal.h"
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
extern "C" {
void fn_801F86C8(Manager*, const void*, short);
char* strcpy(char*, const char*);
}
struct HierarchyCopyHandle : Handle_801F7F10 {
    HierarchyCopyHandle(const Handle& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct HierarchyRelatedOwner {
    char unknown00[0x28];
    Handle owner;
    void setOwner(const Handle_801F7F10& source) {
        fn_801F86C8(lbl_801E9D24.manager, &owner, -1);
        owner.value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
extern "C" void fn_80203890(Hierarchy_80200478* self, const Handle& owner, const char* name) {
    fn_801F86C8(lbl_801E9D24.manager, &self->owner, -1);
    self->owner.value = owner.value;
    fn_801F86C8(lbl_801E9D24.manager, &owner, 1);
    strcpy(self->name, name);
    HierarchyCopyHandle identity(self->getIdentity());
    ((HierarchyRelatedOwner*)resolve(self->related))->setOwner(identity);
}

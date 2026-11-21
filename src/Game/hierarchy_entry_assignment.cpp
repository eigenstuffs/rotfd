#include "group_runtime_internal.h"
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
extern "C" void fn_801F86C8(Manager*, const void*, short);
struct ZeroHandle : Handle_801F7F10 { ZeroHandle() { value = 0; } };
struct OwnedHandle : ZeroHandle {
    OwnedHandle(const Handle& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct GameEntry {
    char unused[0x14]; Handle target; char unused18[0x34];
    void setTarget(const Handle& source) {
        fn_801F86C8(lbl_801E9D24.manager, &target, -1);
        target.value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct AssignmentHolder {
    char unknown00[0x0C];
    Handle owner;
    char unknown10[0x80];
    HandleList primary;
    char unknown9C[0x18];
    HandleList assigned;
    char unknownC0[0x24];
    int offset;
};
inline GameEntry& gameEntry(int index) { return ((GameEntry*)lbl_801E9D24.game)[index]; }
extern "C" void fn_8003125C(Game*, int, OwnedHandle);
extern "C" void fn_80201F94(AssignmentHolder* self, int index) {
    int relative = index - self->offset;
    gameEntry(index).setTarget(self->assigned.data[relative]);
    fn_8003125C(lbl_801E9D24.game, index, OwnedHandle(self->owner));
    resolve(self->primary.data[relative])->slot11();
}

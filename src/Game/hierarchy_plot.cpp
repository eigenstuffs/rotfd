// Reconstructed hierarchy plot lookup and command dispatch from original instructions.
#include "group_runtime_internal.h"
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
struct PlotFoundHandle : Handle_801F7F10 {};
struct NameHash { u32 value; NameHash(const char*); };
extern "C" {
u32 fn_801F948C(void*, const char*);
void fn_801F86C8(Manager*, const void*, short);
PlotFoundHandle fn_8026A494(Object*, const NameHash&);
extern const char lbl_8037A8F0[5], lbl_8037A8F8[5];
extern const char lbl_802AD910[];
int sprintf(char*, const char*, ...);
}
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
struct PlotZeroHandle : Handle_801F7F10 { PlotZeroHandle() { value = 0; } };
struct PlotOwnedHandle : PlotZeroHandle {
    PlotOwnedHandle(const Handle_801F7F10& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct PlotObject : Object {
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void command(const PlotOwnedHandle&, const PlotOwnedHandle&, Handle*);
};
struct HierarchyPlot {
    char unknown00[0x0C];
    Handle owner;
    char unknown10[0x8C];
    HandleList assigned;
};
struct PlotSetupKey:Handle {PlotSetupKey(const Handle&h){value=h.value;}};
extern "C" int fn_80200EEC(HierarchyPlot*, int, const Handle&, int);
extern "C" signed char fn_802017D8(HierarchyPlot* self, int index, Handle source, int mode) {
    signed char initialized = fn_80200EEC(self, index, PlotSetupKey(source), mode);
    if (!initialized)
        return 0;
    char name[64];
    sprintf(name, lbl_8037A8F0, lbl_8037A8F8, index);
    Object* owner = resolve(self->owner);
    PlotOwnedHandle plot(fn_8026A494(owner, NameHash(name)));
    owner = resolve(self->owner);
    PlotOwnedHandle base(fn_8026A494(owner, NameHash(lbl_802AD910)));
    ((PlotObject*)resolve(self->assigned.data[index - 1]))->command(plot, base, &self->owner);
    return 1;
}

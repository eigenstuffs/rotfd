#include "Game/engine_record_dispatch.h"

extern "C" void fn_802352CC(EngineDispatchLargeOwner* self, float value)
{
    signed char active = 0;
    for (int i = 0; i < 4; i++) {
        if (self->states[i].active) {
            fn_8023475C(self, i, value);
            active = 1;
        }
    }
    if (active && (!self->flag18 || !fn_801F7EB8(&self->target0))) {
        fn_8024C338(engineDispatchResolve(self->first));
        fn_8023D400(engineDispatchResolve(self->second), 16);
    }
}

extern "C" signed char fn_80235404(EngineDispatchLargeOwner* self)
{
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    if (fn_801F7EB8(&self->target0))
        engineDispatchResolve(self->target0)->slot1C();
    if (fn_801F7EB8(&self->target1))
        engineDispatchResolve(self->target1)->slot1C();
    return 1;
}

extern "C" void fn_80235514(EngineDispatchLargeOwner* self)
{
    for (int i = 0; i < 4; i++) {
        self->states[i].age = lbl_8037B1E0;
        self->states[i].flags = i ? 0x400 : 0;
        self->states[i].flags |= 0x200;
        self->states[i].active = 0;
        self->states[i].weight = lbl_8037B1E8;
    }
    if (fn_801F7EB8(&self->first))
        fn_8024C5D4(engineDispatchResolve(self->first));
    if (fn_801F7EB8(&self->target0))
        engineDispatchResolve(self->target0)->slot34();
}

extern "C" void fn_802356CC(EngineDispatchLargeOwner* self)
{
    slot18__11Activable_ZFv(self);
    fn_80213920(self, 0);
    EngineDispatchHandle empty;
    __ct__15Handle_801F7F10Fv(&empty);
    empty.value = 0;
    fn_801F86C8(lbl_801E9D24.manager, &self->target1, -1);
    self->target1.value = empty.value;
    fn_801F86C8(lbl_801E9D24.manager, &empty, 1);
    __dt__15Handle_801F7F10Fv(&empty, 0);
    ((EngineDispatchTarget*)self)->slot34();
}

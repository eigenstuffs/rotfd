#include "Game/engine_handle_action_sweep.h"

using namespace HandleActionSweep;

extern "C" {
extern Global lbl_801E9D24;
unsigned int fn_801F7EB8(const Handle*);
int fn_80207B94(void*, int, int);
void fn_80262180(void*);
}

typedef char HandleActionOwnerSize[sizeof(Owner) == 0x290 ? 1 : -1];

extern "C" void fn_80263764(Owner* self)
{
    int i, offset;
    for (offset = 0, i = 0; i < self->first.count; offset += 4, i++) {
        if (fn_801F7EB8((Handle*)((char*)self->first.data + offset)))
            lbl_801E9D24.manager->get(
                *(Handle*)((char*)self->first.data + offset))->slot1C();
    }
    for (i = 0, offset = 0; i < self->second.count; offset += 4, i++) {
        if (fn_801F7EB8((Handle*)((char*)self->second.data + offset)))
            lbl_801E9D24.manager->get(
                *(Handle*)((char*)self->second.data + offset))->slot1C();
    }
    if (fn_801F7EB8(&self->scalar))
        lbl_801E9D24.manager->get(self->scalar)->slot1C();
    if (fn_801F7EB8(&self->h280))
        lbl_801E9D24.manager->get(self->h280)->slot1C();
    if (fn_801F7EB8(&self->h284))
        lbl_801E9D24.manager->get(self->h284)->slot1C();
    if (fn_801F7EB8(&self->h288))
        lbl_801E9D24.manager->get(self->h288)->slot1C();
    if (fn_801F7EB8(&self->h28C))
        lbl_801E9D24.manager->get(self->h28C)->slot1C();

    i = self->limit == 0 ? -1 : fn_80207B94(self->bits, 1, 0);
    while (i >= 0) {
        fn_80262180(self->records + i * 12);
        int next = i + 1;
        i = next >= self->limit ? -1 : fn_80207B94(self->bits, 1, next);
    }
}

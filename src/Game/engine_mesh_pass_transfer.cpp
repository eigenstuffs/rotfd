#include "Game/engine_mesh_pass_transfer.h"

using namespace MeshPassTransfer;

extern "C" {
extern Global lbl_801E9D24;
extern char lbl_80341360[];
void fn_802802C8(Owner*, State*, Related*, int);
void fn_800F22F4(void*, u32);
void fn_802828FC(Part*, State*, Pass*);
}

extern "C" void fn_80280174(Owner* self, State* state, Related* related)
{
    int count = self->count, offset, i;
    for (i = 0, offset = 0; i < count; offset += 4, i++) {
        PartManager* manager = lbl_801E9D24.manager;
        Part* part = manager->get(*(Handle*)((char*)self->parts + offset));
        if (part->type == 6) {
            Pass* pass = ((PassManager*)manager)->get(
                *(Handle*)((char*)related->passes + offset));
            if ((!pass || !(pass->flags & 1)) &&
                (!pass || !(pass->flags & 0x40))) {
                state->scratch = lbl_80341360;
                fn_802802C8(self, state, related, i);
                fn_800F22F4(lbl_80341360, 0xC000);
                fn_802828FC(part, state, pass);
            }
        }
    }
}

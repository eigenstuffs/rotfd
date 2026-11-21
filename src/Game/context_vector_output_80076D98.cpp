/* Original context-derived vector output; see docs/notes/game-context-vector-output.md. */
#include "Game/early_actor_record_dispatch_views.h"
struct VectorOutputOwner {
    char unknown00[0xD0];
    int mode;
    char unknownD4[8];
    float height;
};
extern "C" void fn_80076F44(const float*, float*);
extern "C" void fn_80076D98(VectorOutputOwner* self, RecordDispatchVector* output) {
    if(self->mode==3) {
        fn_80076F44((const float*)self,(float*)output);
        output->y-=self->height;
    } else {
        RecordDispatchGroup*group=resolveGroup(*resolveSystemGroup(*lbl_801E9D24.system->handle)->next);
        const RecordDispatchHandle& handle=group->actor;
        RecordDispatchActor* actor=validResolve(handle);
        const RecordDispatchVector& position=resolveActor(*actor->slot37(0))->transform->position;
        *output=RecordDispatchVector(position.x,position.y,position.z);
    }
}

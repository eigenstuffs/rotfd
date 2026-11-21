#include "record_pool_internal.h"

Record_80209EA0::~Record_80209EA0(){fn_80209F80(this);}
extern "C" void fn_80209F80(Record_80209EA0* self) {
    self->handle40=PoolHandle2();
    self->handle48=PoolHandle3();
    self->handle44=PoolHandle3();
    self->handle4c=PoolHandle3();
    self->position=game_vec3_zero;
    self->velocity=game_vec3_zero;
    self->field18=lbl_8037AA44;
    self->field24=lbl_8037AA40;
    self->field28=lbl_8037AA44;
    self->field50=0;
}

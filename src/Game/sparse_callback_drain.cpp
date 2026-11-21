#include "Game/sparse_callback_drain_internal.h"
extern "C" void fn_8026863C(View*self){
 for(int i=self->first();i>=0;i=self->next(i)){
  Record*r=&self->records[i];
  resolved(r->object->related)->callback(r->context);
  self->records.release(i);
 }
}

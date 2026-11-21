#include "Game/sparse_callback_drain_internal.h"
extern "C" const float lbl_8037B648;
struct TimedView {
 char unknown00[0xC10C];signed char active;char unknownC10D[0xC170-0xC10D];Pool records;
 int first(){if(records.limit==0)return -1;return fn_80207B94(&records.occupied,1,0);}
 int next(int i){if(i+1>=records.limit)return -1;return fn_80207B94(&records.occupied,1,i+1);}
};
extern "C" void fn_8026847C(TimedView*self,float step){
 if(self->active){
  for(int i=self->first();i>=0;i=self->next(i)){
   Record*r=&self->records[i];
   if(r->duration>lbl_8037B648){
    r->elapsed+=step;
    if(r->elapsed>r->duration){resolved(r->object->related)->callback(r->context);self->records.release(i);}
   }
  }
 }
}

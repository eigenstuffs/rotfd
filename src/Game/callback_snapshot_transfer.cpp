#include "Game/callback_snapshot_internal.h"
extern "C" void fn_8025F620(CallbackSnapshot *self,void *buffer) {
 if(buffer && self->size) memcpy(self->bytes,buffer,self->size);
}
extern "C" void fn_8025F658(CallbackSnapshot *self,void *buffer) {
 if(buffer && self->size) memcpy(buffer,self->bytes,self->size);
}
extern "C" void fn_8025F694(CallbackSnapshot *self,int size) {
 if(size) {
  self->size=size;
  self->bytes=fn_801EFA1C(lbl_801EF5C8,self->size,lbl_802AECA0,lbl_802AECB0,105,4);
 }
}

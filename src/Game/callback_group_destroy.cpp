#include "Game/callback_entry_internal.h"
extern "C" CallbackGroup *fn_8025FA84(CallbackGroup *self,int flag) {
 if(self) {
  if(self->first)fn_8025FB2C(self->first,1);
  self->first=0;
  if(self->second)fn_8025FB2C(self->second,1);
  self->second=0;
  if(self->next)fn_8025FA84(self->next,1);
  self->next=0;
  if((short)flag>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}

#include "Game/callback_entry_internal.h"
extern "C" CallbackEntry *fn_8025FB2C(CallbackEntry *self,int flag) {
 if(self) {
  if(self->next) {
   fn_8025FB2C(self->next,-1);
   fn_801EF610(lbl_801EF5C8,self->next);
   self->next=0;
  }
  if((short)flag>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}

#include "Game/platform_audio_internal.h"
extern "C" void fn_80286738(PlatformAudioOwner*self,int i){
 if(i<0)return;
 signed char done=0;
 if(self->channels[i].flags&0x200)done=!fn_8028A6C4(self->secondary,self->channels[i].field1C);
 else if(self->channels[i].voice->pb.state==0)done=1;
 if(done){
  fn_8023B720(self,i);
  self->channels[i].field04=lbl_8037B898;
  self->channels[i].field08=lbl_8037B898;
  self->channels[i].field0C=lbl_8037B89C;
  self->channels[i].field00=lbl_8037B898;
  self->channels[i].flags=0;
  self->channels[i].field1C=-1;
 }
}

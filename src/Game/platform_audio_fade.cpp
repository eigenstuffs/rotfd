#include "Game/platform_audio_update_internal.h"
extern "C" int fn_8023AF08(PlatformAudioUpdateOwner*,const OwnerHandle&,const OwnerHandle&,float);
extern "C" int fn_80287080(PlatformAudioUpdateOwner*self,const OwnerHandle&handle,const OwnerHandle&first,float duration){
 if(!fn_801F7EB8(&handle))return -1;
 int index=fn_8023AF08(self,handle,first,duration);if(index<0)return -1;
 if(duration>=lbl_8037B898){
  self->channels[index].flags|=0x400;
  self->channels[index].field14=lbl_8037B89C/duration;
  self->channels[index].field18=lbl_8037B89C;
 }else AXSetVoiceState(self->channels[index].voice,0);
 return index;
}

#include "Game/platform_audio_internal.h"
extern "C" float fn_80286288(PlatformAudioOwner*self){return self->field418;}
extern "C" float fn_80286290(PlatformAudioOwner*self){return self->field414;}
extern "C" void fn_80286298(PlatformAudioOwner*self){
 for(int i=0;i<32;++i){
  if(self->channels[i].flags&1){
   AXVPB*voice=self->channels[i].voice;
   if(voice&&voice->pb.state==1)AXSetVoiceState(voice,0);
   self->channels[i].field04=lbl_8037B898;
   self->channels[i].field08=lbl_8037B898;
   self->channels[i].field0C=lbl_8037B89C;
   self->channels[i].field00=lbl_8037B898;
   self->channels[i].flags=0;
   self->channels[i].field14=lbl_8037B898;
   self->channels[i].field18=lbl_8037B8A0;
  }
  fn_8023B720(self,i);
 }
 fn_80285730(lbl_801E9D24.item);
}

#include "Game/platform_audio_update_internal.h"
extern "C" void fn_80289828(void*,u32);
extern "C" void fn_80287554(PlatformAudioUpdateOwner*self,u32 flags){
 u32 secondary=0;
 for(int i=0;i<32;++i){
  if(self->channels[i].flags&1){
   if(self->channels[i].flags&0x200){if(flags&4)secondary|=1;else secondary&=~1UL;}
   else if(self->channels[i].flags&0x10){if(flags&2)self->channels[i].flags|=2;else self->channels[i].flags&=~2UL;}
   else{if(flags&1)self->channels[i].flags|=2;else self->channels[i].flags&=~2UL;}
  }
 }
 if(flags&8)secondary|=2;else secondary&=~2UL;
 fn_80289828(self->secondary,secondary);
}

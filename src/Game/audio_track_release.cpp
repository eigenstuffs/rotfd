#include "Game/platform_audio_update_internal.h"
extern "C" const float lbl_8037B318;
extern "C" void fn_8023B720(PlatformAudioOwner*owner,int index){
 PlatformAudioUpdateOwner*self=reinterpret_cast<PlatformAudioUpdateOwner*>(owner);
 if(index>=0){
  self->tracks[index].running=0;self->tracks[index].timer=lbl_8037B318;
  {OwnerHandle empty;empty.value=0;self->tracks[index].owner=empty;}
  {OwnerHandle empty;empty.value=0;self->tracks[index].first=empty;}
  {OwnerHandle empty;empty.value=0;self->tracks[index].second=empty;}
 }
}

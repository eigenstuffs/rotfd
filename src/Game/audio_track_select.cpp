#include "Game/platform_audio_update_internal.h"
extern "C" const float lbl_8037B318;
inline void releaseTrack(PlatformAudioUpdateOwner*self,int index){
 if(index>=0){
  self->tracks[index].running=0;self->tracks[index].timer=lbl_8037B318;
  {OwnerHandle empty;empty.value=0;self->tracks[index].owner=empty;}
  {OwnerHandle empty;empty.value=0;self->tracks[index].first=empty;}
  {OwnerHandle empty;empty.value=0;self->tracks[index].second=empty;}
 }
}
extern "C" int fn_8023B864(PlatformAudioUpdateOwner*self){
 int chosen=-1;float greatest=lbl_8037B318;
 int start=*reinterpret_cast<int*>(reinterpret_cast<char*>(self)+0x400);
 for(int i=start;i<32;++i){
  if(!self->tracks[i].running)return i;
  if(self->tracks[i].timer>greatest){greatest=self->tracks[i].timer;chosen=i;}
 }
 if(chosen>=0&&chosen<32){releaseTrack(self,chosen);return chosen;}
 releaseTrack(self,0);return 0;
}

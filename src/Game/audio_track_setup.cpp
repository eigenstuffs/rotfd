#include "Game/platform_audio_update_internal.h"
inline Activable_Z*resolve(const OwnerHandle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int actual=m->entries[index].getGeneration();int expected=h.bits.generation;if(actual==expected)return m->entries[index].object;return 0;}
inline bool sameHandle(const OwnerHandle&stored,const OwnerHandle&requested){Activable_Z*object=stored.get();return object==requested.get();}
extern "C" int fn_8023B864(PlatformAudioUpdateOwner*);
extern "C" int fn_8023B03C(PlatformAudioUpdateOwner*self,const OwnerHandle&resource,u32,const OwnerHandle&first,const OwnerHandle&second){
 if(fn_801F7EB8(&first)){
  Activable_Z*firstObject=first.get();
  if(fn_8023B508(self,firstObject,resolve(second)))return -1;
  for(int i=0;i<32;++i){
   if(self->tracks[i].running&&sameHandle(self->tracks[i].owner,resource)&&sameHandle(self->tracks[i].first,first)&&sameHandle(self->tracks[i].second,second))return i+32;
  }
 }
 int index=fn_8023B864(self);self->tracks[index].running=1;
 self->tracks[index].owner=resource;self->tracks[index].first=first;self->tracks[index].second=second;
 return index;
}

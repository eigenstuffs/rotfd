#include "Game/platform_audio_update_internal.h"
inline bool sameHandle(const OwnerHandle&stored,const OwnerHandle&requested){Activable_Z*object=stored.get();return object==requested.get();}
extern "C" int fn_8023AF08(PlatformAudioUpdateOwner*self,const OwnerHandle&resource,const OwnerHandle&first,float){
 for(int i=0;i<32;++i){
  if(self->tracks[i].running&&sameHandle(self->tracks[i].owner,resource)&&sameHandle(self->tracks[i].first,first))return i;
 }
 return -1;
}

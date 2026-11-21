#include "Game/platform_audio_stream_internal.h"
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
inline int findStreamName(AudioStreamingState*self,const char*name){for(u32 i=0;i<6;++i){if(!strncmp(self->names[i],name,16))return i;}return -1;}
extern "C" int fn_80289968(AudioStreamingState*self,const char*name){
 if(!name)return -1;
 OSLockMutex(&lbl_8035E958);
 AudioStreamRegistry*node=lbl_803780D0;
 if(node){
  if(!fn_801F4520(name,reinterpret_cast<char*>(node)+0x80)){
   lbl_803780D0=node->next;fn_801EF610(lbl_801EF5C8,node);
  }
  while(node->next){
   if(!fn_801F4520(name,reinterpret_cast<char*>(node->next)+0x80)){
    node->next=node->next->next;fn_801EF610(lbl_801EF5C8,node);
    OSUnlockMutex(&lbl_8035E958);return 0;
   }
   node=node->next;
  }
 }
 OSUnlockMutex(&lbl_8035E958);
 int index=findStreamName(self,name);
 if(index>=0){fn_8028A4F0(self,index);self->records[index].flags=0;memset(self->names[index],0,16);}
 return index;
}

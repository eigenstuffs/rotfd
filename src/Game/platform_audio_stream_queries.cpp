#include "Game/platform_audio_stream_internal.h"
extern "C" signed char fn_8028A6C4(void*owner,int index){AudioStreamingState*self=static_cast<AudioStreamingState*>(owner);return self->records[index].flags&2;}
inline int findName(AudioStreamingState*self,const char*name){for(u32 i=0;i<6;++i){if(!strncmp(self->names[i],name,16))return i;}return -1;}
extern "C" signed char fn_8028A6DC(AudioStreamingState*self,const char*name){
 if(!name)return 0;
 OSLockMutex(&lbl_8035E958);
 for(AudioStreamRegistry*node=lbl_803780D0;node;node=node->next){if(!fn_801F4520(name,reinterpret_cast<char*>(node))){OSUnlockMutex(&lbl_8035E958);return 1;}}
 OSUnlockMutex(&lbl_8035E958);
 int index=findName(self,name);
 if(index<0)return 0;
 return self->records[index].flags&2;
}
extern "C" int fn_8028A7DC(AudioStreamingState*self){
 
 if(self->opened){for(int i=0;i<6;++i){if((self->records[i].flags&2)&&(self->records[i].flags&0x80000000)){memset(self->names[i],0,16);fn_8028A4F0(self,i);}}
 DVDClose(self->fileInfo);self->opened=0;}
 return 1;
}

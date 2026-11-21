#include "Game/platform_audio_stream_lifetime_internal.h"
extern "C" {

StreamingLifetimeState*fn_8028AF48(StreamingLifetimeState*self,short deleteFlag){
 if(self){
  OSCancelThread(self->thread);fn_801EF610(lbl_801EF5C8,self->allocation670);
  if(self->allocation4AD4)fn_801EF610(lbl_801EF5C8,self->allocation4AD4);
  self->allocation4AD4=0;
  if(lbl_8035E9AC[0])DVDClose(lbl_8035E970);
  if(deleteFlag>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}
StreamingLifetimeState*fn_8028AFF0(StreamingLifetimeState*self){
 OSInitMutex(&lbl_8035E958);self->allocation4AD4=0;lbl_8035E9AC[0]=0;return self;
}
}
typedef char CheckStreamingLifetimeState[sizeof(StreamingLifetimeState)==0x4AD8?1:-1];

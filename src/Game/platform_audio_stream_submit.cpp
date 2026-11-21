#include "Game/platform_audio_stream_submit_internal.h"
extern "C" {
int fn_8028A31C(AudioStreamingState*self,const char*name,int kind,int loop,int cookie){
 if(!name)return -1;
 for(u32 i=0;i<6;++i){if(!strncmp(name,self->names[i],16))return -2;}
 StreamSubmitContext*context=reinterpret_cast<StreamSubmitGlobals*>(&lbl_801E9D24)->context;
 if(context){
  StreamSubmitOwner*owner=reinterpret_cast<StreamSubmitOwner*>(context->owner.get());
  if(owner){StreamSubmitTarget*target=reinterpret_cast<StreamSubmitTarget*>(owner->target.get());
   if(target){target->callback=fn_8028AE40;target->cookie=self;}
  }
 }
 StreamSubmitRegistry*node=static_cast<StreamSubmitRegistry*>(fn_801EFA1C(lbl_801EF5C8,0x110,lbl_802AF56C,lbl_802AF57C,0x1E0,32));
 strncpy(node->path,name,128);strncpy(node->name,name+128,128);
 node->kind=kind;node->loop=loop;node->cookie=cookie;node->next=0;
 OSLockMutex(&lbl_8035E958);
 if(lbl_803780D0){StreamSubmitRegistry*tail=reinterpret_cast<StreamSubmitRegistry*>(lbl_803780D0);while(tail->next)tail=tail->next;tail->next=node;}
 else lbl_803780D0=reinterpret_cast<AudioStreamRegistry*>(node);
 OSUnlockMutex(&lbl_8035E958);return 0;
}
}

typedef char CheckStreamSubmitRegistry[sizeof(StreamSubmitRegistry)==0x110?1:-1];

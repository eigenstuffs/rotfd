#include "Game/audio_voice_buffer_apply.h"

// Partial receiver and SDK parameter views; original external identities remain unchanged.
typedef unsigned int u32;
typedef unsigned short u16;
struct Voice;
struct VoiceBufferRecord {u32 bytes;char unknown04[0x50];u32 flags;char unknown58[4];};
struct VoiceBufferRequest {u32 code;int index;u32 bytes;u32 offset;};
struct AudioVoiceBufferOwner {
 VoiceBufferRecord records[6];char unknown228[0xF0];
 Voice*left;Voice*right;u32 address;char*staging;
 char unknown328[0x6E4];VoiceBufferRequest*requestHead;char unknownA10[8];VoiceBufferRequest*pendingRequest;
 char unknownA1C[0x40B8];void*source;
};
struct VoiceBufferGlobals {char unknown00[0x110];void*console;char unknown114[0x78];void*transfer;};
struct VoiceAddress {u16 loop,format,loopHi,loopLo,endHi,endLo,currentHi,currentLo;};
struct VoiceSrc {u16 ratioHi,ratioLo,fraction,last0,last1,last2,last3;};
extern "C" {
extern VoiceBufferGlobals lbl_801E9D24;
extern const char lbl_802AF548[];
extern const float lbl_8037B8E0;
void fn_8028531C(void*);
void fn_8028533C(void*,void*,u32,u32,u32);
void fn_80287E0C(AudioVoiceBufferOwner*,void*,void*,void*,u32);
void DCStoreRange(void*,u32);
void AXSetVoiceAddr(Voice*,const VoiceAddress*);
void AXSetVoiceType(Voice*,u32);
void AXSetVoiceSrcType(Voice*,u32);
void AXSetVoiceSrc(Voice*,const VoiceSrc*);
void AXSetVoiceSrcRatio(Voice*,float);
void fn_801FA014(void*,const char*,...);
void*memset(void*,int,u32);
void fn_80287E48(AudioVoiceBufferOwner*self,signed char secondary) {
 VoiceBufferRequest*request;
 if(secondary==1)request=self->pendingRequest;else request=self->requestHead;
 VoiceBufferRecord*record=&self->records[request->index];
 VoiceBufferGlobals*global=&lbl_801E9D24;
 fn_8028531C(global->transfer);
 if(record->flags&4) {
  if(record->flags&0x80000000)fn_80287E0C(self,self->source,self->staging,self->staging+(record->bytes>>1),record->bytes);
  else fn_80287E0C(self,(char*)self->source+0x40,self->staging,self->staging+(record->bytes>>1),record->bytes);
  DCStoreRange(self->staging,record->bytes);
  fn_8028533C(global->transfer,self->staging,self->address,record->bytes>>1,0);
  fn_8028533C(global->transfer,self->staging+(record->bytes>>1),self->address+(record->bytes>>1),record->bytes>>1,0);
  VoiceAddress address;
  address.loop=1;address.format=10;
  address.loopHi=self->address>>17;
  address.loopLo=self->address>>1;
  address.endHi=((self->address>>1)+0x3FFF)>>16;
  address.endLo=(self->address>>1)+0x3FFF;
  address.currentHi=address.loopHi;address.currentLo=address.loopLo;
  AXSetVoiceAddr(self->left,&address);
  address.loop=1;address.format=10;
  address.loopHi=((self->address>>1)+0x4000)>>16;
  address.loopLo=(self->address>>1)+0x4000;
  address.endHi=((self->address>>1)+0x7FFF)>>16;
  address.endLo=(self->address>>1)+0x7FFF;
  address.currentHi=address.loopHi;address.currentLo=address.loopLo;
  AXSetVoiceAddr(self->right,&address);
  AXSetVoiceType(self->left,1);AXSetVoiceType(self->right,1);
  VoiceSrc src;
  src.ratioHi=1;src.ratioLo=0;src.fraction=0;src.last0=0;src.last1=0;src.last2=0;src.last3=0;
  AXSetVoiceSrcType(self->left,1);AXSetVoiceSrc(self->left,&src);AXSetVoiceSrcRatio(self->left,lbl_8037B8E0);
  AXSetVoiceSrcType(self->right,1);AXSetVoiceSrc(self->right,&src);AXSetVoiceSrcRatio(self->right,lbl_8037B8E0);
  record->flags&=~4;record->flags|=8;
 }else if(record->flags&0x10) {
  fn_80287E0C(self,self->source,self->staging,self->staging+(record->bytes>>1),record->bytes>>1);
  DCStoreRange(self->staging,record->bytes);
  if(request->offset==0) {
   fn_801FA014(lbl_801E9D24.console,lbl_802AF548);
   memset(self->staging,0,0x200);
   memset(self->staging+(record->bytes>>1),0,0x200);
  }
  fn_8028533C(global->transfer,self->staging,self->address,record->bytes>>2,0);
  fn_8028533C(global->transfer,self->staging+(record->bytes>>1),self->address+(record->bytes>>1),record->bytes>>2,0);
  record->flags|=0x20;record->flags&=~0x10;
 }else if(record->flags&0x20) {
  fn_80287E0C(self,self->source,self->staging,self->staging+(record->bytes>>1),record->bytes>>1);
  DCStoreRange(self->staging,record->bytes);
  fn_8028533C(global->transfer,self->staging,self->address+(record->bytes>>2),record->bytes>>2,0);
  fn_8028533C(global->transfer,self->staging+(record->bytes>>1),self->address+((record->bytes*3)>>2),record->bytes>>2,0);
  record->flags|=0x10;record->flags&=~0x20;
 }
}
}

typedef char VoiceBufferFlagsOffset[((unsigned int)&((VoiceBufferRecord*)0)->flags==0x54)?1:-1];
typedef char VoiceBufferRecordSize[(sizeof(VoiceBufferRecord)==0x5C)?1:-1];
typedef char VoiceBufferLeftOffset[((unsigned int)&((AudioVoiceBufferOwner*)0)->left==0x318)?1:-1];
typedef char VoiceBufferStagingOffset[((unsigned int)&((AudioVoiceBufferOwner*)0)->staging==0x324)?1:-1];
typedef char VoiceBufferPrimaryOffset[((unsigned int)&((AudioVoiceBufferOwner*)0)->requestHead==0xA0C)?1:-1];
typedef char VoiceBufferSecondaryOffset[((unsigned int)&((AudioVoiceBufferOwner*)0)->pendingRequest==0xA18)?1:-1];
typedef char VoiceBufferSourceOffset[((unsigned int)&((AudioVoiceBufferOwner*)0)->source==0x4AD4)?1:-1];

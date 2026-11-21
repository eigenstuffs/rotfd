#include "Game/audio_adpcm_buffer_apply.h"

// Partial owner views with the original C calling convention.
typedef unsigned int u32;
typedef unsigned short u16;
struct Voice;
struct AdpcmBufferStream {u32 bytes;char file[0x3C];u32 begin,current,total,remaining,end,flags;int type;};
struct AdpcmBufferRequest {u32 code;int index;u32 bytes,offset,marker;};
struct Adpcm {u16 coefficients[16],gain,predictor,history0,history1;};
struct AdpcmBufferVoice {Voice*voice;u32 address,index;Adpcm adpcm;char unknown34[8];};
struct AdpcmSampleInfo {u32 rate;char unknown04[0xC];u16 coefficients[16];char unknown30[0x10];};
struct AudioAdpcmBufferOwner {
 AdpcmBufferStream records[6];AdpcmBufferVoice voices[4];char unknown318[0x6F4];
 AdpcmBufferRequest*head;char unknownA10[8];AdpcmBufferRequest*pending;char unknownA1C[0x1C];
 AdpcmSampleInfo samples[256];char unknown4A38[0x30];signed char direct;char unknown4A69[0x6B];
 unsigned char*source;u32*addresses;u16*predictors;u32 sampleIndices[4];
};
struct AdpcmBufferGlobals {char unknown00[0x18C];void*transfer;};
struct VoiceAddress {u16 loop,format,loopHi,loopLo,endHi,endLo,currentHi,currentLo;};
struct VoiceSrc {u16 ratioHi,ratioLo,fraction,last0,last1,last2,last3;};
struct AdpcmLoop {u16 predictor,history0,history1;};
extern "C" {
extern AdpcmBufferGlobals lbl_801E9D24;
extern const float lbl_8037B8E4;
void fn_8028531C(void*);
void fn_8028533C(void*,void*,u32,u32,u32);
void AXSetVoiceType(Voice*,u32);
void AXSetVoiceAddr(Voice*,const VoiceAddress*);
void AXSetVoiceAdpcmLoop(Voice*,const AdpcmLoop*);
void AXSetVoiceAdpcm(Voice*,const Adpcm*);
void AXSetVoiceSrcType(Voice*,u32);
void AXSetVoiceSrc(Voice*,const VoiceSrc*);
void AXSetVoiceSrcRatio(Voice*,float);
void*memcpy(void*,const void*,u32);
void fn_80288210(AudioAdpcmBufferOwner*self,signed char secondary) {
 AdpcmBufferRequest*request;
 if(secondary==1)request=self->pending;else request=self->head;
 AdpcmBufferStream*record=&self->records[request->index];
 AdpcmBufferVoice*voice=&self->voices[request->index];
 AdpcmBufferGlobals*global=&lbl_801E9D24;
 fn_8028531C(global->transfer);
 if(record->flags&4) {
  if(self->direct) {
   if(request->marker==~0U)fn_8028533C(global->transfer,self->source,voice->address,record->bytes,1);
  }else fn_8028533C(global->transfer,self->source+0x60,voice->address,record->bytes,1);
  unsigned char*data=self->source;
  VoiceAddress address;
  VoiceSrc src;
  if(record->flags&0x1000) {
   AXSetVoiceType(voice->voice,0);
   address.loop=(record->flags>>11)&1;
   u32 length;
   AdpcmLoop loop;
   if(record->flags&0x80000000) {
    length=record->total;
    if(request->marker!=~0U) {
     voice->address=self->addresses[self->sampleIndices[voice->index]];
     loop.predictor=self->predictors[self->sampleIndices[voice->index]];
    }else loop.predictor=self->source[0];
   }else {length=record->total-0x60;loop.predictor=self->source[0x60];}
   loop.history0=0;loop.history1=0;
   AXSetVoiceAdpcmLoop(voice->voice,&loop);
   address.format=0;
   address.loopLo=voice->address*2+2;address.loopHi=(voice->address*2+2)>>16;
   address.endHi=((voice->address+(length&~31U))*2-1)>>16;address.endLo=(voice->address+(length&~31U))*2-1;
   address.currentHi=address.loopHi;address.currentLo=address.loopLo;
  }else {
   AXSetVoiceType(voice->voice,1);
   address.loop=1;address.format=0;
   address.loopHi=(voice->address*2+2)>>16;address.loopLo=voice->address*2+2;
   address.endHi=(voice->address*2+0xFFFF)>>16;address.endLo=voice->address*2+0xFFFF;
   address.currentHi=address.loopHi;address.currentLo=address.loopLo;
  }
  AXSetVoiceAddr(voice->voice,&address);
  if(record->flags&0x80000000) {
   memcpy(&voice->adpcm,self->samples[voice->index].coefficients,32);
   if(request->marker!=~0U)voice->adpcm.predictor=self->predictors[self->sampleIndices[voice->index]];
   else voice->adpcm.predictor=self->source[0];
  }else {
   memcpy(&voice->adpcm,data+0x1C,32);
   voice->adpcm.predictor=self->source[0x60];
  }
  voice->adpcm.gain=0;voice->adpcm.history0=0;voice->adpcm.history1=0;
  AXSetVoiceAdpcm(voice->voice,&voice->adpcm);
  src.ratioHi=1;src.ratioLo=0;src.fraction=0;src.last0=0;src.last1=0;src.last2=0;src.last3=0;
  AXSetVoiceSrcType(voice->voice,1);AXSetVoiceSrc(voice->voice,&src);
  if(record->flags&0x80000000)AXSetVoiceSrcRatio(voice->voice,(float)self->samples[voice->index].rate/lbl_8037B8E4);
  else AXSetVoiceSrcRatio(voice->voice,(float)*(u32*)(data+8)/lbl_8037B8E4);
  record->flags&=~4;record->flags|=8;
 }else if(record->flags&0x10) {
  fn_8028533C(global->transfer,self->source,voice->address,record->bytes>>1,0);
  record->flags|=0x20;record->flags&=~0x10;
 }else if(record->flags&0x20) {
  fn_8028533C(global->transfer,self->source,voice->address+(record->bytes>>1),record->bytes>>1,0);
  record->flags|=0x10;record->flags&=~0x20;
 }
}
}

typedef char AdpcmStreamSize[(sizeof(AdpcmBufferStream)==0x5C)?1:-1];
typedef char AdpcmVoiceSize[(sizeof(AdpcmBufferVoice)==0x3C)?1:-1];
typedef char AdpcmSampleSize[(sizeof(AdpcmSampleInfo)==0x40)?1:-1];
typedef char AdpcmOwnervoicesOffset[((unsigned int)&((AudioAdpcmBufferOwner*)0)->voices==0x228)?1:-1];
typedef char AdpcmOwnerheadOffset[((unsigned int)&((AudioAdpcmBufferOwner*)0)->head==0xA0C)?1:-1];
typedef char AdpcmOwnerpendingOffset[((unsigned int)&((AudioAdpcmBufferOwner*)0)->pending==0xA18)?1:-1];
typedef char AdpcmOwnersamplesOffset[((unsigned int)&((AudioAdpcmBufferOwner*)0)->samples==0xA38)?1:-1];
typedef char AdpcmOwnerdirectOffset[((unsigned int)&((AudioAdpcmBufferOwner*)0)->direct==0x4A68)?1:-1];
typedef char AdpcmOwnersourceOffset[((unsigned int)&((AudioAdpcmBufferOwner*)0)->source==0x4AD4)?1:-1];
typedef char AdpcmOwneraddressesOffset[((unsigned int)&((AudioAdpcmBufferOwner*)0)->addresses==0x4AD8)?1:-1];
typedef char AdpcmOwnerpredictorsOffset[((unsigned int)&((AudioAdpcmBufferOwner*)0)->predictors==0x4ADC)?1:-1];
typedef char AdpcmOwnersampleIndicesOffset[((unsigned int)&((AudioAdpcmBufferOwner*)0)->sampleIndices==0x4AE0)?1:-1];

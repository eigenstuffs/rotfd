#include "Game/platform_audio_stream_release_internal.h"
extern "C" {
extern const char lbl_802AF640[16]="RELEASE DSP: %s";
extern const char lbl_802AF650[16]="RELEASE WAV: %s";
void fn_8028A4F0(void*owner,int index){
 StreamReleaseState*self=static_cast<StreamReleaseState*>(owner);
 StreamReleaseRecord*record=&self->records[index];
 if(!(record->flags&0x80000000)&&fn_801F4520(reinterpret_cast<const char*>(lbl_8035E9AC),self->names[index]))DVDClose(record->fileInfo);
 if(static_cast<u32>(index)<4){
  fn_801FA014(lbl_801E9D24.logger,lbl_802AF640,self->names[index]);
  char*name=self->names[index];
  memset(name,0,16);
  StreamReleaseVoice*voice=&self->voices[index];
  AXSetVoiceState(voice->voice[0],0);MIXReleaseChannel(voice->voice[0]);AXFreeVoice(voice->voice[0]);
  voice->voice[1]=0;voice->unknown34=0;voice->unknown38=0;
  record->flags|=0x40;record->flags=0;
 }else if(static_cast<u32>(index)==4){
  fn_801FA014(lbl_801E9D24.logger,lbl_802AF650,self->names[index]);
  char*name=self->names[index];
  memset(name,0,16);
  AXSetVoiceState(self->voices[4].voice[0],0);AXSetVoiceState(self->voices[4].voice[1],0);
  MIXReleaseChannel(self->voices[4].voice[0]);MIXReleaseChannel(self->voices[4].voice[1]);
  self->voices[4].unknown08=0;fn_801EF610(lbl_801EF5C8,self->voices[4].unknown0C);
  self->voices[4].unknown0C=0;self->voices[4].unknown14=0;self->voices[4].unknown18=1;
  record->flags|=0x40;record->flags=0;
 }
 record->unknown00=0;record->unknown48=0;record->unknown4C=0;record->unknown44=0;record->unknown40=0;record->unknown58=1;

}
}

typedef char CheckStreamReleaseRecord[sizeof(StreamReleaseRecord)==0x5C?1:-1];
typedef char CheckStreamReleaseVoice[sizeof(StreamReleaseVoice)==0x3C?1:-1];
typedef char CheckStreamReleaseState[sizeof(StreamReleaseState)==0x4AD4?1:-1];

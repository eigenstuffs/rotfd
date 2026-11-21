#include "Game/platform_audio_stream_internal.h"
extern "C" void fn_8028970C(void*owner){AudioStreamingState*self=static_cast<AudioStreamingState*>(owner);OSWakeupThread(&self->queue);}
extern "C" void fn_80289730(void*owner,float level){
 AudioStreamingState*self=static_cast<AudioStreamingState*>(owner);int input=(int)level;self->effectsLevel=level;
 for(int i=0;i<4;++i){if((self->records[i].flags&2)&&!(self->records[i].flags&0x80))MIXSetInput(self->voices[i].voice[0],input);}
}
extern "C" void fn_802897BC(void*owner,float level){
 AudioStreamingState*self=static_cast<AudioStreamingState*>(owner);self->musicLevel=level;
 if((self->records[4].flags&2)&&!(self->records[4].flags&0x80)){int input=(int)level;MIXSetInput(self->voices[4].voice[0],input);MIXSetInput(self->voices[4].voice[1],input);}
}
extern "C" void fn_80289828(void*owner,u32 flags){
 AudioStreamingState*self=static_cast<AudioStreamingState*>(owner);
 if(self->records[4].flags&2){
  if(flags&2){MIXSetInput(self->voices[4].voice[0],-904);MIXSetInput(self->voices[4].voice[1],-904);self->records[4].flags|=0x80;}
  else{MIXSetInput(self->voices[4].voice[0],(int)self->musicLevel);MIXSetInput(self->voices[4].voice[1],(int)self->musicLevel);self->records[4].flags&=~0x80UL;}
 }
 if(flags&1){for(u32 i=0;i<4;++i){if(self->records[i].flags&2){AXSetVoiceState(self->voices[i].voice[0],0);self->records[i].flags|=0x80;}}}
 else{for(u32 i=0;i<4;++i){if(self->records[i].flags&2){AXSetVoiceState(self->voices[i].voice[0],1);self->records[i].flags&=~0x80UL;}}}
}

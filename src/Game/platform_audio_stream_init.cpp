#include "Game/platform_audio_stream_init_internal.h"
inline void resetRecord(StreamReleaseRecord&record){
 record.unknown00=0;record.unknown48=0;record.unknown4C=0;record.unknown44=0;record.unknown40=0;record.flags=0;record.unknown58=1;
}
extern "C" void fn_8028AC20(StreamInitState*self){
 self->allocation4AD4=fn_801EFA1C(lbl_801EF5C8,0x10800,lbl_802AF56C,lbl_802AF57C,0x88,32);
 resetRecord(self->records[0]);resetRecord(self->records[1]);resetRecord(self->records[2]);
 resetRecord(self->records[3]);resetRecord(self->records[4]);resetRecord(self->records[5]);
 self->voices[0].unknown34=0;self->voices[0].unknown38=0;
 self->voices[1].unknown34=0;self->voices[1].unknown38=0;
 self->voices[2].unknown34=0;self->voices[2].unknown38=0;
 self->voices[3].unknown34=0;self->voices[3].unknown38=0;
 self->music.unknown0C=0;self->music.unknown10=0;self->music.unknown14=0;self->music.unknown18=0;
 self->music.voice[0]=AXAcquireVoice(31,0,0);self->music.voice[1]=AXAcquireVoice(31,0,0);
 self->music.unknown1C=0;self->unknownA04=0;self->unknownA08=0;self->musicLevel=lbl_8037B8F8;
 self->unknown4A64=0;self->opened=0;self->unknownA20=0;self->unknownA24=0x1104;
 self->countA14=0;self->headA0C=0;self->tailA10=0;self->currentA18=0;self->unknownA1C=0;
 memset(self->names,0,96);
 self->stack=static_cast<char*>(fn_801EFA1C(lbl_801EF5C8,0x4000,lbl_802AF56C,lbl_802AF57C,0xC2,4));
 OSInitThreadQueue(&self->queue);
 if(OSCreateThread(self->thread,fn_80288D00,self,self->stack+0x4000,0x4000,0,1))OSResumeThread(self->thread);
}

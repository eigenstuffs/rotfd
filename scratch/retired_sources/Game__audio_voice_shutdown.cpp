/* Audio voice shutdown; see docs/notes/game-audio-voice-shutdown.md. */
struct AudioChannel{char unknown00[0x24];void*voice;};struct AudioOwner{char unknown00[0x410];AudioChannel*channels;};struct AudioContext{char unknown00[0x110];void*logger;};
extern "C"{void AXSetVoiceState(void*,unsigned short);void MIXReleaseChannel(void*);void AXFreeVoice(void*);void AXQuit();void fn_8023BAF8(void*);void fn_801FA014(void*,const char*,...);extern AudioContext lbl_801E9D24;extern const char lbl_802AF49C[];}
extern "C" void fn_80287718(AudioOwner*self){for(int i=0;i<32;++i){AXSetVoiceState(self->channels[i].voice,0);MIXReleaseChannel(self->channels[i].voice);AXFreeVoice(self->channels[i].voice);self->channels[i].voice=0;}AXQuit();fn_8023BAF8(self);fn_801FA014(lbl_801E9D24.logger,lbl_802AF49C);}

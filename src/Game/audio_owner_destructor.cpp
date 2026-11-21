/* Audio owner destructor; see docs/notes/game-audio-owner-destructor.md. */
extern "C" {extern char lbl_802F1550[],lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_8028AF48(void*,short);void fn_8020B7DC(void*,int);}
struct AudioOwner_80287A48{char unknown00[0x7C];void*table;char unknown80[0x390];void*channels;char unknown414[0xC];char stream420[1];~AudioOwner_80287A48();static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}};
AudioOwner_80287A48::~AudioOwner_80287A48(){table=lbl_802F1550;if(channels)fn_801EF610(lbl_801EF5C8,channels);channels=0;fn_8028AF48(stream420,-1);fn_8020B7DC(this,0);}

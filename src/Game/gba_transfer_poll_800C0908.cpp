typedef unsigned long Word;
struct TransferRecord { int state; char gap04[8]; int timeout; Word readBuffer; Word gap14; Word writeBuffer; signed char channel; unsigned char status; unsigned char gap1E; unsigned char received; };
struct Context { char gap00[0x110]; void* logger; };
extern "C" { extern Context lbl_801E9D24; extern const char lbl_802A17D8[]; int GBAGetStatus(int, unsigned char*); int GBAWrite(int, const void*, unsigned char*); int GBARead(int, void*, unsigned char*); void fn_801FA014(void*,const char*,...); }
extern "C" signed char fn_800C0908(TransferRecord* self) {
 const char* pool=lbl_802A17D8;
 switch(self->state) {
 case 6: self->state=7; self->timeout=60;
 case 7:
  if(GBAGetStatus(self->channel,&self->status)!=0 || (self->status&0x30)!=0x30) { fn_801FA014(lbl_801E9D24.logger,pool+0xC); return 0; }
  if(self->status&2) break;
  if(GBAWrite(self->channel,&self->writeBuffer,&self->status)!=0 || (self->status&0x30)!=0x30) { fn_801FA014(lbl_801E9D24.logger,pool+0x24); return 0; }
  self->state=8; self->timeout=60;
 case 8:
  self->received=0;
  if(GBAGetStatus(self->channel,&self->status)!=0 || (self->status&0x30)!=0x30) { fn_801FA014(lbl_801E9D24.logger,pool+0x38); return 0; }
  if(self->status!=0x38) break;
  if(GBARead(self->channel,&self->readBuffer,&self->status)!=0 || (self->status&0x30)!=0x30) { fn_801FA014(lbl_801E9D24.logger,pool+0x50); return 0; }
  self->received=1; self->state=6; return 1;
 default: return 0;
 }
 if(self->timeout==0) { fn_801FA014(lbl_801E9D24.logger,pool+0x64,self->state); return 0; }
 --self->timeout; return 1;
}

/* Original record resource lifecycle; see docs/notes/game-engine-record-operations.md. */
typedef unsigned long u32;
struct ServicePrefix{char opaque00[0x30];};
struct Service:ServicePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual int slot20(const char*,void*,unsigned long);virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual int slot40();virtual int slot44();virtual void slot48(int*);virtual int slot4C(const char*);virtual int slot50();virtual int slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual signed char slot64(int);};
struct Entry{u32 opaque00;const char*name;int second,first;};struct Resource{char opaque00[0xEC];Entry*tableEC;};struct Context{char opaque00[0x15058];Resource*resource15058;};
extern "C"{extern struct{char opaque00[0x110];void*logger110;char opaque114[0x10];Context*context124;char opaque128[0x40];Service*service168;}lbl_801E9D24;extern const char lbl_80379844[7],lbl_8037984C[7],lbl_802AB2B0[],lbl_802AB2C8[],lbl_802AB2E0[];void fn_801FA014(void*,const char*,...);void fn_8007D6A0(void*,int);}
struct Record{int first,second;char opaque08[0x3B5C-8];};
struct View{char opaque00[0x60];char name60[32];char opaque80[0xCF-0x80];signed char flagsCF[4];char opaqueD3;Record recordsD4[3];Service*serviceB2E8;char*objectB2EC;u32 bytesB2F0;int statusB2F4,indexB2F8;const char**namesB2FC;signed char flagsB300[9];};
extern "C"{const char*fn_800E8828(View*,int,int);int fn_800E8AEC(View*);signed char fn_800E8BD4(View*);}
typedef char RecordStrideCheck[(sizeof(Record)==0x3B5C)?1:-1];
extern "C" bool fn_800E8B70(View*self){self->statusB2F4=self->serviceB2E8->slot20(self->name60,(char*)self+0xC8,self->bytesB2F0);return !(self->statusB2F4==19);}

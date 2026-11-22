typedef unsigned long u32;
struct ServicePrefix{char opaque00[0x30];};
struct Service:ServicePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual int slot1C(const char*,void*,unsigned long);virtual int slot20(const char*,void*,unsigned long);virtual int slot24(const char*);virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual int slot40();virtual int slot44();virtual void slot48(int*);virtual int slot4C(const char*);virtual int slot50();virtual int slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual signed char slot64(int);};
struct View;
struct Entry{u32 opaque00;const char*name;int second,first;};struct Resource{char opaque00[0xEC];Entry*tableEC;};struct Context{char opaque00[0x15058];Resource*resource15058;View*record1505C;};
extern "C"{extern struct{char opaque00[0x110];void*logger110;char opaque114[0x10];Context*context124;char opaque128[0x40];Service*service168;}lbl_801E9D24;extern const char lbl_80379844[7],lbl_8037984C[7],lbl_802AB2B0[],lbl_802AB2C8[],lbl_802AB2E0[];void fn_801FA014(void*,const char*,...);void fn_8007D6A0(void*,int);}
struct Record{int first,second;char opaque08[0x3B5C-8];};
struct View{char opaque00[0x60];char name60[32];char opaque80[0xCF-0x80];signed char flagsCF[4];char opaqueD3;Record recordsD4[3];Service*serviceB2E8;char*objectB2EC;u32 bytesB2F0;int statusB2F4,indexB2F8;const char**namesB2FC;signed char flagsB300[9];};
extern "C"{const char*fn_800E8828(View*,int,int);int fn_800E8AEC(View*);signed char fn_800E8BD4(View*);}
typedef char RecordStrideCheck[(sizeof(Record)==0x3B5C)?1:-1];
extern "C"{extern const char lbl_802AB250[],lbl_802AB364[];void fn_80054E1C(Resource*,Record*,int);void fn_800541F0(Resource*,Record*,int);}
inline void clearOccupancy(View*self){for(int i=0;i<3;i++)self->flagsCF[i+1]=0;}

struct Owner{char opaque00[8];char*object08;View*record0C;union{float time10;signed char flag10;};union{float time14;signed char flag14;int value14;};char opaque18[4];int state1C;};
extern "C"{extern const char lbl_8037983C[5],lbl_802AB3B8[],lbl_802AB3D4[];extern const float lbl_80379864;void fn_800E863C(View*);void fn_800E8744(View*,signed char);void fn_800E89D0(View*);signed char fn_800E8CA4(View*);signed char fn_800E8B70(View*);signed char fn_800E8BF8(View*);void fn_800E86C4(View*);void fn_800E86E4(View*);void fn_800E88EC(View*);}

extern "C" {int fn_800E8EB8(View*);int fn_800E8F78(View*);void fn_801EBE14();extern const char lbl_802AB4D0[],lbl_802AB598[];}

extern "C" void fn_800E89F4(View*);
extern "C" void fn_800ECB44(Owner*self){if(!lbl_801E9D24.service168->slot64(0))fn_8007D6A0(self->object08+0x20,6);else if(self->record0C->flagsB300[4]){fn_800E86C4(self->record0C);fn_8007D6A0(self->object08+0x20,0);fn_800E86E4(self->record0C);}else if(self->record0C->flagsB300[5]){fn_800E86C4(self->record0C);if(self->record0C->flagsB300[0])fn_801EBE14();else fn_8007D6A0(self->object08+0x20,20);}}

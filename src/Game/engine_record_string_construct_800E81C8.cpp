/* Original record/string native construction; see docs/notes/game-engine-record-string-construct.md. */
typedef unsigned long u32;
extern "C" {extern char lbl_802C9160[],lbl_801EF5C8[],lbl_802AB274[],lbl_802AB284[];extern const char *lbl_80375BA0,*lbl_80375BA8,*lbl_803778B8,*lbl_80375BA4;char*strncpy(char*,const char*,u32);void*fn_801EFA1C(void*,u32,const char*,const char*,int,int);void fn_800E863C(void*);}
struct ContainerBase_802563CC {u32 unknown00[2];void*vtable;char opaque0C[0x60-0xC];ContainerBase_802563CC();~ContainerBase_802563CC();};
struct StringFields {char name60[32],name80[32],nameA0[32],nameC0[6];char opaqueC6[2];StringFields(ContainerBase_802563CC*owner){owner->vtable=lbl_802C9160;}};
struct Object_800E6E68 {char opaque[0xB220];Object_800E6E68();~Object_800E6E68();};
struct Object_800E81C8:ContainerBase_802563CC {StringFields strings60;Object_800E6E68 recordsC8;u32 fieldB2E8,fieldB2EC,fieldB2F0,fieldB2F4,opaqueB2F8;void*storageB2FC;unsigned char flagsB300[9];char opaqueB309[7];Object_800E81C8();};
Object_800E81C8::Object_800E81C8():strings60(this){fieldB2E8=0;fieldB2EC=0;fieldB2F0=0;fieldB2F4=0;storageB2FC=0;flagsB300[0]=0;flagsB300[1]=0;flagsB300[2]=0;flagsB300[3]=0;flagsB300[4]=0;flagsB300[5]=0;flagsB300[6]=0;flagsB300[7]=0;flagsB300[8]=0;strncpy(strings60.name60,lbl_80375BA0,32);strncpy(strings60.name80,lbl_80375BA8,32);strncpy(strings60.nameC0,lbl_803778B8,6);strncpy(strings60.nameA0,lbl_80375BA4,32);storageB2FC=fn_801EFA1C(lbl_801EF5C8,12,lbl_802AB274,lbl_802AB284,79,4);fn_800E863C(this);}
typedef char ObjectSizeCheck[(sizeof(Object_800E81C8)==0xB310)?1:-1];

typedef unsigned long Word;
extern "C" {void fn_8002722C(void*);void __ct__4CFSMFv(void*);void*fn_801EFA1C(void*,int,void*,void*,int,int);extern char lbl_801EF5C8[],lbl_802B074C[],lbl_80299D28[],lbl_80299D38[];extern float game_vec3_zero[3];}
struct Objects_802EB940{Word unknown00[2];void*vtable;char unknown0C[0x318-0xC];Objects_802EB940(){fn_8002722C(this);}~Objects_802EB940();};
struct CFSM{void*secondaryTable;char unknown04[0x2C-4];CFSM(){__ct__4CFSMFv(this);}~CFSM();};
struct Object_80026BB8:Objects_802EB940,CFSM{Word*storage344;float point348[3];unsigned char byte354,byte355;Object_80026BB8();};
Object_80026BB8::Object_80026BB8(){vtable=lbl_802B074C;secondaryTable=lbl_802B074C+0x170;point348[0]=game_vec3_zero[0];point348[1]=game_vec3_zero[1];point348[2]=game_vec3_zero[2];byte354=0;byte355=0;storage344=(Word*)fn_801EFA1C(lbl_801EF5C8,12,lbl_80299D28,lbl_80299D38,17,4);for(int i=0;i<3;++i)storage344[i]=0;}

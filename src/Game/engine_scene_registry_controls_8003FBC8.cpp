/* Original scene registry and record controls; see docs/notes/game-engine-scene-registry-controls.md. */
typedef unsigned long u32;
struct Target{};
struct Record{int first,second;char opaque08[0x3B54];};
struct Backup{char opaque00[0xD4];Record recordD4;};
struct Scene{char opaque00[0x15058];Target*first15058;Backup*second1505C;};
struct RenderPrefix{char opaque00[0x7C];};
struct Renderer:RenderPrefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30(float);virtual void v34();virtual void v38(float);};
extern "C" struct Global{char opaque00[0x124];Scene*scene;char opaque128[0x30];Renderer*renderer;}lbl_801E9D24;
extern "C"{u32 fn_801EC014();signed char fn_801EC044(void*,int);void fn_80054E1C(Target*,Record*,int);void fn_80057AA0(Target*,int,int);void fn_800596BC(Target*,int,int*,int*);}
extern "C" int fn_8003FBC8(){int first=-1,second=-1;Target*a=lbl_801E9D24.scene->first15058;Backup*b=lbl_801E9D24.scene->second1505C;if(fn_801EC014()!=8&&fn_801EC044(&b->recordD4,sizeof(Record))){fn_80054E1C(lbl_801E9D24.scene->first15058,&b->recordD4,1);fn_80057AA0(a,b->recordD4.first,b->recordD4.second);}else{if(fn_801EC014()==8){float values[2];fn_801EC044(values,8);lbl_801E9D24.renderer->v30(values[0]);lbl_801E9D24.renderer->v38(values[1]);}fn_800596BC(a,0x1E,&first,&second);fn_80057AA0(lbl_801E9D24.scene->first15058,first,second);}return 1;}

/* Scene numeric argument: when the converted float argument exceeds -1, query the indexed pair from the current scene target and apply it. */
typedef unsigned long u32;
struct Arguments{char opaque00[0x8A5];signed char present8A5;char opaque8A6[0x12];float number8B8;};struct Target{};struct Scene{char opaque00[0x15058];Target*first15058;Target*first(){return first15058;}};
extern "C" struct Global{char opaque00[0x110];Arguments*args;char opaque114[0x10];Scene*scene;}lbl_801E9D24;
extern "C"{extern const float lbl_803784E8;void fn_800596BC(Target*,int,int*,int*);void fn_80057AA0(Target*,int,int);}
extern "C" int fn_8003E198(){int first=-1,second=-1;int value=-1;if(lbl_801E9D24.args->present8A5)value=(int)lbl_801E9D24.args->number8B8;if(value>lbl_803784E8){fn_800596BC(lbl_801E9D24.scene->first(),value,&first,&second);fn_80057AA0(lbl_801E9D24.scene->first(),first,second);}return 1;}

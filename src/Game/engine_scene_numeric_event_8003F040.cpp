/* Scene argument command: with exactly two arguments, forwards event 0x57 to the
 * current scene target with the optional numeric argument (default -1) as a float.
 * The int->float conversion bias is compiler-generated here; the original
 * references the shared bias at lbl_803784F0 (see DATA-MAP in the report). */
typedef unsigned long u32;
struct Arguments{char opaque00[0x860];int count860;char opaque864[4];const char*argument868;char opaque86C[0x39];signed char present8A5;char opaque8A6[0x12];float number8B8;};
struct Target{};struct Scene{char opaque00[0x15058];Target*target15058;};
extern "C" struct Global{char opaque00[0x110];Arguments*args;char opaque114[0x10];Scene*scene;}lbl_801E9D24;
extern "C"{void fn_801FA014(Arguments*,const char*,...);extern const char lbl_8029A888[];void fn_802073E8(void*,int,void*,float);}
extern "C" int fn_8003F040(){Target*t=lbl_801E9D24.scene->target15058;if(lbl_801E9D24.args->count860!=2){fn_801FA014(lbl_801E9D24.args,lbl_8029A888);return 0;}int value=-1;if(lbl_801E9D24.args->present8A5)value=(int)lbl_801E9D24.args->number8B8;fn_802073E8(t,0x57,t,(float)value);return 1;}

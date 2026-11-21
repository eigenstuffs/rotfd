/* Original scene argument Key controls; see docs/notes/game-engine-scene-argument-actions.md. */
typedef unsigned long u32;
struct Arguments{char opaque00[0x860];int count860;char opaque864[4];const char*argument868;char opaque86C[0x39];signed char present8A5;char opaque8A6[0x12];float number8B8;};
struct Record{char opaque00[0x29];signed char first29,second2A,third2B;char opaque2C[0x68];};struct Target{char opaque00[0xF0];int indexF0;char opaqueF4[0xC];int mode100;char opaque104[0x34];Record*records138;};struct Scene{char opaque00[0x15058];Target*target15058;};extern "C" struct Global{char opaque00[0x110];Arguments*args;char opaque114[0x10];Scene*scene;}lbl_801E9D24;
extern "C"{u32 fn_801F948C(void*,const char*);extern const char lbl_8029A938[],lbl_8029A944[];}
struct Key{u32 word;Key():word(0){}Key(const char*s){word=fn_801F948C(this,s);}};
extern "C" void fn_800BE0E4(Scene*,Key);
extern "C" int fn_8003F0E4(){Key key;Target*target=lbl_801E9D24.scene->target15058;if(lbl_801E9D24.args->count860>1)key=Key(lbl_801E9D24.args->argument868);Record*r=&target->records138[target->indexF0];if(r->first29&&!r->second2A&&r->third2B)key=Key(lbl_8029A938);else if(target->mode100==3)key=Key(lbl_8029A944);else if(target->mode100==4)key=Key(lbl_8029A944);fn_800BE0E4(lbl_801E9D24.scene,key);return 1;}

/* Original scene registry and record controls; see docs/notes/game-engine-scene-registry-controls.md. */
typedef unsigned long u32;
struct Arguments{char opaque00[0x860];int count860;};
struct Object{char opaque00[0xC];unsigned char flags0C;};
struct Entry{Object*object;u32 opaque04;short type08;char opaque0A[6];};
struct Manager{int count;int capacity;Entry*entries;};
extern "C" struct Global{char opaque00[0x110];Arguments*args;char opaque114[4];Manager*manager;}lbl_801E9D24;
extern "C"{int fn_801B51BC(Manager*,const char*);void fn_801FA014(Arguments*,const char*,...);extern const char lbl_80378518[6];extern const char lbl_8029A9C0[];}
extern "C" int fn_8003F9A4(){if(lbl_801E9D24.args->count860!=1)return 0;int count=lbl_801E9D24.manager->count;int type=fn_801B51BC(lbl_801E9D24.manager,lbl_80378518);fn_801FA014(lbl_801E9D24.args,lbl_8029A9C0);for(int i=0;i<count;i++){Entry*e=&lbl_801E9D24.manager->entries[i];if(e->type08==type)e->object->flags0C|=4;}return 1;}

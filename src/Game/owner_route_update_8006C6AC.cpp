typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Object;
struct Entry{Object*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Mode{char unknown00[0x60];Handle handle;};
struct Scene{char unknown00[0x15058];Mode*root;};
extern "C"struct Global{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];void*groups;}lbl_801E9D24;
extern "C"{int fn_801FF834(void*,int);int fn_80206E28(void*,int,int);void fn_800A8520(Object*,int,int);void fn_802073E8(Mode*,int,Mode*,float);}
inline Object*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
extern "C"void fn_8006C6AC(void*,unsigned char value){
 Mode*mode=lbl_801E9D24.scene->root;
 if(!(signed char)fn_80206E28(lbl_801E9D24.groups,fn_801FF834(lbl_801E9D24.groups,0),-1)){
  fn_800A8520(resolve(mode->handle),0,0);
  fn_802073E8(mode,0x57,mode,(float)value);
 }
}

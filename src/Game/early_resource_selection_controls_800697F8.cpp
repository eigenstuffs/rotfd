typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Target;struct Entry{Target*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct Record{char unknown00[8];int first8,secondC;};struct Child{Record records[30];char unknown1E0[8];int first1E8,second1EC;};struct SceneOwner{char unknown00[0xEC];Child*childEC;char unknownF0[0x120];short flag210;char unknown212[0xDE];int value2F0;};struct Scene{char unknown00[0x15058];SceneOwner*first;};struct Service{char unknown00[0x1C];Handle_801F7F10*state;};
extern "C"struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];Service*service;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);int fn_80030E9C(Target*,int,int);void fn_80031654(Target*,int,int);}
struct InitZero_697F8:Handle_801F7F10{InitZero_697F8(){word=0;}~InitZero_697F8(){}};
struct Handle_80020834:InitZero_697F8{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8003E120:Handle_80020834{Handle_8003E120(const Handle_8003E120&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8003E120(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"Handle_8003E120 fn_800BCF58(Scene*,const Handle_801F7F10&);
inline Target*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;const Entry*entries=m->entries;int tag=entries[index].getTag();return tag==h.bits.tag?entries[index].object:0;}
extern "C"signed char fn_800697F8(void*,unsigned char selection){Handle_8002B67C current(*lbl_801E9D24.service->state);Handle_8003E120 target(fn_800BCF58(lbl_801E9D24.scene,current));fn_80030E9C(resolve(target),0,0);SceneOwner*owner=lbl_801E9D24.scene->first;int second,first;if(selection==40){owner->flag210=1;second=owner->childEC->second1EC;first=owner->childEC->first1E8;}else{second=owner->childEC->records[selection].secondC;first=owner->childEC->records[selection].first8;}owner->value2F0=0;fn_80031654(resolve(target),second,first);return 1;}

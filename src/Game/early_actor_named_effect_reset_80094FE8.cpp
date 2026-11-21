typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Point{float x,y,z;};struct Prefix{char unknown00[8];};
struct Node:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void stop();virtual void v34();virtual void activate();virtual void v3C();virtual void reset(int);virtual void v44();virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();virtual void v68();virtual void v6C();virtual void v70();virtual void v74();virtual void v78();virtual void v7C();virtual void v80();virtual void v84();virtual void v88();virtual void v8C();virtual void v90();virtual void v94();virtual void v98();virtual void v9C();virtual void vA0();virtual void vA4();virtual void vA8();virtual void vAC();virtual Point position(int);char unknown0C[0x14];Handle_801F7F10 self20;char unknown24[0x14];unsigned long long flags38;char unknown40[0x18];Handle_801F7F10 related58;char unknown5C[8];Handle_801F7F10 related64;char unknown68[0x28];Word key90;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct Mode;struct Scene{char unknown00[0x15058];Mode*first;};
extern "C"struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void fn_80255D88(Node*,int,int,int,int);signed char fn_800564C0(Mode*,Word);void fn_80056490(Mode*,Word);void fn_802554F4(Node*);void fn_80254BB4(Node*,const Point&);void fn_802139D8(Node*);Word fn_8005E9A0();}
struct Returned_94FE8:Handle_801F7F10{Returned_94FE8();~Returned_94FE8(){}};
struct Name{Word word;Name(const char*);};extern "C"{Word fn_801F948C(Name*,const char*);extern const char lbl_8029DD08[],lbl_8029DD28[];Returned_94FE8 fn_80058778(Mode*,const Name&,signed char);}inline Name::Name(const char*s){word=fn_801F948C(this,s);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80027528:Handle_8001FF78{Handle_80027528(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80027528(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Monitor{char unknown00[0x140];void*active;};extern "C"{extern Monitor*lbl_803776B8;void fn_8006845C(Monitor*,Node*);}
struct Owner{char unknown00[8];Node*controller;Node*actor;};
extern "C"void fn_80094FE8(Owner*self){
 Mode*mode=lbl_801E9D24.scene->first;
 fn_80255D88(self->actor,0x20,15,0,0);
 if(fn_800564C0(mode,self->actor->key90)){
  Node*first=resolve(fn_80058778(mode,Name(lbl_8029DD08),0));
  if(first){first->activate();fn_802554F4(first);fn_80254BB4(first,self->controller->position(0));}
  Node*second=resolve(fn_80058778(mode,Name(lbl_8029DD28),0));
  if(second){second->activate();fn_802554F4(second);fn_80254BB4(second,self->controller->position(0));}
 }
 const Handle_801F7F10&source=resolve(self->actor->related58)->self20;Handle_80027528 copy(source);
 resolve(copy)->reset(-1);
 self->actor->flags38|=0x40000ULL;
 fn_802139D8(resolve(self->actor->related64));fn_802139D8(self->controller);self->actor->stop();
 fn_80056490(mode,self->actor->key90);
 if(lbl_803776B8&&fn_8005E9A0()&&lbl_803776B8->active)fn_8006845C(lbl_803776B8,self->actor);
}

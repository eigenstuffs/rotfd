typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Point{float x,y,z;Point(float a,float b,float c):x(a),y(b),z(c){}};struct Prefix{char unknown00[8];};
struct Node:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44(int);virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();virtual void v68();virtual void v6C();virtual void v70();virtual void v74();virtual void v78();virtual void v7C();virtual void v80();virtual void v84();virtual void v88();virtual void v8C();virtual void v90();virtual void v94();virtual void v98();virtual void v9C();virtual void vA0();virtual void vA4();virtual void vA8();virtual void vAC();virtual void vB0();virtual void vB4();virtual void vB8();virtual void vBC();virtual void vC0();virtual void vC4();virtual void vC8();virtual void vCC();virtual void vD0();virtual void vD4();virtual void vD8();virtual void vDC();virtual void vE0();virtual void vE4();virtual void vE8();virtual void vEC();virtual void vF0();virtual void vF4();virtual void vF8();virtual void vFC();virtual void v100();virtual void v104();virtual void v108();virtual void v10C();virtual void v110();virtual void v114();virtual void v118();virtual void v11C();virtual void v120();virtual void v124();virtual void v128();virtual void v12C();virtual void v130();virtual void v134();virtual void v138();virtual void v13C();virtual void v140();virtual void v144();virtual void v148();virtual void v14C();virtual void v150();virtual void v154();virtual void v158();virtual void v15C();virtual void v160();virtual void v164();virtual void v168();virtual void v16C();virtual void v170();virtual void v174();virtual void v178();virtual void v17C();virtual void v180();virtual void v184();virtual void v188();virtual void v18C(const Point&);Handle_801F7F10 handle0C;char unknown10[0x10];Handle_801F7F10 handle20;char unknown24[0xFC];Word flags120;char unknown124[0x2EC];float time410;unsigned char active414,disabled415;};
struct Owner:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();char unknown0C[0x2C];unsigned long long flags38;char unknown40[0x18];Handle_801F7F10 handle58;char unknown5C[0x14];Handle_801F7F10 actor70;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};
struct Controller{char unknown00[8];Handle_801F7F10*handle;};
extern "C"struct Global{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;Controller*controller;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,int);extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);Word fn_801F7EB8(const Handle_801F7F10*);void fn_801F9D68(void*,const char*,...);extern const char lbl_8029A55C[];extern const float lbl_80378420,lbl_80378454;void fn_800356DC(Owner*);void fn_8025795C(Owner*,int,int);void fn_80255D88(Owner*,int,int,int,int);const Handle_801F7F10*fn_80268080(Node*,const Handle_801F7F10&);void fn_801ED9FC(Node*,float);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80027528:Handle_8001FF78{Handle_80027528(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80027528(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"void fn_800384DC(Owner*self,float time){
 if(!resolve(self->actor70)->disabled415){
 fn_801F9D68(lbl_801E9D24.logger,lbl_8029A55C);fn_800356DC(self);
 Point point(lbl_80378420,lbl_80378454,lbl_80378420);resolve(self->actor70)->v18C(point);
 Node*actor=resolve(self->actor70);if(!actor->disabled415){self->flags38|=0x20000ULL;fn_8025795C(self,0x99,0);fn_80255D88(self,0x23,15,0,0);actor->time410=time;actor->active414=1;actor->disabled415=1;}
 const Handle_801F7F10&firstSource=resolve(self->handle58)->handle0C;Handle_80020B90 first(firstSource);
 if(fn_801F7EB8(&first)){
 if(resolve(first)->flags120&0x80)fn_801ED9FC(resolve(*fn_80268080(resolve(*lbl_801E9D24.controller->handle),first)),lbl_80378420);
 const Handle_801F7F10&secondSource=self->handle58;Handle_80020B90 second(secondSource);
 const Handle_801F7F10&thirdSource=resolve(second)->handle20;Handle_80027528 third(thirdSource);
 resolve(second)->flags120|=0x40000UL;resolve(second)->flags120&=~0x10000UL;if(fn_801F7EB8(&third))resolve(third)->v44(-1);
 }
 self->v34();
 }
}

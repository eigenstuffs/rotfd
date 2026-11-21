/* Planar/radial range toggles with attached node dispatch. The engine square root is the
   bare reciprocal of a reciprocal-square-root estimate (frsqrte into f4, then fres, no frsp),
   which no compiler built-in produces; it is written as a minimal inline asm statement in the
   vector helpers. */
typedef unsigned long Word;
extern "C" const float lbl_803788A8,lbl_803788B8;
struct Vec3{
 float x,y,z;
 float planarLength()const{
  register float sq=x*x+z*z;
  register float result=lbl_803788A8;
  if(sq!=result){
   asm{frsqrte f4,sq}
   asm{fres result,f4}
  }
  return result;
 }
 float length()const{
  register float sq=x*x+y*y+z*z;
  register float result=lbl_803788A8;
  if(sq!=result){
   asm{frsqrte f4,sq}
   asm{fres result,f4}
  }
  return result;
 }
};
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Object;
struct Entry{Object*object;char opaque4[8];signed char tag;char opaqueD[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Globals{char opaque[0x118];Manager*manager;};
extern "C" Globals lbl_801E9D24;
inline Object*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct NodePrefix{char unknown00[8];};
struct Node:NodePrefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();virtual void v68();virtual void v6C();virtual void v70();virtual void v74();virtual void attach78(Object*,int);};
struct Self{char unknown00[0x38];unsigned long long flags38;char unknown40[0x18];Handle owner58;char unknown5C[0x34];signed char active90;char unknown91[3];float enter94;float exit98;char unknown9C[4];Node*nodes[3];signed char attachedAC;};
extern "C"{void fn_80255D88(Self*,int,int,int,int);void fn_80255CBC(Self*,int,int);void fn_802554F4(Node*);void fn_80255678(Node*);}
extern "C" void fn_80070BCC(Self*self,const Vec3*v){
 if(!self->active90&&v->planarLength()>self->enter94){
  fn_80255D88(self,0x79,0xF,0,0);
  self->active90=1;
  self->flags38|=0x20000ULL;
 }else if(self->active90&&v->planarLength()<self->exit98){
  fn_80255CBC(self,0x79,0);
  self->active90=0;
  self->flags38&=~0x20000ULL;
 }
 int i;
 if(v->length()>lbl_803788B8){
  if(!self->attachedAC){
   self->attachedAC=1;
   for(i=0;i<3;i++){
    if(self->nodes[i]){
     fn_802554F4(self->nodes[i]);
     self->nodes[i]->attach78(resolve(self->owner58),0);
    }
   }
  }
 }else if(self->attachedAC){
  self->attachedAC=i=0;
  for(;i<3;i++){
   if(self->nodes[i])fn_80255678(self->nodes[i]);
  }
 }
}

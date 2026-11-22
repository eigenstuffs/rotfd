/* slot40__17CActorScriptAgentFi: CActorScriptAgent activation helper (called by
 * CMediumAgent::slot_040). Selects kind 0x86, checks the
 * related owner's parent and flag 0x800, looks up a named child, then (when
 * registered) prepares the resource handle, binds identity and actor, sets
 * mode 31, calls the base handler and copies the queried body's matrix
 * position and forward axis (rotation * (0,0,1)) into the actor.
 *
 * Pooled-literal emulation: the original wrote the forward axis with float
 * literals pooled into the shared .sdata2 labels lbl_803786FC (0.0f) and
 * lbl_803786F8 (1.0f). The x row reads the labels through
 * *(const float*)&lbl (a distinct expression from plain lbl, so it is not
 * CSE'd with the other uses), which reproduces the original FPR assignment. */
typedef unsigned long Word;typedef unsigned long long Wide;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];int generation()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Globals{char unknown00[0x118];Manager*manager;};
struct Name;
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801EF610(void*,void*);
void fn_801F86C8(Manager*,const void*,int);Word fn_801F948C(Name*,const char*);
extern __declspec(section ".sdata2") const char lbl_803786F0[];
extern const char lbl_8029BBE8[];
extern const float lbl_803786F8,lbl_803786FC;
}
struct Name{Word value;Name(const char*s){value=fn_801F948C(this,s);}};
/* Typed handle layers (each layer's default constructor clears the word). */
struct ModeZero1_63290:Handle_801F7F10{ModeZero1_63290(){word=0;}~ModeZero1_63290(){}};
struct ModeZero2_63290:ModeZero1_63290{ModeZero2_63290(){word=0;}~ModeZero2_63290(){}};
struct Handle_80021B54:ModeZero2_63290{Handle_80021B54(){word=0;}~Handle_80021B54(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025BF4:Handle_80021B54{Handle_80025BF4(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80025BF4(const Handle_80025BF4&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ResZero1_63290:Handle_801F7F10{ResZero1_63290(){word=0;}~ResZero1_63290(){}};
struct ResZero2_63290:ResZero1_63290{ResZero2_63290(){word=0;}~ResZero2_63290(){}};
struct ResZero3_63290:ResZero2_63290{ResZero3_63290(){word=0;}~ResZero3_63290(){}};
struct ResZero4_63290:ResZero3_63290{ResZero4_63290(){word=0;}~ResZero4_63290(){}};
struct Handle_80062F24:ResZero4_63290{Handle_80062F24(){word=0;}~Handle_80062F24(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80062EA0:Handle_80062F24{Handle_80062EA0(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 Handle_80062EA0&operator=(const Handle_80062EA0&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
 ~Handle_80062EA0(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}Handle_80020478(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(const Handle_80020478&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 Handle_80020834&operator=(const Handle_80020478&h){Handle_80020834 copy(h);fn_801F86C8(lbl_801E9D24.manager,this,-1);word=copy.word;fn_801F86C8(lbl_801E9D24.manager,&copy,1);return*this;}
 ~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
/* Vector/matrix views (same idioms as facing_angle_query_80058350.cpp). */
struct Vec3{float x,y,z;Vec3(){}Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}};
struct BodyMatrix{float m[16];Vec3 getPos()const{return Vec3(m[12],m[13],m[14]);}};
struct BodyRotation{Vec3 r0,r1,r2;Vec3 transform(const Vec3&v)const{Vec3 result;result.x=r0.x*v.x+r1.x*v.y+r2.x*v.z;result.y=r0.y*v.x+r1.y*v.y+r2.y*v.z;result.z=r0.z*v.x+r1.z*v.y+r2.z*v.z;return result;}};
struct Body{char unknown00[0x30];BodyRotation rotation;char unknown54[0x124-0x54];BodyMatrix*matrix;
 Vec3 getPos()const{return matrix->getPos();}
 Vec3 getForward()const{Vec3 result;
  result.x=rotation.r0.x*(*(const float*)&lbl_803786FC)+rotation.r1.x*lbl_803786FC+rotation.r2.x*(*(const float*)&lbl_803786F8);
  result.y=rotation.r0.y*lbl_803786FC+rotation.r1.y*lbl_803786FC+rotation.r2.y*lbl_803786F8;
  result.z=rotation.r0.z*lbl_803786FC+rotation.r1.z*lbl_803786FC+rotation.r2.z*lbl_803786F8;
  return result;}};
struct Prefix{char unknown00[8];};
struct Node:Prefix{
 virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();
 virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();
 virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();
 virtual void setKind(int);virtual void v6C();virtual void v70();virtual void v74();virtual void v78();virtual void v7C();virtual void v80();virtual void v84();
 virtual void v88();virtual void v8C();virtual void v90();virtual void v94();virtual void v98();virtual const Handle_801F7F10&query(int);
 char unknown0C[0x10];Handle_801F7F10 parent;char unknown20[4];Handle_80020834 binding;char unknown28[0xF8];Word flags;char unknown124[0x48];Handle_801F7F10 child;
 void setBinding(const Handle_80020478&h){binding=h;}
 char unknown170[0x1A8];char control[0x80];Vec3 position;Vec3 direction;char unknown3B0[0x22];signed char reset;
};
/* Separate handle/view types keep the first owner lookup from being commoned. */
struct ParentPrefix{char unknown00[0x1C];Handle_801F7F10 parent;};
struct ParentEntry{ParentPrefix*object;char unknown04[8];signed char tag;char unknown0D[3];int generation()const{return tag;}};
struct ParentManager{int count,capacity;ParentEntry*entries;};
struct ParentHandle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct ParentView{char unknown00[0x58];ParentHandle related;};
struct AgentPrefix{Word unknown00;Handle_801F7F10 identity;};
struct Agent:AgentPrefix{
 virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();
 virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();
 virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();
 virtual void setKind(int);
 char unknown0C[0x2C];Wide flags;char unknown40[0x18];Handle_801F7F10 related;char unknown5C[0x14];Handle_801F7F10 actor;char unknown74[0x179];signed char registered;char unknown1EE[2];int mode;Handle_80062EA0 resource;
};
inline Word resolveWord(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].generation();if(generation==h.bits.tag)return(Word)m->entries[index].object;return 0;}
inline Node*resolve(const Handle_801F7F10&h){return(Node*)resolveWord(h);}
inline Body*resolveBody(const Handle_801F7F10&h){return(Body*)resolveWord(h);}
inline ParentPrefix*resolvePrefix(const ParentHandle&h){ParentManager*m=(ParentManager*)lbl_801E9D24.manager;int index=h.bits.index;int generation=m->entries[index].generation();if(generation==h.bits.tag)return m->entries[index].object;return 0;}
extern "C" {
int fn_8024A86C(Node*,const Name&);Handle_801F7F10 fn_801B52EC(Manager*,const char*);void fn_802001D4(Node*,const Handle_80062EA0*,int);
void fn_8022F624(Node*,const Handle_80025BF4&);void fn_8002B824(Agent*,const Handle_801F7F10&);void fn_8007D6A0(void*,int);
}
extern "C" void slot40__17CActorScriptAgentFi(Agent*self,const Handle_801F7F10&other){
 self->setKind(0x86);
 int found=-1;
 if(resolve(resolvePrefix(((ParentView*)self)->related)->parent)&&(resolve(self->related)->flags&0x800)){
  const Handle_801F7F10&original=self->actor;
  Node*child=resolve(resolve(Handle_80025BF4(original))->child);
  found=fn_8024A86C(child,Name(lbl_803786F0));
 }
 if(found!=-1){
  self->registered=1;
  resolve(self->actor)->reset=0;
  self->flags|=0x800000000000ULL;
  self->flags&=~0x1000000ULL;
 }
 if(self->registered==1){
  self->resource=Handle_80062EA0(fn_801B52EC(lbl_801E9D24.manager,lbl_8029BBE8));
  fn_802001D4(resolve(other),&self->resource,4);
  {const Handle_801F7F10&identity=self->identity;resolve(self->resource)->setBinding(Handle_80020478(identity));}
  {const Handle_801F7F10&original=self->actor;Handle_80025BF4 actor((Handle_80025BF4(original)));fn_8022F624(resolve(self->resource),actor);self->mode=31;}
 }
 fn_8002B824(self,other);
 resolve(self->actor)->position=resolveBody(resolve(self->actor)->query(0))->getPos();
 resolve(self->actor)->direction=resolveBody(resolve(self->actor)->query(0))->getForward();
 fn_8007D6A0(resolve(self->actor)->control,0);
}

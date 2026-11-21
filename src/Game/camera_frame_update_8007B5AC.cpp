/* Camera per-frame update dispatcher (fn_8007B5AC), reconstructed from GSQE78.
 * Every zero is the original translation unit's pooled literal 0.0f, now the
 * shared label lbl_8037899C (referenced by many other camera units, so this
 * unit must not own a private copy). The original literal was loaded once per
 * use and the back end merged the loads, numbering the shared register after
 * the later use; plain label reads are merged by the front end into one early
 * temporary, which swaps registers. Reading one use through a pointer
 * (*(const float*)&lbl_8037899C) keeps that load distinct, as with the
 * literal: the eye offset's z component, the pending reset store, and the
 * m[0][2] term of the rotated (0, 0, lbl_80378A74) follow offset. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry{void*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct SceneRecord{char unknown00[0x14];Handle_801F7F10 handle;char unknown18[0x34];};
struct WorldHandles{char unknown00[0x60];Handle_801F7F10 first,second;};
struct World{char unknown00[0x15058];WorldHandles*handles;};
extern "C" struct Globals{char unknown00[0x110];void*logger;SceneRecord*records;Manager*manager;char unknown11C[8];World*world;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_ZeroB5AC:Handle_801F7F10{Handle_ZeroB5AC(){word=0;}~Handle_ZeroB5AC(){}};
struct Handle_80027614:Handle_ZeroB5AC{Handle_80027614(){word=0;}~Handle_80027614(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct HeldHandleB5AC:Handle_80027614{HeldHandleB5AC(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~HeldHandleB5AC(){}};
template<class T> inline T*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return (T*)m->entries[index].object;return 0;}
template<class T> inline T*copyResolve(const Handle_801F7F10&h){HeldHandleB5AC held(h);return resolve<T>(held);}
struct Vec{float x,y,z;Vec(){}Vec(float a,float b,float c):x(a),y(b),z(c){}Vec(const Vec&v):x(v.x),y(v.y),z(v.z){}Vec&operator=(const Vec&v){x=v.x;y=v.y;z=v.z;return*this;}Vec operator+(const Vec&v)const{return Vec(x+v.x,y+v.y,z+v.z);}};
struct Transform{char unknown00[0x30];Vec position;};
struct Frame{char unknown00[0x30];float m[3][3];};
struct Prefix{char unknown00[8];};
struct ViewNode{char unknown00[0x124];Vec position;};
struct SceneNode{char unknown00[0x1C];Handle_801F7F10 child;char unknown20[0x104];Transform*transform;};
struct WorldNode{char unknown00[0x3D];signed char paused;};
struct TargetNode:Prefix{
virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();
virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();
virtual void s20();virtual void s21();virtual void s22();virtual void s23();virtual void s24();virtual void s25();virtual void s26();virtual void s27();virtual void s28();virtual void s29();
virtual void s30();virtual void s31();virtual void s32();virtual void s33();virtual void s34();virtual void s35();virtual void s36();virtual const Handle_801F7F10*frame(int);virtual void s38();virtual void s39();
virtual void s40();virtual void s41();virtual void s42();virtual void s43();virtual void s44();virtual void s45();virtual void s46();virtual void s47();virtual void s48();virtual void s49();
virtual void s50();virtual void s51();virtual void s52();virtual void s53();virtual void s54();virtual void s55();virtual void s56();virtual void s57();virtual void s58();virtual void s59();
virtual void s60();virtual void s61();virtual void s62();virtual void s63();virtual void s64();virtual void s65();virtual void s66();virtual void s67();virtual void s68();virtual void s69();
virtual void s70();virtual void s71();virtual void s72();virtual void s73();virtual void s74();virtual void s75();virtual void s76();virtual void s77();virtual void s78();virtual void s79();
virtual void s80();virtual void s81();virtual void look(const Vec*);
char unknown0C[0x30C];char controls[4];};
struct Camera:Prefix{
virtual void c0();virtual void c1();virtual void c2();virtual void c3();virtual void c4();virtual void c5();virtual void c6();virtual void c7();virtual void c8();virtual void c9();
virtual void c10();virtual void reset();
char unknown0C[0x14];int viewIndex;Handle_801F7F10 target;char unknown28[0x9C];signed char followHeight;char unknownC5[0xB];int mode;float zoom;char unknownD8[4];float height;char unknownE0[0x14];
Vec current;char unknown100[0x10];float unknown110,unknown114;Vec previous;Vec viewPosition;unsigned char flag130,flag131;char unknown132[0x12];float distance;char unknown148[4];Vec anchor;Vec focus;char unknown164[0x18];
int follow;signed char shaking;char unknown181[3];float duration,amplitude,jitter;Vec followPosition;char unknown19C[0x40];signed char disabled;char unknown1DD[0xF];Handle_801F7F10 from,to;Vec fromPosition,toPosition;char unknown20C[0x10];
float speed,timer;char unknown224[2];signed char hold;char unknown227;int track;float pitch;char unknown230[8];signed char locked;char unknown239[3];float pending;};
extern "C"{
unsigned long fn_801F7EB8(const Handle_801F7F10*);signed char fn_8007D604(void*,int);void fn_80078D88(Camera*,Vec*);void fn_8007705C(Camera*);
void fn_8023D100(SceneNode*,const Vec*);float fn_801F1200();int fn_801F1224(int,int);void fn_8007B468(Camera*,float);void fn_80079094(Camera*,float);void fn_8007AF08(Camera*);
void fn_80236BF4(Camera*,float);float fn_80079C34(Camera*);void fn_801F9D68(void*,const char*,...);void fn_80076D98(Camera*,Vec*);void fn_80077A48(Camera*,float);void fn_8007A980(Camera*,float);
void fn_8007A330(Camera*,float);void fn_80077E74(Camera*,float);void fn_80077678(Camera*,float);void fn_8007682C(Camera*,float);void fn_80078194(Camera*,float);void fn_8007A864(Camera*,float);void fn_800788C4(Camera*,float);
float fn_800785E0(Camera*);void fn_8023D648(SceneNode*);void fn_8023DE28(SceneNode*);void fn_800E731C(WorldNode*);void fn_800E73B8(WorldNode*);
extern const float lbl_8037899C,lbl_803789C4,lbl_803789C8,lbl_803789CC,lbl_80378A6C,lbl_80378A70,lbl_80378A74,lbl_803789F4;extern const char lbl_8029CCFC[];}
inline SceneNode*recordNode(const SceneRecord&r){return resolve<SceneNode>(r.handle);}
inline SceneNode*recordViewNode(Camera*self){return recordNode(lbl_801E9D24.records[self->viewIndex]);}
inline SceneNode*viewNode(Camera*self){return resolve<SceneNode>(lbl_801E9D24.records[self->viewIndex].handle);}
inline float scaledJitter(float value,const float&amplitude){return value*amplitude;}
inline void updateShake(Camera*self,float delta){
 self->jitter=scaledJitter(fn_801F1200()-lbl_803789C4,self->amplitude);
 int range=lbl_803789C8*self->amplitude;
 fn_801F1224((short)-range,(short)range);
 if(self->duration>=lbl_8037899C){self->duration-=delta;if(self->duration<=lbl_8037899C){self->shaking=0;self->duration=lbl_8037899C;self->amplitude=lbl_8037899C;self->jitter=lbl_8037899C;}}
}
inline void applyView(Camera*self){
 Vec eye=self->current+Vec(lbl_8037899C,self->jitter,*(const float*)&lbl_8037899C);
 fn_8023D100(viewNode(self),&eye);
 resolve<TargetNode>(self->target)->look(&eye);
 self->previous=self->current;
}
extern "C" void fn_8007B5AC(Camera*self,float delta){
 if(self->disabled==1)return;
 if(!fn_801F7EB8(&self->target))return;
 self->zoom=lbl_8037899C;self->unknown110=lbl_8037899C;self->unknown114=lbl_8037899C;
 if(self->followHeight)fn_80078D88(self,&self->previous);
 if(!fn_8007D604(resolve<TargetNode>(self->target)->controls,6)||resolve<WorldNode>(lbl_801E9D24.world->handles->first)->paused==1){
  if(self->mode==1||self->mode==2)fn_8007705C(self);
 }
 if(self->mode==4){
  if(self->track==1){
   const Vec&a=resolve<SceneNode>(self->from)->transform->position;self->fromPosition=Vec(a.x,a.y,a.z);
   const Vec&b=resolve<SceneNode>(self->to)->transform->position;self->toPosition=Vec(b.x,b.y,b.z);
  }
  if(self->track==1||self->track==0){
   self->previous=self->fromPosition;
   self->current=self->previous;
   fn_8023D100(recordViewNode(self),&self->previous);
   self->viewPosition=self->toPosition;
   const Handle_801F7F10&input=viewNode(self)->child;copyResolve<ViewNode>(input)->position=self->viewPosition;
  }
  updateShake(self,delta);
  fn_8007B468(self,delta);
  applyView(self);
  fn_80079094(self,delta);
 }else{
  fn_8007AF08(self);
  {const Handle_801F7F10&input=recordViewNode(self)->child;copyResolve<ViewNode>(input)->position=self->followPosition;}
  if(self->follow==0){
   fn_80236BF4(self,delta);
   if(self->locked==1){
    updateShake(self,delta);
    fn_8007B468(self,delta);
   }else{
    const Vec&p=viewNode(self)->transform->position;self->current=Vec(p.x,p.y,p.z);
    self->previous=self->current;
    updateShake(self,delta);
    fn_8007B468(self,delta);
    if(self->pending>lbl_8037899C){self->pending=*(const float*)&lbl_8037899C;self->reset();}
   }
   applyView(self);
   fn_80079094(self,delta);
  }else{
   if(fn_8007D604(resolve<TargetNode>(self->target)->controls,0xD)||fn_8007D604(resolve<TargetNode>(self->target)->controls,4))self->speed=lbl_803789C4;
   else self->speed=lbl_803789CC;
   self->anchor=self->current;
   self->previous=self->current;
   if(self->timer>=lbl_80378A6C||fn_80079C34(self)>=lbl_80378A70){
    self->timer=lbl_8037899C;
    fn_801F9D68(lbl_801E9D24.logger,lbl_8029CCFC);
    Vec position;fn_80076D98(self,&position);
    position.y+=self->height;
    Frame*frame=resolve<Frame>(*resolve<TargetNode>(self->target)->frame(0));
    self->current=Vec(position.x+(frame->m[0][0]*lbl_8037899C+frame->m[1][0]*lbl_8037899C+frame->m[2][0]*lbl_80378A74),
                      position.y+(frame->m[0][1]*lbl_8037899C+frame->m[1][1]*lbl_8037899C+frame->m[2][1]*lbl_80378A74),
                      position.z+(frame->m[0][2]**(const float*)&lbl_8037899C+frame->m[1][2]*lbl_8037899C+frame->m[2][2]*lbl_80378A74));
    self->anchor=self->current;
    self->previous=self->current;
    self->flag130=0;self->flag131=0;
   }
   if(self->mode==0){self->previous=self->current;fn_80077A48(self,delta);}
   fn_80079094(self,delta);
   if(self->mode==0)fn_8007A980(self,delta);
   if(self->mode==0)fn_8007A330(self,delta);
   if(self->mode==0&&self->pitch<lbl_803789F4)fn_80077E74(self,delta);
   if(self->mode==0)fn_8007A980(self,delta);
   if(!resolve<WorldNode>(lbl_801E9D24.world->handles->first)->paused)fn_80077678(self,delta);
   fn_8007682C(self,delta);
   if(self->mode==0){
    if(lbl_8037899C!=self->zoom)fn_80078194(self,self->zoom);
    fn_8007A864(self,delta);
   }
   if(self->mode==0&&!self->hold)self->zoom=lbl_8037899C;
   fn_800788C4(self,delta);
   applyView(self);
   fn_8007B468(self,delta);
  }
 }
 self->distance=fn_800785E0(self);
 fn_80076D98(self,&self->focus);
 SceneNode*view=viewNode(self);
 fn_8023D648(view);
 fn_8023DE28(view);
 if(self->follow==1){
  if(self->mode==3)fn_800E731C(resolve<WorldNode>(lbl_801E9D24.world->handles->second));
  else fn_800E73B8(resolve<WorldNode>(lbl_801E9D24.world->handles->second));
 }else fn_800E731C(resolve<WorldNode>(lbl_801E9D24.world->handles->second));
}

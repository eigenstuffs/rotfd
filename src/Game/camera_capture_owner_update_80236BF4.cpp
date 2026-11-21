/* fn_80236BF4: camera zone capture owner update (vtable slot 0x38 of
 * lbl_802EBE80, the class of camera_bitmap_capture_80235D54.cpp). While a
 * capture is active it only forwards to the capture step (slot 0x48). Otherwise
 * it seeds the target's surface flags once, eases the target's drift/orbit
 * offsets, collides the eased orbit point (rotated by the frame yaw) against
 * the surface query, blends the camera position/direction and writes them to
 * the view node (resolved through the actor's parent handle) and the actor.
 * The pooled 0.0f/1.0f/0.5f/... are shared extern labels; the frame-yaw basis
 * product uses distinct read forms per use (pooled-literal emulation). The
 * by-value settle arguments are VecData (trivially copied with lwz/stw). */
typedef unsigned long Word;
struct Handle_801F7F10 {union {Word word;struct {signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct SceneRecord{char unknown00[0x14];Handle_801F7F10 handle;char unknown18[0x34];};
struct Context{char unknown00[0x110];void*logger;SceneRecord*records;Manager*manager;};
extern "C"{extern Context lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,short);unsigned long fn_801F7EB8(const Handle_801F7F10*);}
struct Handle_8001FF78:Handle_801F7F10 {Handle_8001FF78(){word=0;}~Handle_8001FF78(){}};
struct Handle_80020C04:Handle_8001FF78 {Handle_80020C04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020C04(){}};
struct Zero1_6BF4:Handle_801F7F10{Zero1_6BF4(){word=0;}~Zero1_6BF4(){}};struct Zero2_6BF4:Zero1_6BF4{Zero2_6BF4(){word=0;}~Zero2_6BF4(){}};struct Zero3_6BF4:Zero2_6BF4{Zero3_6BF4(){word=0;}~Zero3_6BF4(){}};struct Zero4_6BF4:Zero3_6BF4{Zero4_6BF4(){word=0;}~Zero4_6BF4(){}};
struct Handle_80075D64:Zero4_6BF4 {Handle_80075D64(){word=0;}~Handle_80075D64(){}Handle_80075D64&operator=(const Handle_80075D64&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct Handle_80027614:Zero1_6BF4 {Handle_80027614(){word=0;}~Handle_80027614(){}};
struct Copy27614_6BF4:Handle_80027614 {Copy27614_6BF4(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Copy27614_6BF4(){}};
struct Record{char opaque[0x44];};
extern "C"{void fn_8007B464(void*);void __construct_array(void*,void(*)(void*),void*,Word,Word);}
struct HandleOwner_8007B3C8{int selected;Handle_80075D64 handle;int count;int items[4];Record records[4];HandleOwner_8007B3C8(){__construct_array(records,fn_8007B464,0,sizeof(Record),4);selected=-1;handle=Handle_80075D64();}~HandleOwner_8007B3C8(){}};
extern "C"{double __fabs(double);extern const float lbl_8037B2A8,lbl_8037B2AC,lbl_8037B2B0,lbl_8037B2B4,lbl_8037B2B8,lbl_8037B2BC,lbl_8037B2C0,lbl_8037B2C4,lbl_8037B2C8,lbl_8037B2CC;}
extern "C"{float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
inline int pairEqualD(float x,float y){int result=0;double ax=__fabs(x);if((float)ax<lbl_8037B2B8){if((float)__fabs(y)<lbl_8037B2B8)result=1;}return result;}
inline int pairEqual(float x,float y){int result=0;if((float)__fabs(x)<lbl_8037B2B8){if((float)__fabs(y)<lbl_8037B2B8)result=1;}return result;}
struct VecData{float x,y,z;};
struct Vec:VecData{Vec(){}Vec(float a,float b,float c){x=a;y=b;z=c;}Vec(const Vec&v){x=v.x;y=v.y;z=v.z;}Vec&operator=(const Vec&v){x=v.x;y=v.y;z=v.z;return*this;}
 Vec operator+(const Vec&v)const{return Vec(x+v.x,y+v.y,z+v.z);}Vec operator-(const Vec&v)const{return Vec(x-v.x,y-v.y,z-v.z);}Vec operator*(float s)const{return Vec(x*s,y*s,z*s);}
 Vec&operator+=(const Vec&v){x+=v.x;y+=v.y;z+=v.z;return*this;}
 float lengthSquared()const{return x*x+y*y+z*z;}
 Vec&normalize(){float inv=reciprocalSqrt(lengthSquared());x*=inv;y*=inv;z*=inv;return*this;}
 signed char isZero()const{signed char result=0;if(pairEqualD(x,y)&&(float)__fabs(z)<lbl_8037B2B8)result=1;return result;}
/* Equality builds its difference as a temporary; the free vecEqual form keeps it in registers. */
 signed char equals(const Vec&o)const{return Vec(x-o.x,y-o.y,z-o.z).isZero();}
};
inline signed char vecEqual(float x,float y,float z){signed char result=0;if(pairEqual(x,y)&&(float)__fabs(z)<lbl_8037B2B8)result=1;return result;}
struct Rotation{float w,x,y,z;Rotation(){}};
extern "C"{Vec fn_801F1B1C(const Rotation*,const Vec*);
 void fn_8007D4B4(const Vec*start,const Vec*target,Vec*result,float base,float elapsed);extern const Vec game_vec3_zero;}
struct Matrix{float m[4][4];};
struct NodePrefix{char unknown00[8];};
struct Node:NodePrefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
 virtual const Handle_801F7F10*frame(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();
 virtual Vec offset(int);
 virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();
 virtual void slotD0();virtual void slotD4();virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual void slotE4();virtual void slotE8();virtual void slotEC();
 virtual void slotF0();virtual void slotF4();virtual void slotF8();virtual void slotFC();virtual void slot100();virtual void slot104();virtual void slot108();virtual void slot10C();
 virtual void slot110();virtual void slot114();virtual void slot118();virtual void slot11C();virtual void slot120();virtual void slot124();virtual void slot128();virtual void slot12C();
 virtual void slot130();virtual void slot134();virtual void slot138();virtual void slot13C();
 virtual Word selection();
 virtual void slot144();virtual void slot148();
 virtual void face(const Vec*);
 virtual void look(const Vec*);
 virtual void slot154();virtual void slot158();
 virtual const Handle_801F7F10*body();
 char unknown0C[0x10];Handle_801F7F10 parent;char unknown20[0x98];Vec direction;char unknownC4[0x58];float angle;char unknown120[4];Matrix*transform;
 char unknown128[0xD4];Vec orbit;Vec pivot;Vec lead;Vec drift;signed char settledHigh;signed char settledLow;
};
struct View{char unknown00[0xB8];float valueB8;char unknownBC[0x60];float angle;char unknown120[4];Vec position;};
struct Query{signed char flag;char unknown01[3];Vec point;Vec direction;float angle;float value;char unknown24[0x1C];};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*resolveParent(Node*n){const Handle_801F7F10&h=n->parent;Copy27614_6BF4 held(h);return resolve(held);}
struct Owner:NodePrefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void capture(float);virtual void finish();virtual void slot50();virtual void slot54();
 virtual Vec settle(Node*,VecData,VecData,float);
 char unknown0C[0x14];int index;Handle_801F7F10 target;Handle_801F7F10 resource;Vec position;signed char blending;char unknown39[3];float blendTime;float blendRate;Vec smoothed;Vec offset;signed char reset;signed char active;
};
extern "C"{const Handle_801F7F10*fn_80235C08(const Owner*);signed char fn_80269DE0(Node*,const Vec*,HandleOwner_8007B3C8*,Word);signed char fn_80242C34(Node*,Vec*,const Vec*,const HandleOwner_8007B3C8*,Query*);
 void fn_80242E7C(Node*,int,unsigned short);unsigned short fn_80242E98(const Node*,int);void fn_8023D648(Node*);void fn_8023DE28(Node*);}

extern "C" void fn_80236BF4(Owner*self,float dt){
 if(!fn_801F7EB8(&self->target))return;
 Node*actor=resolve(lbl_801E9D24.records[self->index].handle);
 Node*viewNode=resolveParent(actor);
 Node*world=resolve(*fn_80235C08(self));
 Handle_80020C04 frame(*resolve(self->target)->frame(0));
 if(self->active){self->capture(dt);return;}
 HandleOwner_8007B3C8 hits;
 Node*target=resolve(self->target);
 Vec position;
 if(!target->settledLow||!target->settledHigh){
  const Vec&p=*(const Vec*)&resolve(*target->body())->transform->m[3][0];
  position=Vec(p.x,p.y,p.z);
  if(fn_80269DE0(world,&position,&hits,target->selection())){
   Node*mesh=resolve(hits.handle);
   if(!target->settledLow)for(int i=0;i<hits.count;i++)fn_80242E7C(mesh,hits.items[i],0x4000);
   if(!target->settledHigh)for(int i=0;i<hits.count;i++)fn_80242E7C(mesh,hits.items[i],0x8000);
   self->blending=1;self->blendTime=lbl_8037B2A8;
  }
  target->settledLow=1;target->settledHigh=1;
 }
 position=target->offset(0)+target->pivot;
 Vec drift(target->drift);
 position+=drift;
 fn_8007D4B4(&drift,&game_vec3_zero,&drift,lbl_8037B2AC,dt);
 target->drift=drift;
 if(fn_80269DE0(world,&position,&hits,target->selection())){
  Node*mesh=resolve(hits.handle);
  Vec orbit(target->orbit);
  if(self->reset)self->smoothed=orbit;
  else{fn_8007D4B4(&self->smoothed,&orbit,&self->smoothed,lbl_8037B2AC,dt);orbit=self->smoothed;}
  const Matrix&m=*resolve(frame)->transform;
  float yaw=fn_80285124(m.m[0][0]*lbl_8037B2A8+m.m[1][0]**(const float*)&lbl_8037B2A8+m.m[2][0]*lbl_8037B2B0,m.m[0][2]**(const float*)(unsigned long)&lbl_8037B2A8+m.m[1][2]**(const float*)(int)&lbl_8037B2A8+m.m[2][2]**(const float*)&lbl_8037B2B0);
  float half=yaw*lbl_8037B2B4;
  Rotation rotation;
  {float c=fn_8028506C(half);float s=fn_80284FA8(half);rotation.w=c;rotation.x=lbl_8037B2A8*s;rotation.y=lbl_8037B2B0*s;rotation.z=lbl_8037B2A8*s;}
  Vec to=position+fn_801F1B1C(&rotation,&orbit);
  Query query;query.flag=0;
  if(!fn_80242C34(mesh,&position,&to,&hits,&query))return;
  if(query.flag&&!self->position.equals(game_vec3_zero)){
   Vec lead(target->lead);
   fn_8007D4B4(&self->offset,&lead,&self->offset,lbl_8037B2BC,dt);
   query.direction+=self->offset;
  }
  for(int i=0;i<hits.count;i++)if(fn_80242E98(mesh,hits.items[i])&0x8000)break;
  Vec facing=(query.point-query.direction).normalize();
  target->face(&facing);
  if(!query.flag||vecEqual(self->position.x-game_vec3_zero.x,self->position.y-game_vec3_zero.y,self->position.z-game_vec3_zero.z)){
   self->position=query.point;
  }else{
   if(self->blending){
    Vec direction(actor->direction);
    if(self->blendTime>=lbl_8037B2C0){self->blending=0;self->blendTime=lbl_8037B2C0;}
    float t=self->blendTime/lbl_8037B2C0;
    t*=t;
    self->blendRate=lbl_8037B2C8*t+lbl_8037B2C4;
    Vec eased;fn_8007D4B4(&direction,&query.direction,&eased,self->blendRate,dt);
    query.direction=eased;
    self->blendTime+=dt;
   }
   fn_8007D4B4(&self->position,&query.point,&self->position,lbl_8037B2CC,dt);
  }
  query.direction=self->settle(world,query.direction,self->position,dt);
  View*view=(View*)viewNode;view->position=self->position;
  view->angle=query.angle;
  view->valueB8=query.value;
  actor->direction=query.direction;
  fn_8023D648(actor);
  target->look(&query.direction);
 }
 self->reset=0;
 fn_8023DE28(actor);
}

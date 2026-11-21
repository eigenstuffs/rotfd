/* fn_80224294: place an owner on the ground below its first handle's raised
 position (initial cast, then a 10-unit down ray), face it toward the
 orientation handle (yaw quaternion) and notify the context.
 Pooled-literal emulation: the 0.0f label uses distinct read forms per use in
 the initial-cast and down-ray blocks.
 The orientation target is copied into a by-value Vec3 and self-assigned
 (target=target): the second definition stops the optimizer forwarding the
 z,y,x-ordered loads into the call arguments, so target.z is numbered first
 and the f2/f3 colouring before fn_80285124 matches. */
typedef unsigned long Word;
typedef unsigned long long Flags;
struct Vec3 {float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}};
struct Vec4:Vec3 {float w;Vec4(const Vec3&v,float f):Vec3(v),w(f){}};
struct Quat {float w,x,y,z;Quat(const Quat&q):w(q.w),x(q.x),y(q.y),z(q.z){}Quat(float a,float b,float c,float d):w(a),x(b),y(c),z(d){}Quat&operator=(const Quat&q){w=q.w;x=q.x;y=q.y;z=q.z;return *this;}};
struct Ray {Vec3 origin;float length;Vec3 direction;float unknown1C;Ray(){}};
struct Hit {Vec3 point;char unknown0C[0x28-12];Flags flags;void*object;void*other;void*extra;signed char hit;char unknown3D[3];Word end;Hit(){hit=0;object=0;other=0;extra=0;flags=0;}};
struct Actor;
struct Handle {signed int generation:8,index:24;};
struct Entry {Actor*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager {int count,capacity;Entry*entries;};
struct Context {char unknown00[0x118];Manager*manager;};
extern "C" {extern Context lbl_801E9D24;}
inline Actor*resolve(const Handle&h){int i=h.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[i].getGeneration();return generation==h.generation?m->entries[i].object:0;}
extern "C" {extern const float lbl_8037B0E0,lbl_8037B10C;}
inline Word resolveNotify(const Handle&h){int i=h.index;Manager*m=lbl_801E9D24.manager;int g=m->entries[i].getGeneration();return g==h.generation?(Word)m->entries[i].object:0;}
struct Geometry {char unknown00[0x30];Vec3 position;Vec3 getPosition()const{return Vec3(position.x,position.y,position.z);}Vec3 getRaisedPosition()const{return getPosition()+Vec3(lbl_8037B0E0,lbl_8037B10C,lbl_8037B0E0);}};
struct Actor {char unknown00[0x20];Handle owner;char unknown24[12];Handle child;char unknown34[0x120-0x34];Word flags;Geometry*geometry;signed char initialCast(const Vec3&,Hit*,const Vec4&);signed char downCast(const Vec3&,Hit*);};
struct Prefix {Word unknown00,unknown04;};
struct Owner:Prefix {
virtual void slot08();
virtual void slot0C();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1C();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3C();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5C();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6C();
virtual void slot70();
virtual void slot74();
virtual void slot78();
virtual void slot7C();
virtual void slot80();
virtual void applyHandle(const Handle&);
virtual signed char getPoint(Vec4&,int,int);
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual const Handle&getHandle(int);
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void slotBC();
virtual void setTransform(const Vec3&,const Quat&,int);
virtual void slotC4();
virtual void slotC8();
virtual void slotCC();
virtual void slotD0();
virtual void slotD4();
virtual void slotD8();
virtual void slotDC();
virtual void slotE0();
virtual void slotE4();
virtual void slotE8();
virtual void slotEC();
virtual void slotF0();
virtual void slotF4();
virtual void slotF8();
virtual void slotFC();
virtual void slot100();
virtual void slot104();
virtual void notify(Actor*,const Vec3&,const Vec3&,int,int);
void notifyHandle(const Handle&h,const Vec3&p){notify((Actor*)resolveNotify(h),p,p,0,1);}
virtual void slot10C();
virtual void slot110();
virtual void slot114();
virtual void slot118();
virtual void slot11C();
virtual void slot120();
virtual void slot124();
virtual void slot128();
virtual void slot12C();
virtual void slot130();
virtual void slot134();
virtual void slot138();
virtual void slot13C();
virtual void slot140();
virtual void slot144();
virtual void setPosition(const Vec3&);
char unknown0C[0x30-0xC];Flags flags;
};
extern "C" {Word fn_801F7EB8(const Handle*);float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);signed char fn_80268FE8(Actor*,const Vec3&,const Vec3&,Hit*,Flags,Flags,float);signed char fn_80269230(Actor*,const Ray&,Hit*,Flags,Flags);void fn_801CBDE4(Actor*,Actor*,void*,float);void fn_8023DE28(Actor*);extern const Vec3 game_vec4_zero;extern const Quat game_quat_identity;extern const float lbl_8037B0E0,lbl_8037B0E4,lbl_8037B0EC,lbl_8037B0F0,lbl_8037B108,lbl_8037B10C,lbl_8037B110;}
inline signed char Actor::initialCast(const Vec3&p,Hit*h,const Vec4&point){return fn_80268FE8(this,p,p-Vec3(*(const float*)&lbl_8037B0E0,lbl_8037B0F0,lbl_8037B0E0),h,0xFFFFEFFBFFFFFFFFULL,0,point.w);}
inline signed char Actor::downCast(const Vec3&p,Hit*h){Ray ray;ray.origin=Vec3(p.x+lbl_8037B0E0,p.y+lbl_8037B0F0,p.z+*(const float*)&lbl_8037B0E0);ray.direction=Vec3(*(const float*)(unsigned long)&lbl_8037B0E0,lbl_8037B108,*(const float*)(long)&lbl_8037B0E0);ray.length=lbl_8037B110;return fn_80269230(this,ray,h,0xAULL,0x400000000ULL);}
extern "C" void fn_80224294(Owner*self,const Handle&first,const Handle&orientation,const Handle&context){
 if(!fn_801F7EB8(&first)||!fn_801F7EB8(&context))return;
 Actor*actor=resolve(self->getHandle(0));
 Geometry*geometry=resolve(first)->geometry;
 Vec3 start=geometry->getPosition()+Vec3(lbl_8037B0E0,lbl_8037B10C,lbl_8037B0E0);
 Vec3 current=start;
 Quat q=game_quat_identity;
 if(fn_801F7EB8(&orientation)){
  Vec3 target=resolve(orientation)->geometry->getPosition();target=target;
  float dx=target.x-start.x;float dz=target.z-start.z;float angle=fn_80285124(dx,dz);angle*=lbl_8037B0EC;
  float cosine=fn_8028506C(angle);
  float sine=fn_80284FA8(angle);
  q=Quat(cosine,lbl_8037B0E0*sine,lbl_8037B0E4*sine,lbl_8037B0E0*sine);
 }
 Hit hit;
 actor->flags&=~0x40000UL;
 Vec4 point(game_vec4_zero,lbl_8037B0E4);
 signed char have=self->getPoint(point,0,0);
 if(have&&resolve(context)->initialCast(start,&hit,point))current=hit.point;
 if(resolve(context)->downCast(current,&hit)){
  fn_801CBDE4(resolve(actor->owner),actor,hit.object,lbl_8037B0E0);
  if(!have)current=hit.point;
 }
 actor->flags|=0x40000UL;
 self->setPosition(current);
 self->setTransform(current,q,0);
 fn_8023DE28(resolve(resolve(context)->child));
 self->applyHandle(self->getHandle(0));
 if(self->flags&0x1000ULL)self->notifyHandle(context,current);
}

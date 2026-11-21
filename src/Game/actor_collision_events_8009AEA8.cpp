/* Actor collision-result events with an alternate sphere query for flagged
 * owners. Partial object layouts cover only observed fields. The vector
 * expression retains its native temporary; result access uses array indices.
 * Owned data: shared scalar defaults, native conversion bias and exception records.
 */
namespace {
typedef unsigned long Word;
struct Vec3 {float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}};
struct Sphere{Vec3 center;float radius;Sphere(const Vec3&c,float r):center(c),radius(r){}};
struct Handle{signed int generation:8,index:24;};
struct Prefix{Word unknown00,unknown04;};
struct Node:Prefix{virtual void slot08();
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
virtual signed char getStartEvent(int*);
virtual signed char getEndEvent(int*);
virtual void slot54();
virtual void slot58();
virtual void slot5C();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6C();
virtual void slot70();
virtual void setSource(const Handle*);
virtual void slot78();
virtual void slot7C();
virtual void slot80();
virtual void slot84();
virtual signed char getSphere(Sphere*,int,int);
Word unknown0C;Handle first10;Word unknown14;Handle next18;Word unknown1C,unknown20;Handle source24;char unknown28[0x38-0x28];unsigned long long flags38;char unknown40[0x130-0x40];Handle owner130;
};
struct Entry{Node*object;Word unknown04,unknown08;signed char generation;char unknown0D[3];};
struct Manager{Word count,capacity;Entry*entries;};
struct Context{char unknown00[0x118];Manager*manager;};
struct Result{char unknown00[0x28];Word unknown28,unknown2C;Node*object;void*material;Word unknown38;signed char active;char unknown3D[3];unsigned long type;Word unknown44;Result(){active=0;object=0;material=0;unknown38=0;unknown2C=0;unknown28=0;}};
}
extern "C"{extern Context lbl_801E9D24;extern const Vec3 game_vec4_zero;extern const float lbl_80378D60,lbl_80378D5C;signed char fn_80268794(void*,const Sphere*,const Vec3*,Result*,int,unsigned long long,unsigned long long,signed char,float);signed char fn_80243384(void*,int*);signed char fn_80243364(void*,int*);void fn_802073E8(Node*,int,Node*,float);}
namespace {
inline Node*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
}

/* These accessors precede the shared definitions so their reads retain the
 * external scalar identities when inlined into the consumer below. */
inline const float& sphereRadius(){return lbl_80378D60;}
inline const float& queryMinimum(){return lbl_80378D5C;}
extern "C"{extern const float lbl_80378D58=-1.0f;extern const float lbl_80378D5C=0.0f;extern const float lbl_80378D60=1.0f;extern const float lbl_80378D64=-1.0f;extern const float lbl_80378D68=60.0f;}
extern "C"void fn_8009AEA8(Node*self,void*world,const Vec3*origin,const Vec3*offset,int which,signed char moving){
 Sphere sphere(game_vec4_zero,sphereRadius());
 if(!self->getSphere(&sphere,2,which)){
  if(!(resolve(self->source24)->flags38&0x1000000000000ULL))return;
  self->getSphere(&sphere,0,which);
 }
 {
  Vec3 to=(sphere.center-*origin)+*offset;
  Result results[8];
  Node*source=resolve(self->source24);
  if(source){
   if(fn_80268794(world,&sphere,&to,results,8,0x800000000ULL,0,0,queryMinimum())){
    float parameter=(float)which;
    Node*object;
    for(int i=0;i<8;++i){
     Result*hit=&results[i];
     if(hit->active){
      object=hit->object;
      void*material=hit->material;
      Node*const recipient=resolve(object->owner130);
      int response;
      if(hit->type==1){
       recipient->setSource(&self->source24);
       fn_802073E8(recipient,0x8a,source,parameter);
       if(source->getStartEvent(&response)){
        fn_802073E8(source,response,recipient,parameter);
        Node*child=resolve(object->first10);
        while(child){Node*owner=resolve(child->owner130);if(owner)fn_802073E8(source,response,owner,parameter);child=resolve(child->next18);}
       }
      }else if(hit->type==3){
       fn_802073E8(recipient,0x8b,source,parameter);
       if(source->getEndEvent(&response)){
        fn_802073E8(source,response,recipient,parameter);
        Node*child=resolve(object->first10);
        while(child){Node*owner=resolve(child->owner130);if(owner)fn_802073E8(source,response,owner,parameter);child=resolve(child->next18);}
       }
      }else if(hit->type==2&&moving){
       int event=0x2e;
       if(fn_80243384(material,&event)){
        fn_802073E8(recipient,event,source,parameter);
        if(source->getStartEvent(&event))fn_802073E8(source,event,recipient,parameter);
       }else fn_802073E8(recipient,event,source,parameter);
      }
     }
    }
   }
  }
 }
}

/* fn_8022ED80: detaches the related object's anchor, then re-spawns one retained
   record per selected item around it (random yaw/pitch/distance offsets). */
typedef unsigned long u32;
struct Manager;struct Selector;
struct Context{char unknown00[0x118];Manager*manager;char unknown11C[0x28];Selector*selector;};
extern "C"{extern Context lbl_801E9D24;}
struct Handle_801F7F10{
    union{u32 value;struct{signed int generation:8;signed int index:24;}bits;};
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ZeroHandle1:Handle_801F7F10{ZeroHandle1(){value=0;}~ZeroHandle1(){}};
struct ZeroHandle2:ZeroHandle1{ZeroHandle2(){value=0;}~ZeroHandle2(){}};
struct ZeroHandle3:ZeroHandle2{ZeroHandle3(){value=0;}~ZeroHandle3(){}};
struct Entry{void*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager{int count,capacity;Entry*entries;};
struct Selector{char unknown00[0x94];int*selection;const int&operator[](int index)const{return selection[index];}};
inline void*resolveOrNull(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();void*r=0;if(generation==h.bits.generation)r=m->entries[index].object;return r;}
inline void*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.bits.generation)return m->entries[index].object;return 0;}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
extern "C"{
extern const float lbl_8037B18C,lbl_8037B190,lbl_8037B198,lbl_8037B1B0,lbl_8037B1B4;
extern const char lbl_8037B1A0[6],lbl_8037B1A8[6];
float fn_80285124(float,float);
float fn_8028506C(float);
float fn_80284FA8(float);
float fn_801F1200();
}
struct Vec3{
 float x,y,z;
 Vec3(){}
 Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}
 Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}
 Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
 Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return*this;}
 float lengthXZ()const{float sq=x*x+z*z;float r=lbl_8037B18C;if(sq!=r)r=fastSqrt(sq);return r;}
 float lengthSq()const{return x*x+y*y+z*z;}
 float length()const{float sq=lengthSq();float r=lbl_8037B18C;if(sq!=r)r=fastSqrt(sq);return r;}
};
struct Quat{
 float w;Vec3 v;
 Quat(){}
 Quat(float angle,float x,float y,float z){float half=angle*lbl_8037B198;w=fn_8028506C(half);float s=fn_80284FA8(half);v=Vec3(x*s,y*s,z*s);}
 Quat&operator=(const Quat&q){w=q.w;v.x=q.v.x;v.y=q.v.y;v.z=q.v.z;return*this;}
};
struct Matrix{float m[16];Vec3 column(int i)const{return Vec3(m[i],m[i+4],m[i+8]);}};
struct Basis{float m[9];};
extern "C"{
void fn_801F1080(const Matrix*,const Matrix*,Matrix*);
void fn_801F2170(Basis*,const void*,const void*);
Quat fn_801F20F4(const Basis*);
Vec3 fn_801F1B1C(const Quat*,const Vec3*);
}
inline Vec3 operator*(const Quat&q,const Vec3&v){return fn_801F1B1C(&q,&v);}
inline Matrix relative(const Matrix*a,const Matrix*b){Matrix r;fn_801F1080(a,b,&r);return r;}

struct BitNativeCtorPoint{float x,y,z;};
struct BitParameterRecord{
 char unknown00[0x38];unsigned long long token38;char unknown40[0x68];
 BitParameterRecord(const Handle_801F7F10&,const Handle_801F7F10&,const Handle_801F7F10&,const Handle_801F7F10&,const BitNativeCtorPoint&,unsigned long long,float,float);
};
/* The native constructor and destructor carry different invented class names;
   this private view derives the destructor owner from the constructor owner so a
   local record calls both original symbols (destructor flag -1). */
struct Record_80209EA0:BitParameterRecord{
 Record_80209EA0(const Handle_801F7F10&h44,const Handle_801F7F10&h48,const Handle_801F7F10&h4C,const Handle_801F7F10&h40,const BitNativeCtorPoint&point,unsigned long long token,float a,float b):BitParameterRecord(h44,h48,h4C,h40,point,token,a,b){}
 ~Record_80209EA0();
};
struct SpawnRecord{Vec3 velocity;Vec3 spin;float unknown18,phase1C,phase20,speed24,unknown28,range2C,range30;char unknown34[0x74];};
typedef char SpawnRecordSize[sizeof(SpawnRecord)==0xA8?1:-1];

struct ManipulatorPrefix{unsigned long unknown00[2];};
struct Manipulator_Z:ManipulatorPrefix{
 Manipulator_Z();virtual ~Manipulator_Z();
 virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C(float);virtual void slot30();virtual void slot34();virtual void slot38(float)=0;virtual void slot3C();
 char unknown0C[0x20-0x0C];
};
struct Node{char unknown00[0x30];Basis orientation;char unknown54[0x120-0x54];u32 flags;Matrix*matrix;};
struct RelatedObject:Manipulator_Z{
 virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
 virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();
 virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();
 virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();
 virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();
 virtual void slot90();virtual void slot94();virtual void slot98();
 virtual Handle_801F7F10*anchor(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();
 virtual void setMode(int,int);
 char unknown20[8];Handle_801F7F10*items;Handle_801F7F10&getItem(int i){return items[i];}char unknown2C[4];unsigned long long flags;char unknown38[0x16C-0x38];Handle_801F7F10 related;
};
template<class T>struct Array{int count,capacity;T*data;T&operator[](int i){return data[i];}};
struct Borrowed{RelatedObject*value;Borrowed(RelatedObject*p):value(p){}operator RelatedObject*()const{return value;}RelatedObject*operator->()const{return value;}};
struct BitRecordOwner{int count,capacity;SpawnRecord*records;char unknown0C[0x18];};
struct SpawnOwner:Manipulator_Z{
 virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
 virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();
 virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();
 virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();
 virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();
 virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9C();
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();
 virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();
 virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();
 virtual void slotD0();virtual void startRecord(int);
 char unknown20[0x10];unsigned long long token;char unknown38[0x180-0x38];BitRecordOwner records;u32 unknown1A4;Handle_801F7F10 related;Array<float>scales;char unknown1B8[0x18];Array<Quat>rotations;Array<float>baseScales;float elapsed;
};
struct SpawnParams{float speed00,speed04,size08,unknown0C,distanceMin,distanceMax,pitchMin,pitchMax,phase20,phase24,range28,range2C;Vec3 origin;Vec3 extent;};
extern "C"{
int fn_8024A094(void*,const char*,int);
int fn_8024A120(void*,const char*,int);
int fn_802257EC(BitRecordOwner*,const Record_80209EA0*);
void fn_8021FE84(RelatedObject*,Handle_801F7F10*,int);
void fn_8021FD9C(void*,const Handle_801F7F10*,void*,signed char);
const Handle_801F7F10*fn_80240F28(void*);
}

extern "C" void fn_8022ED80(SpawnOwner*self,const Vec3*origin,const SpawnParams*params){
 RelatedObject*related=(RelatedObject*)resolve(self->related);
 Handle_801F7F10*anchor=related->anchor(0);
 related->setMode(0xC0000,0);
 related->flags&=~0x81FFFE00ULL;
 fn_8021FE84(related,anchor,0x42);
 fn_8021FD9C(self,anchor,resolve(*fn_80240F28(resolve(*anchor))),1);
 RelatedObject*owner=(RelatedObject*)resolve(self->related);
 Borrowed object((RelatedObject*)resolve(owner->related));
 int count=fn_8024A094(object,lbl_8037B1A0,1);
 fn_8024A120(object,lbl_8037B1A8,1);
 ZeroHandle3 none;
 Node*base=(Node*)resolveOrNull(*anchor);
 float radius=params->extent.lengthXZ();
 for(int i=0;i<count;++i){
  Handle_801F7F10&item=object->getItem((*lbl_801E9D24.selector)[i+0x1C]);
  Node*node=(Node*)resolve(item);
  node->flags&=~0x80000UL;
  Matrix m=relative(base->matrix,node->matrix);
  float x=m.m[12],z=m.m[14];
  Basis basis;fn_801F2170(&basis,&base->orientation,&node->orientation);
  self->rotations[i]=fn_801F20F4(&basis);
  self->baseScales[i]=self->scales[i]=m.column(0).length();
  float yaw=fn_80285124(x-origin->x,z-origin->z);float jitterYaw=fn_801F1200();yaw+=jitterYaw*lbl_8037B1B0;
  float distance=params->distanceMin+(params->distanceMax-params->distanceMin)*fn_801F1200();
  float pitch=params->pitchMin+(params->pitchMax-params->pitchMin)*fn_801F1200();
  Quat qp(pitch,lbl_8037B190,lbl_8037B18C,lbl_8037B18C);
  Quat qy(yaw,lbl_8037B18C,lbl_8037B190,lbl_8037B18C);
  Vec3 position=qy*(qp*Vec3(lbl_8037B18C,lbl_8037B18C,distance));
  position+=qy*(qp*Vec3(lbl_8037B18C,lbl_8037B18C,radius));
  int index;
  {
   Record_80209EA0 record(none,none,none,item,(const BitNativeCtorPoint&)position,self->token,params->size08,lbl_8037B1B4);
   index=fn_802257EC(&self->records,&record);
  }
  self->startRecord(index);
  SpawnRecord*rec=&self->records.records[index];
  rec->spin=Vec3(lbl_8037B18C,params->speed00,lbl_8037B18C);
  rec->speed24=params->speed04;
  rec->range2C=params->range28;rec->range30=params->range2C;
  float jitter=lbl_8037B198*fn_801F1200();
  rec->phase1C=params->phase24+jitter;
  rec->phase20=params->phase20+jitter;
 }
 self->elapsed=lbl_8037B18C;
}

#ifndef GAME_EARLY_MOTION_VECTOR_CONTROL_VIEWS_H
#define GAME_EARLY_MOTION_VECTOR_CONTROL_VIEWS_H
struct MotionVectorHandle{signed int tag:8;signed int index:24;};
struct MotionVector{float x,y,z;MotionVector(){}MotionVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}MotionVector&operator=(const MotionVector&v){x=v.x;y=v.y;z=v.z;return*this;}MotionVector operator*(float s)const{return MotionVector(x*s,y*s,z*s);}MotionVector operator+(const MotionVector&v)const{return MotionVector(x+v.x,y+v.y,z+v.z);}MotionVector&operator+=(const MotionVector&v){x+=v.x;y+=v.y;z+=v.z;return*this;}};
struct MotionVectorTransform{char unknown00[0x30];MotionVector position;};
struct MotionVectorPrefix{char unknown00[8];};
struct MotionVectorActor:MotionVectorPrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual const MotionVectorHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const MotionVector&,int);
char unknown0C[0x18];MotionVectorHandle handle;char unknown28[0x10];unsigned long long flags;char unknown40[0x104];MotionVector velocity;char unknown150[0x18];char controller[8];int state;char unknown174[0x28];MotionVector origin;signed char originActive;char unknown1A9[3];MotionVector position;char unknown1B8[0x1A0];MotionVector acceleration;char unknown364[8];float scale;char unknown370[0x14];MotionVector impulse;MotionVector saved;
};
struct MotionVectorResource{char unknown00[0x38];unsigned long long flags;char unknown40[0xE0];unsigned long property;MotionVectorTransform*transform;};
struct MotionVectorEntry{MotionVectorResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct MotionVectorManager{char unknown00[8];MotionVectorEntry*entries;};
struct MotionVectorContext{char unknown00[0x118];MotionVectorManager*manager;};
extern "C"MotionVectorContext lbl_801E9D24;
inline MotionVectorResource*resolveResource(const MotionVectorHandle&h){int index=h.index;MotionVectorManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct MotionVectorController{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void update(float,void*,const MotionVector*,void*,void*);};
struct MotionVectorOscillator{char unknown00[8];MotionVectorActor*actor;char unknown0C[8];float offset,phase,amplitude,speed;};
struct MotionVectorStatus{char unknown00[0x70];signed char active;};
struct MotionVectorGroup{char unknown00[0x94];MotionVectorStatus*status;};
struct MotionVectorTimed{char unknown00[8];MotionVectorActor*actor;MotionVectorGroup*group;char unknown10[4];float duration,time,rate;MotionVector velocity;};
extern "C"{MotionVectorController*fn_8007DCF8(void*);float fn_80284FA8(float);MotionVector fn_800AB440(MotionVectorTimed*);void fn_8007D6A0(void*,int);extern const float lbl_80379038,lbl_80379048,lbl_8037907C,lbl_80379088,lbl_80378D68;}
#endif

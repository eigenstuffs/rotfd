#ifndef GAME_EARLY_ACTOR_INPUT_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_INPUT_CONTROL_VIEWS_H

struct InputVector{float x,y,z;InputVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){};InputVector&operator*=(float v){x*=v;y*=v;z*=v;return*this;}InputVector operator*(float v)const{return InputVector(x*v,y*v,z*v);}InputVector&operator+=(const InputVector&v){x+=v.x;y+=v.y;z+=v.z;return*this;}};
struct InputHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct InputResource{char unknown00[0x98];InputHandle*nested;};
struct InputEntry{InputResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct InputManager{int count,capacity;InputEntry*entries;};
struct InputService{char unknown00[0x1C];InputHandle*handle;};
struct InputFeedbackPrefix{char unknown00[0x1C];};
struct InputFeedback:InputFeedbackPrefix{
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
virtual void feedback(int,unsigned char,unsigned char);
};
struct InputContext{char unknown00[0x118];InputManager*manager;char unknown11C[8];void*scene;char unknown128[0x14];InputService*service;char unknown140[0x14];InputFeedback*feedback;};
extern "C" InputContext lbl_801E9D24;
inline InputResource*resolveInput(const InputHandle&h){InputEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct InputRecord{char unknown00[8];int key;};
struct InputActor{char unknown00[0x30];unsigned long long flags;char unknown38[0x2E0];InputRecord record;char unknown324[0x30];float speed;InputVector acceleration;char unknown364[0xAE];signed char enabled412;char unknown413[0x11];float scale;
inline signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}};
struct InputControllerPrefix{char unknown00[8];};
struct InputController:InputControllerPrefix{
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
virtual void slot37();
virtual void*slot38();
};
struct InputOwner{char unknown00[8];InputActor*actor;InputController*controller;char unknown10[0x30];InputHandle bound;signed char active;unsigned char level,mode;};
struct InputMotionOwner{char unknown00[8];InputActor*actor;InputController*controller;char unknown10[0x30];InputVector vector;float speed;};
struct InputMonitor{char unknown00[0x130];void*first;void*second;};
struct InputAxes{char unknown00[0x110];float x,y;};
extern "C"{extern InputMonitor*lbl_803776B8;extern const InputVector game_vec3_zero;extern const double lbl_80378B08;extern const float lbl_80378AE0;double __fabs(double);void fn_80257828(void*,int,int,int);void fn_8006803C(InputMonitor*,int);void fn_80068158(InputMonitor*,int);void fn_80255D88(void*,int,int,int,int);void fn_80255CBC(void*,int,int);void fn_800C3BC8(InputResource*,void*);void fn_800C3D44(InputResource*,void*);void fn_80257490(void*);InputAxes*fn_8007D074(void*);void fn_802603A0(void*,int,InputResource*,float);void fn_8007D6A0(InputRecord*,int);void fn_80092DAC(InputActor*,double);void fn_80085298(InputOwner*);}
struct InputSecondEntry{InputResource*object;char unknown04[8];signed char tag;char unknown0D[3];};struct InputSecondManager{int count,capacity;InputSecondEntry*entries;};
inline InputResource*resolveInputSecond(const InputHandle&h){InputSecondEntry*e=&((InputSecondManager*)lbl_801E9D24.manager)->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}

#endif

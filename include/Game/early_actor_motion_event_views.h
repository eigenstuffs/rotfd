#ifndef GAME_EARLY_ACTOR_MOTION_EVENT_VIEWS_H
#define GAME_EARLY_ACTOR_MOTION_EVENT_VIEWS_H

struct MotionVector{float x,y,z;MotionVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){};MotionVector(const MotionVector&v,float yy):x(v.x),y(yy),z(v.z){};MotionVector&operator+=(const MotionVector&v){x+=v.x;y+=v.y;z+=v.z;return*this;}};
struct MotionSceneMode{char unknown00[0xF0];int state;};
struct MotionScene{char unknown00[0x15058];MotionSceneMode*mode;};

struct MotionHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct MotionComponent{char unknown00[0xC];float value;};
struct MotionResource{char unknown00[0x74];MotionComponent*first;MotionComponent*second;char unknown7C[0xA4];unsigned long flags;};
struct MotionEntry{MotionResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct MotionManager{int count,capacity;MotionEntry*entries;};
struct MotionContext{char unknown00[0x118];MotionManager*manager;char unknown11C[8];MotionScene*scene;};
extern "C" MotionContext lbl_801E9D24;
inline MotionResource*resolveMotion(const MotionHandle&h){MotionEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct MotionRecord{char unknown00[8];int key;};
struct MotionActorPrefix{char unknown00[8];};
struct MotionActor:MotionActorPrefix{
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
virtual const MotionHandle* slot37(int);
char unknown0C[0x24];unsigned long long flags;char unknown38[0x10C];MotionVector velocity;char unknown150[0xC];MotionVector position;MotionHandle handle;char unknown16C[0x40];MotionHandle selected;char unknown1B0[8];MotionVector direction;char unknown1C4[0x154];MotionRecord record;char unknown324[0x30];float speed;MotionVector acceleration;char unknown364[0x88];float height;char unknown3F0[0xC];float value;char unknown400[5];signed char enabled405,enabled406;char unknown407[2];signed char enabled409,enabled40A;char unknown40B[2];signed char enabled40D;char unknown40E[6];MotionVector offset;
inline void clearFlags(unsigned long long mask){flags&=~mask;}
inline signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}
};
struct MotionOwner{char unknown00[8];MotionActor*actor;void*controller;char unknown10[0x30];signed char enabled40;};
struct MotionMonitor{char unknown00[0x130];void*first;void*second;};
extern "C"{extern MotionMonitor*lbl_803776B8;extern const float lbl_80378AA8,lbl_80378AF0,lbl_80378AD8;MotionResource* fn_801F7EB8(const MotionHandle*);signed char fn_8007D604(MotionRecord*,int);void fn_8025795C(void*,int,int);void fn_8006803C(MotionMonitor*,int);void fn_80068158(MotionMonitor*,int);void fn_80285ED8(void*,int,int);int fn_80092844(MotionActor*);void fn_8007D6A0(MotionRecord*,int);void fn_80092BF4(MotionActor*,int,double);void fn_80092DAC(MotionActor*,double);void fn_80257828(void*,int,int,int);}
struct MotionFirstResource{char unknown00[0x74];MotionComponent*first;};
struct MotionFirstEntry{MotionFirstResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct MotionFirstManager{int count,capacity;MotionFirstEntry*entries;};
inline MotionFirstResource*resolveMotionFirst(const MotionHandle&h){MotionFirstEntry*e=&((MotionFirstManager*)lbl_801E9D24.manager)->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C"{extern const float lbl_80378AD0;extern const MotionVector game_vec3_zero;void fn_80255D88(void*,int,int,int,int);}

#endif

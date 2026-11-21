#ifndef GAME_EARLY_ACTOR_SCENE_EFFECT_VIEWS_H
#define GAME_EARLY_ACTOR_SCENE_EFFECT_VIEWS_H
struct EffectVector{float x,y,z;EffectVector(float a,float b,float c):x(a),y(b),z(c){}};
struct EffectTransform{char unknown00[0x30];EffectVector position;};
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct EffectPrefix{char unknown00[8];};
struct SceneEffect:EffectPrefix{
virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void activate();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual void control(int,int);
char unknown0C[0x118];EffectTransform*transform;
};
struct EffectActor:EffectPrefix{
virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual void slot28();virtual void slot29();virtual void slot30();virtual void slot31();virtual void slot32();virtual void slot33();virtual void slot34();virtual void slot35();virtual void slot36();virtual const Handle_801F7F10*getResource(int);
char unknown0C[0x24];unsigned long long flags;char unknown38[0x128];float velocityY;char unknown164[0x21C];float height;char unknown384[0x3C];float forwardX;char unknown3C4[4];float forwardZ;
inline signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}
};
struct EffectEntry{SceneEffect*object;char unknown04[8];signed char tag;char unknown0D[3];};struct EffectManager{int count,capacity;EffectEntry*entries;};
struct EffectSystem{char unknown00[0x2E];signed char enabled;};
struct EffectScene{char unknown00[0x15058];void*mode;};struct EffectContext{char unknown00[0x118];EffectManager*manager;char unknown11C[8];EffectScene*scene;char unknown128[0x14];void*service;char unknown140[0x24];EffectSystem*system;};
struct EffectOwner{char unknown00[8];EffectActor*actor;void*controller;char unknown10[0x30];SceneEffect*first,*second;float maximum,minimum;};
extern "C" {extern EffectContext lbl_801E9D24;extern const char lbl_8029D680[];unsigned long fn_801F948C(void*,const char*);void fn_80255D88(void*,int,int,int,int);void fn_802554F4(SceneEffect*);void fn_80254BB4(SceneEffect*,const EffectVector*);}
struct EffectName{unsigned long value;EffectName(const char*s){value=fn_801F948C(this,s);}};
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){value=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){value=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C" Handle_80020834 fn_80058778(void*,const EffectName&,signed char);
inline SceneEffect*resolveEffect(const Handle_801F7F10&h){EffectEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct EffectQuaternion{float w,x,y,z;EffectQuaternion(float a,float b,float c,float d):w(a),x(b),y(c),z(d){}};
extern "C" {signed char fn_80206E28(void*,int,int);void fn_80255588(SceneEffect*);void fn_80255678(SceneEffect*);void fn_80254AF4(SceneEffect*,const EffectVector*,const EffectQuaternion*);float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);extern const float lbl_80378AEC,lbl_80378AD0,lbl_80378ADC;}
#endif

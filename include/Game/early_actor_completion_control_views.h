#ifndef GAME_EARLY_ACTOR_COMPLETION_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_COMPLETION_CONTROL_VIEWS_H

struct CompletionVector{float x,y,z;};
struct CompletionHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct CompletionRecord{char unknown00[8];int key;};
struct CompletionActorPrefix{char unknown00[8];};
struct CompletionActor:CompletionActorPrefix{
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
virtual void slot29(int,float);
char unknown0C[0x24];unsigned long long flags;char unknown38[0x10C];CompletionVector position;char unknown150[0xC];CompletionVector velocity;char unknown168[0x44];CompletionHandle related;char unknown1B0[0x168];CompletionRecord record;int state;char unknown328[0x28];float speed;char unknown354[4];CompletionVector acceleration;char unknown364[0x88];union{float value3EC;int state3EC;};char unknown3F0[0x1B];signed char enabled40B,enabled40C,enabled40D;char unknown40E;signed char enabled40F;
inline signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}inline void setFlags(unsigned long long mask){flags|=mask;}inline void clearFlags(unsigned long long mask){flags&=~mask;}
};
struct CompletionOwner{char unknown00[8];CompletionActor*actor;void*controller;char unknown10[0x30];int mode;};
struct CompletionEntry{CompletionActor*object;char unknown04[8];signed char tag;char unknown0D[3];};struct CompletionManager{int count,capacity;CompletionEntry*entries;};
struct CompletionSelection{char unknown00[0x14];CompletionHandle handle;char unknown18[0x34];};
struct CompletionSceneMode{char unknown00[0xF0];int state,substate;};struct CompletionScene{char unknown00[0x15058];CompletionSceneMode*mode;};
struct CompletionFeedbackPrefix{char unknown00[0x1C];};struct CompletionFeedback:CompletionFeedbackPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void feedback(int,unsigned char,unsigned char);};
struct CompletionSystem{char unknown00[0x2D];signed char active;};
struct CompletionContext{char unknown00[0x114];CompletionSelection*selections;CompletionManager*manager;char unknown11C[8];CompletionScene*scene;char unknown128[0x2C];CompletionFeedback*feedback;char unknown158[0xC];CompletionSystem*system;};
struct CompletionInput{char unknown00[0x20];int index;char unknown24[0xAC];int state;char unknownD4[0x108];signed char active;};
struct CompletionController{char unknown00[0x84];int mode;};
struct CompletionMonitor{char unknown00[0x130];void*first,*second;};
extern "C" {extern CompletionContext lbl_801E9D24;extern CompletionMonitor*lbl_803776B8;extern const float lbl_80378AF0,lbl_80378D58,lbl_80378AE0,lbl_80378AD0;extern int lbl_80378598;CompletionActor*fn_801F7EB8(const CompletionHandle*);void fn_8025795C(void*,int,int);void fn_80255CBC(void*,int,int);void fn_8006803C(CompletionMonitor*,int);void fn_80068158(CompletionMonitor*,int);CompletionInput*fn_8007D074();void fn_8007705C(CompletionInput*);void fn_80092BF4(CompletionActor*,int,double);void fn_80092DAC(CompletionActor*,double);int fn_80092844(CompletionActor*);void fn_8007D6A0(CompletionRecord*,int);void fn_80286058(void*,int);void fn_802073E8(void*,int,CompletionSceneMode*,float);void fn_80056434(CompletionSceneMode*);}
inline signed char validCompletion(const CompletionHandle&h){return fn_801F7EB8(&h)!=0;}
inline CompletionActor*resolveCompletion(const CompletionHandle&h){CompletionEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}

#endif

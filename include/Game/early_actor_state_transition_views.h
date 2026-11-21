#ifndef GAME_EARLY_ACTOR_STATE_TRANSITION_VIEWS_H
#define GAME_EARLY_ACTOR_STATE_TRANSITION_VIEWS_H

struct StateVector{float x,y,z;StateVector(float a,float b,float c):x(a),y(b),z(c){}StateVector(const StateVector&v,float yy):x(v.x),y(yy),z(v.z){}StateVector&operator+=(const StateVector&v){x+=v.x;y+=v.y;z+=v.z;return*this;}};
struct StateRecord{char unknown00[8];int key;};
struct StateActor{char unknown00[0x30];unsigned long long flags;char unknown38[0x10C];StateVector position;char unknown150[0xC];StateVector velocity;char unknown168[0x1B0];StateRecord record;int state;char unknown328[0x28];float speed;char unknown354[4];StateVector acceleration;char unknown364[0xA1];signed char enabled405;char unknown406[2];signed char enabled408;inline signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}};
struct StateOwner{char unknown00[8];StateActor*actor;void*controller;char unknown10[0x30];float timer;char unknown44[8];void*action;char unknown50[8];signed char mode;};
struct StateSystem{char unknown00[0x2E];signed char flag;};
struct StateFeedbackPrefix{char unknown00[0x1C];};struct StateFeedback:StateFeedbackPrefix{
virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void feedback(int,unsigned char,unsigned char);
};
struct StateContext{char unknown00[0x154];StateFeedback*feedback;char unknown158[0xC];StateSystem*system;};
struct StateMonitor{char unknown00[0x130];void*first,*second;};
extern "C"{extern StateContext lbl_801E9D24;extern StateMonitor*lbl_803776B8;extern const StateVector game_vec3_zero;extern const float lbl_80378AD0,lbl_80378B38,lbl_80378D58,lbl_80378B10;void fn_80092DAC(StateActor*,double);void fn_80092BF4(StateActor*,int,double);int fn_80092844(StateActor*);void fn_8007D6A0(StateRecord*,int);void fn_8006803C(StateMonitor*,int);void fn_80068158(StateMonitor*,int);void fn_80255678(void*);void fn_80255CBC(void*,int,int);void fn_80255D88(void*,int,int,int,int);void fn_8025795C(void*,int,int);void fn_80257828(void*,int,int,int);void fn_80285ED8(void*,int,int);signed char fn_8025E9FC(void*,int);void fn_800B7214(StateSystem*,int,unsigned char*,int);}

#endif

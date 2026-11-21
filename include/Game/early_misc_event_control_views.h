#ifndef GAME_EARLY_MISC_EVENT_CONTROL_VIEWS_H
#define GAME_EARLY_MISC_EVENT_CONTROL_VIEWS_H
struct MiscVector{float x,y,z;MiscVector(){}MiscVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}MiscVector(const MiscVector&v):x(v.x),y(v.y),z(v.z){}};
struct MiscTransform{char unknown00[0x30];MiscVector position;};
struct MiscObject{char unknown00[0x124];MiscTransform*transform;};
struct MiscActor{char unknown00[0x30];unsigned long long flags;char unknown38[0x10C];MiscVector velocity;char unknown150[0x1C8];char record[8];int key;char unknown324[0xE3];signed char state407;char unknown408[4];signed char state40C; signed char hasFlag(unsigned long long mask)const{if(flags&mask)return 1;return 0;}};
struct MiscMonitor{char unknown00[0x130];void*first,*second;};
struct MiscControlOwner{char unknown00[8];MiscActor*actor;void*controller;};
struct MiscFlagsArray{char unknown00[0x18];unsigned long long flags;char unknown20[0xC];void**items;};
struct MiscPrefix8{char unknown00[8];};
struct MiscTarget:MiscPrefix8{
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
virtual void slot21(int);
virtual void slot22(int);
char unknown0C[0x2C];unsigned long long flags;
};
struct MiscPrefix4{char unknown00[4];};
struct MiscService:MiscPrefix4{virtual void slot0();virtual void slot1();virtual void slot2();virtual MiscTarget*getTarget();};
struct MiscDispatch{char unknown00[0x860];int mode;char unknown864[4];void*value;};
struct MiscScene{char unknown00[0x15058];void*state;};
struct MiscContext{char unknown00[0x110];MiscDispatch*dispatch;char unknown114[0x10];MiscScene*scene;};
struct MiscTimerOwner{char unknown00[0x1A4];float time;signed char enabled;};
struct MiscAngleOwner{char unknown00[0xD0];int mode;};
struct MiscRelated{char unknown00[0x118];void*value;};
struct MiscController{char unknown00[0x94];MiscRelated*related;};
struct MiscDelayedOwner{char unknown00[0xC];MiscController*controller;float time;signed char complete;};
extern "C"{extern MiscContext lbl_801E9D24;extern MiscMonitor*lbl_803776B8;extern const float lbl_80379350,lbl_8037899C,lbl_803789EC,lbl_80378AA8,lbl_80378AB0,lbl_80379090,lbl_80379094;extern const char lbl_8029A8DC[];void fn_8023D100(MiscObject*,const MiscVector*);void fn_8023DE28(MiscObject*);void fn_80257828(void*,int,int,int);void fn_8006803C(MiscMonitor*,int);void fn_801FA014(MiscDispatch*,const char*,...);void fn_80058AB8(void*,void*);int fn_80092844(MiscActor*);void fn_8007D6A0(void*,int);void fn_80092DAC(MiscActor*,double);void fn_800B4628(MiscTimerOwner*,float);void fn_800B5134(MiscTimerOwner*,int);void fn_800784A8(MiscAngleOwner*,MiscVector*);float fn_80285124(float,float);void fn_8002B780(MiscTarget*);void fn_80072F98(void*);void fn_802603A0(MiscScene*,int,MiscRelated*,float);}
#endif

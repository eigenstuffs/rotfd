// Bounded native C-entry actor and scene views; no complete class identity claim.
#ifndef GAME_SIX_CALLBACK_NATIVE_MOTION_VIEWS_H
#define GAME_SIX_CALLBACK_NATIVE_MOTION_VIEWS_H
struct ClampVectorHandle{signed int tag:8;signed int index:24;};
struct ClampVector{float x,y,z;ClampVector(){}ClampVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}ClampVector&operator=(const ClampVector&v){x=v.x;y=v.y;z=v.z;return*this;}ClampVector operator*(float s)const{return ClampVector(x*s,y*s,z*s);}ClampVector operator+(const ClampVector&v)const{return ClampVector(x+v.x,y+v.y,z+v.z);}ClampVector&operator+=(const ClampVector&v){x+=v.x;y+=v.y;z+=v.z;return*this;}};
extern "C" const float lbl_80379038;
struct ClampVectorActor{unsigned long unknown00[2];
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
virtual const ClampVectorHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const ClampVector&,int);
float getRadius()const{return lbl_80379038;}const float&getCenterHeight()const{return position.y;}
char unknown0C[0x18];ClampVectorHandle handle;char unknown28[0x10];unsigned long long flags;char unknown40[0x104];ClampVector velocity;char unknown150[0xC];ClampVector previousVelocity;char controller[8];int state;char unknown174[0x28];ClampVector origin;signed char originActive;char unknown1A9[3];ClampVector position;
};
struct ClampSceneStatus{char unknown00[0x152];short count;};struct ClampScene{char unknown00[0x15058];ClampSceneStatus*status;};struct ClampVectorContext{char unknown00[0x118];void*manager;char unknown11C[8];ClampScene*scene;};
extern "C"ClampVectorContext lbl_801E9D24;
struct ClampVectorController{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void update(float,void*,const ClampVector*,void*,void*);};
extern "C"{ClampVectorController*fn_8007DCF8(void*);signed char fn_8007D6A0(void*,int);}
extern "C"{signed char fn_8007D604(void*,int);signed char fn_8007DA74(void*,float);extern const ClampVector game_vec3_zero;}
#endif

#ifndef GAME_EARLY_RECORD_SERVICE_ARRAY_VIEWS_H
#define GAME_EARLY_RECORD_SERVICE_ARRAY_VIEWS_H
struct ServiceArrayHandle{signed int tag:8;signed int index:24;};
struct ServiceArray{float x,y,z;ServiceArray(){}ServiceArray(float xx,float yy,float zz):x(xx),y(yy),z(zz){}ServiceArray&operator=(const ServiceArray&v){x=v.x;y=v.y;z=v.z;return*this;}ServiceArray operator*(float s)const{return ServiceArray(x*s,y*s,z*s);}ServiceArray operator+(const ServiceArray&v)const{return ServiceArray(x+v.x,y+v.y,z+v.z);}ServiceArray&operator+=(const ServiceArray&v){x+=v.x;y+=v.y;z+=v.z;return*this;}};
struct ServiceArrayTransform{char unknown00[0x30];ServiceArray position;};
struct ServiceArrayPrefix{char unknown00[8];};
struct ServiceArrayActor:ServiceArrayPrefix{
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
virtual const ServiceArrayHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43(const ServiceArray&);
virtual void slot44();
virtual void slot45(const ServiceArray&,int);
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
virtual void slot58();
virtual void slot59();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void slot63();
virtual void slot64();
virtual void slot65();
virtual void slot66();
virtual void slot67();
virtual void slot68();
virtual void slot69();
virtual void slot70();
virtual void slot71();
virtual void slot72();
virtual void slot73();
virtual void slot74();
virtual void slot75();
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void slot80();
virtual void slot81();
virtual void slot82();
virtual void slot83();
virtual void slot84();
virtual void slot85();
virtual void slot86();
virtual void slot87();
virtual void slot88();
virtual void slot89();
virtual void slot90();
virtual void slot91();
virtual void slot92();
virtual void slot93();
virtual void slot94();
virtual void slot95();
virtual void slot96();
virtual void slot97();
virtual void slot98();
virtual void slot99();
virtual void slot100(float);
char unknown0C[0x18];ServiceArrayHandle handle;char unknown28[0x10];unsigned long long flags;char unknown40[0x104];ServiceArray velocity;char unknown150[0xC];ServiceArray previousVelocity;char controller[8];int state;char unknown174[0x28];ServiceArray origin;signed char originActive;char unknown1A9[3];ServiceArray position;char unknown1B8[0x160];char extraController[0x40];ServiceArray acceleration;char unknown364[8];float scale;char unknown370[0x14];ServiceArray impulse;ServiceArray saved;
};
struct ServiceArrayResource:ServiceArrayPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual void slot28();virtual void slot29();virtual void slot30();virtual void slot31();virtual void slot32();virtual void slot33();virtual void slot34();virtual void slot35();virtual void slot36();virtual void slot37();virtual void slot38();virtual void slot39();virtual void slot40();virtual void slot41();virtual void slot42();virtual void slot43(const ServiceArray&);char unknown0C[0x2C];unsigned long long flags;char unknown40[0xE0];unsigned long property;ServiceArrayTransform*transform;};
struct ServiceArrayEntry{ServiceArrayResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ServiceArrayManager{char unknown00[8];ServiceArrayEntry*entries;};
struct ServiceArrayContext{char unknown00[0x118];ServiceArrayManager*manager;};
extern "C"ServiceArrayContext lbl_801E9D24;
inline ServiceArrayResource*resolveResource(const ServiceArrayHandle&h){int index=h.index;ServiceArrayManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct ServiceArrayController{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void update(float,void*,const ServiceArray*,void*,void*);};
struct ServiceArrayOscillator{char unknown00[8];ServiceArrayActor*actor;char unknown0C[8];float offset,phase,amplitude,speed;};
struct ServiceArrayStatus{char unknown00[0x70];signed char active;};
struct ServiceArrayGroup{char unknown00[0x94];ServiceArrayStatus*status;};
struct ServiceArrayTimed{char unknown00[8];ServiceArrayActor*actor;ServiceArrayGroup*group;char unknown10[4];float duration,time,rate;ServiceArray velocity;};
extern "C"{ServiceArrayController*fn_8007DCF8(void*);float fn_80284FA8(float);ServiceArray fn_800AB440(ServiceArrayTimed*);void fn_8007D6A0(void*,int);extern const float lbl_80379038,lbl_80379048,lbl_8037907C,lbl_80379088,lbl_80378D68;}

struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ServiceArrayHandleArray{int count,capacity;Handle_801F7F10*data;};
struct ServiceArrayRecord{char unknown00[8];ServiceArrayHandleArray*arrays;};
struct ServiceArrayOwner{char unknown00[0x20];int count,capacity;ServiceArrayRecord**data;};
struct ServiceArrayObjectEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct ServiceArrayObjectManager{char unknown00[8];ServiceArrayObjectEntry*entries;};
inline void*resolveObject(const Handle_801F7F10&h){ServiceArrayObjectEntry*e=&((ServiceArrayObjectManager*)lbl_801E9D24.manager)->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
extern "C"{extern const ServiceArray game_vec3_zero;void slot188__10CActorMoveFv(ServiceArrayActor*);void fn_80222E44(ServiceArrayActor*,float);extern char lbl_801EF5C8[],lbl_8028F698[];extern const char lbl_802A0590[],lbl_802A05A0[];void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);ServiceArrayRecord*__ct__22ControllerListDefaultsFv(void*);void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);void*memcpy(void*,const void*,unsigned long);void fn_801F86C8(ServiceArrayManager*,const Handle_801F7F10*,short);}
inline void*operator new(unsigned long,void*p){return p;}
struct ServiceArrayRetainedHandle:Handle_801F7F10{ServiceArrayRetainedHandle(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
inline void growRecords(ServiceArrayOwner*self,int increase){int capacity=self->capacity+increase;if(capacity){if(self->data)self->data=(ServiceArrayRecord**)fn_8028FAF4(lbl_8028F698,self->data,self->capacity*4,capacity*4);else self->data=(ServiceArrayRecord**)fn_8028FF24(lbl_8028F698,capacity*4);}else if(self->data){fn_8028FD50(lbl_8028F698,self->data,self->capacity*4);self->data=0;}self->capacity+=increase;}
inline void growHandles(ServiceArrayHandleArray*self,int increase){int capacity=self->capacity+increase;if(capacity){if(self->data)self->data=(Handle_801F7F10*)fn_8028FAF4(lbl_8028F698,self->data,self->capacity*4,capacity*4);else self->data=(Handle_801F7F10*)fn_8028FF24(lbl_8028F698,capacity*4);}else if(self->data){fn_8028FD50(lbl_8028F698,self->data,self->capacity*4);self->data=0;}self->capacity+=increase;}
inline void eraseHandle(ServiceArrayHandleArray*self,int index){self->data[index].~Handle_801F7F10();int count=self->count-1;Handle_801F7F10*dest=&self->data[index];self->count=count;memcpy(dest,dest+1,(count-index)*4);}
#endif

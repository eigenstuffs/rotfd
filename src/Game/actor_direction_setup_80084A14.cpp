struct DirectionIndex{int value;DirectionIndex(int v):value(v){}operator const int&()const{return value;}};
struct DirectionHandle{signed int tag:8;signed int index:24;};
struct DirectionVector{float x,y,z;DirectionVector&operator=(const DirectionVector&v){x=v.x;y=v.y;z=v.z;return *this;}DirectionVector operator*(float a)const{return DirectionVector(x*a,y*a,z*a);}DirectionVector(){}DirectionVector(float a,float b,float c):x(a),y(b),z(c){}};
struct DirectionQuaternion{float w;DirectionVector vector;};
struct DirectionPrefix{char unknown00[8];};
struct DirectionActor:DirectionPrefix{
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
virtual const DirectionHandle*getHandle(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void setTransform(void*,const DirectionQuaternion&,int);
char unknown0C[0x18];DirectionHandle controller;char unknown28[8];unsigned long long flags;char unknown38[0x130];DirectionHandle property;char unknown16C[0x8C];DirectionHandle related;char unknown1FC[0x124];int record;};
struct DirectionProperty{char unknown00[0xC];float value;};struct DirectionResource{char unknown00[0x74];DirectionProperty*first,*second;};
struct DirectionEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};struct DirectionEntryArray{DirectionEntry*p;DirectionEntry&operator[](int i)const{return p[i];}};struct DirectionManager{int count,capacity;DirectionEntryArray entries;};struct DirectionContext{char unknown00[0x118];DirectionManager*manager;};
struct DirectionOwner{char unknown00[8];DirectionActor*actor;void*control;char unknown10[0x30];void*object;float savedFirst,savedSecond;};struct DirectionMonitor{char unknown00[0x130];void*first,*second;};
extern "C"{extern DirectionContext lbl_801E9D24;extern DirectionMonitor*lbl_803776B8;extern const float lbl_80378AD0,lbl_80378ADC,lbl_80378AEC,lbl_80378AE0,lbl_80378AF8;void fn_8025795C(void*,int,void*);void*fn_801F7EB8(DirectionHandle*);void fn_802073E8(void*,int,void*,float);void fn_8006803C(DirectionMonitor*,int);float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);extern const DirectionVector lbl_802F4148;}
inline DirectionActor*resolve(const DirectionHandle&h){DirectionManager*m=lbl_801E9D24.manager;DirectionIndex i(h.index);signed char t=h.tag;if(m->entries[i].matchesTag(t))return static_cast<DirectionActor*>(m->entries[i].object);return 0;}
inline DirectionResource*resolveSecond(const DirectionHandle&h){DirectionEntry*e=lbl_801E9D24.manager->entries.p+h.index;if(e->tag==h.tag)return static_cast<DirectionResource*>(e->object);return 0;}
extern "C"void fn_80084A14(DirectionOwner*self){
 self->object=resolve(self->actor->controller);
 fn_8025795C(self->object,0x1F,0);
 if(fn_801F7EB8(&self->actor->related))fn_802073E8(self->object,0x9A,resolveSecond(resolve(self->actor->related)->controller),lbl_80378AE0);
 if(lbl_803776B8&&lbl_803776B8->first)fn_8006803C(lbl_803776B8,self->actor->record);
 DirectionProperty*p=resolveSecond(self->actor->property)->second;
 if(p){self->savedSecond=p->value;p->value=lbl_80378AF8;}
 p=resolveSecond(self->actor->property)->first;
 if(p){self->savedFirst=p->value;p->value=lbl_80378AF8;}
 self->actor->flags&=~0x80000000ULL;
}

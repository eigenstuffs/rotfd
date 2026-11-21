/* fn_80084C50: resolves the actor's related handle (+0x1F8), asks the resolved
   node (virtual slot 0x9C) for its transform handle, resolves that node and
   rotates the forward axis (0, 0, 1) by its 3x3 basis at +0x30. The yaw
   atan2(x, z) is halved into a quaternion about the axis lbl_802F4148, which
   is passed to the actor's virtual slot 0xC0 together with the third argument.
   Sibling of fn_80084A14 (actor_direction_setup_80084A14.cpp, same shapes).

   lbl_80378AD0 (0.0f), lbl_80378ADC (1.0f) and lbl_80378AEC (0.5f) were pooled
   literals of the original translation unit: every use was its own load, which
   the back end merged. Plain label reads are merged by the front end into one
   early temporary, which rotates the f4/f5/f6 assignment. The zero factors of
   the x component and the two unit factors are therefore read through two
   different expression forms, and the zero factors of the z component through
   a third (an integer address cast), so no two of them share a front-end
   common subexpression across the components, as with the literals. */
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
char unknown0C[0x18];DirectionHandle controller;char unknown28[8];unsigned long long flags;char unknown38[0x130];DirectionHandle property;char unknown16C[0x8C];DirectionHandle related;};
struct DirectionEntry{DirectionActor*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct DirectionEntryArray{DirectionEntry*p;DirectionEntry&operator[](int i)const{return p[i];}};
struct DirectionManager{int count,capacity;DirectionEntryArray entries;};
struct DirectionContext{char unknown00[0x118];DirectionManager*manager;};
struct DirectionOwner{char unknown00[8];DirectionActor*actor;};
struct DirectionMatrix{char unknown00[0x30];float m[9];};
extern "C"{
extern DirectionContext lbl_801E9D24;
extern const float lbl_80378AD0,lbl_80378ADC,lbl_80378AEC;
extern const DirectionVector lbl_802F4148;
float fn_80285124(float,float);
float fn_8028506C(float);
float fn_80284FA8(float);
}
inline DirectionActor*resolve(const DirectionHandle&h){DirectionManager*m=lbl_801E9D24.manager;DirectionIndex i(h.index);signed char t=h.tag;if(m->entries[i].matchesTag(t))return m->entries[i].object;return 0;}
extern "C"void fn_80084C50(DirectionOwner*self,void*,void*target){
 DirectionMatrix*m=(DirectionMatrix*)resolve(*resolve(self->actor->related)->getHandle(0));
 float x=m->m[0]*lbl_80378AD0+m->m[3]**(const float*)&lbl_80378AD0+m->m[6]*lbl_80378ADC;
 float z=m->m[2]**(const float*)(unsigned long)&lbl_80378AD0+m->m[5]**(const float*)(unsigned long)&lbl_80378AD0+m->m[8]**(const float*)&lbl_80378ADC;
 float angle=fn_80285124(x,z);angle*=lbl_80378AEC;
 DirectionQuaternion q;q.w=fn_8028506C(angle);q.vector=lbl_802F4148*fn_80284FA8(angle);
 self->actor->setTransform(target,q,0);
}

/* Actor forward-axis yaw to quaternion; sibling of fn_80026938. */
struct Handle{signed int generation:8,index:24;};
struct Resource{char unknown[0x30];float basis[9];};
struct Entry{Resource*object;char unknown4[8];signed char generation;char tail[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Globals{char unknown[0x118];Manager*manager;};
extern "C" {extern Globals lbl_801E9D24;extern const float lbl_80378268,lbl_8037826C,lbl_80378270;extern const float lbl_802F4148[3];float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);}
inline Resource*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
struct Vector4{float x,y,z,w;};
struct Prefix{char unknown0[8];};
struct Actor:Prefix{
virtual void slot08();
virtual void slot0C();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1C();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3C();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5C();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6C();
virtual void slot70();
virtual void slot74();
virtual void slot78();
virtual void slot7C();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual const Handle& getHandle(int);
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void slotBC();
virtual void setValue(void*,const Vector4&,int);
};
struct Owner{char unknown[8];Actor*actor;};
extern "C" void fn_8002607C(Owner*self){
 Resource*resource=resolve(self->actor->getHandle(0));
 float angle=fn_80285124(resource->basis[0]*lbl_8037826C+resource->basis[3]*lbl_8037826C+resource->basis[6]*lbl_80378268,resource->basis[2]*lbl_8037826C+resource->basis[5]*lbl_8037826C+resource->basis[8]*lbl_80378268);
 angle*=lbl_80378270;
 Vector4 value;value.x=fn_8028506C(angle);float sine=fn_80284FA8(angle);value.y=lbl_802F4148[0]*sine;value.z=lbl_802F4148[1]*sine;value.w=lbl_802F4148[2]*sine;
 self->actor->setValue((char*)self->actor+0x348,value,0);
}

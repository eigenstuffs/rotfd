/* Places the owner's actor (+0x8, virtual slot 0xBC) at the current player's
   linked local offset transformed into the frame of the node returned by the
   player's virtual slot 0x9C: the offset is rotated by the node's 3x3 basis at
   +0x30 and the node's matrix translation (+0x124 -> +0x30) is added.
   Same handle chain as fn_800E1EB4 (early_spatial_state_control_800e1eb4.cpp).
   The translation is added through a float-argument add() member: building the
   sum with a 3-argument constructor/operator+ reverses the f0/f2 assignment. */
struct ForwardSpatialHandle{signed int tag:8;signed int index:24;};
struct ForwardSpatialVector{float x,y,z;ForwardSpatialVector(){}ForwardSpatialVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}ForwardSpatialVector&operator=(const ForwardSpatialVector&v){x=v.x;y=v.y;z=v.z;return*this;}ForwardSpatialVector&operator+=(const ForwardSpatialVector&v){x+=v.x;y+=v.y;z+=v.z;return*this;}void add(float ax,float ay,float az){x+=ax;y+=ay;z+=az;}};
struct ForwardSpatialTransform{char unknown00[0x30];ForwardSpatialVector position;};
struct ForwardSpatialPrefix{char unknown00[8];};
struct ForwardSpatialLink{char unknown00[0x124];ForwardSpatialTransform*transform;};
struct ForwardSpatialFrame{char unknown00[0x30];ForwardSpatialVector axisX,axisY,axisZ;char unknown54[0x124-0x54];ForwardSpatialTransform*transform;};
struct ForwardSpatialActor:ForwardSpatialPrefix{
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
virtual void slot35(int,int);
virtual void slot36();
virtual const ForwardSpatialHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const ForwardSpatialVector&,int);
char unknown0C[0x428-0xC];ForwardSpatialLink*link;
};
struct ForwardSpatialPointerOwner{char unknown00[0x8];ForwardSpatialActor*actor;};
struct ForwardSpatialSystemGroup{char unknown00[0xB0];ForwardSpatialHandle*next;};
struct ForwardSpatialGroup{char unknown00[0x70];ForwardSpatialHandle actor;};
struct ForwardSpatialSystem{char unknown00[0x1C];ForwardSpatialHandle*handle;};
struct ForwardSpatialActorEntry{ForwardSpatialActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ForwardSpatialActorManager{char unknown00[8];ForwardSpatialActorEntry*entries;};
struct ForwardSpatialFrameEntry{ForwardSpatialFrame*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ForwardSpatialFrameManager{char unknown00[8];ForwardSpatialFrameEntry*entries;};
struct ForwardSpatialSystemGroupEntry{ForwardSpatialSystemGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ForwardSpatialSystemGroupManager{char unknown00[8];ForwardSpatialSystemGroupEntry*entries;};
struct ForwardSpatialGroupEntry{ForwardSpatialGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ForwardSpatialGroupManager{char unknown00[8];ForwardSpatialGroupEntry*entries;};
struct ForwardSpatialContext{char unknown00[0x118];ForwardSpatialActorManager*manager;char unknown11C[0x20];ForwardSpatialSystem*system;};
extern "C"ForwardSpatialContext lbl_801E9D24;
inline ForwardSpatialActor*resolveActor(const ForwardSpatialHandle&h){int index=h.index;ForwardSpatialActorManager*m=(ForwardSpatialActorManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline ForwardSpatialFrame*resolveFrame(const ForwardSpatialHandle&h){int index=h.index;ForwardSpatialFrameManager*m=(ForwardSpatialFrameManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline ForwardSpatialSystemGroup*resolveSystemGroup(const ForwardSpatialHandle&h){int index=h.index;ForwardSpatialSystemGroupManager*m=(ForwardSpatialSystemGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline ForwardSpatialGroup*resolveGroup(const ForwardSpatialHandle&h){int index=h.index;ForwardSpatialGroupManager*m=(ForwardSpatialGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C"unsigned long fn_801F7EB8(const ForwardSpatialHandle*);
inline ForwardSpatialActor*validResolve(const ForwardSpatialHandle&h){if(fn_801F7EB8(&h))return resolveActor(h);else return 0;}
extern "C"void fn_800AEBE8(ForwardSpatialPointerOwner*self){
ForwardSpatialHandle&handle=resolveGroup(*resolveSystemGroup(*lbl_801E9D24.system->handle)->next)->actor;
ForwardSpatialActor*actor=validResolve(handle);
ForwardSpatialFrame*frame=resolveFrame(*actor->slot37(0));
ForwardSpatialVector&v=actor->link->transform->position;
float vx=v.x,vy=v.y,vz=v.z;
float x=frame->axisX.x*vx+frame->axisY.x*vy+frame->axisZ.x*vz;
float y=frame->axisX.y*vx+frame->axisY.y*vy+frame->axisZ.y*vz;
float z=frame->axisX.z*vx+frame->axisY.z*vy+frame->axisZ.z*vz;
ForwardSpatialVector position(x,y,z);
ForwardSpatialVector&t=frame->transform->position;
position.add(t.x,t.y,t.z);
self->actor->slot45(position,0);
}

/* fn_800A1830: height follow. When a player resource exists (fn_8005E9A0),
   the target height is lbl_80378E48 plus the player's owner transform Y; the
   difference from the agent's query(0) transform Y steps toward the agent
   height (0x3E0) by step (0x3E4), clamped. The stepped position is written to
   the query(0) resource's desired vector (0xB8) and fn_8023DE28 is called;
   fn_800A4DF0 always runs. Declaring py,px,pz before the first Y local fixes
   the FPR assignment; assigning py, pz, px in that order fixes the load order. */
struct HeightFollowHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct HeightFollowVector{float x,y,z;HeightFollowVector(){}HeightFollowVector(float a,float b,float c):x(a),y(b),z(c){}HeightFollowVector&operator=(const HeightFollowVector&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct HeightFollowTransform{char unknown00[0x30];HeightFollowVector position;};
struct HeightFollowResource{char unknown00[0x58];HeightFollowHandle owner;char unknown5C[0x5C];HeightFollowVector desired;char unknownC4[0x60];HeightFollowTransform*transform;};
struct HeightFollowEntry{HeightFollowResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct HeightFollowManager{int count,capacity;HeightFollowEntry*entries;};
struct HeightFollowContext{char unknown00[0x118];HeightFollowManager*manager;};
extern "C" HeightFollowContext lbl_801E9D24;
inline HeightFollowResource*resolveHeightFollow(const HeightFollowHandle&h){HeightFollowEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct HeightFollowPrefix{char unknown00[8];};
struct HeightFollowAgent:HeightFollowPrefix{
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
virtual const HeightFollowHandle*getHandle(int);
char unknown0C[0x3D4];float height,step;};
struct HeightFollowAction{char unknown00[8];HeightFollowAgent*agent;};
extern "C"{HeightFollowResource*fn_8005E9A0();void fn_8023DE28(HeightFollowResource*);void fn_800A4DF0(HeightFollowAction*,float);extern const float lbl_80378E48;}

inline float heightFollowY(const HeightFollowVector&v){return v.y;}
extern "C" void fn_800A1830(HeightFollowAction*self,float delta){
if(fn_8005E9A0()){
float py,px,pz;float y=heightFollowY(resolveHeightFollow(fn_8005E9A0()->owner)->transform->position);
float difference=(lbl_80378E48+y)-resolveHeightFollow(*self->agent->getHandle(0))->transform->position.y;
if(difference!=self->agent->height){
if(difference<self->agent->height){difference+=self->agent->step;if(difference>self->agent->height)difference=self->agent->height;}
else if(difference>=self->agent->height){difference-=self->agent->step;if(difference<self->agent->height)difference=self->agent->height;}
const HeightFollowVector&s=resolveHeightFollow(*self->agent->getHandle(0))->transform->position;
py=s.y+difference;pz=s.z;px=s.x;
resolveHeightFollow(*self->agent->getHandle(0))->desired=HeightFollowVector(px,py,pz);
fn_8023DE28(resolveHeightFollow(*self->agent->getHandle(0)));
}}
fn_800A4DF0(self,delta);
}

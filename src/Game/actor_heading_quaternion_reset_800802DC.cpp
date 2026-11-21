/* fn_800802DC: clears actor vectors +0x144/+0x15C and the related scalar, then sets the
   quaternion at +0xC8 to a rotation about the up axis matching the resolved basis forward
   heading. Shared pooled labels: lbl_80378AA8 (0.0f), lbl_80378AAC (1.0f), lbl_80378AB4 (0.5f).
   Front-end CSE is off (pooled-literal load order); the context address shared by the two
   later resolves is an explicit local, as the original CSE kept it in r30. */
typedef unsigned long Word;
struct Handle {union {Word value;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{float x,y,z;Vec3(){}Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}void set(float a,float b,float c){x=a;y=b;z=c;}};
extern "C"{float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);}
struct Rotation{
 float w,x,y,z;
 Rotation(){}
 Rotation(float ax,float ay,float az,float half){w=fn_8028506C(half);float s=fn_80284FA8(half);x=ax*s;y=ay*s;z=az*s;}
};
struct Matrix{
 float m[9];
 Vec3 transform(float x,float y,float z)const{Vec3 o;o.x=m[0]*x+m[3]*y+m[6]*z;o.y=m[1]*x+m[4]*y+m[7]*z;o.z=m[2]*x+m[5]*y+m[8]*z;return o;}
};
struct Scalar{char unknown00[12];float value;};
struct Node;
struct Prefix{Word unknown00[2];};
struct Node:Prefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual void slot28();virtual void slot29();virtual void slot30();virtual void slot31();virtual void slot32();virtual void slot33();virtual void slot34();virtual void slot35();virtual void slot36();virtual const Handle*get(int);char unknown0C[0x30-0xC];Matrix basis;char unknown54[0x78-0x54];Scalar*scalar;char unknown7C[0xC8-0x7C];Rotation rotation;char unknownD8[0x144-0xD8];Vec3 vector144;char unknown150[12];Vec3 vector15C;Handle related;};
struct Self{Word unknown00[2];Node*node;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Node*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline Node*resolveIn(Context*c,const Handle&h){Entry*e=&c->manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C" {Node*fn_801F7EB8(const Handle*);extern const float lbl_80378AA8,lbl_80378AAC,lbl_80378AB4;}
#pragma opt_common_subs off
extern "C" void fn_800802DC(Self*self){
 self->node->vector144.set(lbl_80378AA8,lbl_80378AA8,lbl_80378AA8);
 self->node->vector15C.set(lbl_80378AA8,lbl_80378AA8,lbl_80378AA8);
 {Node*node=self->node;if(fn_801F7EB8(&node->related)){Scalar*s=resolve(node->related)->scalar;if(s)s->value=lbl_80378AA8;}}
 const Handle&h=*self->node->get(0);Context*ctx=&lbl_801E9D24;
 Vec3 forward=resolveIn(ctx,h)->basis.transform(lbl_80378AA8,lbl_80378AA8,lbl_80378AAC);
 float angle=fn_80285124(forward.x,forward.z);
 Node*node=resolveIn(ctx,*self->node->get(0));
 float half=angle*lbl_80378AB4;float cosine=fn_8028506C(half);float sine=fn_80284FA8(half);
 node->rotation.w=cosine;node->rotation.x=lbl_80378AA8*sine;node->rotation.y=lbl_80378AAC*sine;node->rotation.z=lbl_80378AA8*sine;
}
#pragma opt_common_subs reset

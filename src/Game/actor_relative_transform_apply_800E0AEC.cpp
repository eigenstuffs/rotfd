typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Vec{float x,y,z;Vec(){}Vec(float a,float b,float c):x(a),y(b),z(c){}Vec operator+(const Vec&v)const{return Vec(x+v.x,y+v.y,z+v.z);}};
struct Quat{float x,y,z,w;};
struct Basis;
extern "C"{void fn_801F2170(Basis*,const Basis*,const Basis*);Quat*fn_801F20F4(Quat*,const Basis*);}
struct Basis{float m[9];
Vec operator*(const Vec&v)const{Vec r;r.x=m[0]*v.x+m[3]*v.y+m[6]*v.z;r.y=m[1]*v.x+m[4]*v.y+m[7]*v.z;r.z=m[2]*v.x+m[5]*v.y+m[8]*v.z;return r;}
Basis operator*(const Basis&b)const{Basis r;fn_801F2170(&r,this,&b);return r;}
};
struct Transform{char unknown00[0x30];Vec position;};
struct NodePrefix{Word unknown00,unknown04;};
struct Node:NodePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40(int);virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle_801F7F10*slot9C(int);virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0(const Vec*,const Quat*,int);
char unknown0C[0x24];Basis rotation;char unknown54[0x1C];Handle_801F7F10 actor;char unknown74[0x3C];Handle_801F7F10*child;char unknownB4[0x70];Transform*transform;};
struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown00[0x1C];Handle_801F7F10*handle;};
extern "C"struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
extern "C"{void*fn_801F7EB8(const Handle_801F7F10*);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*actor(){const Handle_801F7F10&h=resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;if(fn_801F7EB8(&h))return resolve(h);return 0;}
struct Owner{virtual void slot08();virtual void reset();unsigned char enabled;char unknown05[3];Node*node;char unknown0C[4];Node*resource;Node*target;Node*actor;Vec offset;};
extern "C"void fn_800E0AEC(Owner*self){
if(actor()!=self->actor)self->reset();
Transform*transform=self->resource->transform;
float z=transform->position.z,x=transform->position.x,y=transform->position.y;
Basis rotation=self->target->rotation;
x+=self->offset.x;y+=self->offset.y;z+=self->offset.z;
Vec rotated=rotation*Vec(x,y,z);
Transform*base=self->target->transform;
Vec position=Vec(base->position.x,base->position.y,base->position.z)+rotated;
Basis resourceRotation=self->resource->rotation;
Basis product=rotation*resourceRotation;
Quat q;fn_801F20F4(&q,&product);
self->node->slotC0(&position,&q,0);
}

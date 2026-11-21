/* Scene owner actor target/optional sync (fn_8003543C). */
struct Handle{signed int tag:8;signed int index:24;};
/* Second handle view: the final lookup reads the owner handle through a distinct
   handle type, which keeps the compiler from reusing the earlier bitfield reads. */
struct ActorHandle{signed int tag:8;signed int index:24;};
struct Vec{float x,y,z;Vec(){}Vec(float xx,float yy,float zz):x(xx),y(yy),z(zz){}Vec&operator=(const Vec&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct Transform{char unknown00[0x30];Vec position;};
struct Prefix{char unknown00[8];};
struct Optional{char unknown00[0xC];float value;};
struct Actor:Prefix{
virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();
virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();
virtual void s20();virtual void s21();virtual void s22();virtual void s23();virtual void s24();virtual void s25();virtual void s26();virtual void s27();virtual void s28();virtual void s29();
virtual void s30();virtual void s31();virtual void s32();virtual void s33();virtual void s34();virtual void s35();virtual void s36();
virtual const Handle*slot9C(int);
char unknown0C[0x24];unsigned long long flags;char unknown38[0x40];Optional*optional78;char unknown7C[0xA8];Transform*transform;char unknown128[0x40];Handle relatedTarget;char unknown16C[0x1AC];char component318[0xD8];Vec targetPosition;float optionalValue;
};
struct Entry{Actor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
struct Context{char unknown00[0x118];Manager*manager;};
extern "C" Context lbl_801E9D24;
inline Actor*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline Actor*resolve(const ActorHandle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct Owner{char unknown00[0x70];Handle handle;const ActorHandle&actorHandle()const{return*(const ActorHandle*)&handle;}};
extern "C"{void fn_8025A0A4(Owner*,int);void fn_8007D6A0(void*,int);}
extern "C" void fn_8003543C(Owner*self,int value){
fn_8025A0A4(self,value);
const Vec&source=resolve(*resolve(self->handle)->slot9C(0))->transform->position;
Vec position(source.x,source.y,source.z);
resolve(self->handle)->targetPosition=position;
fn_8007D6A0(resolve(self->handle)->component318,3);
resolve(self->handle)->flags|=0x200ULL;
Optional*optional=resolve(resolve(self->handle)->relatedTarget)->optional78;
if(optional)resolve(self->actorHandle())->optionalValue=optional->value;
}

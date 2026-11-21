/* Original actor quaternion/action control; see docs/notes/game-actor-quaternion-action.md. */
struct Handle {union{unsigned long value;struct{signed int tag:8,index:24;}bits;};};struct Matrix {float values[9];};struct Entity {char unknown0[0x2C];float angle;Matrix basis;};struct Entry {Entity*object;char unknown4[8];signed char tag;char unknownD[3];int getTag()const{return tag;}};struct Manager {int count,capacity;Entry*entries;};extern "C" struct Context {char unknown0[0x118];Manager*manager;}lbl_801E9D24;
inline Entity*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline unsigned long resolveWord(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?(unsigned long)m->entries[index].object:0;}
struct Prefix {char unknown0[8];};struct Self:Prefix {virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual void slot28();virtual void slot29();virtual void slot30();virtual void slot31();virtual void slot32();virtual void slot33();virtual void slot34();virtual void slot35();virtual void slot36();virtual Handle*slot37(int); char unknownC[0x24-0xC];Handle actor;char unknown28[0x318-0x28];char component;char unknown319[0x348-0x319];Handle event;char unknown34C[0x449-0x34C];signed char active;};
struct Quaternion {float w,x,y,z;Quaternion(float ww,float xx,float yy,float zz):w(ww),x(xx),y(yy),z(zz){}};
extern "C" {signed char fn_8025E9FC(Entity*,int);float fn_8028506C(float);float fn_80284FA8(float);void fn_801F1CD8(const Quaternion*,Matrix*);void fn_8023DE28(Entity*);void fn_802073E8(Entity*,int,Entity*,float);void fn_8007D6A0(void*,int);extern const float lbl_80378BEC,lbl_80378BAC,lbl_80378BE8,lbl_80378C20;}
extern "C" void fn_8009332C(Self*self) {
 Entity*actor=resolve(self->actor);
 if(fn_8025E9FC(actor,0x91)) {
  float angle=actor->angle*lbl_80378BEC;float cosine=fn_8028506C(angle);float sine=fn_80284FA8(angle);
  Quaternion q(cosine,lbl_80378BAC*sine,lbl_80378BE8*sine,lbl_80378BAC*sine);Matrix matrix;fn_801F1CD8(&q,&matrix);
  resolve(*self->slot37(0))->basis=matrix;
  fn_8023DE28(resolve(*self->slot37(0)));self->active=1;
 }
 if(fn_8025E9FC(actor,0x97)) {fn_802073E8(actor,0x65,(Entity*)resolveWord(self->event),lbl_80378C20);fn_8007D6A0(&self->component,0xB);}
}

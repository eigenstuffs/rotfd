/* Scene reinitialization through native four-byte mode-key and Handle APIs.
 * Partial object views describe observed fields and virtual entry ABIs. */
typedef unsigned long Word;
struct Handle_801F7F10 {union {Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ModeKey{Word word;};
struct Node;struct Target;
struct Entry {void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}bool matchesTag(signed char t)const{return tag==t;}};
struct Manager {char unknown00[8];Entry*entries;};
struct Service {char unknown00[0x1C];Handle_801F7F10*handle;};
struct Config {char unknown00[0x100];int delay;};
struct World {char unknown00[0x15058];Config*config;void*card;};
struct Globals {char unknown00[0x110];void*console;char unknown114[4];Manager*manager;char unknown11C[8];World*world;char unknown128[0x14];Service*service;};
extern "C" {extern Globals lbl_801E9D24;extern ModeKey lbl_803777D0;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);Word fn_801F7EB8(const Handle_801F7F10*);Word fn_801F948C(void*,const char*);}
struct Zero1_BD6A8:Handle_801F7F10{Zero1_BD6A8(){word=0;}~Zero1_BD6A8(){}};
struct Zero2_BD6A8:Zero1_BD6A8{Zero2_BD6A8(){word=0;}~Zero2_BD6A8(){}};
struct Zero3_BD6A8:Zero2_BD6A8{Zero3_BD6A8(){word=0;}~Zero3_BD6A8(){}};
struct Handle_80025BF4:Zero3_BD6A8{Handle_80025BF4(){word=0;}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025B74:Handle_80025BF4 {Handle_80025B74(){word=0;}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_80025B74&operator=(const Handle_801F7F10&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct Handle_8002B67C:Handle_801F7F10 {Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct SceneCardReturn_BD6A8:Handle_801F7F10 {~SceneCardReturn_BD6A8(){}};
struct Name {Word word;Name(const char*s){word=fn_801F948C(this,s);}Name(Word n):word(n){}};
struct Point {float x,y,z;};struct Rotation{float x,y,z,w;};
extern "C" {extern const Point lbl_80306E08;extern const Rotation lbl_80306E14;extern const char lbl_802A13F4[],agent_type_registry_CGCMemCardAgent[];}
struct Prefix{Word unknown00,unknown04;};
struct Node:Prefix {
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
virtual void slot9C();
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void slotBC();
virtual void slotC0(const Point*,const Rotation*,int);
char unknown0C[0xA4-0xC];Handle_801F7F10*selected;char unknownA8[8];Handle_801F7F10*child;
};
struct Target:Prefix {
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
virtual void slot9C();
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void slotBC();
virtual void slotC0();
};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?static_cast<Node*>(m->entries[index].object):0;}
inline Node*current(){return resolve(*lbl_801E9D24.service->handle);}

inline Node*resolveSelection(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;int index=h.bits.index;int tag=m->entries[index].getTag();Node*result=0;if(tag==h.bits.tag)result=static_cast<Node*>(m->entries[index].object);return result;}
inline Node*selection(){return resolveSelection(*lbl_801E9D24.service->handle);}
inline Target*relatedChild(){const Handle_801F7F10&source=*lbl_801E9D24.service->handle;Handle_8002B67C held(source);if(fn_801F7EB8(&held)){const Handle_801F7F10&child=*resolve(held)->child;if(fn_801F7EB8(&child))return (Target*)resolve(child);}return 0;}
extern "C" {signed char fn_802017D8(Node*,int,ModeKey,int);void fn_801FEF6C(Service*,int);void fn_802603A0(World*,int,Target*,float);void fn_80057100(Config*,int);void fn_802020AC(Node*);void fn_801FA014(void*,const char*,...);SceneCardReturn_BD6A8 fn_80260868(World*,const Name&,const char*);}
extern "C"void fn_800BD6A8(World*self){
{Node*parent=current();fn_802017D8(parent,1,lbl_803777D0,0);}
Handle_80025B74 selected;const Handle_801F7F10&source=*selection()->selected;selected=source;
resolve(selected)->slotC0(&lbl_80306E08,&lbl_80306E14,0);
fn_801FEF6C(lbl_801E9D24.service,0);
Target*target=relatedChild();
fn_802603A0(lbl_801E9D24.world,0x57,target,(float)self->config->delay);
fn_80057100(self->config,-1);
target->slotC0();
fn_802020AC(current());
if(!self->card){fn_801FA014(lbl_801E9D24.console,lbl_802A13F4);Node*card=resolve(fn_80260868(lbl_801E9D24.world,Name(agent_type_registry_CGCMemCardAgent),0));lbl_801E9D24.world->card=card;}
}

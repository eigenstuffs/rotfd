typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};struct GroupService{char unknown00[8];Handle_801F7F10*state;};
extern "C"struct Context{char unknown00[0x118];Manager*manager;GroupService*groups;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);}
struct Node{char unknown00[4];Handle_801F7F10 self;char unknown08[0xB4];unsigned short flagsBC;char unknownBE[0x62];Word flags120;};
struct Actor{char unknown00[8];virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void stop30();char unknown0C[0x2C];unsigned long long flags38;char unknown40[0x18];Handle_801F7F10 related58;};
struct State{char unknown00[0x45];unsigned char active45;char unknown46[0x112];signed char selected158;};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80066960:Handle_801F7F10{Handle_80066960(const Handle_80066960&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80066960(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"{State*fn_8005EE10(Actor*);const Handle_80066960&fn_80268080(Node*,const Handle_80020B90&);void fn_8006B470(void*,Node*,int);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct FlagHandleView_6AE80{union{Word word;struct{signed int tag:8,index:24;}bits;};};
inline Node*resolveFlags(const FlagHandleView_6AE80&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Word resolveWord(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?(Word)m->entries[index].object:0;}
extern "C"void fn_8006AE80(void*self,Actor*actor){State*state=fn_8005EE10(actor);if(!state->active45){state->active45=1;actor->flags38|=0x40000ULL;if(resolveFlags(*(const FlagHandleView_6AE80*)&actor->related58)->flags120&0x80){const Handle_801F7F10&original=resolve(actor->related58)->self;Handle_80066960 h(fn_80268080(resolve(*lbl_801E9D24.groups->state),Handle_80020B90(original)));int selected=resolve(h)->flagsBC&1;state->selected158=selected;if((signed char)selected)fn_8006B470(self,(Node*)resolveWord(actor->related58),0);}actor->stop30();}}

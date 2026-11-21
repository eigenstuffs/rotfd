/* Actor event dispatcher fn_800410E4: selection/flag events, queued DD resource
 * events and event 57's time conversion, then the base event loop fn_8002BAB4.
 * Prior research: scratch/engine_actor_event_dispatch_20261011ks/FINDINGS.md. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Name{Word word;Name(const char*);Name(const Name&n){word=n.word;}};
struct Prefix{char unknown00[8];};
struct Node:Prefix{
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
virtual void slot78(Node*,Word);
char unknown0C[0x318-0xC];char control[0x407-0x318];unsigned char flag407,flag408,flag409,flag40A,flag40B,flag40C,flag40D,flag40E,flag40F,flag410,flag411;char unknown412[0x458-0x412];float value458;void apply(const Handle_801F7F10&,const Word&);};
struct Owner:Prefix{
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
virtual int key();
char unknown0C[0x2C-0xC];float time;char unknown30[0x58-0x30];Handle_801F7F10 target58;char unknown5C[0x70-0x5C];Handle_801F7F10 actor70;char unknown74[0x80-0x74];Handle_801F7F10 target80;int mode84;char unknown88[4];void*resource8C;};
struct Primary{char unknown00[0x60];Handle_801F7F10 handle60;};struct Scene{char unknown00[0x15058];Primary*primary;};struct Slot{int key;};struct UI{char unknown00[0x1C];Slot*current;const int&get(int index){return current[index].key;}char unknown20[0xD];signed char enabled2D;};struct Mode{char unknown00[0xD0];int state;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
extern "C"struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x3C];UI*ui;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F948C(Name*,const char*);}
inline Name::Name(const char*s){word=fn_801F948C(this,s);}
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ZeroHandle_800410E4:Handle_801F7F10{ZeroHandle_800410E4(){word=0;}~ZeroHandle_800410E4(){}};
struct Handle_80020834:ZeroHandle_800410E4{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8003E120:Handle_80020834{Handle_8003E120(const Handle_8003E120&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8003E120(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"{signed char fn_8025E9FC(Owner*,int);void fn_80041B7C(Owner*);signed char fn_8007D604(void*,int);Mode*fn_8007D074();signed char fn_8006E7F4();Handle_8003E120 fn_800BCF58(Scene*,const Handle_801F7F10&);Word fn_801F7EB8(const Handle_801F7F10*);signed char fn_80206A20(Node*);int fn_80030E9C(Node*,int,int);void fn_800B6C84(UI*,int,Word);void fn_800A6234(Node*,int,Name);void fn_80285ED8(Owner*,int,int);extern int lbl_803777B0;extern Word lbl_803777BC;extern const float lbl_80378528,lbl_80378540;extern const char lbl_8037853C[4];}
struct Return_800410E4:ZeroHandle_800410E4{~Return_800410E4(){}};
struct Event{char unknown00[8];Name name;char unknown0C[0x18];Word value;};
extern "C"{Event*fn_8025E548(Owner*);Return_800410E4 fn_80058778(Primary*,const Name&,signed char);void fn_802554F4(Node*);void fn_80286058(Owner*,int);void fn_800944A0(Node*,int);void fn_8002BAB4(Owner*);}
inline Word resolveAddress(const Handle_801F7F10&h){return (Word)resolve(h);}
inline void Node::apply(const Handle_801F7F10&h,const Word&value){slot78((Node*)resolveAddress(h),value);}
extern "C"void fn_800410E4(Owner*self){
 if(fn_8025E9FC(self,0xBF)||fn_8025E9FC(self,0xC0))fn_80041B7C(self);
 if(fn_8025E9FC(self,0x55)&&lbl_801E9D24.ui->get(0)==lbl_803777B0&&!fn_8007D604(resolve(self->actor70)->control,0x2C)&&!fn_8007D604(resolve(self->actor70)->control,0x2D)&&!fn_8007D604(resolve(self->actor70)->control,0x2E)&&!fn_8007D604(resolve(self->actor70)->control,6)&&lbl_801E9D24.ui->enabled2D&&(fn_8007D074()->state!=4||fn_8006E7F4())&&resolve(self->actor70)->value458<=lbl_80378528){
  const Handle_801F7F10&source=self->target80;Handle_8002B67C held(source);Handle_8003E120 target(fn_800BCF58(lbl_801E9D24.scene,held));
  if(fn_801F7EB8(&target)&&fn_80206A20(resolve(self->target80))){Node*node=resolve(target);if((signed char)fn_80030E9C(node,self->key(),0))fn_800B6C84(lbl_801E9D24.ui,self->key(),lbl_803777BC);}
 }
 if(fn_8025E9FC(self,0xCD)){Node*selected=resolve(lbl_801E9D24.scene->primary->handle60);fn_800A6234(selected,0,Name(Name(lbl_8037853C)));}
 if(fn_8025E9FC(self,0x77))resolve(self->actor70)->flag40D=1;
 if(fn_8025E9FC(self,0x9E))resolve(self->actor70)->flag407=1;
 if(fn_8025E9FC(self,0x7B))resolve(self->actor70)->flag408=1;
 if(fn_8025E9FC(self,0x79))resolve(self->actor70)->flag409=1;
 if(fn_8025E9FC(self,0x7E))resolve(self->actor70)->flag40B=1;
 if(fn_8025E9FC(self,0x76))resolve(self->actor70)->flag40C=1;
 if(fn_8025E9FC(self,0x78))resolve(self->actor70)->flag40E=1;
 if(fn_8025E9FC(self,0x7D))resolve(self->actor70)->flag40F=1;
 if(fn_8025E9FC(self,0x7C))resolve(self->actor70)->flag410=1;
 if(fn_8025E9FC(self,0x9D))resolve(self->actor70)->flag411=1;
 if(fn_8025E9FC(self,0x74)){fn_80285ED8(self,0x74,0);*((unsigned char*)resolve(self->actor70)+0x404)=0;}
 if(fn_8025E9FC(self,0xDD)&&self->mode84==1)while(fn_8025E9FC(self,0xDD)){
  if(self->time>=lbl_80378540&&self->resource8C)return;
  Event*event=fn_8025E548(self);Node*resource=resolve(fn_80058778(lbl_801E9D24.scene->primary,event->name,0));if(resource){resource->apply(self->target58,event->value);fn_802554F4(resource);}fn_80286058(self,0xDD);
 }
 if(fn_8025E9FC(self,0x57)){int value=(int)self->time;fn_800944A0(resolve(self->actor70),value);}
 fn_8002BAB4(self);
}

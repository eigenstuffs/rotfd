/* Ordinary scene lifetime routine; see docs/notes/game-scene-selected-record.md. */
typedef unsigned long Word;typedef unsigned long long Wide;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};
struct Service{char unknown00[0x1C];Handle_801F7F10*handle;};
extern "C"struct Global{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Service*service;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];extern const float lbl_8037859C;void fn_8007D6A0(void*,int);}
struct SceneRecordZero_57E40:Handle_801F7F10{SceneRecordZero_57E40(){word=0;}~SceneRecordZero_57E40(){}};
struct Handle_80021BCC:SceneRecordZero_57E40{Handle_80021BCC(){word=0;}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021B54:Handle_80021BCC{Handle_80021B54(){word=0;}Handle_80021B54(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80021B54(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_80021B54&operator=(const Handle_80021B54&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return *this;}};
struct Handle_80025BF4:Handle_80021B54{Handle_80025BF4(){word=0;}Handle_80025BF4(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025B74:Handle_80025BF4{Handle_80025B74(){word=0;}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80038014:Handle_80025B74{Handle_80038014(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80038014(const Handle_80038014&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80038014(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Point{float x,y,z;};
struct Record_800218F8{char unknown00[0x5C];Point point;char unknown68[0x24];Handle_80021B54 first,second;Record_800218F8();~Record_800218F8(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Prefix{Word unknown00;Handle_801F7F10 handle04;};
struct Node:Prefix{
virtual void v08();
virtual void v0C();
virtual void v10();
virtual void v14();
virtual void v18();
virtual void v1C();
virtual void v20();
virtual void v24();
virtual void v28();
virtual void v2C();
virtual void v30();
virtual void v34();
virtual void v38();
virtual void v3C();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4C();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5C();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6C();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7C();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8C();
virtual void v90();
virtual void v94();
virtual void v98();
virtual const Handle_801F7F10*getChild(int);
virtual void vA0();
virtual void vA4();
virtual void vA8();
virtual void vAC();
virtual void vB0();
virtual void vB4();
virtual void vB8();
virtual void vBC();
virtual void vC0();
virtual void vC4();
virtual void vC8();
virtual void vCC();
virtual void vD0();
virtual void vD4();
virtual void vD8();
virtual void vDC();
virtual void vE0();
virtual void vE4();
virtual void vE8();
virtual void vEC();
virtual void vF0();
virtual void vF4();
virtual void vF8();
virtual void vFC();
virtual void v100();
virtual void v104();
virtual void v108();
virtual void v10C();
virtual void v110();
virtual void v114();
virtual void v118();
virtual void v11C();
virtual void apply(Record_800218F8*);
char unknown0C[0x24];Wide flags30;char unknown38[0x38];Handle_801F7F10 actor70;char unknown74[0x3C];Handle_801F7F10*childB0;char unknownB4[0x6C];Word flags120;char unknown124[0x88];Handle_801F7F10 target1AC;char unknown1B0[0x168];char counter318[4];};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline const Handle_801F7F10&getActorHandle(){return resolve(*resolve(*lbl_801E9D24.service->handle)->childB0)->actor70;}
inline Node*getActor(){const Handle_801F7F10&h=getActorHandle();if(fn_801F7EB8(&h))return resolve(h);return 0;}
extern "C"void fn_80057E40(void*){
 Node*actor=resolve(getActorHandle());
 if(fn_801F7EB8(&actor->target1AC)){
  const Handle_801F7F10&original=actor->target1AC;Handle_80025BF4 first(original);
  Handle_80038014 target((Handle_80038014(first)));
  Record_800218F8 record;
  record.point.x=lbl_8037859C;record.point.y=lbl_8037859C;record.point.z=lbl_8037859C;
  record.first=Handle_80021B54(getActor()->handle04);
  resolve(target)->apply(&record);
  resolve(*resolve(target)->getChild(0))->flags120|=0x40000UL;
  resolve(target)->flags30&=~0x200ULL;
  fn_8007D6A0(resolve(target)->counter318,2);
 }
}

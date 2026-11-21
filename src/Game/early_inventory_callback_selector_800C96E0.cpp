// Isolated exact aggregate; integration blocked on original secondary-label caller migration.
typedef unsigned long Word;
struct MemberPointer{Word a,b,c;};
struct Callback{char unknown00[0x28];unsigned short flags;short index;};
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Node{char unknown00[0x24];Handle inventory;char unknown28[0x48];Handle actor;char unknown74[0x10];int count;char unknown88[0x28];Handle*child;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown00[0x1C];Handle*handle;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
inline Word resolveValue(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return(Word)m->entries[index].object;return 0;}
struct Owner{char unknown00[0x68];signed char enabled;char unknown69[0xB];float time;char unknown78;unsigned char state;int getState()const{return state;}};
extern "C"{struct Pool{MemberPointer header[2];MemberPointer entries[5];};extern Pool lbl_802C13A8;extern Word lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,Word);void fn_8025F620(Callback*,Word);signed char fn_8025E9FC(Owner*,int);void fn_8025F4F4(Callback*,int,const char*);extern const char lbl_802A2808[];extern const float lbl_80379644;Word fn_801F7EB8(const Handle*);void fn_802073E8(Owner*,int,void*,float);void fn_802073BC(Owner*,int,void*,float,float);}
extern "C" Pool lbl_802C13A8 = {{{0,0x8C,8},{0,0x90,8}},{{0,0x90,8},{0,0x90,8},{0,0x90,8},{0,0x90,8},{0,0x90,8}}};
extern "C"int fn_800C96E0(Owner*self,int event,Callback*callback){
 const Pool*members=&lbl_802C13A8;int result=1;
 switch(event){
 case 0:fn_8025EF34(self,members->entries[0],-1);return 1;
 case 1:fn_8025EEB4(self,members->entries[1]);return 1;
 case 2:fn_8025EB70(self,members->entries[2]);return 1;
 case 3:if(callback)return(signed char)((callback->flags>>2)&1);callback=fn_8025F074(self,members->entries[3]);if(callback)return(signed char)((callback->flags>>2)&1);return 0;
 case 4:if(callback)return(signed char)(callback->flags&1);callback=fn_8025F074(self,members->entries[4]);if(callback)return(signed char)(callback->flags&1);return 0;
 case 5:return 1;
 case 6:if(callback)return callback->index;return -9999;
 }
 lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
 if(event==8||event==7)fn_8025F4F4(callback,0,lbl_802A2808);
 if(event==11&&callback->index==-1)return 1;
 fn_8025F658(callback,lbl_80378090);
 int action;if(event>=14)action=event+callback->index*2;else action=event;
 switch(action){
 case 7:fn_8025F694(callback,lbl_8037808C);
 case 8:break;
 case 14:result=fn_8025E9FC(self,0x8F)&&self->enabled;break;
 case 15:if(self->getState()==1){
  const Handle*h=&resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;
  Node*actor;if(fn_801F7EB8(h))actor=resolve(*h);else actor=0;
  Node*inventory=(Node*)resolveValue(actor->inventory);
  if(inventory->count<=0){fn_802073E8(self,0x8B,self,lbl_80379644);return 1;}
  fn_802073BC(self,0x8F,self,self->time,lbl_80379644);
  fn_802073E8(self,0x87,inventory,lbl_80379644);
 }break;
 default:result=2;break;
 }
 fn_8025F620(callback,lbl_80378090);return result;
}

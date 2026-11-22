typedef unsigned long Word;
struct MemberPointer{Word a,b,c;};
struct Callback{char unknown00[0x28];unsigned short flags;short index;};
extern "C" {extern const struct SelectorPool{char unknown00[0x70];MemberPointer entries[5];}lbl_802AFBA0;extern Word lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,Word);void fn_8025F620(Callback*,Word);}
struct Handle_801F7F10{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct SelectorPrefix{char unknown00[8];};
struct SelectorResource:SelectorPrefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void stop(int);virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual signed char ready();
char unknown0C[0x14];Handle_801F7F10 related;char unknown24[0x10C];Handle_801F7F10 child;
};
struct SelectorEntry{SelectorResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SelectorManager{int count,capacity;SelectorEntry*entries;};
extern "C" struct SelectorContext{char unknown00[0x118];SelectorManager*manager;}lbl_801E9D24;
inline SelectorResource*resolve(const Handle_801F7F10&h){int index=h.bits.index;SelectorManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct SelectorVector{float x,y,z;};
struct SelectorOwner{char unknown00[0x38];unsigned long long flags;char unknown40[0x48];Handle_801F7F10 resource;char unknown8C[0x20];SelectorVector position;};
extern "C"{Word fn_801F7EB8(const Handle_801F7F10*);void fn_8023D100(SelectorResource*,const SelectorVector*);signed char fn_8025E9FC(SelectorOwner*,int);}

/* Five complete original member-pointer records preceding the switch. */
extern "C" MemberPointer lbl_802AFC10[5] = {
    {0,0x9C,8},
    {0,0x9C,8},
    {0,0x9C,8},
    {0,0x9C,8},
    {0,0x9C,8},
};

extern "C" int fn_8002264C(SelectorOwner*self,int event,Callback*callback){
 const SelectorPool*members=&lbl_802AFBA0;int result=1;
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
 if(event==11&&callback->index==-1)return 1;
 fn_8025F658(callback,0);
 int action;if(event>=14)action=event+callback->index*2;else action=event;
 switch(action){
 case 7:fn_8025F694(callback,lbl_8037808C);
 case 8:break;
 case 10:if(fn_801F7EB8(&self->resource)){
  if(!resolve(resolve(self->resource)->child)->ready()){
   resolve(resolve(self->resource)->related)->stop(-1);
   fn_8023D100(resolve(self->resource),&self->position);
  }
 }break;
 case 11:result=fn_8025E9FC(self,0xAC);break;
 case 12:self->flags&=~0x20000ULL;callback->flags&=0xFFFB;break;
 default:result=2;break;
 }
 fn_8025F620(callback,lbl_80378090);return result;
}

typedef unsigned long Word;
struct MemberPointer{Word a,b,c;};
struct Callback{char unknown00[0x28];unsigned short flags;short index;};
extern "C" {extern const struct RecordSelectorPool{char unknown00[0x590];MemberPointer entries[5];}lbl_802B3708;extern Word lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,Word);void fn_8025F620(Callback*,Word);}
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10{unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct ModeHandleZero_4B984:Handle_801F7F10{ModeHandleZero_4B984(){value=0;}~ModeHandleZero_4B984(){}};
struct Manager;extern "C"struct Context{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
extern "C"void fn_801F86C8(Manager*,const Handle_801F7F10*,int);
struct Handle_80020B90:ModeHandleZero_4B984{Handle_80020B90(){value=0;}~Handle_80020B90(){}void assign(const Handle_801F7F10&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct SelectorPrefix{char unknown00[8];};
struct Selector:SelectorPrefix{
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
virtual void select94(int,int);virtual void select98(int,int);virtual const Handle_801F7F10&get9C(int);
char unknown0C[0x54];unsigned char state60;char unknown61[3];int mode64;char unknown68[8];unsigned char state70,state71,count72;
};
extern "C"{void fn_8025F4F4(Callback*,int,const char*);extern const char lbl_8029AAF8[];float fn_8025E268(Selector*,int);const Handle_801F7F10*fn_8025E1D4(Selector*,int);unsigned long fn_801F7EB8(const Handle_801F7F10*);}
extern "C"MemberPointer lbl_802B3C98[5]={{0,0x9C,8},{0,0x9C,8},{0,0x9C,8},{0,0x9C,8},{0,0x9C,8}};
extern "C" int fn_8004B984(Selector*self,int event,Callback*callback){
 const RecordSelectorPool*members=&lbl_802B3708;int result=1;
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
 if(event==8||event==7)fn_8025F4F4(callback,0,lbl_8029AAF8);
 if(event==11&&callback->index==-1)return 1;
 fn_8025F658(callback,lbl_80378090);
 int action;if(event>=14)action=event+callback->index*2;else action=event;
 switch(action){
 case 7:fn_8025F694(callback,lbl_8037808C);
 case 8:break;
 case 15:{
  self->mode64=(unsigned char)(int)fn_8025E268(self,0);
  self->state60=(int)fn_8025E268(self,1);
  self->state70=(int)fn_8025E268(self,2);
  self->state71=(int)fn_8025E268(self,3);
  Handle_80020B90 handle;
  for(unsigned char i=0;i<=9;++i){handle.assign(*fn_8025E1D4(self,i));if(fn_801F7EB8(&handle))++self->count72;}
  switch(self->mode64){case 0:self->select94(0,0);self->select98(0,0);break;case 1:self->select94(0,0);self->select98(1,0);break;case 2:self->select98(0,0);self->select94(1,0);break;default:self->select94(0,0);self->select98(0,0);break;}
  callback->flags&=0xFFFB;
 }break;
 default:result=2;break;
 }
 fn_8025F620(callback,lbl_80378090);return result;
}

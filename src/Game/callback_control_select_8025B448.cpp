// Native callback control event dispatcher. The partial class view preserves
// the original vptr at 0x08, Handle fields, and 64-bit state at 0x38.
// Its category strings and switch tables are compiler-generated local objects.
// The original final rodata zero byte remains outside this source unit.
typedef unsigned long Word;typedef unsigned long long Wide;
struct MemberPointer{Word a,b,c;};
struct Callback{char unknown00[0x28];unsigned short flags;short index;};
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Prefix{char unknown00[8];};
struct Selector:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9C();virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual void slotE4();virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();virtual void slotF8();virtual void slotFC();virtual void slot100();virtual void slot104();virtual void slot108();virtual void slot10C();virtual void slot110();virtual void slot114();virtual void slot118();virtual void slot11C();virtual void slot120();virtual void slot124();
char unknown0C[0x1C];Handle_801F7F10 handle28;char unknown2C[0xC];Wide flags;char unknown40[0x30];Handle_801F7F10 related;
};
struct Entry{Selector*object;char unknown04[8];signed char tag;char unknown0D[3];};struct Manager{char unknown00[8];Entry*entries;};
extern "C" {
extern struct Context{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
extern struct MemberPool{MemberPointer entries[6];}lbl_802ECBB8={{{0,0x7C,8},{0,0x7C,8},{0,0x7C,8},{0,0x7C,8},{0,0x7C,8},{0,0x7C,8}}};
extern Word lbl_8037808C,lbl_80378090;extern int lbl_80378094;
void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);
void fn_8025F4F4(Callback*,int,const char*);void fn_8025F3C8(Callback*,int,const char*);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,Word);void fn_8025F620(Callback*,Word);signed char fn_8025E9FC(void*,int);
void fn_801F86C8(Manager*,const Handle_801F7F10*,short);Word fn_801F7EB8(const Handle_801F7F10*);
}

extern "C" {
void fn_80020FE8(void*);
void slot0C__12BaseObject_ZFUl(void*);
void slot10__12BaseObject_ZFv(void*);
void slot14__12BaseObject_ZFv(void*);
void fn_8025BBA8(void*);
void fn_80259F0C(void*);
void fn_8025B2FC(void*);
void fn_8025B304(void*);
void fn_8025B30C(void*);
void fn_8025B388(void*);
void fn_8025A244(void*);
void fn_8025A190(void*);
void fn_8025BB68(void*);
void fn_8025A324(void*);
void fn_8025A0A4(void*);
void fn_80259FB4(void*);
void fn_8002392C(void*);
void fn_80023934(void*);
void fn_8002393C(void*);
void fn_8025BAF4(void*);
void fn_8025BAD4(void*);
void fn_8002390C(void*);
void fn_80023914(void*);
void fn_80257C58(void*);
void fn_80257C50(void*);
void fn_80256028(void*);
void fn_80023944(void*);
void fn_80023928(void*);
void fn_8025A5F8(void*);
int fn_8025B448(Selector*,int,Callback*);
void fn_8025BB14(void*);
void fn_8002391C(void*);
void fn_80023920(void*);
void fn_80023924(void*);
void fn_8025B928(void*);
struct CallbackControlDispatchTable {
const void* typeInfo;
long displacement;
void (*slot8)(void*);
void (*slotC)(void*);
void (*slot10)(void*);
void (*slot14)(void*);
void (*slot18)(void*);
void (*slot1C)(void*);
void (*slot20)(void*);
void (*slot24)(void*);
void (*slot28)(void*);
void (*slot2C)(void*);
void (*slot30)(void*);
void (*slot34)(void*);
void (*slot38)(void*);
void (*slot3C)(void*);
void (*slot40)(void*);
void (*slot44)(void*);
void (*slot48)(void*);
void (*slot4C)(void*);
void (*slot50)(void*);
void (*slot54)(void*);
void (*slot58)(void*);
void (*slot5C)(void*);
void (*slot60)(void*);
void (*slot64)(void*);
void (*slot68)(void*);
void (*slot6C)(void*);
void (*slot70)(void*);
void (*slot74)(void*);
void (*slot78)(void*);
int (*slot7C)(Selector*,int,Callback*);
void (*slot80)(void*);
void (*slot84)(void*);
void (*slot88)(void*);
void (*slot8C)(void*);
void (*slot90)(void*);
};
CallbackControlDispatchTable lbl_802ECC00={
0,
0,
fn_80020FE8,
slot0C__12BaseObject_ZFUl,
slot10__12BaseObject_ZFv,
slot14__12BaseObject_ZFv,
fn_8025BBA8,
fn_80259F0C,
fn_8025B2FC,
fn_8025B304,
fn_8025B30C,
fn_8025B388,
fn_8025A244,
fn_8025A190,
fn_8025BB68,
fn_8025A324,
fn_8025A0A4,
fn_80259FB4,
fn_8002392C,
fn_80023934,
fn_8002393C,
fn_8025BAF4,
fn_8025BAD4,
fn_8002390C,
fn_80023914,
fn_80257C58,
fn_80257C50,
fn_80256028,
fn_80023944,
fn_80023928,
fn_8025A5F8,
fn_8025B448,
fn_8025BB14,
fn_8002391C,
fn_80023920,
fn_80023924,
fn_8025B928
};
}

struct CallbackControlZero1_8025B448:Handle_801F7F10{CallbackControlZero1_8025B448(){word=0;}~CallbackControlZero1_8025B448(){}};
struct CallbackControlZero2_8025B448:CallbackControlZero1_8025B448{CallbackControlZero2_8025B448(){word=0;}~CallbackControlZero2_8025B448(){}};
struct CallbackControlZero3_8025B448:CallbackControlZero2_8025B448{CallbackControlZero3_8025B448(){word=0;}~CallbackControlZero3_8025B448(){}};
struct CallbackControlCopy_8025B448:CallbackControlZero3_8025B448{CallbackControlCopy_8025B448(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~CallbackControlCopy_8025B448(){}};
inline Selector*resolveSelector(const Handle_801F7F10&h){Entry*entry=&lbl_801E9D24.manager->entries[h.bits.index];return entry->tag==h.bits.tag?entry->object:0;}
inline int queryBool(Selector*self,int key){return fn_8025E9FC(self,key)?1:0;}
inline int eitherQuery(Selector*self){return queryBool(self,0x39)||queryBool(self,0x3A);}
inline signed char handleValid(const Handle_801F7F10&h){return fn_801F7EB8(&h)!=0;}
inline const Handle_801F7F10&relatedHandle(Selector*self){return self->related;}
extern "C" int fn_8025B448(Selector*self,int event,Callback*callback){
const MemberPool*members=&lbl_802ECBB8;int result=1;
switch(event){
case 0:fn_8025EF34(self,members->entries[1],-1);return 1;
case 1:fn_8025EEB4(self,members->entries[2]);return 1;
case 2:fn_8025EB70(self,members->entries[3]);return 1;
case 3:if(callback)return(signed char)((callback->flags>>2)&1);callback=fn_8025F074(self,members->entries[4]);if(callback)return(signed char)((callback->flags>>2)&1);return 0;
case 4:if(callback)return(signed char)(callback->flags&1);callback=fn_8025F074(self,members->entries[5]);if(callback)return(signed char)(callback->flags&1);return 0;
case 5:return 1;
case 6:if(callback)return callback->index;return -9999;
}
lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
if(event==8||event==7){fn_8025F4F4(callback,0,"cat_default");fn_8025F4F4(callback,1,"cat_check_thrown");fn_8025F3C8(callback,2,"cat_thrown");}
if(event==11&&callback->index==-1)return 1;
fn_8025F658(callback,lbl_80378090);
int action;if(event>=14)action=event+callback->index*2;else action=event;
switch(action){
case 7:fn_8025F694(callback,lbl_8037808C);break;
case 8:break;
case 9:result=fn_8025E9FC(self,0x35);break;
case 10:self->slot88();self->flags|=0x10000ULL;break;
case 11:result=fn_8025E9FC(self,0x36);break;
case 12:self->slot8C();self->flags&=~0x10000ULL;break;
case 14:result=eitherQuery(self)&&!handleValid(resolveSelector(CallbackControlCopy_8025B448(relatedHandle(self)))->handle28);break;
case 15:self->slot80();resolveSelector(CallbackControlCopy_8025B448(relatedHandle(self)))->slot124();break;
default:result=2;break;
}
fn_8025F620(callback,lbl_80378090);return result;
}

/* Former original/callback_category_neighbor_802AEC2C data 0x802AEC2C..0x802AEC38 (.rodata), referenced as part of this unit; it starts mid-line (not 8-aligned), so it can only follow the data above. The zero alignment bytes before it (padding/callback_selector_tail_802AEC2B.s) are now internal alignment of this unit. */
#pragma explicit_zero_data on
#pragma force_active on
extern "C" __declspec(section ".rodata") const char lbl_802AEC2C[] = "ObjectThrow";

#pragma force_active reset

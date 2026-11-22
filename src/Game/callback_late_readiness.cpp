struct LateCallbackHandle {union{unsigned long word;struct{signed int tag:8,index:24;}bits;};};
struct LateCallbackPrefix{char unknown00[8];};
struct LateCallback:LateCallbackPrefix{
virtual void slot08();
virtual void slot0C();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual signed char slot1C();
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
char unknown0C[0xC];signed char active;char unknown19[0x68-0x19];LateCallbackHandle first,second;
};
struct LateCallbackEntry{LateCallback*object;unsigned long unknown04,unknown08;signed char generation;char unknown0D[3];};
struct LateCallbackManager{char unknown00[8];LateCallbackEntry*entries;};
struct LateCallbackContext{char unknown00[0x118];LateCallbackManager*manager;};
extern "C" LateCallbackContext lbl_801E9D24;
inline LateCallback*resolveLateCallback(const LateCallbackHandle&h){LateCallbackEntry*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->generation==h.bits.tag)return e->object;return 0;}
extern "C"{signed char slot1C__12BaseObject_ZFv(void*);void fn_801C4F7C(void*);void fn_801C6C94(void*);void fn_801C4BC4(void*);void fn_8025E588(void*);}
extern "C" signed char fn_8025D3E0(LateCallback*self){if(!slot1C__12BaseObject_ZFv(self))return 0;resolveLateCallback(self->second)->slot1C();return resolveLateCallback(self->first)->slot1C();}
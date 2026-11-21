/* Original callback-registration lifetime; all retained sections and actual relocations verified.
 * See docs/notes/game-engine-callback-registration.md. */
typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802EC720[],__vt__23ContainerLayer_80044168[],lbl_802B4B50[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);void fn_8025E31C();void fn_8025E714(void*,const struct MemberPointer&);}
struct Handle_801F7F10{u32 word;~Handle_801F7F10();};struct H1:Handle_801F7F10{};struct H2:H1{};
struct Element{u32 word;~Element(){}};
struct Array{int count,capacity;Element*data;~Array(){if(data){for(int i=0;i<count;i++)data[i].~Element();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}};
struct Object_8025F0D8{u32 unknown00[2];void*vtable;char unknown0C[0x48-0xC];~Object_8025F0D8();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ContainerBase_802563CC:Object_8025F0D8{Array array48;u32 unknown54;H2 handle58;u32 unknown5C;ContainerBase_802563CC();~ContainerBase_802563CC(){vtable=lbl_802EC720;}};
struct RegistrationLayer_80048470:ContainerBase_802563CC{RegistrationLayer_80048470(){vtable=__vt__23ContainerLayer_80044168;}~RegistrationLayer_80048470(){vtable=__vt__23ContainerLayer_80044168;}};
struct Agent_80044118:RegistrationLayer_80048470{char unknown60[8];unsigned char enabled68;char unknown69[7];Agent_80044118(){vtable=lbl_802B4B50;enabled68=1;}~Agent_80044118(){vtable=lbl_802B4B50;}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct MemberPointer{u32 delta,vslot,tableOffset;};
extern "C"{extern MemberPointer lbl_802B3708[6];extern u32 lbl_80377648;}
extern "C"{void*fn_800485C8(void*);extern u32 lbl_80377658;extern MemberPointer lbl_802B3AE4;}
struct Object_80048624{u32 unknown00;char opaque04[0x70-4];Object_80048624(){fn_800485C8(this);}~Object_80048624();};
inline void registerBase(MemberPointer&first){Agent_80044118 base;first=lbl_802B3708[0];fn_8025E714(&base,first);}
extern "C" void fn_80048470(){MemberPointer second,first;lbl_80377658=0;lbl_80377648=0;fn_8025E31C();registerBase(first);{Object_80048624 a;second=lbl_802B3AE4;fn_8025E714(&a,second);}}

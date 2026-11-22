typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802EC720[],__vt__23ContainerLayer_80044168[],lbl_802B4B50[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);void fn_8025E31C();void fn_8025E714(void*,const struct MemberPointer&);}
struct Handle_801F7F10{u32 word;~Handle_801F7F10();};struct H1:Handle_801F7F10{};struct H2:H1{};
struct Element{u32 word;~Element(){}};
struct Array{int count,capacity;Element*data;~Array(){if(data){for(int i=0;i<count;i++)data[i].~Element();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}};
struct Object_8025F0D8{u32 unknown00[2];void*vtable;char unknown0C[0x48-0xC];~Object_8025F0D8();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ContainerBase_802563CC:Object_8025F0D8{Array array48;u32 unknown54;H2 handle58;u32 unknown5C;ContainerBase_802563CC();~ContainerBase_802563CC(){vtable=lbl_802EC720;}};
struct RegistrationLayer_80048EF4:ContainerBase_802563CC{RegistrationLayer_80048EF4(){vtable=__vt__23ContainerLayer_80044168;}~RegistrationLayer_80048EF4(){vtable=__vt__23ContainerLayer_80044168;}};
struct Agent_80044118:RegistrationLayer_80048EF4{char unknown60[8];unsigned char enabled68;char unknown69[7];Agent_80044118(){vtable=lbl_802B4B50;enabled68=1;}~Agent_80044118(){vtable=lbl_802B4B50;}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct MemberPointer{u32 delta,vslot,tableOffset;};
extern "C"{extern MemberPointer lbl_802B3708[6];extern u32 lbl_80377648;}
extern "C"{void*__ct__15Object_8004904CFv(void*);extern u32 lbl_8037765C;extern MemberPointer lbl_802B3B48;}
struct Object_800490F0{u32 unknown00;char opaque04[0x88-4];Object_800490F0(){__ct__15Object_8004904CFv(this);}~Object_800490F0();};
extern "C" void fn_80048EF4(){MemberPointer second,first;lbl_8037765C=0;lbl_80377648=0;fn_8025E31C();{Agent_80044118 a;first=lbl_802B3708[0];fn_8025E714(&a,first);}{Object_800490F0 a;second=lbl_802B3B48;fn_8025E714(&a,second);}}

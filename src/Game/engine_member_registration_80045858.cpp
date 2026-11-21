/* Member registration: the temporary agent registers the shared first member, then
 * Object_80045AC4 registers its three callback members (same shape as fn_8004B578). */
typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802EC720[],__vt__23ContainerLayer_80044168[],lbl_802B4B50[],lbl_802B49EC[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);void fn_8025E31C();void fn_8025E714(void*,const struct MemberPointer&);}
struct Handle_801F7F10{u32 word;~Handle_801F7F10();};struct H1:Handle_801F7F10{};struct H2:H1{};
struct Element{u32 word;~Element(){}};
struct Array{int count,capacity;Element*data;~Array(){if(data){for(int i=0;i<count;i++)data[i].~Element();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}};
struct Object_8025F0D8{u32 unknown00[2];void*vtable;char unknown0C[0x48-0xC];~Object_8025F0D8();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ContainerBase_802563CC:Object_8025F0D8{Array array48;u32 unknown54;H2 handle58;u32 unknown5C;ContainerBase_802563CC();~ContainerBase_802563CC(){vtable=lbl_802EC720;}};
struct ContainerLayer_80044168:ContainerBase_802563CC{ContainerLayer_80044168(){vtable=__vt__23ContainerLayer_80044168;}~ContainerLayer_80044168(){vtable=__vt__23ContainerLayer_80044168;}};
struct Agent_80044118:ContainerLayer_80044168{char unknown60[8];unsigned char enabled68;char unknown69[7];Agent_80044118(){vtable=lbl_802B4B50;enabled68=1;}~Agent_80044118(){vtable=lbl_802B4B50;}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Object_80045AC4:Agent_80044118{Object_80045AC4(){vtable=lbl_802B49EC;}~Object_80045AC4(){vtable=lbl_802B49EC;}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct MemberPointer{u32 delta,vslot,tableOffset;};
extern "C"{extern struct MemberPool{MemberPointer first;char opaque0C[0x178];MemberPointer entry184,entry190,entry19C;}lbl_802B3708;extern u32 lbl_80377648,lbl_80377650;}
inline void*address(const Agent_80044118&agent){return (void*)&agent;}
extern "C" void fn_80045858(){MemberPool*const pool=&lbl_802B3708;MemberPointer first,second,third,initial;lbl_80377650=0;lbl_80377648=0;fn_8025E31C();fn_8025E714(address(Agent_80044118()),initial=pool->first);{Object_80045AC4 object;first=pool->entry184;fn_8025E714(&object,first);second=pool->entry190;fn_8025E714(&object,second);third=pool->entry19C;fn_8025E714(&object,third);}}

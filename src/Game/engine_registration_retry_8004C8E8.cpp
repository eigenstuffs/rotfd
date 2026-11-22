typedef unsigned long u32;
struct Object_8004C9FC;
typedef void(Object_8004C9FC::*MemberFunction)();
extern "C" {void*fn_8004C9A0(void*);void fn_8025E31C();void fn_8025E714(void*,const MemberFunction&);extern u32 lbl_8037766C;extern const struct Pool{char opaque00[0x698];MemberFunction entries[3];}lbl_802B3708;}
struct Object_8004C9FC{union{double alignment;char opaque00[0x70];};Object_8004C9FC(){fn_8004C9A0(this);}~Object_8004C9FC();};
inline void addMember(Object_8004C9FC*object,MemberFunction member){fn_8025E714(object,member);}
extern "C" void fn_8004C8E8(){const Pool*members=&lbl_802B3708;lbl_8037766C=0;fn_8025E31C();Object_8004C9FC object;addMember(&object,members->entries[0]);addMember(&object,members->entries[1]);addMember(&object,members->entries[2]);}

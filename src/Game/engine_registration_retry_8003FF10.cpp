/* Original member registration retries; see docs/notes/game-engine-registration-retry.md. */
typedef unsigned long u32;
struct Object_8003FD34;
typedef void(Object_8003FD34::*MemberFunction)();
extern "C" {void*fn_80040064(void*);void fn_8002B58C();void fn_8025E714(void*,const MemberFunction&);extern u32 lbl_8037763C;extern MemberFunction lbl_802B2BF0[7];extern char lbl_802B3168[];void __dt__14Agent_8002B5F4Fv(void*,short);extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Object_8003FD34{union{double alignment;char opaque00[0xA0];};Object_8003FD34(){fn_80040064(this);}~Object_8003FD34(){*(void**)(opaque00+8)=lbl_802B3168;__dt__14Agent_8002B5F4Fv(this,0);}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline void addMember(Object_8003FD34*object,MemberFunction member){fn_8025E714(object,member);}
extern "C" void fn_8003FF10(){const MemberFunction*members=lbl_802B2BF0;lbl_8037763C=0;fn_8002B58C();Object_8003FD34 object;addMember(&object,members[0]);addMember(&object,members[1]);addMember(&object,members[2]);addMember(&object,members[3]);addMember(&object,members[4]);addMember(&object,members[5]);addMember(&object,members[6]);}

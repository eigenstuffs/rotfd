typedef unsigned long u32;struct Object_8002DC0C{union{double alignment;char opaque00[0x98];};Object_8002DC0C();};struct Container_8002E014:Object_8002DC0C{~Container_8002E014();};typedef void(Container_8002E014::*MemberFunction)();extern "C"{extern u32 lbl_803775E0;extern MemberFunction lbl_802B1918[6];void fn_80256448();void fn_8025E714(Container_8002E014*,const MemberFunction&);}inline void addMember(Container_8002E014*object,MemberFunction member){fn_8025E714(object,member);}
extern "C" void fn_8002DAE8(){const MemberFunction*members=lbl_802B1918;lbl_803775E0=0;fn_80256448();Container_8002E014 container;
addMember(&container,members[0]);
addMember(&container,members[1]);
addMember(&container,members[2]);
addMember(&container,members[3]);
addMember(&container,members[4]);
addMember(&container,members[5]);
}

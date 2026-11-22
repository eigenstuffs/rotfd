typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802BD468[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);}
struct BaseObject_Z{u32 unknown00[2];const void*vtable;~BaseObject_Z();};
struct Handle_801F7F10{u32 word;~Handle_801F7F10();};
struct H1:Handle_801F7F10{~H1(){}};
struct H2:H1{~H2(){}};
struct Element{char unknown[0x58];~Element(){}};
struct Pool{int count,capacity;Element*data;~Pool(){if(data){for(int i=0;i<count;i++)data[i].~Element();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Element));data=0;}data=0;}}};
struct Object_800AC150:BaseObject_Z{
 void*storage0C;u32 count10;Pool pool14;char unknown20[0x130];H2 handle150;
 ~Object_800AC150();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
Object_800AC150::~Object_800AC150(){vtable=lbl_802BD468;fn_801EF610(lbl_801EF5C8,storage0C);storage0C=0;count10=0;}

typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802BF5F4[];void fn_801EF610(void*,void*);}
struct BaseObject_Z{u32 unknown00[2];const void*vtable;~BaseObject_Z();};
struct Element{u32 word;Element();static void operator delete[](void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Object_800C1A54:BaseObject_Z{
 Element*storage0C;u32 count10;char active14;
 ~Object_800C1A54();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
Object_800C1A54::~Object_800C1A54(){vtable=lbl_802BF5F4;delete[] storage0C;count10=0;active14=0;}

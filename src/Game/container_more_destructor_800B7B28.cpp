typedef unsigned long u32;
extern "C" {
extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802BEF98[];
void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);void fn_800BBFD8(void*);
}
struct Handle_801F7F10{u32 word;~Handle_801F7F10();};
struct H1:Handle_801F7F10{~H1(){}};
struct H2:H1{~H2(){}};
struct H3:H2{~H3(){}};
struct Pool{int size,capacity;H3*data;~Pool(){if(data){for(int i=0;i<size;i++)data[i].~H3();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}};
struct Object_80260C7C{char unknown00[0x30];const void*vtable;char unknown34[0x1504C-0x34];~Object_80260C7C();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Object_800B7B28:Object_80260C7C{Pool handles1504C;char unknown15058[0x14];H2 handle1506C;~Object_800B7B28();};
Object_800B7B28::~Object_800B7B28(){vtable=lbl_802BEF98;fn_800BBFD8(this);}

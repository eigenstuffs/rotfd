typedef unsigned long u32;
extern "C" {
extern const char lbl_802B1C74[],lbl_802EC720[];
extern char lbl_801EF5C8[],lbl_8028F698[];
void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10 {u32 value;~Handle_801F7F10();};
struct H1:Handle_801F7F10 {~H1(){}};
struct H2:H1 {~H2(){}};
struct H3:H2 {~H3(){}};
struct H4:H3 {~H4(){}};
struct H5:H4 {~H5(){}};
struct Element {u32 value;~Element(){}};
struct Pool {int size,capacity;Element*data;
 ~Pool(){if(data){for(int i=0;i<size;i++)data[i].~Element();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}
};
struct Object_8025F0D8 {u32 unknown[2];const void*vtable;char unknown0C[0x3C];~Object_8025F0D8();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ContainerPrefix:Object_8025F0D8 {Pool pool;u32 unknown54;H2 handle58;char unknown5C[4];~ContainerPrefix(){vtable=lbl_802EC720;}};
struct Container_8002E014:ContainerPrefix {H1 handle60;char unknown64[8];H4 handle6C,handle70,handle74;H5 handle78;H4 handle7C,handle80,handle84,handle88;H5 handle8C;H4 handle90;~Container_8002E014();};
Container_8002E014::~Container_8002E014(){vtable=lbl_802B1C74;}
typedef char PrefixSize[(sizeof(ContainerPrefix)==0x60)?1:-1];
typedef char DerivedSize[(sizeof(Container_8002E014)==0x94)?1:-1];

// Native handle temporary lifetimes and observed container reset fields.
typedef unsigned long u32;
struct Handle_801F7F10;struct PoolManager;struct Context {char unknown[0x118];PoolManager*manager;char unknown11C[0x48];void*service;};
extern "C" {
extern const char lbl_802B1884[],lbl_802ECD68[],lbl_802EC720[];
extern Context lbl_801E9D24;extern unsigned long lbl_8037767C,lbl_803777B8;void fn_801F86C8(PoolManager*,const Handle_801F7F10*,short);void*fn_801F7EB8(const void*);
extern char lbl_801EF5C8[],lbl_8028F698[];
void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10 {u32 value;Handle_801F7F10();~Handle_801F7F10();};
struct H1:Handle_801F7F10 {~H1(){}};
struct H2:H1 {~H2(){}};
struct H3:H2 {~H3(){}};
struct H4:H3 {~H4(){}};
struct H5:H4 {~H5(){}};
struct Element {u32 value;~Element(){}};
struct Pool {int size,capacity;Element*data;
 ~Pool(){if(data){for(int i=0;i<size;i++)data[i].~Element();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}
};
struct Object_8025F0D8 {u32 unknown0;Handle_801F7F10 owner;const void*vtable;char unknown0C[0x3C];~Object_8025F0D8();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ContainerPrefix:Object_8025F0D8 {Pool pool;u32 unknown54;H2 handle58;char unknown5C[4];~ContainerPrefix(){vtable=lbl_802EC720;}};
struct Handle_80020478:Handle_801F7F10 {Handle_80020478(const Handle_801F7F10&o){value=o.value;fn_801F86C8(lbl_801E9D24.manager,&o,1);}Handle_80020478(const Handle_80020478&o):Handle_801F7F10(){value=o.value;fn_801F86C8(lbl_801E9D24.manager,&o,1);}
~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C" {void fn_800B70AC(void*,Handle_80020478,int);}
struct ContainerLayer:ContainerPrefix {H3 handle60;~ContainerLayer(){vtable=lbl_802ECD68;}};
struct Agent_8002CF70:ContainerLayer {~Agent_8002CF70();};
Agent_8002CF70::~Agent_8002CF70(){vtable=lbl_802B1884;const Handle_801F7F10&original=owner;Handle_80020478 handle((Handle_80020478(original)));if(lbl_801E9D24.service)fn_800B70AC(lbl_801E9D24.service,handle,0);}

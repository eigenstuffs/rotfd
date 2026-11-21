// ContainerInVolume.h establishes the 0x68-byte allocation; opaque base fields follow native code.
typedef unsigned long u32;
extern "C" {
extern const char lbl_802C171C[],__vt__23ContainerLayer_80044168[],lbl_802EC720[];
extern char lbl_801EF5C8[],lbl_8028F698[];
void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10 { u32 value; Handle_801F7F10();~Handle_801F7F10();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);} };
struct Handle_80020478:Handle_801F7F10 { Handle_80020478(){value=0;}~Handle_80020478(){} };
struct Handle_80021BCC:Handle_80020478 { Handle_80021BCC(){value=0;}~Handle_80021BCC(){} };
struct Element {u32 value;~Element(){}};
struct Pool {
 int size,capacity;Element*data;
 ~Pool(){if(data){for(int i=0;i<size;i++)data[i].~Element();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}
};
struct Object_8025F0D8 {
 u32 unknown[2]; const void*vtable;char unknown0C[0x3C];
 ~Object_8025F0D8();
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct ContainerBase_802563CC:Object_8025F0D8 {
 Pool pool;u32 unknown54;Handle_80021BCC handle58;char unknown5C[6];unsigned char flag62,flag63;
 ContainerBase_802563CC();~ContainerBase_802563CC(){vtable=lbl_802EC720;}
};
struct ContainerLayer_80044168:ContainerBase_802563CC {
 ContainerLayer_80044168(){vtable=__vt__23ContainerLayer_80044168;}
 ~ContainerLayer_80044168(){vtable=__vt__23ContainerLayer_80044168;}
};
struct ContainerInVolume:ContainerLayer_80044168 {
 u32 unknown64;
 ContainerInVolume();~ContainerInVolume();
};
typedef char ContainerInVolumeExtent[(sizeof(ContainerInVolume)==0x68)?1:-1];
ContainerInVolume::ContainerInVolume(){vtable=lbl_802C171C;flag62=0;flag63=0;}
ContainerInVolume::~ContainerInVolume(){vtable=lbl_802C171C;}

/* Original engine native construction with guarded consumer migration with compiler-emitted exception metadata.
 * See docs/notes/game-engine-base-handle-construct.md. */
typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Zero1:Handle_801F7F10 {Zero1(){word=0;}~Zero1();};
struct Zero2:Zero1 {Zero2(){word=0;}~Zero2();};
struct Zero3:Zero2 {Zero3(){word=0;}~Zero3();};
struct Zero4:Zero3 {Zero4(){word=0;}~Zero4();};
struct Handle_8002B67C:Handle_801F7F10 {Handle_8002B67C(int){word=0;}~Handle_8002B67C();};
struct Handle_8002DE2C:Zero3 {Handle_8002DE2C(int=0){word=0;}~Handle_8002DE2C();};
struct Handle_8002DDAC:Zero4 {Handle_8002DDAC(){word=0;}~Handle_8002DDAC();};
struct Handle_80020834:Zero1 {Handle_80020834(int){word=0;}~Handle_80020834();};
struct Handle_800723F4:Zero1 {Handle_800723F4(int=0){word=0;}~Handle_800723F4();};
extern "C" {extern char lbl_802BD468[],lbl_801EF5C8[],lbl_8029EFC0[],lbl_8029EFD0[];extern const float lbl_803790A8;void*fn_801EFA1C(void*,int,void*,void*,int,int);}
struct BaseObject_Z {u32 unknown00[2];void*vtable;BaseObject_Z();~BaseObject_Z();};
struct Array_800AC098 {int count,capacity;void*data;Array_800AC098(int){count=0;capacity=0;data=0;}~Array_800AC098();};
struct Object_800ABFDC:BaseObject_Z {void*storage0C,*storage10;Array_800AC098 array14;int index20,index24;unsigned char byte28;char unknown29[0x148-0x29];unsigned char byte148;char unknown149[3];float value14C;Handle_80020834 handle150;unsigned char byte154;Object_800ABFDC();};
Object_800ABFDC::Object_800ABFDC():array14((vtable=lbl_802BD468,0)),handle150((value14C=lbl_803790A8,0)){byte148=0;byte28=0;index20=-1;index24=-1;byte154=1;storage0C=fn_801EFA1C(lbl_801EF5C8,15000,lbl_8029EFC0,lbl_8029EFD0,115,4);storage10=storage0C;}

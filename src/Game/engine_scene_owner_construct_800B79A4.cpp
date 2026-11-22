typedef unsigned long u32;
extern "C" {void fn_80260FF8(void*);void fn_800B8308(void*);void fn_800BC8DC(void*);void fn_800BD0F8(void*);extern char lbl_802BEF98[];}
struct Object_80260C7C {
    char unknown00[0x30];void*vtable;char unknown34[0x15048-0x34];unsigned char byte15048,byte15049;char unknown1504A[2];
    Object_80260C7C(){fn_80260FF8(this);}~Object_80260C7C();
};
struct Object_800B7A48 {u32 count,capacity,data;Object_800B7A48(int){count=0;capacity=0;data=0;}~Object_800B7A48();};
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct ZeroHandle:Handle_801F7F10 {ZeroHandle(){word=0;}~ZeroHandle();};
struct Handle_80021BCC:ZeroHandle {Handle_80021BCC(int){word=0;}~Handle_80021BCC();};
struct Object_800B79A4:Object_80260C7C {
    Object_800B7A48 records1504C;u32 field15058,field1505C,field15060,field15064,field15068;Handle_80021BCC handle1506C;
    Object_800B79A4();
};
Object_800B79A4::Object_800B79A4():records1504C((vtable=lbl_802BEF98,byte15048=0,byte15049=0,0)),handle1506C((field15058=0,field1505C=0,field15060=0,field15064=0,field15068=0,0)){field1505C=0;fn_800B8308(this);fn_800BC8DC(this);fn_800BD0F8(this);}

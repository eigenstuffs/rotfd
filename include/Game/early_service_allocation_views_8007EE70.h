#ifndef GAME_EARLY_SERVICE_ALLOCATION_VIEWS_8007EE70_H
#define GAME_EARLY_SERVICE_ALLOCATION_VIEWS_8007EE70_H

/* Complete class declarations reused verbatim from the accepted constructor views. */
typedef unsigned long u32;
extern "C"{extern char lbl_802BD920[],lbl_802B8460[],lbl_8028F698[];void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);extern u32 lbl_803754A4;extern const char lbl_802A0550[];extern const float lbl_8037936C;}
inline void*operator new(unsigned long,void*p){return p;}
struct PoolOwnerVector{float x,y,z;PoolOwnerVector(){}void operator=(const PoolOwnerVector&v){x=v.x;y=v.y;z=v.z;}};
extern "C" PoolOwnerVector game_vec3_zero;
struct PoolOwner38{int count,capacity;void*data;PoolOwner38():count(0),capacity(0),data(0){}};
struct Object_8007F3DC{void*vtable;PoolOwner38 records;Object_8007F3DC():vtable(lbl_802B8460){}~Object_8007F3DC();};
struct Array_800B5E10{int count,capacity;u32*data;Array_800B5E10():count(0),capacity(0),data(0){}~Array_800B5E10();void append(const u32&v){if(count+1>capacity){if(capacity+1){if(data)data=(u32*)fn_8028FAF4(lbl_8028F698,data,capacity*4,(capacity+1)*4);else data=(u32*)fn_8028FF24(lbl_8028F698,(capacity+1)*4);}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}capacity+=1;}new(&data[count++])u32(v);}};
struct Array_800B5D58{int count,capacity;void*data;Array_800B5D58():count(0),capacity(0),data(0){}~Array_800B5D58();};
struct Object_800B5EC8:Object_8007F3DC{unsigned char flag10;char unknown11[3];Array_800B5E10 first;Array_800B5D58 second;unsigned char flag2C,flag2D,flag2E;char unknown2F;PoolOwnerVector position30,position3C;float value;void*object;unsigned char flag50;char unknown51[3];int index;Object_800B5EC8();};

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

#endif

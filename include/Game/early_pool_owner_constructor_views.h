#ifndef GAME_EARLY_POOL_OWNER_CONSTRUCTOR_VIEWS_H
#define GAME_EARLY_POOL_OWNER_CONSTRUCTOR_VIEWS_H
typedef unsigned long u32;
extern "C"{extern char lbl_802BD920[],lbl_802B8460[],lbl_8028F698[];void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);extern u32 lbl_803754A4;extern const char lbl_802A0550[];extern const float lbl_8037936C;}
inline void*operator new(unsigned long,void*p){return p;}
struct PoolOwnerVector{float x,y,z;PoolOwnerVector(){}void operator=(const PoolOwnerVector&v){x=v.x;y=v.y;z=v.z;}};
extern "C" PoolOwnerVector game_vec3_zero;
struct PoolOwnerEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct PoolOwnerManager{char unknown00[8];PoolOwnerEntry*entries;};
struct PoolOwnerContext{char unknown00[0x118];PoolOwnerManager*manager;};
extern "C" PoolOwnerContext lbl_801E9D24;
struct Handle_801F7F10{signed long tag:8,index:24;Handle_801F7F10();~Handle_801F7F10();};
extern "C" Handle_801F7F10 fn_801B52EC(PoolOwnerManager*,const char*);
inline void*resolvePoolOwner(const Handle_801F7F10&h){int index=h.index;PoolOwnerManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct PoolOwner38{int count,capacity;void*data;PoolOwner38():count(0),capacity(0),data(0){}};
struct Object_8007F3DC{void*vtable;PoolOwner38 records;Object_8007F3DC():vtable(lbl_802B8460){}~Object_8007F3DC();};
struct Array_800B5E10{int count,capacity;u32*data;Array_800B5E10():count(0),capacity(0),data(0){}~Array_800B5E10();void append(const u32&v){if(count+1>capacity){if(capacity+1){if(data)data=(u32*)fn_8028FAF4(lbl_8028F698,data,capacity*4,(capacity+1)*4);else data=(u32*)fn_8028FF24(lbl_8028F698,(capacity+1)*4);}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}capacity+=1;}new(&data[count++])u32(v);}};
struct Array_800B5D58{int count,capacity;void*data;Array_800B5D58():count(0),capacity(0),data(0){}~Array_800B5D58();};
struct Object_800B5EC8:Object_8007F3DC{unsigned char flag10;char unknown11[3];Array_800B5E10 first;Array_800B5D58 second;unsigned char flag2C,flag2D,flag2E;char unknown2F;PoolOwnerVector position30,position3C;float value;void*object;unsigned char flag50;char unknown51[3];int index;Object_800B5EC8();};
#endif

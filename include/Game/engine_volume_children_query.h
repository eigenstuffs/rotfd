#ifndef GAME_ENGINE_VOLUME_CHILDREN_QUERY_H
#define GAME_ENGINE_VOLUME_CHILDREN_QUERY_H

struct VolumeHandle {union{unsigned long value;struct{signed int tag:8,index:24;}bits;};};
struct VolumeSphere {float x,y,z,r;VolumeSphere&operator=(const VolumeSphere&o){x=o.x;y=o.y;z=o.z;r=o.r;return *this;}};
struct VolumeObject {char unknown00[0x120];unsigned long flags;};
struct VolumeQueryPrefix {unsigned long unknown00[2];};
struct VolumeQuery:VolumeQueryPrefix {
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
 virtual signed char test(VolumeObject*,void*,void*);virtual VolumeSphere*sphere();
 unsigned long flags;char unknown10[0x10];int count,capacity;char*handles;
 const VolumeHandle&at(int i)const{return *(const VolumeHandle*)(handles+i*4);}
};
struct VolumeEntry {VolumeQuery*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct VolumeManager {char unknown00[8];VolumeEntry*entries;};
struct VolumeContext {char unknown00[0x118];VolumeManager*manager;};
struct VolumeQueryContext {char unknown00[0x1C];float field1C;char field20[0x80];char fieldA0[4];};

typedef char VolumeQuerySizeCheck[(sizeof(VolumeQuery)==0x2C)?1:-1];
typedef char VolumeSphereSizeCheck[(sizeof(VolumeSphere)==16)?1:-1];
extern "C" signed char fn_802457B8(VolumeQuery*,VolumeObject*,void*,VolumeQueryContext*);

#endif

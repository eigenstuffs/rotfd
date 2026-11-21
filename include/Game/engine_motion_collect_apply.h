#ifndef GAME_ENGINE_MOTION_COLLECT_APPLY_H
#define GAME_ENGINE_MOTION_COLLECT_APPLY_H

typedef unsigned long MotionCollectWord;
struct MotionCollectHandle {union{MotionCollectWord value;struct{signed int generation:8; signed int index:24;}bits;};};

struct MotionCollectPoint {float x,y,z;MotionCollectPoint(){}MotionCollectPoint(float a,float b,float c):x(a),y(b),z(c){}void operator=(const MotionCollectPoint&o){x=o.x;y=o.y;z=o.z;}MotionCollectPoint operator+(const MotionCollectPoint&o)const{return MotionCollectPoint(x+o.x,y+o.y,z+o.z);}void operator+=(const MotionCollectPoint&o){x+=o.x;y+=o.y;z+=o.z;}MotionCollectPoint operator-(const MotionCollectPoint&o)const{return MotionCollectPoint(x-o.x,y-o.y,z-o.z);}};

struct MotionCollectMatrix {float m[16];MotionCollectPoint transform(const MotionCollectPoint&v)const{MotionCollectPoint r;r.x=m[0]*v.x+m[4]*v.y+m[8]*v.z+m[12];r.y=m[1]*v.x+m[5]*v.y+m[9]*v.z+m[13];r.z=m[2]*v.x+m[6]*v.y+m[10]*v.z+m[14];return r;}};

struct MotionCollectSphere {MotionCollectPoint center;float radius;MotionCollectSphere(const MotionCollectSphere&s):center(s.center),radius(s.radius){}};

struct MotionCollectOwner;
struct MotionCollectLinked {char unknown00[0x124];MotionCollectMatrix*matrix;char unknown128[0xC];MotionCollectWord index;};

struct MotionCollectContact {MotionCollectPoint point;char unknown0C[0x1C];MotionCollectWord flags28,flags2C;MotionCollectLinked*linked;MotionCollectWord unknown34,unknown38;unsigned char enabled;char unknown3D[3];MotionCollectWord type;char unknown44[4];MotionCollectContact(){enabled=0;linked=0;unknown34=0;unknown38=0;flags2C=0;flags28=0;}};

struct MotionCollectStorage {char unknown00[8];};

struct MotionCollectOwner:MotionCollectStorage {

 virtual void slot08();
 virtual void slot0C();
 virtual void slot10();
 virtual void slot14();
 virtual void slot18();
 virtual void slot1C();
 virtual void slot20();
 virtual void slot24();
 virtual void slot28();
 virtual void slot2C();
 virtual void slot30();
 virtual void slot34();
 virtual void slot38();
 virtual void slot3C();
 virtual void slot40();
 virtual void slot44();
 virtual void slot48(void*,float);
 virtual void slot4C();
 virtual void slot50(void*);
 virtual void slot54();
 virtual void slot58();
 virtual void slot5C();
 virtual void slot60();
 virtual void slot64();
 virtual void slot68();
 virtual void slot6C();
 virtual void slot70();
 virtual void slot74();
 virtual void slot78();
 virtual void slot7C();
 virtual void slot80();
 virtual void slot84();
 virtual void slot88();
 virtual void slot8C();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual void slot9C();
 virtual void slotA0();
 virtual void slotA4();
 virtual void slotA8();
 virtual void slotAC();
 virtual MotionCollectPoint slotB0(int);
 virtual void slotB4();
 virtual void slotB8();
 virtual void slotBC(MotionCollectPoint*,int);
 virtual void slotC0();
 virtual void slotC4();
 virtual void slotC8();
 virtual void slotCC();
 virtual void slotD0();
 virtual void slotD4();
 virtual void slotD8();
 virtual void slotDC();
 virtual void slotE0();
 virtual void slotE4();
 virtual void slotE8();
 virtual void slotEC();
 virtual void slotF0();
 virtual void slotF4();
 virtual void slotF8();
 virtual void slotFC();
 virtual void slot100(MotionCollectOwner*,MotionCollectPoint*,MotionCollectPoint*,MotionCollectPoint*,int,float);
 virtual void slot104();
 virtual void slot108();
 virtual void slot10C();
 virtual void slot110();
 virtual void slot114(MotionCollectContact*,MotionCollectPoint*,int);
 char unknown0C[0x24];unsigned long long flags;char unknown38[0x40];MotionCollectLinked*linked;char unknown7C[0xC];MotionCollectPoint first,second;char unknownA0[0xC8];MotionCollectHandle resource;char unknown16C[0xB4];MotionCollectPoint result;
};

struct MotionCollectResource {char unknown00[0x74];MotionCollectSphere*sphere;};

struct MotionCollectEntry {MotionCollectOwner*owner;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};

struct MotionCollectManager {MotionCollectWord unknown00[2];MotionCollectEntry*entries;};

struct MotionCollectHandleArray {MotionCollectWord count,capacity;MotionCollectHandle*data;};

struct MotionCollectGlobals {char unknown00[0x118];MotionCollectManager*manager;MotionCollectHandleArray*handles;};

extern "C" {extern MotionCollectGlobals lbl_801E9D24;extern const float lbl_8037B0C0;}
static inline MotionCollectOwner*resolveMotionCollect(const MotionCollectHandle&h){int index=h.bits.index;MotionCollectManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.bits.generation?m->entries[index].owner:0;}
struct MotionCollectCollected {char unknown00[0x1C];MotionCollectWord word;char unknown20[8];~MotionCollectCollected(){}};

struct MotionCollectResults {MotionCollectWord storage[0xA00];int count;MotionCollectResults():count(0){}~MotionCollectResults(){for(int i=0;i<count;++i)reinterpret_cast<MotionCollectCollected*>(storage)[i].~MotionCollectCollected();}};

extern "C" int fn_80268918(MotionCollectOwner*,const MotionCollectSphere*,MotionCollectResults*,unsigned long long,unsigned long long);

typedef char MotionCollectPointSize[sizeof(MotionCollectPoint)==12?1:-1];
typedef char MotionCollectContactSize[sizeof(MotionCollectContact)==72?1:-1];
typedef char MotionCollectCollectedSize[sizeof(MotionCollectCollected)==40?1:-1];
typedef char MotionCollectResultsSize[sizeof(MotionCollectResults)==0x2804?1:-1];
extern "C" int fn_80221A0C(MotionCollectOwner*,signed char,void*);
#endif

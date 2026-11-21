#ifndef GAME_ENGINE_RECORD_BOUNDS_REDUCE_H
#define GAME_ENGINE_RECORD_BOUNDS_REDUCE_H
typedef unsigned long RecordBoundsWord;
struct Handle_801F7F10{union{RecordBoundsWord word;struct{signed int generation:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct RecordBoundsEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct RecordBoundsManager{RecordBoundsWord count,capacity;RecordBoundsEntry*entries;};
struct RecordBoundsContext{char unknown00[0x118];RecordBoundsManager*manager;};
extern "C"{extern RecordBoundsContext lbl_801E9D24;void fn_801F86C8(RecordBoundsManager*,const Handle_801F7F10*,short);}
struct RecordBoundsZeroHandle:Handle_801F7F10{RecordBoundsZeroHandle(){word=0;}};struct RecordBoundsCopyHandle:RecordBoundsZeroHandle{RecordBoundsCopyHandle(const RecordBoundsCopyHandle&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}RecordBoundsCopyHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct RecordBoundsSphere{float x,y,z,r;
RecordBoundsSphere(){}RecordBoundsSphere(float a,float b,float c,float d):x(a),y(b),z(c),r(d){}
RecordBoundsSphere(const RecordBoundsSphere&s):x(s.x),y(s.y),z(s.z),r(s.r){}
RecordBoundsSphere&operator=(const RecordBoundsSphere&s){x=s.x;y=s.y;z=s.z;r=s.r;return *this;}
};
struct RecordBoundsRecord{RecordBoundsWord id;RecordBoundsCopyHandle handle;RecordBoundsSphere sphere;RecordBoundsRecord(const RecordBoundsRecord&other):id(other.id),handle(other.handle),sphere(other.sphere){}};
struct RecordBoundsStorage{char unknown00[8];};
struct RecordBoundsOwner:RecordBoundsStorage{
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
virtual const RecordBoundsSphere*getSphere();
char unknown0C[4];RecordBoundsSphere sphere;char unknown20[0x20];int firstCount,firstCapacity;RecordBoundsRecord*first;int secondCount,secondCapacity;RecordBoundsRecord*second;};
struct RecordBoundsObject{char unknown00[0x124];void*matrix;};
extern "C"{extern const RecordBoundsSphere game_vec4_zero;extern const float lbl_8037B428,lbl_8037B42C;RecordBoundsSphere fn_80099A00(const void*,const RecordBoundsSphere*);RecordBoundsSphere fn_801F0A20(const RecordBoundsSphere&,const RecordBoundsSphere&);}
inline char*resolve(const Handle_801F7F10&h){int index=h.bits.index;RecordBoundsManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.bits.generation)return m->entries[index].object;return 0;}
typedef char RecordBoundsHandleSize[sizeof(Handle_801F7F10) == 4 ? 1 : -1];
typedef char RecordBoundsSphereSize[sizeof(RecordBoundsSphere) == 0x10 ? 1 : -1];
typedef char RecordBoundsRecordSize[sizeof(RecordBoundsRecord) == 0x18 ? 1 : -1];
extern "C" void fn_80249D58(RecordBoundsOwner*, signed char);
#endif

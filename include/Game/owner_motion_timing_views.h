#ifndef GAME_OWNER_MOTION_TIMING_VIEWS_H
#define GAME_OWNER_MOTION_TIMING_VIEWS_H
extern "C" const float lbl_80378DBC;
struct MotionTimingVector {
    float x,y,z;
    MotionTimingVector() {}
    MotionTimingVector(float a,float b,float c):x(a),y(b),z(c){}
    MotionTimingVector operator*(float f)const{return MotionTimingVector(x*f,y*f,z*f);}
    MotionTimingVector operator/(float f)const{float inverse=lbl_80378DBC/f;return MotionTimingVector(x*inverse,y*inverse,z*inverse);}
    MotionTimingVector operator+(const MotionTimingVector&v)const{return MotionTimingVector(x+v.x,y+v.y,z+v.z);}
    MotionTimingVector& operator=(const MotionTimingVector&v){x=v.x;y=v.y;z=v.z;return *this;}
};
struct MotionTimingHandle {union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct MotionTimingResource {char unknown00[0x38];unsigned long long flags;};
struct MotionTimingEntry {MotionTimingResource* object;char unknown04[8];signed char tag;char unknown0D[3];};
struct MotionTimingManager {int count,capacity;MotionTimingEntry* entries;};
struct MotionTimingContext {char unknown00[0x118];MotionTimingManager* manager;};
extern "C" MotionTimingContext lbl_801E9D24;
inline MotionTimingResource* resolveMotionTiming(const MotionTimingHandle&handle){
    MotionTimingEntry* entry=&lbl_801E9D24.manager->entries[handle.bits.index];
    if(entry->tag==handle.bits.tag)return entry->object;
    return 0;
}
struct MotionTimingAgent {
    char unknown00[0x24];MotionTimingHandle owner;char unknown28[8];unsigned long long flags;
    char unknown38[0x10C];MotionTimingVector velocity;char unknown150[0xC];MotionTimingVector base;
    char unknown168[0x1B0];char controls;char unknown319[0x3B];float scale;MotionTimingVector movement;
    char unknown364[0x58];float elapsed;
    signed char hasFlag(unsigned long long mask)const{return(flags&mask)!=0;}
};
struct MotionTimingAction {char unknown00[8];MotionTimingAgent* agent;};
extern "C" {
void fn_8025795C(void*,int,int);
int fn_801F1224(int,int);
void slot38__10CActorMoveFf(MotionTimingAgent*,float);
signed char fn_8007D604(void*,int);
void fn_8007D6A0(void*,int);
void fn_8009D820(MotionTimingAgent*);
void slot18C__10CActorMoveFv(MotionTimingAgent*);
void slot190__10CActorMoveFv(MotionTimingAgent*);
extern const float lbl_80378DC8,lbl_80378DA8;
}
#endif

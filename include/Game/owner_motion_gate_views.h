#ifndef GAME_OWNER_MOTION_GATE_VIEWS_H
#define GAME_OWNER_MOTION_GATE_VIEWS_H
struct MotionGateVector {
    float x, y, z;
    MotionGateVector() {}
    MotionGateVector(float a, float b, float c):x(a),y(b),z(c) {}
    MotionGateVector operator-() const {return MotionGateVector(-x,-y,-z);}
    MotionGateVector& operator=(const MotionGateVector& v) {x=v.x;y=v.y;z=v.z;return *this;}
};
struct MotionGatePrefix { char unknown00[8]; };
struct MotionGateAgent : MotionGatePrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual MotionGateVector position(int);
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void finish();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void apply(const MotionGateVector*, float);
    char unknown0C[0x30C];
    char controls;
    char unknown319[0x7B];
    float limit394;
    char unknown398[0x30];
    float height3C8;
    char unknown3CC[0xC];
    float limit3D8;
    float limit3DC;
};
struct MotionGateAction { char unknown00[8]; MotionGateAgent* agent; void* target; };
extern "C" {
signed char fn_8025E9FC(void*, int);
void fn_8007D6A0(void*, int);
void fn_80099F74(MotionGateAgent*, float*);
void fn_8009A270(MotionGateAgent*, float*);
void fn_8009A3CC(MotionGateAgent*, MotionGateVector*);
void planarDirection_8009A6D4__14CJellyfishMoveFP4Vec3(MotionGateAgent*, MotionGateVector*);
}
struct MotionGateHandle {union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct MotionGateEntry {char* object;char unknown04[8];signed char tag;char unknown0D[3];};
struct MotionGateManager {int count,capacity;MotionGateEntry* entries;};
struct MotionGateContext {char unknown00[0x118];MotionGateManager* manager;void* window;};
extern "C" MotionGateContext lbl_801E9D24;
inline char* resolveMotionGate(const MotionGateHandle& handle) {
    MotionGateEntry* entry=&lbl_801E9D24.manager->entries[handle.bits.index];
    if(entry->tag==handle.bits.tag)return entry->object;
    return 0;
}
struct MotionGateResource {char unknown00[0x58];MotionGateHandle handle;};
struct MotionGateObject {char unknown00[0x120];unsigned int flags;};
extern "C" {void fn_8026B440(void*);void fn_8025795C(void*,int,int);}
#endif

#ifndef GAME_OWNER_BASIS_MOTION_VIEWS_H
#define GAME_OWNER_BASIS_MOTION_VIEWS_H
struct BasisMotionHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct BasisMotionResource{char unknown00[0x30];float matrix[9];char unknown54[0xCC];unsigned int flags;};
struct BasisMotionEntry{BasisMotionResource* object;char unknown04[8];signed char tag;char unknown0D[3];};
struct BasisMotionManager{int count,capacity;BasisMotionEntry* entries;};
struct BasisMotionContext{char unknown00[0x118];BasisMotionManager* manager;};
extern "C" BasisMotionContext lbl_801E9D24;
inline BasisMotionResource* resolveBasisMotion(const BasisMotionHandle&handle){
    BasisMotionEntry*entry=&lbl_801E9D24.manager->entries[handle.bits.index];
    if(entry->tag==handle.bits.tag)return entry->object;
    return 0;
}
struct BasisMotionPrefix{char unknown00[8];};
struct BasisMotionAgent:BasisMotionPrefix{
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
    virtual const BasisMotionHandle* getHandle(int);
    char unknown0C[0x24];unsigned long long flags;
    char unknown38[0x10C];float velocityX,velocityY,velocityZ;
    char unknown150[0x1C8];char controls;char unknown319[0x53];float scale;
};
extern "C" {
void fn_8009BEE8(BasisMotionAgent*);
void fn_8007DCDC(void*);
extern const float lbl_80378DD8,lbl_80378DDC;
}
#endif

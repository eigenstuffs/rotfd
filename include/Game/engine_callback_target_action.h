#ifndef GAME_ENGINE_CALLBACK_TARGET_ACTION_H
#define GAME_ENGINE_CALLBACK_TARGET_ACTION_H

typedef unsigned long TargetActionWord;

struct TargetActionMemberPointer { TargetActionWord adjustment, tableOffset, function; };
struct TargetActionCallback {
    char unknown00[0x28];
    unsigned short flags28;
    short index2A;
};

struct TargetActionPrefix { TargetActionWord unknown00, unknown04; };
/* Partial owner view: the inherited eight-byte prefix precedes its vtable. */
struct TargetActionHandle {union {unsigned long value;struct {signed int tag:8,index:24;}bits;};};
struct TargetActionOwner : TargetActionPrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28(int);
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual const TargetActionHandle& slot78(int);
    virtual void slot7C(int);
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    char unknown0C[0x1C];
    TargetActionHandle target28;
    float value2C;
};

extern "C" {
extern TargetActionWord lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
void fn_8025EF34(void*, TargetActionMemberPointer, int);
void fn_8025EEB4(void*, TargetActionMemberPointer);
void fn_8025EB70(void*, TargetActionMemberPointer);
TargetActionCallback* fn_8025F074(void*, TargetActionMemberPointer);
void fn_8025F4F4(TargetActionCallback*, int, const char*);
void fn_8025F658(TargetActionCallback*, int);
void fn_8025F694(TargetActionCallback*, TargetActionWord);
void fn_8025F620(TargetActionCallback*, TargetActionWord);
signed char fn_8025E9FC(void*, int);
int fn_8025C858(TargetActionOwner*, int, TargetActionCallback*);
}
typedef char TargetActionValueOffset[sizeof(TargetActionOwner)==0x30?1:-1];
#endif

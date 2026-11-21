#ifndef GAME_ENGINE_CALLBACK_TARGET_MATCH_H
#define GAME_ENGINE_CALLBACK_TARGET_MATCH_H

typedef unsigned long TargetMatchWord;

struct TargetMatchMemberPointer { TargetMatchWord adjustment, tableOffset, function; };
struct TargetMatchCallback {
    char unknown00[0x28];
    unsigned short flags28;
    short index2A;
};

struct TargetMatchPrefix { TargetMatchWord unknown00, unknown04; };
/* Partial owner view: the inherited eight-byte prefix precedes its vtable. */
struct TargetMatchHandle {union {unsigned long value;struct {signed int tag:8,index:24;}bits;};};
struct TargetMatchOwner : TargetMatchPrefix {
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
    virtual const TargetMatchHandle& slot78(int);
    virtual void slot7C(int);
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    char unknown0C[0x1C];
    TargetMatchHandle target28;
    float value2C;
};

extern "C" {
extern TargetMatchWord lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
void fn_8025EF34(void*, TargetMatchMemberPointer, int);
void fn_8025EEB4(void*, TargetMatchMemberPointer);
void fn_8025EB70(void*, TargetMatchMemberPointer);
TargetMatchCallback* fn_8025F074(void*, TargetMatchMemberPointer);
void fn_8025F4F4(TargetMatchCallback*, int, const char*);
void fn_8025F658(TargetMatchCallback*, int);
void fn_8025F694(TargetMatchCallback*, TargetMatchWord);
void fn_8025F620(TargetMatchCallback*, TargetMatchWord);
signed char fn_8025E9FC(void*, int);
int fn_8025C520(TargetMatchOwner*, int, TargetMatchCallback*);
}
typedef char TargetMatchValueOffset[sizeof(TargetMatchOwner)==0x30?1:-1];
#endif

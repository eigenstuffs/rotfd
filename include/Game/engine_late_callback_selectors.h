#ifndef GAME_ENGINE_LATE_CALLBACK_SELECTORS_H
#define GAME_ENGINE_LATE_CALLBACK_SELECTORS_H

typedef unsigned long LateCallbackWord;

struct LateSelectorOwner;
struct LateCallback;
typedef int (LateSelectorOwner::*LateMemberPointer)(int event, LateCallback *callback);
struct LateCallback {
    char unknown00[0x28];
    unsigned short flags28;
    short index2A;
};

struct LateSelectorPrefix { LateCallbackWord unknown00, unknown04; };
/* Partial owner view: the inherited eight-byte prefix precedes its vtable. */
struct LateSelectorOwner : LateSelectorPrefix {
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
    virtual int slot38(int event, LateCallback *callback);
    virtual int slot3C(int event, LateCallback *callback);
    virtual int slot40(int event, LateCallback *callback);
    virtual int slot44(int event, LateCallback *callback);
    virtual int slot48(int event, LateCallback *callback);
    virtual int slot4C(int event, LateCallback *callback);
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
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
};

extern "C" {
extern LateCallbackWord lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
void fn_8025EF34(void*, LateMemberPointer, int);
void fn_8025EEB4(void*, LateMemberPointer);
void fn_8025EB70(void*, LateMemberPointer);
LateCallback* fn_8025F074(void*, LateMemberPointer);
void fn_8025F4F4(LateCallback*, int, const char*);
void fn_8025F658(LateCallback*, int);
void fn_8025F694(LateCallback*, LateCallbackWord);
void fn_8025F620(LateCallback*, LateCallbackWord);
signed char fn_8025E9FC(void*, int);
int fn_80253850(LateSelectorOwner*, int, LateCallback*);
int fn_80253B0C(LateSelectorOwner*, int, LateCallback*);
int fn_80253DC8(LateSelectorOwner*, int, LateCallback*);
int fn_80254084(LateSelectorOwner*, int, LateCallback*);
int fn_80254340(LateSelectorOwner*, int, LateCallback*);
int fn_802545FC(LateSelectorOwner*, int, LateCallback*);
int fn_8025D874(LateSelectorOwner*, int, LateCallback*);
}

#endif

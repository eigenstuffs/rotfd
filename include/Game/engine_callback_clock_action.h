#ifndef GAME_ENGINE_CALLBACK_CLOCK_ACTION_H
#define GAME_ENGINE_CALLBACK_CLOCK_ACTION_H

typedef unsigned long ClockActionWord;

struct ClockActionMemberPointer { ClockActionWord adjustment, tableOffset, function; };
struct ClockActionCallback {
    char unknown00[0x28];
    unsigned short flags28;
    short index2A;
};

struct ClockActionPrefix { ClockActionWord unknown00, unknown04; };
/* Partial owner view: the inherited eight-byte prefix precedes its vtable. */
struct ClockActionOwner : ClockActionPrefix {
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
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
};

extern "C" {
extern ClockActionWord lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
void fn_8025EF34(void*, ClockActionMemberPointer, int);
void fn_8025EEB4(void*, ClockActionMemberPointer);
void fn_8025EB70(void*, ClockActionMemberPointer);
ClockActionCallback* fn_8025F074(void*, ClockActionMemberPointer);
void fn_8025F4F4(ClockActionCallback*, int, const char*);
void fn_8025F658(ClockActionCallback*, int);
void fn_8025F694(ClockActionCallback*, ClockActionWord);
void fn_8025F620(ClockActionCallback*, ClockActionWord);
signed char fn_8025E9FC(void*, int);
int fn_8025D874(ClockActionOwner*, int, ClockActionCallback*);
}

#endif

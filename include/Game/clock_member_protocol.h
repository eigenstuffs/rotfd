#ifndef GAME_CLOCK_MEMBER_PROTOCOL_H
#define GAME_CLOCK_MEMBER_PROTOCOL_H

typedef unsigned long ClockMemberWord;

struct ClockMemberOwner;
struct ClockMemberCallback;
typedef int (ClockMemberOwner::*ClockMemberPointer)(int, ClockMemberCallback *);
struct ClockMemberCallback {
    char unknown00[0x28];
    unsigned short flags28;
    short index2A;
};

struct ClockMemberPrefix { ClockMemberWord unknown00, unknown04; };
/* Partial owner view: the inherited eight-byte prefix precedes its vtable. */
struct ClockMemberOwner : ClockMemberPrefix {
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
    virtual int slot74(int, ClockMemberCallback *);
    virtual int slot78(int, ClockMemberCallback *);
    virtual void slot7C(int);
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    char unknown0C[0x20];
    float value2C;
};

extern "C" {
extern ClockMemberWord lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
void fn_8025EF34(void*, ClockMemberPointer, int);
void fn_8025EEB4(void*, ClockMemberPointer);
void fn_8025EB70(void*, ClockMemberPointer);
ClockMemberCallback* fn_8025F074(void*, ClockMemberPointer);
void fn_8025F4F4(ClockMemberCallback*, int, const char*);
void fn_8025F658(ClockMemberCallback*, int);
void fn_8025F694(ClockMemberCallback*, ClockMemberWord);
void fn_8025F620(ClockMemberCallback*, ClockMemberWord);
signed char fn_8025E9FC(void*, int);
int fn_8025DB30(ClockMemberOwner*, int, ClockMemberCallback*);
int fn_8025D874(ClockMemberOwner*, int, ClockMemberCallback*);
}
typedef char IndexedActionValueOffset[sizeof(ClockMemberOwner)==0x30?1:-1];
#endif

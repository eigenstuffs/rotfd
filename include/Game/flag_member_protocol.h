#ifndef GAME_FLAG_MEMBER_PROTOCOL_H
#define GAME_FLAG_MEMBER_PROTOCOL_H

typedef unsigned long FlagMemberWord;

struct FlagMemberOwner;
struct FlagMemberCallback;
typedef int (FlagMemberOwner::*FlagMemberMemberPointer)(int,FlagMemberCallback *);
struct FlagMemberCallback {
    char unknown00[0x28];
    unsigned short flags28;
    short index2A;
};

struct FlagMemberPrefix { FlagMemberWord unknown00, unknown04; };
/* Partial owner view: the inherited eight-byte prefix precedes its vtable. */
struct FlagMemberHandle {union {unsigned long value;struct {signed int tag:8,index:24;}bits;};};
struct FlagMemberOwner : FlagMemberPrefix {
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
    virtual const FlagMemberHandle& slot78(int);
    virtual void slot7C(int);
    virtual void slot80();
    virtual int slot84(int,FlagMemberCallback *);
    virtual int slot88(int,FlagMemberCallback *);
    char unknown0C[0x1C];
    FlagMemberHandle target28;
    float value2C;
};

extern "C" {
extern FlagMemberWord lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
void fn_8025EF34(void*, FlagMemberMemberPointer, int);
void fn_8025EEB4(void*, FlagMemberMemberPointer);
void fn_8025EB70(void*, FlagMemberMemberPointer);
FlagMemberCallback* fn_8025F074(void*, FlagMemberMemberPointer);
void fn_8025F4F4(FlagMemberCallback*, int, const char*);
void fn_8025F658(FlagMemberCallback*, int);
void fn_8025F694(FlagMemberCallback*, FlagMemberWord);
void fn_8025F620(FlagMemberCallback*, FlagMemberWord);
signed char fn_8025E9FC(void*, int);
int fn_8025C858(FlagMemberOwner*, int, FlagMemberCallback*);
int fn_8025C520(FlagMemberOwner*, int, FlagMemberCallback*);
}
typedef char FlagMemberValueOffset[sizeof(FlagMemberOwner)==0x30?1:-1];
#endif

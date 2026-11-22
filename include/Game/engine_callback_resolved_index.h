#ifndef GAME_ENGINE_CALLBACK_RESOLVED_INDEX_H
#define GAME_ENGINE_CALLBACK_RESOLVED_INDEX_H

typedef unsigned long ResolvedIndexWord;

struct ResolvedIndexMemberPointer { ResolvedIndexWord adjustment, tableOffset, function; };
struct ResolvedIndexCallback {
    char unknown00[0x28];
    unsigned short flags28;
    short index2A;
};

struct ResolvedIndexPrefix { ResolvedIndexWord unknown00, unknown04; };
/* Partial owner view: the inherited eight-byte prefix precedes its vtable. */
struct ResolvedIndexHandle {union {unsigned long value;struct {signed int tag:8,index:24;}bits;};};
struct ResolvedIndexOwner {char unknown00[0x2C];float value2C;char unknown30[0x40];ResolvedIndexHandle target70;};
struct ResolvedIndexTarget:ResolvedIndexPrefix {
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
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void slotBC();
    virtual void slotC0();
    virtual void slotC4();
    virtual void slotC8();
    virtual void slotCC();
    virtual void slotD0();
    virtual void slotD4();
    virtual void slotD8();
    virtual void slotDC();
    virtual void slotE0();
    virtual void slotE4();
    virtual void slotE8();
    virtual void slotEC();
    virtual void slotF0();
    virtual void slotF4(int);
};

extern "C" {
extern ResolvedIndexWord lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
void fn_8025EF34(void*, ResolvedIndexMemberPointer, int);
void fn_8025EEB4(void*, ResolvedIndexMemberPointer);
void fn_8025EB70(void*, ResolvedIndexMemberPointer);
ResolvedIndexCallback* fn_8025F074(void*, ResolvedIndexMemberPointer);
void fn_8025F4F4(ResolvedIndexCallback*, int, const char*);
void fn_8025F658(ResolvedIndexCallback*, int);
void fn_8025F694(ResolvedIndexCallback*, ResolvedIndexWord);
void fn_8025F620(ResolvedIndexCallback*, ResolvedIndexWord);
signed char fn_8025E9FC(void*, int);
void*fn_801F7EB8(const ResolvedIndexHandle*);
int slot78__13MovingAgent_ZFv(ResolvedIndexOwner*, int, ResolvedIndexCallback*);
}
typedef char ResolvedIndexValueOffset[sizeof(ResolvedIndexOwner)==0x74?1:-1];
#endif

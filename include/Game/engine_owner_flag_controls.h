#ifndef GAME_ENGINE_OWNER_FLAG_CONTROLS_H
#define GAME_ENGINE_OWNER_FLAG_CONTROLS_H

typedef unsigned long Word;
struct OwnerFlagStorage{char unknown00[8];};
struct OwnerFlagControls:OwnerFlagStorage{
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
virtual void slotA8(Word,int);
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void slotBC(const void*,int);
char unknown0C[0x24];unsigned long long flags;};

struct IndexedFlagControls;

extern "C" void slotF8__12ObjectMove_ZFv(OwnerFlagControls*);
extern "C" signed char fn_8021F2D0(const OwnerFlagControls*);
extern "C" signed char fn_8021F308(const OwnerFlagControls*);
extern "C" void slot40__12ObjectMove_ZFPC4Vec3PC4Vec3PC4Vec3if(OwnerFlagControls*, void*, const void*);
extern "C" void fn_80224B7C(IndexedFlagControls*, unsigned long long, int);
extern "C" signed char fn_80224BB4(const IndexedFlagControls*, unsigned long long, int);

#endif

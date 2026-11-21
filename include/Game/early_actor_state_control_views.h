#ifndef GAME_EARLY_ACTOR_STATE_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_STATE_CONTROL_VIEWS_H
struct StateActor;
struct StateHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct StateEntry{StateActor*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct StateManager{int count,capacity;StateEntry*entries;};
struct StateContext{char unknown00[0x118];StateManager*manager;};
extern "C" StateContext lbl_801E9D24;
struct StateActor{char unknown00[0x30];unsigned long long flags;char unknown38[0x2E8];int state;char unknown324[0x2C];float speed;char unknown354[0x98];float speedCopy;char unknown3F0[5];unsigned char enabled;};
inline StateActor*resolveState(const StateHandle&h){StateEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct StatePrefix{char unknown00[4];};
struct StateObject:StatePrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual const StateHandle*getHandle();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void setState(int);
char unknown08[0x7C];signed char mode;
};
extern "C" {signed char fn_8006653C(StateObject*,int);signed char fn_80069654(StateObject*,short);void fn_8009FABC(StateActor*,int);void fn_8006BA70(StateObject*,int);extern const float lbl_803787D4;}

#endif

/* Original actor state-transition control; see docs/notes/game-actor-state-transition.md. */
struct StateActor;
struct StateHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct StateEntry{StateActor*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct StateManager{int count,capacity;StateEntry*entries;};
struct StateContext{char unknown00[0x118];StateManager*manager;};
extern "C" StateContext lbl_801E9D24;
struct StateActor{char unknown00[0x30];unsigned long long flags;char unknown38[0x2E8];int state;};
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
virtual void setState(short);
char unknown08[0x7C];signed char mode;
};
extern "C" {signed char fn_8006653C(StateObject*,int);signed char fn_80069654(StateObject*,int);void fn_8006BA70(StateObject*,int);}

extern "C" signed char fn_80069654(StateObject* self, int state)
{
    if (!fn_8006653C(self, 0xD) &&
        (!fn_8006653C(self, 0xC) || (short)state == 0xD ||
         (fn_8006653C(self, 0xC) && self->mode == 1))) {
        if ((short)state != resolveState(*self->getHandle())->state) {
            self->setState((short)state);
            if ((short)state == 0xD)
                fn_8006BA70(self, 0);
        }
    }
    return 1;
}

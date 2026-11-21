#include "Game/platform_followup_controls.h"

struct Handle_801F7F10 {
    signed int generation : 8, index : 24;
    Handle_801F7F10() { index = 0; generation = 0; }
    ~Handle_801F7F10();
};
extern "C" void fn_8025EAB0(void*, int, const Handle_801F7F10*, float);

extern "C" void fn_802603A0(void*, int key, void* receiver, float time) {
    Handle_801F7F10 empty;
    fn_8025EAB0(receiver, key, &empty, time);
}

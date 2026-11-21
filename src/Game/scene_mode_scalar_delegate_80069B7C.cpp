/* Original scene-mode scalar forwarding; see docs/notes/game-scene-mode-scalar-delegate.md. */
typedef unsigned long Word;
struct Mode{char opaque00[0xF0];int selected;};
struct World{char opaque00[0x15058];Mode*mode;};
struct Context{char opaque00[0x124];World*world;};
extern "C"{extern Context lbl_801E9D24;void fn_80055EE4(Mode*,int);}
extern "C" void fn_80069B7C(void*ignoredSelf,int value){fn_80055EE4(lbl_801E9D24.world->mode, (short)value);}

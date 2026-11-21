#ifndef GAME_EARLY_COMPONENT_CALLS_H
#define GAME_EARLY_COMPONENT_CALLS_H
struct ComponentOwner {char unknown00[0x318];char component[1];};
extern "C" {void fn_80098AF4(ComponentOwner*);void fn_80098CD0(ComponentOwner*);void fn_80098CB0(ComponentOwner*);void fn_8007D6A0(void*,int);}
#endif

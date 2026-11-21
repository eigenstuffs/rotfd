#include "Game/platform_small_controls.h"

typedef unsigned int u32;
extern "C" {
int PADReset(u32);
void PADControlAllMotors(u32*);
}

extern "C" void fn_80275B54() {
    PADReset(0xF0000000);
    u32 commands[4];
    commands[0] = 0;
    commands[1] = 0;
    commands[2] = 0;
    commands[3] = 0;
    PADControlAllMotors(commands);
}

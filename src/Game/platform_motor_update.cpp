#include "Game/platform_followup_controls.h"

struct PlatformMotorOwner { char unknown00[0x70]; signed char enabled; };
extern "C" void PADControlMotor(int, unsigned int);

extern "C" void fn_80275F24(PlatformMotorOwner* self, int port,
                           unsigned char amplitude, unsigned char active) {
    if ((amplitude > 127 || active) && self->enabled)
        PADControlMotor(port, 1);
    else
        PADControlMotor(port, 0);
}

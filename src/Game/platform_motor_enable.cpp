#include "Game/platform_followup_controls.h"

struct PlatformMotorOwner { char unknown00[0x70]; signed char enabled; };
extern "C" void PADControlMotor(int, unsigned int);

extern "C" void fn_80275F7C(PlatformMotorOwner* self, int port, signed char enabled) {
    if (!enabled)
        PADControlMotor(port, 0);
    self->enabled = enabled;
}

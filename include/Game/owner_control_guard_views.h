#ifndef GAME_OWNER_CONTROL_GUARD_VIEWS_H
#define GAME_OWNER_CONTROL_GUARD_VIEWS_H
struct ControlGuardVector {
    float x, y, z;
    ControlGuardVector& operator=(const ControlGuardVector& other)
    { x = other.x; y = other.y; z = other.z; return *this; }
};
struct ControlGuardAgent {
    char unknown00[0x38];
    unsigned long long flags38;
    char unknown40[0x104];
    ControlGuardVector velocity;
    char unknown150[0xC];
    ControlGuardVector angularVelocity;
    char unknown168[0x1B0];
    char controls;
    char unknown319[0x3F];
    ControlGuardVector movement;
    char unknown364[0xA0];
    signed char enabled404;
    char unknown405[5];
    signed char enabled40A;
};
struct ControlGuardAction { char unknown00[8]; ControlGuardAgent* agent; ControlGuardAgent* target; };
struct ControlGuardContext { char unknown00[0x164]; void* input; };
extern "C" {
extern ControlGuardContext lbl_801E9D24;
extern const ControlGuardVector game_vec3_zero;
int fn_80286058(void*, int);
signed char fn_8007D604(void*, int);
void fn_8007D6A0(void*, int);
void fn_8007D7F4(void*, int);
void fn_800B7214(void*, int, bool*, int);
}
#endif

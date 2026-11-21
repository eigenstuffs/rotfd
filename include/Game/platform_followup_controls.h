#ifndef GAME_PLATFORM_FOLLOWUP_CONTROLS_H
#define GAME_PLATFORM_FOLLOWUP_CONTROLS_H

struct PlatformResetRecord;
struct PlatformHierarchyReset;
struct PlatformMotorOwner;
struct PlatformBufferOwner;
struct SixHandleResource_802EA840;

extern "C" {
void fn_802603A0(void*, int key, void* receiver, float time);
void fn_802676F4(PlatformResetRecord*);
void fn_8026A63C(PlatformHierarchyReset*);
void fn_80271980(SixHandleResource_802EA840*, unsigned long* stream);
void fn_80275F24(PlatformMotorOwner*, int port, unsigned char amplitude, unsigned char active);
void fn_80275F7C(PlatformMotorOwner*, int port, signed char enabled);
int fn_80276A08(void*);
void fn_8028C494(PlatformBufferOwner*);
}

#endif

#ifndef GAME_EARLY_MOTION_FLAGS_VIEWS_H
#define GAME_EARLY_MOTION_FLAGS_VIEWS_H
typedef unsigned long long MotionFlags64;
struct MotionFlagOwner{char unknown00[0x30];MotionFlags64 flags;char unknown38[0x10c];float x,y,z;char unknown150[0x1c8];char component[0x40];float motionX,motionY,motionZ;char unknown364[0xd0];signed char ready,overrideReady;char unknown436[2];MotionFlags64 inputFlags;};
struct MotionFlagInput{char unknown00[0x28];MotionFlags64 flags;};
struct MotionFlagVector{float x,y,z;};
extern "C"{extern const MotionFlagVector game_vec3_zero;void slot18__10CActorMoveFv(MotionFlagOwner*);void slot34__10CActorMoveFv(MotionFlagOwner*);void fn_8007DCDC(void*);void fn_8007D6A0(void*,int);int slot5C__10CActorMoveFv(MotionFlagOwner*,const MotionFlagInput*);void fn_80093958(MotionFlagOwner*);void fn_80094378(MotionFlagOwner*);void fn_80092E70(MotionFlagOwner*);void fn_8009332C(MotionFlagOwner*);}
#endif

#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
extern NativeRuntimeBaseList<2> lbl_802B9280;
extern const char lbl_8029D7F0[];
extern const char lbl_8029D800[];
extern const char lbl_8029D810[];
extern const char lbl_8029D828[];
extern const char lbl_8029D840[];
extern const char lbl_8029D854[];
extern const char lbl_8029D864[];
extern const char lbl_8029D878[];
extern const char lbl_8029D888[];
extern const char lbl_8029D894[];
extern const char lbl_8029D8B0[];
extern const char lbl_8029D8CC[];
extern const char lbl_8029D8E4[];
extern const char lbl_8029D8FC[];
extern const char lbl_8029D910[];
extern const char lbl_8029D930[];
extern const char lbl_8029D948[];
extern const char lbl_8029D964[];
extern const char lbl_8029D97C[];
extern const char lbl_8029D990[];
extern const char lbl_8029D9A4[];
extern const char lbl_8029D9B4[];
extern const char lbl_8029D9C4[];
extern const char lbl_8029D9D4[];
extern const char lbl_8029D9E0[];
extern const char lbl_8029D9F0[];
extern const char lbl_8029DA00[];
extern const char lbl_8029DA10[];
extern const char lbl_8029DA20[];
extern const char lbl_8029DA30[];
extern const char lbl_8029DA40[];
extern const char lbl_8029DA4C[];
extern const char lbl_8029DA58[];
extern const char lbl_8029DA68[];
extern const char lbl_8029DA88[];
extern const char lbl_8029DAA0[];
extern const char lbl_8029DAC0[];
extern const char lbl_8029DAD0[];
extern const char lbl_8029DAE4[];
extern const char lbl_8029DAF4[];
extern const char lbl_8029DB04[];
extern const char lbl_8029DB14[];
extern const char lbl_8029DB2C[];
extern const char lbl_8029DB44[];
extern const char lbl_8029DB60[];
extern const char lbl_8029DB78[];
extern const char lbl_8029DB90[];
extern const char lbl_8029DBA4[];
extern const char lbl_8029DBB0[];
extern const char lbl_8029DBBC[];
extern const char lbl_8029DBD4[];
extern const char lbl_8029DBE4[];
extern const char lbl_8029DBF0[];
extern const char lbl_8029DBFC[];
extern const char lbl_8029DC08[];
extern const char lbl_8029DC18[];
extern const char lbl_8029DC24[];
extern const char lbl_8029DC30[];
extern const char lbl_8029DC3C[];
extern const char lbl_80378B94[];

// Projectile damping constant immediately precedes the native state RTTI.
float lbl_80374A18 = 0.99f;

// CState
NativeRuntimeTypeInfo lbl_80374A1C = { lbl_80378B94, 0 };

// CStateSBBase
NativeRuntimeTypeInfo lbl_80374A24 = { lbl_8029D800, lbl_802B87A0.entries };

// CStateCelebrate
NativeRuntimeTypeInfo lbl_80374A2C = { lbl_8029D7F0, lbl_802B87AC.entries };

// CStateFaceCameraForIdle
NativeRuntimeTypeInfo lbl_80374A34 = { lbl_8029D810, lbl_802B87DC.entries };

// CStateHasWaterhelmet
NativeRuntimeTypeInfo lbl_80374A3C = { lbl_8029D828, lbl_802B880C.entries };

// CStateInvulnerable
NativeRuntimeTypeInfo lbl_80374A44 = { lbl_8029D840, lbl_802B883C.entries };

// CStateIdleAnims
NativeRuntimeTypeInfo lbl_80374A4C = { lbl_8029D854, lbl_802B886C.entries };

// CStateFaceTarget
NativeRuntimeTypeInfo lbl_80374A54 = { lbl_8029D864, lbl_802B889C.entries };

// CStateListen
NativeRuntimeTypeInfo lbl_80374A5C = { lbl_8029D878, lbl_802B88CC.entries };

// CStateTalk
NativeRuntimeTypeInfo lbl_80374A64 = { lbl_8029D888, lbl_802B88FC.entries };

// CStateThrowWaterBallJumping
NativeRuntimeTypeInfo lbl_80374A6C = { lbl_8029D894, lbl_802B892C.entries };

// CStateThrowWaterBallMoving
NativeRuntimeTypeInfo lbl_80374A74 = { lbl_8029D8B0, lbl_802B895C.entries };

// CStateThrowWaterBall
NativeRuntimeTypeInfo lbl_80374A7C = { lbl_8029D8CC, lbl_802B898C.entries };

// CStateCostumeMermaidMan
NativeRuntimeTypeInfo lbl_80374A84 = { lbl_8029D8E4, lbl_802B89BC.entries };

// CStateCostumeKarate
NativeRuntimeTypeInfo lbl_80374A8C = { lbl_8029D8FC, lbl_802B89F0.entries };

// CStateCostumeTreasureHunting
NativeRuntimeTypeInfo lbl_80374A94 = { lbl_8029D910, lbl_802B8A24.entries };

// CStateCostumeReefblower
NativeRuntimeTypeInfo lbl_80374A9C = { lbl_8029D930, lbl_802B8A58.entries };

// CStateCostumeJellyfishing
NativeRuntimeTypeInfo lbl_80374AA4 = { lbl_8029D948, lbl_802B8A8C.entries };

// CStateCostumeBase
NativeRuntimeTypeInfo lbl_80374AAC = { lbl_8029D97C, lbl_802B8AC0.entries };

// CStateCostumeDefault
NativeRuntimeTypeInfo lbl_80374AB4 = { lbl_8029D964, lbl_802B8AD4.entries };

// CStateInUnderwear
NativeRuntimeTypeInfo lbl_80374ABC = { lbl_8029D990, lbl_802B8B30.entries };

// CStateInWater
NativeRuntimeTypeInfo lbl_80374AC4 = { lbl_8029D9A4, lbl_802B8B60.entries };

// CStateDefeated
NativeRuntimeTypeInfo lbl_80374ACC = { lbl_8029D9B4, lbl_802B8B90.entries };

// CStateGetHit
NativeRuntimeTypeInfo lbl_80374AD4 = { lbl_8029D9C4, lbl_802B8BC0.entries };

// CStateThrow
NativeRuntimeTypeInfo lbl_80374ADC = { lbl_8029D9D4, lbl_802B8BF0.entries };

// CStateCarryFall
NativeRuntimeTypeInfo lbl_80374AE4 = { lbl_8029D9E0, lbl_802B8C20.entries };

// CStateCarryJump
NativeRuntimeTypeInfo lbl_80374AEC = { lbl_8029D9F0, lbl_802B8C50.entries };

// CStateCarryWalk
NativeRuntimeTypeInfo lbl_80374AF4 = { lbl_8029DA00, lbl_802B8C80.entries };

// CStateCarryIdle
NativeRuntimeTypeInfo lbl_80374AFC = { lbl_8029DA10, lbl_802B8CB0.entries };

// CStatePickup
NativeRuntimeTypeInfo lbl_80374B04 = { lbl_8029DA20, lbl_802B8CE0.entries };

// CStateNoMove
NativeRuntimeTypeInfo lbl_80374B0C = { lbl_8029DA30, lbl_802B8D10.entries };

// CStateGetUp
NativeRuntimeTypeInfo lbl_80374B14 = { lbl_8029DA40, lbl_802B8D40.entries };

// CStateGlide
NativeRuntimeTypeInfo lbl_80374B1C = { lbl_8029DA4C, lbl_802B8D70.entries };

// CStateBellySlam
NativeRuntimeTypeInfo lbl_80374B24 = { lbl_8029DA58, lbl_802B8DA0.entries };

// CStateReefBlowerActiveRunning
NativeRuntimeTypeInfo lbl_80374B2C = { lbl_8029DA68, lbl_802B8DD0.entries };

// CStateReefBlowerActive
NativeRuntimeTypeInfo lbl_80374B34 = { lbl_8029DA88, lbl_802B8E00.entries };

// CStateTreasureDetectorActive
NativeRuntimeTypeInfo lbl_80374B3C = { lbl_8029DAA0, lbl_802B8E30.entries };

// CStateBounce
NativeRuntimeTypeInfo lbl_80374B44 = { lbl_8029DAC0, lbl_802B8E60.entries };

// CStateCannonFire
NativeRuntimeTypeInfo lbl_80374B4C = { lbl_8029DAD0, lbl_802B8E90.entries };

// CStateInCannon
NativeRuntimeTypeInfo lbl_80374B54 = { lbl_8029DAE4, lbl_802B8EC0.entries };

// CStateHookHang
NativeRuntimeTypeInfo lbl_80374B5C = { lbl_8029DAF4, lbl_802B8EF0.entries };

// CStateNetSwipe
NativeRuntimeTypeInfo lbl_80374B64 = { lbl_8029DB04, lbl_802B8F20.entries };

// CStateKarateDuckAttack
NativeRuntimeTypeInfo lbl_80374B6C = { lbl_8029DB14, lbl_802B8F50.entries };

// CStateKarateJumpAttack
NativeRuntimeTypeInfo lbl_80374B74 = { lbl_8029DB2C, lbl_802B8F80.entries };

// CStateKaratePsychoCrusher
NativeRuntimeTypeInfo lbl_80374B7C = { lbl_8029DB44, lbl_802B8FB0.entries };

// CStateKarateDoubleChop
NativeRuntimeTypeInfo lbl_80374B84 = { lbl_8029DB60, lbl_802B8FE0.entries };

// CStateKaratePowerChop
NativeRuntimeTypeInfo lbl_80374B8C = { lbl_8029DB78, lbl_802B9010.entries };

// CStateKarateChop
NativeRuntimeTypeInfo lbl_80374B94 = { lbl_8029DB90, lbl_802B9040.entries };

// CStateDuck
NativeRuntimeTypeInfo lbl_80374B9C = { lbl_8029DBA4, lbl_802B9070.entries };

// CStateFall
NativeRuntimeTypeInfo lbl_80374BA4 = { lbl_8029DBB0, lbl_802B90A0.entries };

// CStateSpringboardJump
NativeRuntimeTypeInfo lbl_80374BAC = { lbl_8029DBBC, lbl_802B90D0.entries };

// CStatePowerJump
NativeRuntimeTypeInfo lbl_80374BB4 = { lbl_8029DBD4, lbl_802B9100.entries };

// CStateJump
NativeRuntimeTypeInfo lbl_80374BBC = { lbl_8029DBE4, lbl_802B9130.entries };

// CStateSlide
NativeRuntimeTypeInfo lbl_80374BC4 = { lbl_8029DBF0, lbl_802B9160.entries };

// CStateSkid
NativeRuntimeTypeInfo lbl_80374BCC = { lbl_8029DBFC, lbl_802B9190.entries };

// CStateHoopRoll
NativeRuntimeTypeInfo lbl_80374BD4 = { lbl_8029DC08, lbl_802B91C0.entries };

// CStateRun
NativeRuntimeTypeInfo lbl_80374BDC = { lbl_8029DC18, lbl_802B91F0.entries };

// CStateJog
NativeRuntimeTypeInfo lbl_80374BE4 = { lbl_8029DC24, lbl_802B9220.entries };

// CStateWalk
NativeRuntimeTypeInfo lbl_80374BEC = { lbl_8029DC30, lbl_802B9250.entries };

// CStateIdle
NativeRuntimeTypeInfo lbl_80374BF4 = { lbl_8029DC3C, lbl_802B9280.entries };

}

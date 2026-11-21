#ifndef GAME_STATE_NATIVE_OPERATION_RECORDS_SELECTED_H
#define GAME_STATE_NATIVE_OPERATION_RECORDS_SELECTED_H
#ifdef __cplusplus
struct CompletionOwner;
struct Control;
struct EffectOwner;
struct EventOwner;
struct IndexStateOwner;
struct InputOwner;
struct MiscControlOwner;
struct MotionOwner;
struct NativeRuntimeTypeInfo;
struct Object_80088C34;
struct Object_8008929C;
struct Object_80089FB4;
struct Object_8008EEAC;
struct Object_8008EF38;
struct Object_8008EFC4;
struct Object_8008F050;
struct Object_8008F0DC;
struct Object_8008F168;
struct Object_8008F1F4;
struct Object_8008F5FC;
struct Object_8008F82C;
struct Object_8008F8B8;
struct Object_8008F944;
struct Object_8008FA5C;
struct Object_8008FAE8;
struct Object_8008FB74;
struct Object_8008FC00;
struct Object_8008FE30;
struct Object_8008FEBC;
struct Owner;
struct PhaseOwner;
struct ReflectionControlOwner;
struct SceneControlOwner;
struct ScopedOwner;
struct SelectionOwner;
struct Self;
struct StateOwner;
struct View;
#else
typedef struct CompletionOwner CompletionOwner;
typedef struct Control Control;
typedef struct EffectOwner EffectOwner;
typedef struct EventOwner EventOwner;
typedef struct IndexStateOwner IndexStateOwner;
typedef struct InputOwner InputOwner;
typedef struct MiscControlOwner MiscControlOwner;
typedef struct MotionOwner MotionOwner;
typedef struct NativeRuntimeTypeInfo NativeRuntimeTypeInfo;
typedef struct Object_80088C34 Object_80088C34;
typedef struct Object_8008929C Object_8008929C;
typedef struct Object_80089FB4 Object_80089FB4;
typedef struct Object_8008EEAC Object_8008EEAC;
typedef struct Object_8008EF38 Object_8008EF38;
typedef struct Object_8008EFC4 Object_8008EFC4;
typedef struct Object_8008F050 Object_8008F050;
typedef struct Object_8008F0DC Object_8008F0DC;
typedef struct Object_8008F168 Object_8008F168;
typedef struct Object_8008F1F4 Object_8008F1F4;
typedef struct Object_8008F5FC Object_8008F5FC;
typedef struct Object_8008F82C Object_8008F82C;
typedef struct Object_8008F8B8 Object_8008F8B8;
typedef struct Object_8008F944 Object_8008F944;
typedef struct Object_8008FA5C Object_8008FA5C;
typedef struct Object_8008FAE8 Object_8008FAE8;
typedef struct Object_8008FB74 Object_8008FB74;
typedef struct Object_8008FC00 Object_8008FC00;
typedef struct Object_8008FE30 Object_8008FE30;
typedef struct Object_8008FEBC Object_8008FEBC;
typedef struct Owner Owner;
typedef struct PhaseOwner PhaseOwner;
typedef struct ReflectionControlOwner ReflectionControlOwner;
typedef struct SceneControlOwner SceneControlOwner;
typedef struct ScopedOwner ScopedOwner;
typedef struct SelectionOwner SelectionOwner;
typedef struct Self Self;
typedef struct StateOwner StateOwner;
typedef struct View View;
#endif

/* Existing native C-entry records: every field keeps its accepted provider
 * prototype. Genuine C++ destructor fields use the compiler entry ABI. */
typedef struct CStateInUnderwearNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_80089FB4 *(*destroy)(Object_80089FB4 *, short);
    void(*slot0C)(Control *);
    void(*slot10)(Control *);
    void(*slot14)(Control *);
    void(*slot18)(void);
} CStateInUnderwearNativeOperations;

typedef struct CStateInWaterNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008929C *(*destroy)(Object_8008929C *, short);
    void(*slot0C)(SelectionOwner *);
    void(*slot10)(EffectOwner *);
    void(*slot14)(SceneControlOwner *);
    void(*slot18)(void);
} CStateInWaterNativeOperations;

typedef struct CStateGetHitNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_80088C34 *(*destroy)(Object_80088C34 *, short);
    void(*slot0C)(Self *);
    void(*slot10)(Owner *, double);
    void(*slot14)(CompletionOwner *);
    void(*slot18)(void);
} CStateGetHitNativeOperations;

typedef struct CStateCarryFallNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008EEAC *(*destroy)(Object_8008EEAC *, short);
    void(*slot0C)(Owner *);
    void(*slot10)(CompletionOwner *, double);
    void(*slot14)(Owner *);
    void(*slot18)(void);
} CStateCarryFallNativeOperations;

typedef struct CStateCarryJumpNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008EF38 *(*destroy)(Object_8008EF38 *, short);
    void(*slot0C)(MotionOwner *);
    void(*slot10)(CompletionOwner *, float);
    void(*slot14)(CompletionOwner *);
    void(*slot18)(void);
} CStateCarryJumpNativeOperations;

typedef struct CStateCarryWalkNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008EFC4 *(*destroy)(Object_8008EFC4 *, short);
    void(*slot0C)(CompletionOwner *);
    void(*slot10)(CompletionOwner *, double);
    void(*slot14)(Owner *);
    void(*slot18)(void);
} CStateCarryWalkNativeOperations;

typedef struct CStateCarryIdleNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008F050 *(*destroy)(Object_8008F050 *, short);
    void(*slot0C)(Owner *);
    void(*slot10)(Owner *, double);
    void(*slot14)(Owner *);
    void(*slot18)(void);
} CStateCarryIdleNativeOperations;

typedef struct CStatePickupNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008F0DC *(*destroy)(Object_8008F0DC *, short);
    void(*slot0C)(Owner *);
    void(*slot10)(Owner *);
    void(*slot14)(Owner *);
    void(*slot18)(void);
} CStatePickupNativeOperations;

typedef struct CStateNoMoveNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008F168 *(*destroy)(Object_8008F168 *, short);
    void(*slot0C)(CompletionOwner *);
    void(*slot10)(Owner *, double);
    void(*slot14)(CompletionOwner *);
    void(*slot18)(Owner *, int, int);
} CStateNoMoveNativeOperations;

typedef struct CStateGetUpNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008F1F4 *(*destroy)(Object_8008F1F4 *, short);
    void(*slot0C)(StateOwner *);
    void(*slot10)(StateOwner *, double);
    void(*slot14)(StateOwner *);
    void(*slot18)(void);
} CStateGetUpNativeOperations;

typedef struct CStateInCannonNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    void*(*destroy)(View *, int);
    void(*slot0C)(InputOwner *);
    void(*slot10)(InputOwner *);
    void(*slot14)(InputOwner *);
    void(*slot18)(Owner *, int, int);
} CStateInCannonNativeOperations;

typedef struct CStateNetSwipeNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008F5FC *(*destroy)(Object_8008F5FC *, short);
    void(*slot0C)(InputOwner *);
    void(*slot10)(ScopedOwner *, double);
    void(*slot14)(Owner *);
    void(*slot18)(void);
} CStateNetSwipeNativeOperations;

typedef struct CStateKarateDoubleChopNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008F82C *(*destroy)(Object_8008F82C *, short);
    void(*slot0C)(Owner *);
    void(*slot10)(Owner *, double);
    void(*slot14)(Owner *);
    void(*slot18)(void);
} CStateKarateDoubleChopNativeOperations;

typedef struct CStateKaratePowerChopNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008F8B8 *(*destroy)(Object_8008F8B8 *, short);
    void(*slot0C)(Owner *);
    void(*slot10)(Owner *);
    void(*slot14)(Owner *);
    void(*slot18)(void);
} CStateKaratePowerChopNativeOperations;

typedef struct CStateKarateChopNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008F944 *(*destroy)(Object_8008F944 *, short);
    void(*slot0C)(Owner *);
    void(*slot10)(MiscControlOwner *, double);
    void(*slot14)(ReflectionControlOwner *);
    void(*slot18)(void);
} CStateKarateChopNativeOperations;

typedef struct CStateFallNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008FA5C *(*destroy)(Object_8008FA5C *, short);
    void(*slot0C)(Owner *);
    void(*slot10)(MotionOwner *, double);
    void(*slot14)(Owner *);
    void(*slot18)(void);
} CStateFallNativeOperations;

typedef struct CStateSpringboardJumpNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008FAE8 *(*destroy)(Object_8008FAE8 *, short);
    void(*slot0C)(MotionOwner *);
    void(*slot10)(MotionOwner *, double);
    void(*slot14)(IndexStateOwner *);
    void(*slot18)(void);
} CStateSpringboardJumpNativeOperations;

typedef struct CStatePowerJumpNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008FB74 *(*destroy)(Object_8008FB74 *, short);
    void(*slot0C)(Self *);
    void(*slot10)(EventOwner *, float);
    void(*slot14)(CompletionOwner *);
    void(*slot18)(void);
} CStatePowerJumpNativeOperations;

typedef struct CStateJumpNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008FC00 *(*destroy)(Object_8008FC00 *, short);
    void(*slot0C)(MotionOwner *);
    void(*slot10)(MotionOwner *, float);
    void(*slot14)(CompletionOwner *);
    void(*slot18)(void);
} CStateJumpNativeOperations;

typedef struct CStateRunNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008FE30 *(*destroy)(Object_8008FE30 *, short);
    void(*slot0C)(PhaseOwner *);
    void(*slot10)(Owner *, float);
    void(*slot14)(Owner *);
    void(*slot18)(void);
} CStateRunNativeOperations;

typedef struct CStateJogNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008FEBC *(*destroy)(Object_8008FEBC *, short);
    void(*slot0C)(PhaseOwner *);
    void(*slot10)(PhaseOwner *, double);
    void(*slot14)(Owner *);
    void(*slot18)(void);
} CStateJogNativeOperations;

#ifdef __cplusplus
extern "C" {
#endif
extern CStateInUnderwearNativeOperations lbl_802B8B44;
extern CStateInWaterNativeOperations lbl_802B8B74;
extern CStateGetHitNativeOperations lbl_802B8BD4;
extern CStateCarryFallNativeOperations lbl_802B8C34;
extern CStateCarryJumpNativeOperations lbl_802B8C64;
extern CStateCarryWalkNativeOperations lbl_802B8C94;
extern CStateCarryIdleNativeOperations lbl_802B8CC4;
extern CStatePickupNativeOperations lbl_802B8CF4;
extern CStateNoMoveNativeOperations lbl_802B8D24;
extern CStateGetUpNativeOperations lbl_802B8D54;
extern CStateInCannonNativeOperations lbl_802B8ED4;
extern CStateNetSwipeNativeOperations lbl_802B8F34;
extern CStateKarateDoubleChopNativeOperations lbl_802B8FF4;
extern CStateKaratePowerChopNativeOperations lbl_802B9024;
extern CStateKarateChopNativeOperations lbl_802B9054;
extern CStateFallNativeOperations lbl_802B90B4;
extern CStateSpringboardJumpNativeOperations lbl_802B90E4;
extern CStatePowerJumpNativeOperations lbl_802B9114;
extern CStateJumpNativeOperations lbl_802B9144;
extern CStateRunNativeOperations lbl_802B9204;
extern CStateJogNativeOperations lbl_802B9234;
#ifdef __cplusplus
}
#endif
#endif

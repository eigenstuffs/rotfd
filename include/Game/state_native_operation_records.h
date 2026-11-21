#ifndef GAME_STATE_NATIVE_OPERATION_RECORDS_H
#define GAME_STATE_NATIVE_OPERATION_RECORDS_H
#ifdef __cplusplus
struct NativeRuntimeTypeInfo;
struct Object_8008E640;
struct Object_8008E114;
struct Object_8008EA30;
struct Object_8008EAC8;
struct Object_8008EB54;
struct Object_8008D040;
struct Object_8008CE9C;
struct Object_8008CCB0;
struct Object_8008EBE0;
struct Object_8008EC6C;
struct Object_8008ECF8;
struct Object_8008BAB4;
struct SceneRecordOwner;
struct SceneControlOwner;
struct SearchOwner;
struct TargetOwner;
struct Owner;
#else
typedef struct NativeRuntimeTypeInfo NativeRuntimeTypeInfo;
typedef struct Object_8008E640 Object_8008E640;
typedef struct Object_8008E114 Object_8008E114;
typedef struct Object_8008EA30 Object_8008EA30;
typedef struct Object_8008EAC8 Object_8008EAC8;
typedef struct Object_8008EB54 Object_8008EB54;
typedef struct Object_8008D040 Object_8008D040;
typedef struct Object_8008CE9C Object_8008CE9C;
typedef struct Object_8008CCB0 Object_8008CCB0;
typedef struct Object_8008EBE0 Object_8008EBE0;
typedef struct Object_8008EC6C Object_8008EC6C;
typedef struct Object_8008ECF8 Object_8008ECF8;
typedef struct Object_8008BAB4 Object_8008BAB4;
typedef struct SceneRecordOwner SceneRecordOwner;
typedef struct SceneControlOwner SceneControlOwner;
typedef struct SearchOwner SearchOwner;
typedef struct TargetOwner TargetOwner;
typedef struct Owner Owner;
#endif

/* Existing native operation records, with their original C-entry ABIs.
 * Compiler destructor entries return self and receive a signed short
 * deletion selector. The genuine C++ definitions remain sole providers.
 * Concrete callback view types and timed parameter types follow the
 * accepted definitions; original motion callbacks retain every argument
 * passed by the generic four-pointer/float state dispatcher. */
typedef struct StateCelebrateNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008E640 *(*destroy)(Object_8008E640 *, short);
    void (*slot0C)(SceneRecordOwner *);
    void (*slot10)(void);
    void (*slot14)(Owner *);
    void (*slot18)(SceneRecordOwner *, void *, void *, void *, void *, float);
} StateCelebrateNativeOperations;

typedef struct StateFaceCameraNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008E114 *(*destroy)(Object_8008E114 *, short);
    void (*slot0C)(Owner *);
    void (*slot10)(SceneRecordOwner *, double);
    void (*slot14)(Owner *);
    void (*slot18)(SceneRecordOwner *, void *, void *, void *, void *, float);
} StateFaceCameraNativeOperations;

typedef struct StateWaterHelmetNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008EA30 *(*destroy)(Object_8008EA30 *, short);
    void (*slot0C)(void);
    void (*slot10)(void);
    void (*slot14)(void);
    void (*slot18)(void);
} StateWaterHelmetNativeOperations;

typedef struct StateInvulnerableNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008EAC8 *(*destroy)(Object_8008EAC8 *, short);
    void (*slot0C)(SearchOwner *);
    void (*slot10)(SearchOwner *, float);
    void (*slot14)(SearchOwner *);
    void (*slot18)(void);
} StateInvulnerableNativeOperations;

typedef struct StateIdleAnimationsNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008EB54 *(*destroy)(Object_8008EB54 *, short);
    void (*slot0C)(SceneRecordOwner *);
    void (*slot10)(Owner *, float);
    void (*slot14)(Owner *);
    void (*slot18)(void);
} StateIdleAnimationsNativeOperations;

typedef struct StateFaceTargetNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008D040 *(*destroy)(Object_8008D040 *, short);
    void (*slot0C)(Owner *);
    void (*slot10)(Owner *, double);
    void (*slot14)(Owner *);
    void (*slot18)(Owner *, void *, void *, void *, void *, float);
} StateFaceTargetNativeOperations;

typedef struct StateListenNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008CE9C *(*destroy)(Object_8008CE9C *, short);
    void (*slot0C)(Owner *);
    void (*slot10)(Owner *, double);
    void (*slot14)(Owner *);
    void (*slot18)(void);
} StateListenNativeOperations;

typedef struct StateTalkNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008CCB0 *(*destroy)(Object_8008CCB0 *, short);
    void (*slot0C)(Owner *);
    void (*slot10)(Owner *, double);
    void (*slot14)(Owner *);
    void (*slot18)(void);
} StateTalkNativeOperations;

typedef struct StateThrowWaterBallJumpingNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008EBE0 *(*destroy)(Object_8008EBE0 *, short);
    void (*slot0C)(SceneControlOwner *);
    void (*slot10)(SceneControlOwner *, double);
    void (*slot14)(SceneRecordOwner *);
    void (*slot18)(void);
} StateThrowWaterBallJumpingNativeOperations;

typedef struct StateThrowWaterBallMovingNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008EC6C *(*destroy)(Object_8008EC6C *, short);
    void (*slot0C)(SceneControlOwner *);
    void (*slot10)(SceneControlOwner *, double);
    void (*slot14)(SceneControlOwner *);
    void (*slot18)(void);
} StateThrowWaterBallMovingNativeOperations;

typedef struct StateThrowWaterBallNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008ECF8 *(*destroy)(Object_8008ECF8 *, short);
    void (*slot0C)(SceneControlOwner *);
    void (*slot10)(SceneControlOwner *, double);
    void (*slot14)(SceneControlOwner *);
    void (*slot18)(void);
} StateThrowWaterBallNativeOperations;

typedef struct StateCostumeMermaidManNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008BAB4 *(*destroy)(Object_8008BAB4 *, short);
    void (*slot0C)(TargetOwner *);
    void (*slot10)(void);
    void (*slot14)(void *);
    void (*slot18)(void);
    void (*slot1C)(Owner *);
} StateCostumeMermaidManNativeOperations;

#ifdef __cplusplus
extern "C" {
#endif
extern StateCelebrateNativeOperations lbl_802B87C0;
extern StateFaceCameraNativeOperations lbl_802B87F0;
extern StateWaterHelmetNativeOperations lbl_802B8820;
extern StateInvulnerableNativeOperations lbl_802B8850;
extern StateIdleAnimationsNativeOperations lbl_802B8880;
extern StateFaceTargetNativeOperations lbl_802B88B0;
extern StateListenNativeOperations lbl_802B88E0;
extern StateTalkNativeOperations lbl_802B8910;
extern StateThrowWaterBallJumpingNativeOperations lbl_802B8940;
extern StateThrowWaterBallMovingNativeOperations lbl_802B8970;
extern StateThrowWaterBallNativeOperations lbl_802B89A0;
extern StateCostumeMermaidManNativeOperations lbl_802B89D0;
#ifdef __cplusplus
}
#endif
#endif

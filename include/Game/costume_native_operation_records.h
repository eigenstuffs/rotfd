#ifndef GAME_COSTUME_NATIVE_OPERATION_RECORDS_H
#define GAME_COSTUME_NATIVE_OPERATION_RECORDS_H
#ifdef __cplusplus
struct NativeRuntimeTypeInfo;
struct Object_8008B49C;
struct Object_8008B378;
struct Object_8008A468;
struct Object_8008A0DC;
struct Owner;
struct View;
struct Actor;
struct Control;
struct SceneOwner;
struct InlineBase;
#else
typedef struct NativeRuntimeTypeInfo NativeRuntimeTypeInfo;
typedef struct Object_8008B49C Object_8008B49C;
typedef struct Object_8008B378 Object_8008B378;
typedef struct Object_8008A468 Object_8008A468;
typedef struct Object_8008A0DC Object_8008A0DC;
typedef struct Owner Owner;
typedef struct View View;
typedef struct Actor Actor;
typedef struct Control Control;
typedef struct SceneOwner SceneOwner;
typedef struct InlineBase InlineBase;
#endif

/* Existing native costume operation records. Entries retain the exact
 * accepted C-entry prototypes; genuine C++ destructors retain their
 * compiler self/signed-short-selector/returned-self native entry ABI. */
typedef struct StateCostumeKarateNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008B49C *(*destroy)(Object_8008B49C *, short);
    void (*slot0C)(void *);
    void (*slot10)(Owner *, float);
    void (*slot14)(void *);
    void (*slot18)(void);
    void (*slot1C)(Owner *);
} StateCostumeKarateNativeOperations;

typedef struct StateCostumeTreasureHuntingNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008B378 *(*destroy)(Object_8008B378 *, short);
    void (*slot0C)(void);
    void (*slot10)(void);
    void (*slot14)(void);
    void (*slot18)(void);
    void (*slot1C)(void);
} StateCostumeTreasureHuntingNativeOperations;

typedef struct StateCostumeReefblowerNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    void *(*destroy)(View *, int);
    void (*slot0C)(Actor *);
    void (*slot10)(Control *);
    void (*slot14)(SceneOwner *);
    void (*slot18)(void);
    void (*slot1C)(Owner *);
} StateCostumeReefblowerNativeOperations;

typedef struct StateCostumeJellyfishingNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008A468 *(*destroy)(Object_8008A468 *, short);
    void (*slot0C)(void *);
    void (*slot10)(void);
    void (*slot14)(void *);
    void (*slot18)(void);
    void (*slot1C)(Owner *);
} StateCostumeJellyfishingNativeOperations;

typedef struct StateCostumeDefaultNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    void *(*destroy)(InlineBase *, int);
    void (*slot0C)(void);
    void (*slot10)(void);
    void (*slot14)(void);
    void (*slot18)(void);
    void (*slot1C)(Owner *);
} StateCostumeDefaultNativeOperations;

typedef struct StateCostumeBaseNativeOperations {
    const NativeRuntimeTypeInfo *type;
    long offset_to_top;
    Object_8008A0DC *(*destroy)(Object_8008A0DC *, short);
    void (*slot0C)(void);
    void (*slot10)(void);
    void (*slot14)(void);
    void (*slot18)(void);
    void (*slot1C)(void);
} StateCostumeBaseNativeOperations;

#ifdef __cplusplus
extern "C" {
#endif
extern StateCostumeKarateNativeOperations lbl_802B8A04;
extern StateCostumeTreasureHuntingNativeOperations lbl_802B8A38;
extern StateCostumeReefblowerNativeOperations lbl_802B8A6C;
extern StateCostumeJellyfishingNativeOperations lbl_802B8AA0;
extern StateCostumeDefaultNativeOperations lbl_802B8AF0;
extern StateCostumeBaseNativeOperations lbl_802B8B10;
#ifdef __cplusplus
}
#endif
#endif

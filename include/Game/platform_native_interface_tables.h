#ifndef GAME_PLATFORM_NATIVE_INTERFACE_TABLES_H
#define GAME_PLATFORM_NATIVE_INTERFACE_TABLES_H

/* Native operation records. C users need only each record's address. */
#ifdef __cplusplus
struct RegistryBase;
struct OwnerLifecycleFixed;
struct PlatformAudioUpdateOwner;
struct OwnerHandle;
struct CardThreadOwnerView;
struct MemoryCardInitView;
struct MemoryCardOwnerView;
struct SmallOwnerName;
struct CardFileReadView;
struct View_800E85C8;
struct CardOwnerControlsView;
struct AllocationOwner_802781AC;
struct StatusInitView;
struct AcquireView;
struct PollView;
struct SlotFlagOwner_80275ED4;
struct PlatformMotorOwner;
struct StorageView;
struct AudioOwnerOperationsTable {
    const void *rtti;
    int offset_to_top;
    void (*slot08)(void *);
    char (*slot0C)(RegistryBase *);
    OwnerLifecycleFixed * (*slot10)(OwnerLifecycleFixed *, int);
    int (*slot14)(void);
    void (*slot18)(void);
    void (*slot1C)(void);
    void (*slot20)(void);
    void (*slot24)(void);
    void (*slot28)(void);
    void (*slot2C)(void);
    void (*slot30)(void);
    float (*slot34)(void);
    void (*slot38)(void);
    float (*slot3C)(void);
    void (*slot40)(void);
    void (*slot44)(void);
    void (*slot48)(void);
    void (*slot4C)(void);
    int (*slot50)(void);
    int (*slot54)(PlatformAudioUpdateOwner *, const OwnerHandle &, unsigned long, const OwnerHandle &, const OwnerHandle &);
    int (*slot58)(PlatformAudioUpdateOwner *, const OwnerHandle &, const OwnerHandle &, float);
    int (*slot5C)(void);
    void (*slot60)(void *);
    void (*slot64)(void);
    void (*slot68)(void);
};
struct ControllerOperationsTable {
    const void *rtti;
    int offset_to_top;
    signed char (*slot08)(StatusInitView *);
    void (*slot0C)(void);
    void (*slot10)(AcquireView *);
    void (*slot14)(void);
    void (*slot18)(void);
    void (*slot1C)(void);
    void (*slot20)(PollView *);
    bool (*slot24)(const SlotFlagOwner_80275ED4 *, unsigned char);
    void (*slot28)(void);
    void (*slot2C)(void);
    void (*slot30)(PollView *);
    void (*slot34)(PlatformMotorOwner *, int, signed char);
    void (*slot38)(PlatformMotorOwner *, int, unsigned char, unsigned char);
    unsigned int (*slot3C)(const void *, int);
    StorageView * (*slot40)(StorageView *, int);
    void (*slot44)(void *, short);
};
struct MemoryCardOperationsTable {
    const void *rtti;
    int offset_to_top;
    int (*slot08)(CardThreadOwnerView *);
    void (*slot0C)(MemoryCardInitView *, const char *);
    void (*slot10)(void);
    void (*slot14)(void *, unsigned int);
    void (*slot18)(SmallOwnerName *, const char *);
    int (*slot1C)(MemoryCardOwnerView *, const char *, void *, int);
    int (*slot20)(CardFileReadView *, const char *, void *, int);
    int (*slot24)(MemoryCardOwnerView *, const char *);
    void (*slot28)(void *, unsigned int);
    void (*slot2C)(View_800E85C8 *, unsigned int, unsigned int);
    void (*slot30)(MemoryCardOwnerView *);
    void (*slot34)(MemoryCardOwnerView *);
    void (*slot38)(CardOwnerControlsView *);
    void (*slot3C)(MemoryCardOwnerView *);
    int (*slot40)(MemoryCardOwnerView *);
    int (*slot44)(MemoryCardOwnerView *);
    int (*slot48)(const AllocationOwner_802781AC *, unsigned int *);
    int (*slot4C)(MemoryCardOwnerView *, const char *);
    unsigned int (*slot50)(const void *);
    int (*slot54)(MemoryCardOwnerView *);
    int (*slot58)(MemoryCardOwnerView *);
    signed char (*slot5C)(const void *);
    unsigned long (*slot60)(MemoryCardOwnerView *, const char *);
    signed char (*slot64)(MemoryCardOwnerView *, int);
};
struct MemoryCardBaseOperationsTable {
    const void *rtti;
    int offset_to_top;
    int (*slot08)(CardThreadOwnerView *);
    void (*slot0C)(MemoryCardInitView *, const char *);
    void (*slot10)(void);
    void (*slot14)(void *, unsigned int);
    void (*slot18)(SmallOwnerName *, const char *);
    int (*slot1C)(MemoryCardOwnerView *, const char *, void *, int);
    int (*slot20)(CardFileReadView *, const char *, void *, int);
    int (*slot24)(void);
    void (*slot28)(void *, unsigned int);
    void (*slot2C)(View_800E85C8 *, unsigned int, unsigned int);
    void (*slot30)(void);
    void (*slot34)(void);
    void (*slot38)(void);
    void (*slot3C)(MemoryCardOwnerView *);
    int (*slot40)(MemoryCardOwnerView *);
    int (*slot44)(MemoryCardOwnerView *);
    int (*slot48)(const AllocationOwner_802781AC *, unsigned int *);
    int (*slot4C)(MemoryCardOwnerView *, const char *);
    int (*slot50)(void);
    int (*slot54)(MemoryCardOwnerView *);
    int (*slot58)(MemoryCardOwnerView *);
    int (*slot5C)(void);
};
extern "C" {
#else
typedef struct AudioOwnerOperationsTable AudioOwnerOperationsTable;
typedef struct ControllerOperationsTable ControllerOperationsTable;
typedef struct MemoryCardOperationsTable MemoryCardOperationsTable;
typedef struct MemoryCardBaseOperationsTable MemoryCardBaseOperationsTable;
#endif
extern AudioOwnerOperationsTable lbl_802EC030;
extern ControllerOperationsTable lbl_802ED6F8;
extern MemoryCardOperationsTable lbl_802EDB80;
extern MemoryCardBaseOperationsTable lbl_802EDC48;
#ifdef __cplusplus
}
#endif
#endif

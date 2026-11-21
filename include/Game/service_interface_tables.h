#ifndef GAME_SERVICE_INTERFACE_TABLES_H
#define GAME_SERVICE_INTERFACE_TABLES_H
struct Object_801C99AC;
struct ControllerStorage;
struct Controller;
struct FlagController;
struct OutputBuffer;
typedef struct PlatformServiceInterfaceTable {
    const void *rtti;
    int offset_to_top;
    void *(*cleanup)(struct Object_801C99AC *, short);
    int (*start)(void *);
    void (*stop)(void *);
    int (*open)(unsigned char *);
    void (*close)(unsigned char *);
    void (*enable)(void *);
    void (*disable)(void *);
    int (*poll)(void *);
    void (*hook28)(void *);
    void (*hook2C)(void *);
} PlatformServiceInterfaceTable;
typedef struct ControllerInterfaceTable {
    const void *rtti;
    int offset_to_top;
    struct ControllerStorage *(*cleanup)(struct ControllerStorage *, short);
    int (*initialize)(struct Controller *);
    void (*hook10)(void *);
    void (*enable_flags)(struct FlagController *, unsigned int);
    void (*disable_flags)(struct FlagController *, unsigned int);
    void (*base_enable_flags)(void *, unsigned int);
    void (*base_disable_flags)(void *, unsigned int);
    void (*update)(struct Controller *, float);
    void (*flush)(struct OutputBuffer *);
    void (*hook2C)(void *);
} ControllerInterfaceTable;
typedef struct StatusStorageInterfaceTable {
    const void *rtti;
    int offset_to_top;
    int (*initialize)(unsigned char *);
    void (*hook0C)(void);
    void (*hook10)(void);
    void (*hook14)(void);
    void (*hook18)(void);
    void (*hook1C)(void);
    void (*hook20)(void);
    int (*result24)(void);
    void (*hook28)(void);
    void (*hook2C)(void);
    void (*hook30)(void);
    void (*hook34)(void);
    void (*hook38)(void);
    int (*result3C)(void);
} StatusStorageInterfaceTable;
#ifdef __cplusplus
extern "C" {
#endif
extern PlatformServiceInterfaceTable lbl_802EA0F8;
extern ControllerInterfaceTable lbl_802EA8D8;
extern StatusStorageInterfaceTable lbl_802ED740;
#ifdef __cplusplus
}
#endif
#endif

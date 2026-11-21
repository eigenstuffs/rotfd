#ifndef GAME_ENGINE_HANDLE_PATHS_H
#define GAME_ENGINE_HANDLE_PATHS_H

struct EnginePathHandle {
    unsigned int value;
};
struct EnginePathDeviceStorage {
    char unknown00[0x7C];
};
struct EnginePathDevice : EnginePathDeviceStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48(const char*, int, EnginePathHandle*, EnginePathHandle*);
    virtual void slot4C(const char*);
};
struct EnginePathArguments {
    char unknown00[0x860];
    int count, unknown864;
    char* path;
};

extern "C" {
extern struct {
    char unknown00[0x110];
    EnginePathArguments* args;
    char unknown114[0x44];
    EnginePathDevice* device;
} lbl_801E9D24;
extern const char lbl_8037B30C[5];
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
void fn_801F459C(char*);
void __ct__15Handle_801F7F10Fv(EnginePathHandle*);
void __dt__15Handle_801F7F10Fv(EnginePathHandle*, int);
}

static inline void enginePathInitializeHandle(EnginePathHandle* handle)
{
    __ct__15Handle_801F7F10Fv(handle);
    handle->value = 0;
    handle->value = 0;
}

#endif

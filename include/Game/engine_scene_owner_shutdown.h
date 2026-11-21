#ifndef GAME_ENGINE_SCENE_OWNER_SHUTDOWN_H
#define GAME_ENGINE_SCENE_OWNER_SHUTDOWN_H

typedef unsigned long SceneOwnerShutdownWord;

struct Handle_801F7F10 {
    SceneOwnerShutdownWord word;
    ~Handle_801F7F10();
};

struct SceneOwnerShutdownHandle : Handle_801F7F10 {
    ~SceneOwnerShutdownHandle() {}
};

struct SceneOwnerShutdownHandleLayer : SceneOwnerShutdownHandle {
    ~SceneOwnerShutdownHandleLayer() {}
};

struct SceneOwnerShutdownNode {
    SceneOwnerShutdownWord unknown00, unknown04;
    SceneOwnerShutdownNode* next;
};

struct SceneOwnerShutdownHash {
    SceneOwnerShutdownWord words[4];
};

/* Partial owner view; array element implementations retain their original
 * external destructor callbacks. */
struct Object_80260C7C {
    char unknown00[0x18];
    SceneOwnerShutdownHandleLayer handle18;
    SceneOwnerShutdownNode* head;
    SceneOwnerShutdownHash hash20;
    void* vtable;
    char handles34[12];
    SceneOwnerShutdownWord unknown40;
    char records44[0xA000];
    SceneOwnerShutdownWord unknownA044;
    char snapshotsA048[0xB000];
    SceneOwnerShutdownWord unknown15048;

    ~Object_80260C7C();
    static void operator delete(void*) throw();
};

typedef char SceneOwnerShutdownSizeCheck[
    sizeof(Object_80260C7C) == 0x1504C ? 1 : -1];

#endif

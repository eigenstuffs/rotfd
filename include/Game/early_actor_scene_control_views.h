#ifndef GAME_EARLY_ACTOR_SCENE_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_SCENE_CONTROL_VIEWS_H
struct Handle_801F7F10 {
    unsigned long value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
extern "C" { void fn_801EF610(void*, void*); extern char lbl_801EF5C8[]; }
struct Handle_80020478 : Handle_801F7F10 {
    Handle_80020478() { value = 0; }
    ~Handle_80020478() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct Handle_80020834 : Handle_80020478 {
    Handle_80020834() { value = 0; }
    ~Handle_80020834() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct SceneControlMode { char unknown00[0xF0]; int mode, submode; };
struct SceneControlScene { char unknown00[0x15058]; SceneControlMode* mode; };
struct SceneControlSystem { char unknown00[0x2D]; unsigned char active; };
struct SceneControlContext { char unknown00[0x124]; SceneControlScene* scene; char unknown128[0x3C]; SceneControlSystem* system; };
struct SceneControlMonitor { char unknown00[0x130]; void* first; void* second; };
struct SceneControlActor {
    char unknown00[0x30];
    unsigned long long flags;
    char unknown38[0x2E8];
    void* record;
    char unknown324[0x108];
    void* target;
};
struct SceneControlOwner { char unknown00[8]; SceneControlActor* actor; void* controller; char unknown10[0x30]; void* first; void* second; };
struct SceneControlService { char unknown00[0x1DC]; unsigned char active; };
extern "C" {
extern SceneControlContext lbl_801E9D24;
extern SceneControlMonitor* lbl_803776B8;
extern const float lbl_80378AE0;
void fn_80057E40(SceneControlMode*);
void fn_80058CB8(SceneControlMode*, int, const Handle_80020834&);
void* fn_80056A0C(SceneControlMode*);
void fn_80257828(void*, int, int, int);
void fn_802073E8(void*, int, void*, float);
SceneControlService* fn_8007D074();
void fn_8006803C(SceneControlMonitor*, void*);
void fn_80068158(SceneControlMonitor*, void*);
void fn_80255678(void*);
}
#endif

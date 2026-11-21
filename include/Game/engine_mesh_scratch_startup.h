#ifndef GAME_ENGINE_MESH_SCRATCH_STARTUP_H
#define GAME_ENGINE_MESH_SCRATCH_STARTUP_H

// This existing native constructor leaves its three float words uninitialized.
struct Vector3_801D5330 {
    float x, y, z;
    Vector3_801D5330();
};

extern "C" {
extern Vector3_801D5330 lbl_80341360[4096];
extern Vector3_801D5330 lbl_8034D360[4096];
}

#endif

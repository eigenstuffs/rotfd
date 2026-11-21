#ifndef GAME_ENGINE_CUBE_AXES_STARTUP_H
#define GAME_ENGINE_CUBE_AXES_STARTUP_H

// Observed three-float point layout used by the global corner and axis arrays.
struct EngineCubePoint3 {
    float x, y, z;
    EngineCubePoint3(float a, float b, float c) : x(a), y(b), z(c) {}
};

extern EngineCubePoint3 lbl_80340AC0[8];
extern EngineCubePoint3 lbl_80340B20[3];

#endif

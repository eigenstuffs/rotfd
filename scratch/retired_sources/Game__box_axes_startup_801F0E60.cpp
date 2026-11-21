#include "Game/engine_cube_axes_startup.h"

// Original shared constants: positive one, zero, and negative one.
extern const float lbl_8037A6CC, lbl_8037A6D0, lbl_8037A6D4;

EngineCubePoint3 lbl_80340AC0[8] = {
    EngineCubePoint3(lbl_8037A6CC, lbl_8037A6CC, lbl_8037A6CC),
    EngineCubePoint3(lbl_8037A6CC, lbl_8037A6CC, lbl_8037A6D4),
    EngineCubePoint3(lbl_8037A6D4, lbl_8037A6CC, lbl_8037A6D4),
    EngineCubePoint3(lbl_8037A6D4, lbl_8037A6CC, lbl_8037A6CC),
    EngineCubePoint3(lbl_8037A6CC, lbl_8037A6D0, lbl_8037A6CC),
    EngineCubePoint3(lbl_8037A6CC, lbl_8037A6D0, lbl_8037A6D4),
    EngineCubePoint3(lbl_8037A6D4, lbl_8037A6D0, lbl_8037A6D4),
    EngineCubePoint3(lbl_8037A6D4, lbl_8037A6D0, lbl_8037A6CC)
};

EngineCubePoint3 lbl_80340B20[3] = {
    EngineCubePoint3(lbl_8037A6D0, lbl_8037A6CC, lbl_8037A6D0),
    EngineCubePoint3(lbl_8037A6CC, lbl_8037A6D0, lbl_8037A6D0),
    EngineCubePoint3(lbl_8037A6D0, lbl_8037A6D0, lbl_8037A6CC)
};

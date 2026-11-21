#include "Game/engine_handle_paths.h"

extern "C" signed char fn_8023ADB8()
{
    char path[128];
    if (lbl_801E9D24.args->count < 2)
        return 0;
    strcpy(path, lbl_801E9D24.args->path);
    strcat(path, lbl_8037B30C);
    fn_801F459C(path);
    lbl_801E9D24.device->slot4C(path);
    return 1;
}

extern "C" signed char fn_8023AE38()
{
    EnginePathHandle first, second;
    char path[128];
    if (lbl_801E9D24.args->count < 2)
        return 0;
    strcpy(path, lbl_801E9D24.args->path);
    strcat(path, lbl_8037B30C);
    fn_801F459C(path);
    enginePathInitializeHandle(&first);
    enginePathInitializeHandle(&second);
    lbl_801E9D24.device->slot48(path, 2, &first, &second);
    __dt__15Handle_801F7F10Fv(&second, 0);
    __dt__15Handle_801F7F10Fv(&first, 0);
    return 1;
}

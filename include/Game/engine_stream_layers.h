#ifndef GAME_ENGINE_STREAM_LAYERS_H
#define GAME_ENGINE_STREAM_LAYERS_H

// Partial view of the fixed stream blocks; names are provisional.
struct EngineStreamLayerView {
    char unknown00[0x0C];
    char field0C[4];
    char field10[0x10];
    char unknown20[0x54];
    char field74[0x14];
    char field88[4];
};

extern "C" {
void slot0C__12BaseObject_ZFUl(EngineStreamLayerView*, void**);
void* fn_801E9F40(void*, const void*, unsigned long);
void fn_80243D38(EngineStreamLayerView*, void**);
void fn_80243DE4(EngineStreamLayerView*, void**);
void fn_80243E44(EngineStreamLayerView*, void**);
void fn_80244190(EngineStreamLayerView*, void**);
}

#endif

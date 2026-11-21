#ifndef GAME_ENGINE_INDEX_CHAIN_H
#define GAME_ENGINE_INDEX_CHAIN_H

typedef struct EngineIndexChainRange {
    short first, last, count;
} EngineIndexChainRange;

typedef struct EngineIndexChainOwner {
    char unknown00[0x30];
    char *records;
} EngineIndexChainOwner;

EngineIndexChainRange fn_8020C8CC(EngineIndexChainOwner *, short, short);

#endif

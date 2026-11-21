#ifndef GAME_ENGINE_BITSET_FIND_H
#define GAME_ENGINE_BITSET_FIND_H

typedef struct EngineBitsetFind {
    int wordCount, capacity;
    unsigned int *words;
    int bitCount;
} EngineBitsetFind;

#ifdef __cplusplus
extern "C" {
#endif
int fn_80207B94(EngineBitsetFind *self, signed char state, int start);
#ifdef __cplusplus
}
#endif
#endif

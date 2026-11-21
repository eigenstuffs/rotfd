#ifndef GAME_NODE_MATRIX_POOL_H
#define GAME_NODE_MATRIX_POOL_H
#include "Game/engine_bitset_find.h"

/* Two matrix-bank pointers precede the existing16-byte occupancy bit set.
 * The selection byte at18 is used by the recovered Node constructor;19 is
 * the bank count used by allocation and initialization. */
struct NodePool {
    char *banks[2];
    EngineBitsetFind occupied;
    unsigned char active;
    unsigned char bankCount;
};
typedef char NodePoolSize[(sizeof(NodePool)==0x1C)?1:-1];
extern "C" short fn_801C9E3C(NodePool *);
#endif

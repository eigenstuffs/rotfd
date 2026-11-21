#ifndef GAME_WORLD_HANDLE_ARRAY_INTERNAL_H
#define GAME_WORLD_HANDLE_ARRAY_INTERNAL_H
#include "objects_owner_internal.h"
template<int N> struct WorldHandleLayer : WorldHandleLayer<N-1> {
    WorldHandleLayer(){value=0;}
    ~WorldHandleLayer(){}
};
template<> struct WorldHandleLayer<1> : Handle_801F7F10 {
    WorldHandleLayer(){value=0;}
    ~WorldHandleLayer(){}
};
struct WorldHandle_801E562C : WorldHandleLayer<4> {
    WorldHandle_801E562C();
    ~WorldHandle_801E562C();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
struct WorldHandleArray_801E55C4 {
    WorldHandle_801E562C handles[144];
    WorldHandleArray_801E55C4();
    ~WorldHandleArray_801E55C4();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
typedef char CheckWorldHandle[sizeof(WorldHandle_801E562C)==4?1:-1];
typedef char CheckWorldHandleArray[sizeof(WorldHandleArray_801E55C4)==576?1:-1];
#endif

#ifndef GAME_ENGINE_ALLOCATOR_STATE_STARTUP_H
#define GAME_ENGINE_ALLOCATOR_STATE_STARTUP_H

// Partial view of the original allocator storage at 8028F698.
struct AllocatorStartupState {
    unsigned int words00[6];
    unsigned int bytes18;
    unsigned int bytes1C;
};
typedef char AllocatorStartupStateSize[sizeof(AllocatorStartupState) == 32 ? 1 : -1];

extern "C" {
extern AllocatorStartupState lbl_8028F698;
void fn_80290B50();
}

#endif

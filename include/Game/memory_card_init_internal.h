#ifndef GAME_MEMORY_CARD_INIT_INTERNAL_H
#define GAME_MEMORY_CARD_INIT_INTERNAL_H

// Partial view for the initializer and label operations; fields retain offsets.
struct MemoryCardInitView {
    int unknown00, unknown04;
    char unknown08[0x28];
    void* table;
    char unknown34[0x344];
    char name[64];
    unsigned long sectorSize;
    int memorySize, channel;
    char label[32], other[32];
    int unknown404;
    void* workArea;
    int freeBytes, freeFiles;
    int unknown414, unknown418, unknown41C, unknown420, unknown424;
    char bytes[96];
    char shortLabel[64];
    int unknown4C8, state, connected, formatted;
};

typedef char CheckMemoryCardInitView[sizeof(MemoryCardInitView) == 0x4D8 ? 1 : -1];
#endif

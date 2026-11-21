#ifndef GAME_MEMORY_CARD_OWNER_INTERNAL_H
#define GAME_MEMORY_CARD_OWNER_INTERNAL_H

// Partial view of the owner used by the operations at 802780BC and nearby.
struct MemoryCardOwnerView {
    char unknown00[0x350];
    char queue[8];
    char mutex[24];
    unsigned long status;
    int unknown374;
    char name[64];
    unsigned long sectorSize;
    int memorySize;
    int channel;
    char unknown3C4[0x44];
    void* workArea;
    unsigned long freeBytes;
    int freeFiles;
    char unknown414[0xB8];
    int state;
    int connected;
    int formatted;
};

#endif

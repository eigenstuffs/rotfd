#ifndef GAME_REEFBLOWER_DERIVED_CONSTRUCTOR_800703F0_H
#define GAME_REEFBLOWER_DERIVED_CONSTRUCTOR_800703F0_H

// Partial views. The factory records ReefblowerObjectAgent.h:123 and size 0xB8.
// Names below distinguish the observed constructor layers and field offsets.
extern const unsigned char lbl_802B780C[], lbl_802B7430[];
extern const float lbl_803788A8;

struct Agent_8002B5F4 {
    union { double alignment; unsigned long prefix[2]; };
    const void* vtable;
    unsigned char opaque[0x90-12];
    Agent_8002B5F4();
};

struct ReefblowerMotionBase : Agent_8002B5F4 {
    signed char active;
    unsigned char pad91[3];
    float value94, value98;
    unsigned long opaque9c;
    ReefblowerMotionBase() {
        vtable = lbl_802B780C;
        active = 0;
        value94 = lbl_803788A8;
        value98 = lbl_803788A8;
    }
};

struct Agent_800703F0 : ReefblowerMotionBase {
    unsigned long slots[3];
    signed char enabled;
    unsigned char padad[3];
    float valueb0, valueb4;
    Agent_800703F0();
};

typedef char AgentBaseSizeCheck[(sizeof(Agent_8002B5F4)==0x90) ? 1 : -1];
typedef char ReefblowerBaseSizeCheck[(sizeof(ReefblowerMotionBase)==0xA0) ? 1 : -1];
typedef char ReefblowerDerivedSizeCheck[(sizeof(Agent_800703F0)==0xB8) ? 1 : -1];

#endif

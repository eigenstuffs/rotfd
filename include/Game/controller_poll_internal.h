#ifndef GAME_CONTROLLER_POLL_INTERNAL_H
#define GAME_CONTROLLER_POLL_INTERNAL_H

struct PollRecord {
    char unknown00[0x10];
    short axes[6];
    char flags[16];
    unsigned long unknown2C;
    signed char ready;
    char unknown31[15];
    void reset() {
        for (int i = 0; i < 16; ++i) flags[i] = 0;
        axes[0] = axes[1] = axes[2] = 0;
        axes[3] = axes[4] = axes[5] = 0;
        ready = 1;
    }
};
struct PollView {
    int count, capacity;
    PollRecord* records;
    char unknown0C[0x14];
    char status[48];
};
extern "C" {
extern unsigned long lbl_802ED6E8[];
int PADRecalibrate(unsigned long);
unsigned long PADRead(void*);
void fn_80275FC8(PollView*, short);
}

typedef char CheckPollRecord[sizeof(PollRecord) == 64 ? 1 : -1];
typedef char CheckPollView[sizeof(PollView) == 80 ? 1 : -1];
#endif

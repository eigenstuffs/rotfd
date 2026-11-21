#include "Game/controller_poll_internal.h"

extern "C" {
extern char lbl_8028F698[], lbl_801E9D24[], lbl_802AF100[];
void* fn_8028FAF4(void*, void*, unsigned long, unsigned long);
void* fn_8028FF24(void*, unsigned long);
void fn_8028FD50(void*, void*, unsigned long);
void fn_801FA014(void*, const char*, ...);
}
struct AcquireStatusView { char unknown00[0x2A]; signed char error; };
struct AcquireView : PollView {
    int mapping[8];
    void storage(int n) {
        if (n) {
            if (records)
                records = (PollRecord*)fn_8028FAF4(lbl_8028F698, records,
                    capacity * sizeof(PollRecord), n * sizeof(PollRecord));
            else records = (PollRecord*)fn_8028FF24(lbl_8028F698, n * sizeof(PollRecord));
        } else if (records) {
            fn_8028FD50(lbl_8028F698, records, capacity * sizeof(PollRecord));
            records = 0;
        }
    }
};

extern "C" void fn_80276590(AcquireView* self) {
    signed char found = 0;
    int index = self->count;
    if (self->count + 1 > self->capacity) {
        self->storage(self->capacity + 8);
        self->capacity += 8;
    }
    ++self->count;
    for (short i = 0; i < 4; ++i) {
        if (!((AcquireStatusView*)((char*)self + i * 12))->error) {
            self->mapping[index] = i;
            found = 0;
        }
    }
    if (!found) fn_801FA014(*(void**)(lbl_801E9D24 + 0x110), lbl_802AF100, index);
    else {
        self->records[index].unknown2C = 0;
        self->records[index].reset();
    }
}

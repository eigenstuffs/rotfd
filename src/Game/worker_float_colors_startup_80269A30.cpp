/* Startup colors and the two original worker thread records. */
#include "OSThread_abi.h"

extern "C" {
extern const float lbl_8037B654, lbl_8037B650;
}

struct WorkerFloatColor {
    float r, g, b, a;
    WorkerFloatColor(float R, float G, float B, float A)
        : r(R), g(G), b(B), a(A) {}
};

typedef char CheckWorkerFloatColor[sizeof(WorkerFloatColor) == 16 ? 1 : -1];
typedef char CheckWorkerThread[sizeof(OSThread) == 0x318 ? 1 : -1];

extern "C" {
WorkerFloatColor lbl_80340D00(lbl_8037B654, lbl_8037B654, lbl_8037B654, lbl_8037B654);
WorkerFloatColor lbl_80340D10(lbl_8037B654, lbl_8037B650, lbl_8037B650, lbl_8037B654);
OSThread lbl_80340D20;
OSThread lbl_80341038;
}

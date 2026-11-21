#ifndef GAME_ENGINE_HANDLE_COPY_PAIR_H
#define GAME_ENGINE_HANDLE_COPY_PAIR_H

struct Handle_801F7F10 {
    unsigned long value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct EnginePairCopyZero : Handle_801F7F10 {
    EnginePairCopyZero() { value = 0; }
};
struct HandleCopy_8023F578 : EnginePairCopyZero {
    HandleCopy_8023F578(const HandleCopy_8023F578 &);
};
struct HandleCopy_8023F5EC : EnginePairCopyZero {
    HandleCopy_8023F5EC(const HandleCopy_8023F5EC &);
};
struct EnginePairCopyContext {
    char unknown00[0x118];
    void *manager;
};
extern "C" {
extern EnginePairCopyContext lbl_801E9D24;
void fn_801F86C8(void *, const Handle_801F7F10 *, short);
}

typedef char CheckHandleCopyFirstSize[sizeof(HandleCopy_8023F578) == 4 ? 1 : -1];
typedef char CheckHandleCopySecondSize[sizeof(HandleCopy_8023F5EC) == 4 ? 1 : -1];

#endif

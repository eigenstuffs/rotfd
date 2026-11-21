#ifndef GAME_ENGINE_QUEUE_GRID_RESET_H
#define GAME_ENGINE_QUEUE_GRID_RESET_H

struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10() { bits.index = 0; bits.tag = 0; }
    ~Handle_801F7F10();
};
struct QueueGridResetTarget {
    char unknown00[0x1C];
    float value;
};
struct QueueGridResetEntry {
    QueueGridResetTarget *object;
    unsigned long key;
    int unknown08;
    signed char tag;
    char unknown0D[3];
};
struct QueueGridResetManager { int count, capacity; QueueGridResetEntry *entries; };
struct QueueGridResetContext {
    char unknown00[0x118];
    QueueGridResetManager *manager;
};
struct QueueGridResetPrefix { char unknown00[8]; };
struct QueueGridResetOwner : QueueGridResetPrefix {
    virtual ~QueueGridResetOwner();
    virtual void unknown0C();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1C();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void replace(const Handle_801F7F10 &, int);
    virtual void unknown30();
    virtual void unknown34();
    virtual int size();
    Handle_801F7F10 parent;
    char padding10[0x60 - 0x10];
    Handle_801F7F10 handles[4][8];
    char unknownE0[0x160 - 0xE0];
    int count[4], state[4];
    char flag180[4], flag184[4];
};
extern "C" {
extern QueueGridResetContext lbl_801E9D24;
extern const float lbl_8037B1D8;
void fn_801F7914(Handle_801F7F10 *, const Handle_801F7F10 &);
unsigned long fn_801F7EB8(const Handle_801F7F10 *);
void fn_80231330(QueueGridResetOwner *, int, signed char);
}

typedef char CheckQueueGridResetHandleSize[sizeof(Handle_801F7F10) == 4 ? 1 : -1];
typedef char CheckQueueGridResetEntrySize[sizeof(QueueGridResetEntry) == 16 ? 1 : -1];

#endif

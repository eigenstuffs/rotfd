#ifndef GAME_ENGINE_RECORD_STREAM_H
#define GAME_ENGINE_RECORD_STREAM_H

struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct StreamObject { char unknown00[12]; char stream[1]; };
struct StreamEntry {
    StreamObject *object;
    unsigned long key;
    int unknown08;
    signed char tag;
    char unknown0D[3];
};
struct StreamManagerStorage {
    int count, capacity;
    StreamEntry *entries;
    char unknown0C[0x24 - 12];
};
struct StreamManager : StreamManagerStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual Handle_801F7F10 lookup(unsigned long);
};
struct StreamContext { char unknown00[0x118]; StreamManager *manager; };
extern "C" {
extern StreamContext lbl_801E9D24;
void fn_801F86C8(StreamManager *, const Handle_801F7F10 *, short);
}
struct StreamHandleLayer : Handle_801F7F10 {
    StreamHandleLayer() { value = 0; }
};
struct StreamHandle : StreamHandleLayer {
    StreamHandle(const Handle_801F7F10 &handle) {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};

extern "C" int fn_8021020C(void *, unsigned long);

#endif

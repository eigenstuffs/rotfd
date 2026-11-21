#ifndef GAME_ENGINE_HANDLE_ACTION_SWEEP_H
#define GAME_ENGINE_HANDLE_ACTION_SWEEP_H

namespace HandleActionSweep {
struct Handle { signed int tag : 8, index : 24; };
struct ObjectPrefix { char unknown[8]; };
struct Object : ObjectPrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
};
struct Entry {
    Object* object;
    char unknown[8];
    signed char tag;
    char tail[3];
};
struct Manager {
    int count, capacity;
    Entry* entries;
    inline Object* get(const Handle& h)
    {
        Entry* e = entries + h.index;
        return e->tag == h.tag ? e->object : 0;
    }
};
struct Global { char unknown[0x118]; Manager* manager; };
struct Array { int count, capacity; Handle* data; };
/* Partial storage view; the record table and fixed array remain external. */
struct Owner {
    Array first, second;
    Handle scalar;
    int count, capacity;
    char* records;
    char bits[16];
    int limit, used;
    char unknown40[0x240];
    Handle h280, h284, h288, h28C;
};
}

extern "C" void fn_80263764(HandleActionSweep::Owner*);

#endif

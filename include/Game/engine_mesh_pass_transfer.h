#ifndef GAME_ENGINE_MESH_PASS_TRANSFER_H
#define GAME_ENGINE_MESH_PASS_TRANSFER_H

namespace MeshPassTransfer {
typedef unsigned int u32;
typedef unsigned short u16;
struct Handle { signed int tag : 8, index : 24; };
struct Part {
    char pad[0x6C];
    u16 type;
};
struct Pass {
    char pad[0xC];
    u32 flags;
};
struct PartEntry {
    Part* object;
    char pad[8];
    signed char tag;
    char tail[3];
};
struct PassEntry {
    Pass* object;
    char pad[8];
    signed char tag;
    char tail[3];
};
struct PartManager {
    int count, capacity;
    PartEntry* entries;
    inline Part* get(const Handle& h)
    {
        PartEntry* e = entries + h.index;
        return e->tag == h.tag ? e->object : 0;
    }
};
struct PassManager {
    int count, capacity;
    PassEntry* entries;
    inline Pass* get(const Handle& h)
    {
        PassEntry* e = entries + h.index;
        return e->tag == h.tag ? e->object : 0;
    }
};
struct Global {
    char pad[0x118];
    PartManager* manager;
};
struct Owner {
    char pad[0x80];
    int count, capacity;
    Handle* parts;
};
struct State {
    char pad[0xBDC];
    void* scratch;
};
struct Related {
    char pad[0x6C];
    Handle* passes;
};
}

extern "C" void fn_80280174(MeshPassTransfer::Owner* self,
    MeshPassTransfer::State* state, MeshPassTransfer::Related* related);

#endif

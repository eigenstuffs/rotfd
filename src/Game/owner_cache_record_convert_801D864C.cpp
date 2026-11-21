typedef unsigned int u32;

struct Resource;
struct Handle;
struct Entry {
    Resource* object;
    u32 unknown[2];
    signed char generation;
    char padD[3];
    signed char getGeneration() const { return generation; }
};
struct Manager { int count, capacity; Entry* entries; };
struct Node {
    int handle;
    unsigned short index, unknown6, prev, next;
};
struct Block { char data[12]; };
struct Cache {
    int count, capacity;
    Node* data;
    int stride;
    Block* blocks;
    void* vtable;

    Node& at(unsigned int n) { Node* base = data; return base[n]; }
    void unlink(unsigned int n) {
        at(at(n).prev).next = at(n).next;
        at(at(n).next).prev = at(n).prev;
    }
    void prepend(unsigned int n) {
        at(n).next = at(0).next;
        at(n).prev = 0;
        at(at(0).next).prev = n;
        at(0).next = n;
    }
    Block* get(unsigned short n) {
        unsigned int next = n + 1;
        unlink(next);
        prepend(next);
        return &blocks[n * stride];
    }
};
struct Globals {
    char unknown[0x118];
    Manager* manager;
    char unknown11C[0x14];
    Cache* cache;
};
extern "C" Globals lbl_801E9D24;

struct Handle {
    signed int generation : 8;
    signed int index : 24;
    Resource* get() const {
        int i = index;
        Manager* m = lbl_801E9D24.manager;
        int gen = m->entries[i].getGeneration();
        return gen == generation ? m->entries[i].object : 0;
    }
};
struct Record90 { char unknown[0x90]; };
struct Record68 { char unknown[0x68]; };
struct Resource { char unknown[0xAC]; Record90* records; };
extern "C" void fn_801D84F4(Resource*, Record90*, Record68*, Block*);

struct Owner {
    char unknown[0xC];
    u32 flags;
    char unknown10[0x10];
    unsigned short index;
    char unknown22[2];
    int count, capacity;
    Record68* records;

    void convert(Resource* resource, Block* block) {
        for (int i = 0; i < count; ++i)
            fn_801D84F4(resource, &resource->records[i], &records[i], block);
    }
};

extern "C" void fn_801D864C(Owner* self, unsigned short index,
                            const Handle* handle) {
    self->index = index;
    if (self->flags & 8) {
        Resource* const resource = handle->get();
        Block* block = lbl_801E9D24.cache->get(index);
        self->convert(resource, block);
    }
}

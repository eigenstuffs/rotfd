#ifndef GAME_ENGINE_NODE_CLEANUP_H
#define GAME_ENGINE_NODE_CLEANUP_H

typedef unsigned long NodeCleanupWord;
struct NodeCleanupHandle { NodeCleanupWord value; };
struct NodeCleanupContext {
    char unknown00[0x118];
    void* manager;
    char unknown11C[0x18];
    void* pool;
};

extern "C" {
extern NodeCleanupContext lbl_801E9D24;
extern const char __vt__17Resource_802E9E20[], lbl_802EC0A0[];
extern char lbl_801EF5C8[];
void fn_801F86C8(void*, const NodeCleanupHandle*, short);
void fn_8023EE7C(void*, const NodeCleanupHandle*);
void fn_8023EE08(void*, const NodeCleanupHandle*);
void fn_801C9E10(void*, short);
void* __dt__12BaseObject_ZFv(void*, short);
void fn_801EF610(void*, void*);
}

struct Handle_801F7F10 : NodeCleanupHandle {
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct NodeCleanupHandle1 : Handle_801F7F10 {
    NodeCleanupHandle1() { value = 0; }
    ~NodeCleanupHandle1() {}
};
struct NodeCleanupHandle2 : NodeCleanupHandle1 {
    NodeCleanupHandle2() { value = 0; }
    ~NodeCleanupHandle2() {}
};
struct NodeCleanupHandle3 : NodeCleanupHandle2 {
    NodeCleanupHandle3() { value = 0; }
    ~NodeCleanupHandle3() {}
};
struct NodeCleanupCopy : NodeCleanupHandle1 {
    NodeCleanupCopy(const NodeCleanupHandle1& from) {
        value = from.value;
        fn_801F86C8(lbl_801E9D24.manager, &from, 1);
    }
};

/* Partial Node storage view for its original C destruction entry. */
struct NodeCleanupObject {
    NodeCleanupWord unknown00[2];
    const void* table;
    NodeCleanupHandle2 handle0C, handle10, handle14, handle18, handle1C, handle20;
    NodeCleanupHandle3 handle24, handle28;
    NodeCleanupHandle2 handle2C;
    char unknown30[0xF4];
    void* first;
    void* second;
    short firstIndex, secondIndex;
    NodeCleanupHandle2 handle130;
    int field134;
};

extern "C" NodeCleanupObject* fn_80241344(NodeCleanupObject*, short);

#endif

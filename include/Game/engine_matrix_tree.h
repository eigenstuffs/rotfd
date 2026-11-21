#ifndef GAME_ENGINE_MATRIX_TREE_H
#define GAME_ENGINE_MATRIX_TREE_H

struct EngineMatrixTreeHandle {
    signed int generation : 8;
    signed int index : 24;
};
struct EngineMatrixTreeMatrix {
    float m[16];
};
struct EngineMatrixTreeNode {
    char unknown00[0x10];
    EngineMatrixTreeHandle child;
    int unknown14;
    EngineMatrixTreeHandle next;
    char unknown1C[0x104];
    unsigned int flags;
    EngineMatrixTreeMatrix* local;
    int unknown128;
    short index;
};
struct EngineMatrixTreeEntry {
    EngineMatrixTreeNode* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct EngineMatrixTreeManager {
    char unknown00[8];
    EngineMatrixTreeEntry* entries;
};
struct EngineMatrixTreeBuffers {
    EngineMatrixTreeMatrix* banks[6];
    unsigned char active;
};
struct EngineMatrixTreeContext {
    char unknown00[0x118];
    EngineMatrixTreeManager* manager;
    char unknown11C[0x18];
    EngineMatrixTreeBuffers* buffers;
};
struct EngineMatrixTreeOwner {
    char unknown00[0x2C];
    EngineMatrixTreeHandle root;
};

extern "C" {
extern EngineMatrixTreeContext lbl_801E9D24;
extern unsigned int lbl_80378010;
void fn_8027B508(EngineMatrixTreeNode*, EngineMatrixTreeNode*);
}

static inline EngineMatrixTreeNode* engineMatrixTreeResolve(EngineMatrixTreeManager* manager, const EngineMatrixTreeHandle& handle)
{
    EngineMatrixTreeEntry* entry = &manager->entries[handle.index];
    return entry->generation == handle.generation ? entry->object : 0;
}

static inline void engineMatrixTreeAssign(EngineMatrixTreeNode*& output, EngineMatrixTreeManager* manager, const EngineMatrixTreeHandle& handle)
{
    EngineMatrixTreeEntry* entry = &manager->entries[handle.index];
    if (entry->generation == handle.generation)
        output = entry->object;
    else
        output = 0;
}

#endif

#ifndef GAME_ENGINE_TREE_RECORDS_H
#define GAME_ENGINE_TREE_RECORDS_H

struct EngineTreeVector {
    float x, y, z;
};
struct EngineTreeQuaternion {
    float x, y, z, w;
};
struct EngineTreeMatrix3 {
    float m[9];
};
struct EngineTreeMatrix4 {
    float m[16];
};
struct EngineTreeHandle {
    signed int generation : 8;
    signed int index : 24;
};
struct EngineTreeNode {
    char unknown00[0xC];
    EngineTreeHandle parent;
    char unknown10[0x20];
    EngineTreeMatrix3 basis;
    EngineTreeMatrix3 transposeBasis;
    char unknown78[0x40];
    EngineTreeVector position;
    unsigned int unknownC4;
    EngineTreeQuaternion orientation;
    EngineTreeVector scale;
    char unknownE4[0x3C];
    unsigned int flags;
    EngineTreeMatrix4* local;
    EngineTreeMatrix4* world;
    short unknown12C, index;
    unsigned int unknown130;
    int group;
};
struct EngineTreeEntry {
    EngineTreeNode* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct EngineTreeManager {
    char unknown00[8];
    EngineTreeEntry* entries;
};
struct EngineTreeMatrixBuffers {
    EngineTreeMatrix4* banks[6];
    unsigned char active;
};
struct EngineTreeHandleTable {
    char unknown00[8];
    EngineTreeHandle* items;
};
struct EngineTreeContext {
    char unknown00[0x118];
    EngineTreeManager* manager;
    EngineTreeHandleTable* groups;
    char unknown120[0x14];
    EngineTreeMatrixBuffers* matrices;
};
extern "C" {
extern EngineTreeContext lbl_801E9D24;
void fn_801F2124(void*,  EngineTreeMatrix3*);
void fn_801F1CD8(const EngineTreeQuaternion*, EngineTreeMatrix3*);
void fn_801F223C(EngineTreeMatrix3*, const EngineTreeMatrix3*);
void fn_801F20F4(EngineTreeQuaternion*, const EngineTreeMatrix3*);
void fn_8023D258(EngineTreeNode*, const EngineTreeVector*);
}
static inline EngineTreeNode* engineTreeResolve(const EngineTreeHandle& handle)
{
    EngineTreeEntry* entry = &lbl_801E9D24.manager->entries[handle.index];
    return entry->generation == handle.generation ? entry->object : 0;
}
static inline void engineTreeRefreshTransposeBasis(EngineTreeNode* node)
{
    if (node->flags & 0x40) {
        fn_801F2124(&node->basis, &node->transposeBasis);
        node->flags &= ~0x40;
    }
}

#endif

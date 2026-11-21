#include "Game/object_list_acquire_trivial.h"

typedef unsigned long Word;

struct ObjectListAcquireNode {
    Word handle;
    int key;
    ObjectListAcquireNode* next;
    float field0C, field10;
};

struct ObjectListAcquirePool {
    char unknown00[0x40];
    ObjectListAcquireNode* freeNodes;
};

struct EmptyHandleStorage {
    union {
        Word value;
        struct {
            signed int generation : 8;
            signed int index : 24;
        } bits;
    };
};

extern "C" {
void fn_801F7914(void*, const void*);
void* __dt__15Handle_801F7F10Fv(void*, short);
extern const float lbl_8037B890, lbl_8037B894;
}

static inline ObjectListAcquireNode* resetNode(ObjectListAcquireNode* node)
{
    {
        EmptyHandleStorage empty;
        empty.bits.index = 0;
        empty.bits.generation = 0;
        fn_801F7914(&node->handle, &empty);
        __dt__15Handle_801F7F10Fv(&empty, -1);
    }
    node->key = 0;
    node->next = 0;
    node->field0C = lbl_8037B890;
    node->field10 = lbl_8037B894;
    return node;
}

extern "C" ObjectListAcquireNode* fn_80285D34(ObjectListAcquirePool* self)
{
    ObjectListAcquireNode* node = self->freeNodes;
    self->freeNodes = self->freeNodes->next;
    return resetNode(node);
}

typedef char CheckEmptyHandleStorage[sizeof(EmptyHandleStorage) == 4 ? 1 : -1];
typedef char CheckObjectListAcquireNode[sizeof(ObjectListAcquireNode) == 20 ? 1 : -1];

#include "Game/object_list_acquire_controls.h"
#include "Game/object_list_pool_internal.h"

static inline ObjectListNode* resetNode(ObjectListNode* node)
{
    {
        ObjectListEmptyHandle empty;
        fn_801F7914(&node->handle, &empty);
    }
    node->key = 0;
    node->next = 0;
    node->field0C = lbl_8037B890;
    node->field10 = lbl_8037B894;
    return node;
}

extern "C" ObjectListNode* fn_80285D34(ObjectListPool* self)
{
    ObjectListNode* node = self->freeNodes;
    self->freeNodes = self->freeNodes->next;
    return resetNode(node);
}

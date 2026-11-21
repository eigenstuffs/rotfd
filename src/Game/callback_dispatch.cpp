#include "Game/callback_cycle_internal.h"
extern "C" void fn_8025F240(DispatchNode *node, CallbackCycle *self) {
    node->flags |= 2;
    if (!(node->flags & 1)) {
        if ((self->*node->callback)(9, node)) {
            node->flags |= 1;
            node->count = 0;
            (self->*node->callback)(10, node);
        } else {
            return;
        }
    }
    if ((self->*node->callback)(11, node) == 1) {
        node->flags &= 0xfffe;
        (self->*node->callback)(12, node);
    } else {
        if ((self->*node->callback)(14, node)) {
            (self->*node->callback)(15, node);
        } else {
            (self->*node->callback)(13, node);
        }
    }
}

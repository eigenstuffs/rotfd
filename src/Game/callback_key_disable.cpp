#include "Game/callback_key_internal.h"
extern "C" void fn_8025ECD8(CallbackCycle *self, int key) {
    for (DispatchKeyView *node = (DispatchKeyView*)self->head; node; node = node->next) {
        if (node->flags & 4) {
            for (int i = 0; i < node->length; ++i) {
                if (key == node->links[i].key) {
                    node->flags &= 0xfffb;
                    break;
                }
            }
        }
    }
}

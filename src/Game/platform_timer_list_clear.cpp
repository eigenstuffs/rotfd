#include "Game/platform_small_controls.h"
#include "Game/timer_linked_list_internal.h"

extern "C" void fn_80260180(TimerList* self) {
    TimerNode* node;
    while ((node = self->head) != 0) {
        self->head = node->next;
        fn_80285CDC(self, node);
    }
}

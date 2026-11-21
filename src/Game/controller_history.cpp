#include "Game/controller_history_internal.h"

extern "C" signed char fn_80275BA4(HistoryView* self, unsigned long count,
                                   const unsigned long* values)
{
    unsigned long j;
    int index = self->next - 1;
    if (index < 0)
        index += 25;
    for (j = 1; j <= count; ++j) {
        if (self->tokens[index] != values[count - j])
            return 0;
        if (--index < 0)
            index += 25;
    }
    return 1;
}

extern "C" void fn_80275C08(HistoryView* self)
{
    int added = 0;
    if (!(self->flags & 0x40))
        return;
    if ((self->flags & 8) && self->last != 8) {
        self->tokens[self->next] = 8;
        added = 1;
    }
    else if ((self->flags & 4) && self->last != 4) {
        self->tokens[self->next] = 4;
        added = 1;
    }
    else if ((self->flags & 1) && self->last != 1) {
        self->tokens[self->next] = 1;
        added = 1;
    }
    else if ((self->flags & 2) && self->last != 2) {
        self->tokens[self->next] = 2;
        added = 1;
    }
    else if ((self->flags & 0x1000) && self->last != 0x1000) {
        self->tokens[self->next] = 0x1000;
        added = 1;
    }
    else if ((self->flags & 0x800) && self->last != 0x800) {
        self->tokens[self->next] = 0x800;
        added = 1;
    }
    else if ((self->flags & 0x400) && self->last != 0x400) {
        self->tokens[self->next] = 0x400;
        added = 1;
    }
    else if ((self->flags & 0x100) && self->last != 0x100) {
        self->tokens[self->next] = 0x100;
        added = 1;
    }
    else if ((self->flags & 0x200) && self->last != 0x200) {
        self->tokens[self->next] = 0x200;
        added = 1;
    }
    else if ((self->flags & 0x20) && self->last != 0x20) {
        self->tokens[self->next] = 0x20;
        added = 1;
    }
    else if ((self->flags & 0x10) && self->last != 0x10) {
        self->tokens[self->next] = 0x10;
        added = 1;
    }
    else if (self->flags == 0x40 && self->last != 0)
        self->last = 0;
    if (added) {
        self->last = self->tokens[self->next];
        ++self->next;
        self->next %= 25;
        if (self->next == self->oldest)
            ++self->oldest;
    }
}

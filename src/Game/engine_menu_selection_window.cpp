#include "Game/engine_menu_selection_window.h"

static inline signed char eligible(const MenuSelectionItem* item) {
    if (item->flags & 0x100) return !(item->flags & 2);
    int result = 0;
    if (!(item->flags & 6) && (item->flags & 1)) result = 1;
    return result;
}

static inline unsigned short getVisible(const MenuSelectionWindow* menu) {
    return menu->visible;
}

extern "C" void fn_8021D51C(MenuSelectionWindow* self, int input) {
    int count = self->count;
    signed char found = 0;
    if (self->requestedVisible == 0) self->requestedVisible = count;
    self->visible = self->requestedVisible;
    self->start = 0;
    self->selected = input;
    while (self->selected < count) {
        if (eligible(self->items[self->selected])) {
            found = 1;
            break;
        }
        ++self->selected;
    }
    if (!found) self->selected = input;
    self->previous = self->selected;
    switch (self->mode) {
    case 0:
        break;
    case 2:
        if (self->requestedVisible == 1) {
            self->visible = self->requestedVisible;
            self->start = self->selected;
            break;
        }
        int oldVisible;
        do {
            oldVisible = self->visible;
            int end = fn_8021DA0C(self->start + oldVisible, self->count);
            self->visible = self->requestedVisible;
            for (int i = self->start; i < end;) {
                MenuSelectionItem* item = self->items[i++];
                if (item->flags & 2) --self->visible;
            }
            if (self->visible >= self->count) self->visible = self->count;
            if (self->start + self->visible <= self->selected)
                self->start = self->selected - self->visible + 1;
            if (self->selected < self->start) self->start = self->selected;
            if (self->start + self->visible >= self->count)
                self->start = self->count - self->visible;
            if (getVisible(self) > 2) {
                short selected = self->selected;
                if (selected > 0 && selected == self->start) --self->start;
                else if (selected < self->count - 1 &&
                         selected == self->start + getVisible(self) - 1)
                    ++self->start;
            }
        } while (oldVisible != self->visible);
        break;
    case 1:
        fn_801FA014(lbl_801E9D24.logger, lbl_802AE918);
        break;
    }
    self->refresh(1, 0);
}

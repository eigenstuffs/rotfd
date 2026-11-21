#include "Game/engine_menu_selection_set.h"

static inline unsigned short getVisible(const MenuSelectionSet* menu) {
    return menu->visible;
}

extern "C" signed char fn_8021CDAC(MenuSelectionSet* self, unsigned int index) {
    if(index < (unsigned int)self->count && (self->items[index]->flags & 1)) {
        self->selected = index;
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
                    MenuSelectionSetItem* item = self->items[i++];
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
        self->refresh(1, 1);
        return 1;
    }
    return 0;
}

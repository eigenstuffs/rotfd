#ifndef GAME_CONTROLLER_HISTORY_INTERNAL_H
#define GAME_CONTROLLER_HISTORY_INTERNAL_H

struct HistoryView {
    char unknown00[0x20];
    unsigned short flags;
    char unknown22[0x5A];
    unsigned long tokens[25];
    unsigned long oldest, next, last;
};

typedef char CheckHistoryView[sizeof(HistoryView) == 0xEC ? 1 : -1];
#endif

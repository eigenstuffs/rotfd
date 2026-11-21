#ifndef GAME_CALLBACK_LINE_READER_INTERNAL_H
#define GAME_CALLBACK_LINE_READER_INTERNAL_H

// Only the observed storage, length and cursor prefix is known.
struct LineReaderPrefix {
    char unknown0[0xC];
    signed char* data;
    int length;
    int cursor;
};

#endif

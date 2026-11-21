#include "Game/callback_line_reader_internal.h"

extern "C" signed char* fn_802530C8(LineReaderPrefix* self, int* length) {
    *length = 0;
    if (self->cursor >= self->length) {
        return 0;
    }
    int position = self->cursor;
    while (position < self->length) {
        if (self->data[position] == '\n') {
            break;
        }
        ++*length;
        ++position;
    }
    self->cursor += *length;
    int start = self->cursor - *length;
    while (self->cursor < self->length &&
           (self->data[self->cursor] == '\r' ||
            self->data[self->cursor] == '\n' ||
            self->data[self->cursor] == ' ')) {
        ++self->cursor;
    }
    return self->data + start;
}


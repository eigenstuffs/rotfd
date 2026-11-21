/* Recovered log buffer clearing and empty callbacks. */
#include "logger_internal.h"

extern "C" {
void fn_801F9D64(Logger *self) {}
void fn_801F9D60(Logger *self) {}
void fn_801F9D0C(Logger *self)
{
    memset(self->buffer,0,0x6000);
    self->scroll=0;
    self->refresh();
}
}

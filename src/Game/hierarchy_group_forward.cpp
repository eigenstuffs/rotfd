#include "group_runtime_internal.h"

extern "C" {
int fn_80206868(Object*, int);
void fn_80206B44(Object*, int, int);
void fn_80206C54(Object*, int, int, const void*);
void fn_80207004(Object*, int);

int fn_80206E28(Group* self, int member, int index) {
    return fn_80206868(resolve(self->entries.data[member]), index);
}
void fn_80206E9C(Group* self, int member, int index, int offset) {
    fn_80206B44(resolve(self->entries.data[member]), index, offset);
}
void fn_80206F14(Group* self, int member, int index, int argument, const void* name) {
    fn_80206C54(resolve(self->entries.data[member]), index, argument, name);
}
void fn_80206F90(Group* self, int member, int count) {
    fn_80207004(resolve(self->entries.data[member]), count);
}
}

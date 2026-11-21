// World record callback dispatch, reference fixups and binary loading.
#include "world_records_internal.h"
extern "C" {
void fn_801B3E54(Manager*, void*);
void fn_8028BFA4(WorldRecord50*);
void fn_801F6AF8(void*);
unsigned char* fn_801E9F40(void*, const unsigned char*, int);
void fn_801E4450(WorldRecordArray<WorldRecord50>*, int, signed char);
void fn_801E3F2C(WorldRecordArray<WorldRecord4C>*, int, signed char);
void fn_801E3AC4(WorldRecordArray<WorldRecord3C>*, int, signed char);
void fn_801E3868(WorldRecordArray<WorldRecord1C>*, int, signed char);
void fn_801E3614(WorldRecordArray<WorldRecord14>*, int, signed char);
void fn_8028BFC8(WorldRecord50*, unsigned char**);
void fn_801AC7FC(WorldRecord4C*, unsigned char**);
void fn_801AEFF4(WorldRecord3C*, unsigned char**);
void fn_801B41F4(Manager*, void*, unsigned char**);
void fn_801B41B8(Manager*, void*, unsigned char**);
void fn_801B3FD0(Manager*, void*, unsigned char**);
void fn_801F6BFC(void*, unsigned char**);
void fn_801E30E4(WorldRecordView* self) {
    for (int i = 0; i < self->records3C.count; ++i) {
        WorldNotifyObject* callback = self->records3C.data[i].handle10.get();
        Activable_Z* object = self->records3C.data[i].handle0C.get();
        if (callback) callback->slot20(object, 0);
    }
}
void fn_801E31EC(WorldRecordView* self) {
    int i;
    Manager* manager = lbl_801E9D24.manager;
    for (i = 0; i < self->records30.count; ++i) {
        fn_801B3E54(manager, &self->records30.data[i].handle10);
        fn_801B3E54(manager, &self->records30.data[i].handle14);
        fn_801B3E54(manager, &self->records30.data[i].handle18);
    }
    for (i = 0; i < self->records0C.count; ++i)
        fn_8028BFA4(&self->records0C.data[i]);
    for (i = 0; i < self->records3C.count; ++i) {
        fn_801B3E54(manager, &self->records3C.data[i].handle0C);
        fn_801B3E54(manager, &self->records3C.data[i].handle08);
    }
    fn_801F6AF8(self->object54);
}
void fn_801E3310(WorldRecordView* self, unsigned char** cursor) {
    self->BaseObject_Z::slot0C((u32)cursor);
    Manager* manager = lbl_801E9D24.manager;
    int count, i;
    *cursor = fn_801E9F40(&self->field74, *cursor, 4);
    *cursor = fn_801E9F40(&count, *cursor, 4);
    fn_801E4450(&self->records0C, count, 0);
    for (i = 0; i < count; ++i) fn_8028BFC8(&self->records0C.data[i], cursor);
    *cursor = fn_801E9F40(&count, *cursor, 4);
    fn_801E3F2C(&self->records18, count, 0);
    for (i = 0; i < count; ++i) fn_801AC7FC(&self->records18.data[i], cursor);
    *cursor = fn_801E9F40(&count, *cursor, 4);
    fn_801E3AC4(&self->records24, count, 0);
    for (i = 0; i < count; ++i) fn_801AEFF4(&self->records24.data[i], cursor);
    *cursor = fn_801E9F40(&count, *cursor, 4);
    fn_801E3868(&self->records30, count, 0);
    for (i = 0; i < count; ++i) {
        fn_801B41F4(manager, &self->records30.data[i].name00, cursor);
        fn_801B41F4(manager, &self->records30.data[i].name04, cursor);
        *cursor = fn_801E9F40(&self->records30.data[i].field08, *cursor, 4);
        *cursor = fn_801E9F40(&self->records30.data[i].flag0C, *cursor, 1);
        fn_801B41B8(manager, &self->records30.data[i].handle10, cursor);
        fn_801B41B8(manager, &self->records30.data[i].handle14, cursor);
        fn_801B41B8(manager, &self->records30.data[i].handle18, cursor);
    }
    *cursor = fn_801E9F40(&count, *cursor, 4);
    fn_801E3614(&self->records3C, count, 0);
    for (i = 0; i < count; ++i) {
        *cursor = fn_801E9F40(&self->records3C.data[i].field00, *cursor, 4);
        fn_801B41F4(manager, &self->records3C.data[i].name04, cursor);
        fn_801B41B8(manager, &self->records3C.data[i].handle0C, cursor);
        fn_801B41B8(manager, &self->records3C.data[i].handle08, cursor);
        fn_801B3FD0(manager, &self->records3C.data[i].handle10, cursor);
    }
    fn_801F6BFC(self->object54, cursor);
}
}

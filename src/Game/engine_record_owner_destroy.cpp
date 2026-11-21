#include "Game/engine_record_owner_destroy.h"

extern "C" {
extern char __vt__19DrawRecord_802EB0E0[], __vt__24ManipulatorDraw_802BC9D0[];
extern char __vt__13Manipulator_Z[], lbl_8028F698[], lbl_801EF5C8[];
void fn_8028FD50(void *, void *, int);
void fn_801EF610(void *, void *);
void __dt__11Activable_ZFv(void *, int);
void __dt__15Handle_801F7F10Fv(Handle_801F7F10 *, int);
}

static inline void unlinkOwner(OwnerDestroyObject *self, MembershipContext *context)
{
    if (self->isActive()) {
        {
            const Handle_801F7F10 &original = self->handle;
            MembershipHandle handle(original);
            fn_801E1F3C(context->groups + self->group * 0x4C, handle);
        }
        fn_802139D8(self);
    }
}

static inline void destroyHandle(Handle_801F7F10 *self)
{
    if (self)
        __dt__15Handle_801F7F10Fv(self, 0);
}

static inline void destroyWrapped(OwnerDestroyWrapped *self)
{
    if (self)
        destroyHandle(&self->handle);
}

static inline void destroyRecord(OwnerDestroyRecord *self)
{
    if (self) {
        if (self)
            destroyHandle(&self->handle);
    }
}

static inline void destroyArray(OwnerDestroyArray *self)
{
    if (self) {
        if (self->data) {
            int i = 0;
            int offset = i;
            for (; i < self->count; offset += 0xD4, ++i)
                destroyRecord((OwnerDestroyRecord *)((char *)self->data + offset));
            if (self->data) {
                fn_8028FD50(lbl_8028F698, self->data, self->capacity * 0xD4);
                self->data = 0;
            }
            self->data = 0;
        }
    }
}

static inline void destroyRoot(OwnerDestroyObject *self)
{
    if (self) {
        self->table = __vt__13Manipulator_Z;
        __dt__11Activable_ZFv(self, 0);
    }
}

static inline void destroyDraw(OwnerDestroyObject *self)
{
    if (self) {
        self->table = __vt__24ManipulatorDraw_802BC9D0;
        destroyRoot(self);
    }
}

extern "C" OwnerDestroyObject *fn_80210FD4(OwnerDestroyObject *self, short deleting)
{
    if (self) {
        self->table = __vt__19DrawRecord_802EB0E0;
        MembershipContext *context = &lbl_801E9D24;
        if (context->groups && self->isActive())
            unlinkOwner(self, context);
        destroyWrapped(&self->tail);
        destroyArray(&self->records);
        destroyDraw(self);
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}

#include "Game/engine_record_stream.h"

extern "C" {
extern const char lbl_8037ABD8[5];
unsigned long fn_801F7EB8(const Handle_801F7F10 *);
void fn_801F372C(void *, char *);
signed char fn_801F2E04(void *);
int strcmp(const char *, const char *);
void fn_8020F8BC(void *, void *);
void fn_80210FA4(void *, int);
}

static inline StreamObject *resolve(const Handle_801F7F10 &handle)
{
    StreamEntry *entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->tag == handle.bits.tag ? entry->object : 0;
}

extern "C" int fn_8021020C(void *self, unsigned long key)
{
    StreamHandle handle(lbl_801E9D24.manager->lookup(key));
    if (!fn_801F7EB8(&handle))
        return 0;

    char buffer[128];
    void *stream = resolve(handle)->stream;
    fn_801F372C(stream, buffer);
    while (!fn_801F2E04(stream)) {
        if (strcmp(buffer, lbl_8037ABD8) == 0)
            fn_8020F8BC(self, stream);
        fn_801F372C(stream, buffer);
    }
    fn_80210FA4(self, 6);
    return 1;
}

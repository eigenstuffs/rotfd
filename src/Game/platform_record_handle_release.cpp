#include "Game/platform_record_handle_release.h"

extern "C" void fn_801F6AF8(unsigned long*);
extern "C" void fn_8028BFA4(PlatformReleaseRecord* self)
{
    fn_801F6AF8(&self->handle3C);
}

#include "Game/early_python_event_views.h"
extern "C" {
    extern const char lbl_803781C8[6];
    extern EventPyObject* lbl_80377540;
    extern EventPyObject* lbl_80377544;
    void fn_8001F834(void*);
    EventPyObject* PyDict_New();
    EventPyObject* PyDict_Copy(EventPyObject*);
    EventPyObject* fn_8001FB04(const char*,void*);
    void fn_800200F8(const char*);
}
#define RELEASE_GLOBAL(object) if(object) { if(--object->references==0)object->type->destroy(object); }
extern "C" int fn_8001F754(void* self,void* argument)
{
    fn_8001F834(self);
    RELEASE_GLOBAL(lbl_80377540);
    lbl_80377540=PyDict_New();
    EventPyObject* result=fn_8001FB04(lbl_803781C8,argument);
    releaseEventObject(result);
    fn_800200F8(lbl_803781C8);
    RELEASE_GLOBAL(lbl_80377544);
    lbl_80377544=PyDict_Copy(lbl_80377540);
    return 1;
}

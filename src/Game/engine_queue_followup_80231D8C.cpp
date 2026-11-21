#include "Game/engine_queue_followup.h"

extern "C" void fn_80231D8C(EngineFollowupOwner *object, int value, float a, float b) {
    if (fn_801F7EB8(&object->handle))
        engineFollowupResolve(object->handle)->slot4C(value, a, b);
}

extern "C" void fn_80231E4C(EngineFollowupOwner *object, int first, float a, float b,
                            float c, float d, float e, int last) {
    if (fn_801F7EB8(&object->handle))
        engineFollowupResolve(object->handle)->slot48(first, a, b, c, d, e, last);
}

extern "C" void fn_80231F34(EngineFollowupOwner *object) {
    if (fn_801F7EB8(&object->handle))
        fn_802139D8(engineFollowupResolve(object->handle));
}

extern "C" void fn_80231FB8(EngineFollowupOwner *object) {
    if (fn_801F7EB8(&object->handle))
        fn_80213A18(engineFollowupResolve(object->handle));
}

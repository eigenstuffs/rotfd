// Reconstructed from GSQE78 fn_80212674 and its native static initialization.
#include "ingame_manipulator_update_native_internal.h"

extern "C" {
float fn_8028506C(float);
float fn_80284FA8(float);
inline void fromAxis(Transform* target, float ax, float ay, float az, float angle) {
    float cosine = fn_8028506C(angle / 2.0f);
    float sine = fn_80284FA8(angle / 2.0f);
    target->w = cosine;
    target->x = ax * sine;
    target->y = ay * sine;
    target->z = az * sine;
}
}
void InGameObjectsManipulator_802128A0::slot38(float delta) {
    static float phase = 0.0f;
    if (fn_801F7EB8(&handle20)) {
        Node* node = resolve(handle20);
        Transform* target = resolveRelated(node->related);
        if (target) {
            fromAxis(target,0.0f,1.0f,0.0f,phase);
            phase += (6.28318530717958647692f * delta) / 6.0f;
            if (phase > 6.28318530717958647692f)
                phase -= 6.28318530717958647692f;
        }
    }
}

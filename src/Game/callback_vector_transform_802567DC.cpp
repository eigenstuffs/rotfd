/* Prepare a callback vector, then transform it through the owner's cached basis.
 * The public native entry agrees with the existing Python binding's ABI.
 */
#pragma fp_contract on
#include "Game/callback_handle_transfers_internal.h"

struct CallbackTransformVector { float x, y, z; };
struct Matrix3 { float m[9]; };
struct CallbackTransformTarget {
    char unknown00[0x30];
    Matrix3 basis30;
    Matrix3 transpose54;
    char unknown78[0xA8];
    unsigned int flags120;
};

extern "C" {
    signed char fn_802568F4(void*, long, long, void*);
    void fn_801F2124(const Matrix3*, Matrix3*);
}

static inline float dot3(float a, float b, float c, float x, float y, float z) {
    return a * x + b * y + c * z;
}

static inline void transformCallbackVector(const Matrix3& matrix,
                                          CallbackTransformVector& vector) {
    float x = dot3(matrix.m[0], matrix.m[3], matrix.m[6],
                   vector.x, vector.y, vector.z);
    float y = dot3(matrix.m[1], matrix.m[4], matrix.m[7],
                   vector.x, vector.y, vector.z);
    float z = dot3(matrix.m[2], matrix.m[5], matrix.m[8],
                   vector.x, vector.y, vector.z);
    vector.x = x;
    vector.y = y;
    vector.z = z;
}

extern "C" signed char fn_802567DC(void* nativeOwner, long first, long second,
                                  void* nativeVector) {
    CallbackTransferOwner* self = (CallbackTransferOwner*)nativeOwner;
    CallbackTransformVector* vector = (CallbackTransformVector*)nativeVector;
    if (fn_802568F4(nativeOwner, first, second, nativeVector)) {
        CallbackTransformTarget* target =
            (CallbackTransformTarget*)resolveRelated(self->handle58);
        if (target->flags120 & 0x40) {
            fn_801F2124(&target->basis30, &target->transpose54);
            target->flags120 &= ~0x40;
        }
        transformCallbackVector(target->transpose54, *vector);
        return 1;
    }
    return 0;
}

typedef char VectorSize[sizeof(CallbackTransformVector) == 12 ? 1 : -1];
typedef char MatrixSize[sizeof(Matrix3) == 36 ? 1 : -1];

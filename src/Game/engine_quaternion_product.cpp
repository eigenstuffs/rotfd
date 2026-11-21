#include "Game/engine_quaternion_product.h"

extern "C" EngineQuaternionProduct fn_801F1C64(
    const EngineQuaternionProduct* left, const EngineQuaternionProduct* right)
{
    return EngineQuaternionProduct(
        left->w * right->w - left->x * right->x - left->y * right->y - left->z * right->z,
        left->w * right->x + left->x * right->w + left->y * right->z - left->z * right->y,
        left->w * right->y + left->y * right->w + left->z * right->x - left->x * right->z,
        left->w * right->z + left->z * right->w + left->x * right->y - left->y * right->x);
}

#ifndef GAME_ENGINE_QUATERNION_PRODUCT_H
#define GAME_ENGINE_QUATERNION_PRODUCT_H

struct EngineQuaternionProduct {
    float w;
    float x;
    float y;
    float z;

    EngineQuaternionProduct(float a, float b, float c, float d)
        : w(a), x(b), y(c), z(d) {}
};

extern "C" EngineQuaternionProduct fn_801F1C64(
    const EngineQuaternionProduct* left, const EngineQuaternionProduct* right);

#endif

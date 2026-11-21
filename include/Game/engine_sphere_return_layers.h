#ifndef GAME_ENGINE_SPHERE_RETURN_LAYERS_H
#define GAME_ENGINE_SPHERE_RETURN_LAYERS_H

struct SphereReturnPoint {
    float x, y, z;
    SphereReturnPoint() {}
    SphereReturnPoint(const SphereReturnPoint& p): x(p.x), y(p.y), z(p.z) {}
    SphereReturnPoint& operator=(const SphereReturnPoint& p)
    { x = p.x; y = p.y; z = p.z; return *this; }
};
struct SphereReturnValue {
    SphereReturnPoint point;
    float radius;
    SphereReturnValue() {}
    SphereReturnValue(const SphereReturnValue& s): point(s.point), radius(s.radius) {}
    SphereReturnValue& operator=(const SphereReturnValue& s)
    { point = s.point; radius = s.radius; return *this; }
};
struct SphereReturnOwner { char unknown00[0xB0]; SphereReturnValue* sphere; };
struct SphereReturnObject { char unknown00[0x124]; void* matrix; };

extern "C" {
SphereReturnValue fn_80099A00(const void*, const SphereReturnValue*);
SphereReturnValue fn_80246E64(const void*);
SphereReturnValue fn_801F0A20(const SphereReturnValue&, const SphereReturnValue&);
int fn_8024673C(SphereReturnOwner*, SphereReturnObject*, SphereReturnValue*);
SphereReturnValue fn_80246E14(const SphereReturnValue&, const void*);
}
typedef char SphereReturnValueSize[sizeof(SphereReturnValue) == 16 ? 1 : -1];

#endif

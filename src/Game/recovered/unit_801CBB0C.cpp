extern "C" const float lbl_8037A438;
/* fn_801CBB0C: picks a level-of-detail index from the planar distance between
 * two nodes. The square root helper is the engine's own two-instruction
 * frsqrte/fres sequence with a hard-coded f4 scratch register, exactly as in
 * the already matched users (e.g. actor_force_velocity_clamp_80096FC8.cpp).
 *
 * Register allocation note: Vec3::operator- keeps every component in its own
 * declared local (from.z, to.z, to.x, from.x, to.y, from.y, then the z/x/y
 * differences) and the function is compiled with opt_propagation off so these
 * locals keep their own virtual registers; that reproduces the original
 * float colouring. */
extern "C" {
int fn_801CBC44(int, int, int);
}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

struct Vec2 {
    float x, y;
    Vec2(float a, float b) : x(a), y(b) {}
    float length() const {
        float sq = x * x + y * y;
        float r = lbl_8037A438;
        if (sq != r)
            r = fastSqrt(sq);
        return r;
    }
};

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec2 xz() const { return Vec2(x, z); }
    Vec3 operator-(const Vec3& o) const {
        float bz, az, ax, bx, ay, by, zd, xd, yd;
        bz = o.z;
        az = z;
        ax = x;
        bx = o.x;
        ay = y;
        by = o.y;
        zd = az - bz;
        xd = ax - bx;
        yd = ay - by;
        return Vec3(xd, yd, zd);
    }
};

struct Transform { char pad[0x30]; Vec3 position; };
struct Node { char pad[0x124]; Transform* transform; };
struct Settings { char pad[0x21c]; int scale; };
struct View { char pad[0x18]; float f18; float f1c; char pad2[0x28]; Settings* settings; float getF1c() const { return f1c; } };
struct Item {
    View* view;
    char pad[8];
    Node* from;
    Node* to;
    char pad2[0xbcc - 0x14];
    int lod;
};
struct Owner { char pad[0xb4]; float fb4; float fb8; int pad2; int count; };

#pragma push
#pragma opt_propagation off
extern "C" void fn_801CBB0C(Owner* self, Item* item) {
    Transform* to = item->to->transform;
    Transform* from = item->from->transform;
    float len = (to->position - from->position).xz().length();
    View* view = item->view;
    item->lod = (float)self->count / (self->fb8 * (len * (float)view->settings->scale)) * (self->fb4 * (view->getF1c() * view->f18));
    item->lod = fn_801CBC44(item->lod, 0, self->count - 1);
    item->lod = self->count - item->lod - 1;
}
#pragma pop

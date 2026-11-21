/* fn_80241E10: camera view-matrix apply to a Node (roll about z, look-at
   basis from the node origin toward the camera's (target-resolved) position).
   Matching notes: the up vector's first 0.0 uses the *(const float*)& pooled
   literal form (the original TU's literals were separate loads); the Mat3
   copy of the basis is filled in column order. Neighbor flags (-O4,p, no
   exceptions, no -fp_contract). */
typedef unsigned long Word;
struct Vec3 { float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct Mat3 { float m[3][3]; };
struct Matrix4 { float m[4][4]; Vec3 translation() const { return Vec3(m[3][0], m[3][1], m[3][2]); } };
struct NodePool { char* banks[2]; char occupied[0x10]; unsigned char active; unsigned char bankCount; };
struct Node;
struct Entry { Node* object; char unknown04[8]; signed char tag; char pad[3];
    signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; Entry* entries; };
struct Handle { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; };
extern "C" struct Global { char unknown00[0x118]; Manager* manager; char unknown11C[0x18]; NodePool* pool; } lbl_801E9D24;
inline Node* resolve(const Handle& h) {
    int index = h.bits.index; Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
struct Node {
    char unknown00[0x30];
    Mat3 basis;
    char unknown54[0x120 - 0x54];
    int flags120;
    Matrix4* first;
    Matrix4* second;
    short firstIndex, secondIndex;
};
struct Camera {
    char unknown00[0x120];
    float roll;
    Vec3 position;
    Handle target;
};
extern "C" {
extern const float lbl_8037B340, lbl_8037B344;
void* memset(void*, int, unsigned long);
float fn_8028506C(float);
float fn_80284FA8(float);
void fn_801F18D0(const Vec3*, const Vec3*, Matrix4*);
Matrix4* fn_801F2788(Matrix4*, const Matrix4*);
}
inline float frsqrte(register float x) { register float r; asm { frsqrte r, x } return r; }

extern "C" void fn_80241E10(Camera* self, Node* node) {
    Matrix4 view;
    Matrix4 roll;
    memset(&roll, 0, sizeof(Matrix4));
    roll.m[0][0] = lbl_8037B340; roll.m[1][1] = lbl_8037B340;
    roll.m[2][2] = lbl_8037B340; roll.m[3][3] = lbl_8037B340;
    roll.m[0][0] = fn_8028506C(self->roll);
    roll.m[1][0] = -fn_80284FA8(self->roll);
    roll.m[0][1] = fn_80284FA8(self->roll);
    roll.m[1][1] = fn_8028506C(self->roll);
    Vec3 eye = node->first->translation();
    Node* target = resolve(self->target);
    if (target) {
        self->position = target->first->translation();
    }
    Vec3 dir(self->position.x - eye.x, self->position.y - eye.y, self->position.z - eye.z);
    Vec3 up(*(const float*)&lbl_8037B344, lbl_8037B340, lbl_8037B344);
    float s = frsqrte(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    dir.x *= s; dir.y *= s; dir.z *= s;
    fn_801F18D0(&dir, &up, &view);
    view.m[3][0] = eye.x; view.m[3][1] = eye.y; view.m[3][2] = eye.z;
    fn_801F2788(&view, &roll);
    node->first = (Matrix4*)(lbl_801E9D24.pool->banks[lbl_801E9D24.pool->active] + node->firstIndex * 0x40);
    *node->first = view;
    node->flags120 |= 0x20;
    Mat3 b;
    b.m[0][0] = view.m[0][0]; b.m[1][0] = view.m[1][0]; b.m[2][0] = view.m[2][0]; b.m[0][1] = view.m[0][1]; b.m[1][1] = view.m[1][1]; b.m[2][1] = view.m[2][1]; b.m[0][2] = view.m[0][2]; b.m[1][2] = view.m[1][2]; b.m[2][2] = view.m[2][2];
    node->basis = b;
}

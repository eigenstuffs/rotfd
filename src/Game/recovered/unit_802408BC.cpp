/* fn_802408BC: attach child handle h under self (parent/next/prev links,
   scene index), optionally converting the child's world transform into
   self's local space. Structures follow the matched sibling
   node_hierarchy_scene_link_8023FBE4.cpp. */
typedef unsigned long Word;
inline void* operator new(unsigned long, void* p) { return p; }

struct Handle { union { Word value; struct { signed int generation : 8, index : 24; } bits; }; };
struct Node;
struct Entry { Node* object; Word unknown04[2]; signed char generation; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
struct HandleList { int count, capacity; Handle* handles; };
struct NodePool { char* banks[2]; char occupied[0x10]; unsigned char active; unsigned char bankCount; };
struct Globals { char unknown00[0x118]; Manager* manager; HandleList* scenes; char unknown120[0x14]; NodePool* pool; };
extern "C" {
extern Globals lbl_801E9D24;
extern const float lbl_8037B32C;
void fn_801F86C8(Manager*, const void*, int);
Node* fn_801F7EB8(const void*);
void fn_8023D648(Node*);
void fn_8026736C(void*, int);
}
extern "C" {
inline signed char fn_8023C798(const Handle* h) { return h->bits.generation; }
inline int fn_8023C7B4(const Handle* h) { return h->bits.index; }
inline Entry* fn_8023C7A4(Manager* m, unsigned int index) { return m->entries + index; }
inline Node* fn_8023C2DC(Manager* m, const Handle* h) { int index = fn_8023C7B4(h); int generation = (signed char)fn_8023C798(h); int actual = fn_8023C7A4(m, index)->generation; if (actual == generation) return fn_8023C7A4(m, index)->object; return 0; }
inline Node* fn_8023C1C8(const Handle* h) { return fn_8023C2DC(lbl_801E9D24.manager, h); }
}

struct Handle_801F7F10 : Handle { Handle_801F7F10(); ~Handle_801F7F10(); };
struct NodeHandle1 : Handle_801F7F10 {
    NodeHandle1() { value = 0; } ~NodeHandle1() {}
    NodeHandle1& operator=(const NodeHandle1& h) { fn_801F86C8(lbl_801E9D24.manager, this, -1); value = h.value; fn_801F86C8(lbl_801E9D24.manager, &h, 1); return *this; }
};
struct NodeHandle2 : NodeHandle1 { NodeHandle2() { value = 0; } ~NodeHandle2() {} };
struct NodeCopy : NodeHandle1 {
    NodeCopy(const NodeHandle1& h) { value = h.value; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    NodeCopy(const NodeCopy& h) { value = h.value; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    ~NodeCopy() {}
};
struct Scene;
inline Scene* sceneOf(const Node* n);
inline signed char valid(const Handle& h) { return fn_801F7EB8(&h) != 0; }

struct Vec3 { float x, y, z;
    Vec3() {} Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; } };
inline float fastSqrt(register float x, register float zero) { register float r = zero; if (x != r) { asm { frsqrte f4, x
 fres r, f4 } } return r; }
struct Row { float x, y, z;
    Row(float a, float b, float c) : x(a), y(b), z(c) {}
    Row(const Row& v) : x(v.x), y(v.y), z(v.z) {}
    float dot(const Row& v) const { return x * v.x + y * v.y + z * v.z; }
    float length(float zero) const { return fastSqrt(dot(*this), zero); } };
struct Quat { float w, x, y, z; Quat() {} Quat& operator=(const Quat& q) { w = q.w; x = q.x; y = q.y; z = q.z; return *this; } };
struct Basis { float m[9]; };
struct Matrix { float m[4][4]; Row row(int i) const { return Row(m[i][0], m[i][1], m[i][2]); }
    const Vec3& translation() const { return *(const Vec3*)m[3]; } };
/* The original pooled literal 0.0f was reloaded for each length; three
   distinct read forms of the shared label keep three loads. */
inline Vec3 getScale(const Matrix& m) {
    float x = m.row(0).length(lbl_8037B32C);
    float y = m.row(1).length(*(const float*)&lbl_8037B32C);
    float z = m.row(2).length(*(const float*)(unsigned long)&lbl_8037B32C);
    return Vec3(x, y, z);
}
struct Resource { char unknown00[0x6C]; unsigned short type; };
struct SpatialGrid { char unknown00[0x4044]; };
struct Scene { char unknown00[0x34]; SpatialGrid primary, special, secondary; };
extern "C" {
Quat* fn_801F20F4(Quat*, const Basis*);
void fn_801F230C(const Matrix*, Matrix*);
void fn_801F2124(const Basis*, Basis*);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
void fn_801F223C(Basis*, const Basis*);
}
inline Matrix multiply(const Matrix* a, const Matrix* b) { Matrix r; fn_801F1080(a, b, &r); return r; }

struct Node {
    Word unknown00;
    NodeHandle1 self;
    const void* table;
    NodeHandle2 parent, child, prev, next, resource, handle20;
    char unknown24[0xC];
    Basis basis;
    Basis basisInverse;
    char unknown78[0xB8 - 0x78];
    Vec3 position;
    int firstIndex;
    Quat rotation;
    Vec3 scale;
    int secondIndex;
    char unknownE8[0x120 - 0xE8];
    Word flags;
    Matrix* first;
    Matrix* second;
    short firstIndex12C, secondIndex12E;
    NodeHandle2 handle130;
    int scene;
    const NodeHandle2& getParent() const { return parent; }
    const NodeHandle2& getChild() const { return child; }
    const NodeHandle2& getPrev() const { return prev; }
    const NodeHandle2& getNext() const { return next; }
    const NodeHandle1& getSelf() const { return self; }
    void setParent(const NodeHandle1& h) { parent.NodeHandle1::operator=(h); }
    void setChild(const NodeHandle1& h) { child.NodeHandle1::operator=(h); }
    void setPrev(const NodeHandle1& h) { prev.NodeHandle1::operator=(h); }
    void setNext(const NodeHandle1& h) { next.NodeHandle1::operator=(h); }
    void refreshInverse() {
        if (flags & 0x20) {
            second = (Matrix*)(lbl_801E9D24.pool->banks[lbl_801E9D24.pool->active] + secondIndex12E * 0x40);
            fn_801F230C(first, second);
            flags &= ~0x20;
        }
    }
    void refreshBasis() {
        if (flags & 0x40) {
            fn_801F2124(&basis, &basisInverse);
            flags &= ~0x40;
        }
    }
};

extern "C" void fn_8023FBE4(Node* self, int scene, signed char recurse);
/* inline copy of fn_8023FBE4 (matched in node_hierarchy_scene_link_8023FBE4.cpp) */
inline void setScene(Node* self, int scene, signed char recurse) {
    self->scene = scene;
    if (recurse) {
        Node* child = fn_8023C1C8(&self->child);
        if (child) fn_8023FBE4(child, scene, recurse);
        Node* next = fn_8023C1C8(&self->next);
        if (next) fn_8023FBE4(next, scene, recurse);
    }
}

extern "C" void fn_802408BC(Node* self, const NodeHandle1& h, signed char keepWorld) {
    Manager* m = lbl_801E9D24.manager;
    int index = h.bits.index;
    int generation = 0; generation += h.bits.generation;
    int actual = fn_8023C7A4(m, index)->generation;
    setScene(actual == generation ? fn_8023C7A4(m, index)->object : 0, self->scene, 0);
    fn_8023C1C8(&h)->setParent(NodeCopy(self->getSelf()));
    fn_8023C1C8(&h)->setNext(self->getChild());
    fn_8023C1C8(&h)->setPrev(NodeHandle2());
    if (fn_801F7EB8(&self->child)) fn_8023C1C8(&self->child)->setPrev(h);
    self->setChild(h);
    if (keepWorld) {
        Node* child = fn_8023C1C8(&h);
        Matrix* childWorld = child->first;
        self->refreshInverse();
        Matrix m = multiply(self->second, childWorld);
        self->refreshBasis();
        Basis b = self->basisInverse;
        fn_801F223C(&b, &child->basis);
        Quat q;
        fn_801F20F4(&q, &b);
        child->rotation = q;
        child->scale = getScale(m);
        child->position = m.translation();
    }
    fn_8023D648(fn_8023C1C8(&h));
}

#include "Game/node_matrix_pool.h"
/* Partial Node_Z.h constructor view; original tables retain their owners. */
typedef unsigned long NodeWord;

struct Handle_801F7F10 {
    NodeWord value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct NodeHandle1 : Handle_801F7F10 {
    NodeHandle1() { value = 0; }
    ~NodeHandle1() {}
};
struct NodeHandle2 : NodeHandle1 {
    NodeHandle2(int = 0) { value = 0; }
    ~NodeHandle2() {}
};
struct NodeHandle3 : NodeHandle2 {
    NodeHandle3() { value = 0; }
    ~NodeHandle3() {}
};
struct NodeContext {
    char unknown00[0x118];
    void* manager;
    char unknown11C[0x18];
    NodePool* pool;
};
struct NodePoint3 {
    float x, y, z;
    NodePoint3() {}
    NodePoint3(const NodePoint3& p) { x = p.x; y = p.y; z = p.z; }
    NodePoint3& operator=(const NodePoint3& p) {
        x = p.x; y = p.y; z = p.z;
        return *this;
    }
};
struct NodeQuat {
    float w, x, y, z;
    NodeQuat& operator=(const NodeQuat& q) {
        w = q.w; x = q.x; y = q.y; z = q.z;
        return *this;
    }
};
extern "C" {
extern NodeContext lbl_801E9D24;
extern const char lbl_802EC0A0[];
extern const NodePoint3 game_vec4_zero, game_vec3_zero;
extern const NodeQuat game_quat_identity;
extern const float lbl_8037B330, lbl_8037B32C;
void fn_801F86C8(void*, const Handle_801F7F10*, short);
void fn_8023EE7C(void*, const Handle_801F7F10*);
void fn_8023EE08(void*, const Handle_801F7F10*);
void* memset(void*, int, unsigned long);
}
struct RootStorage_80207414 { NodeWord unknown00[2]; };
struct BaseObject_Z : RootStorage_80207414 {
    BaseObject_Z();
    virtual ~BaseObject_Z();
    virtual void slot0C(unsigned long);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};
struct Resource_802E9E20 : BaseObject_Z {
    Resource_802E9E20() {}
    virtual ~Resource_802E9E20();
};
struct NodeRootView { NodeWord unknown00[2]; const void* table; };
struct NodeCopy : NodeHandle1 {
    NodeCopy(const NodeHandle1& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};
static inline void assignNode(Handle_801F7F10& to, const Handle_801F7F10& from) {
    fn_801F86C8(lbl_801E9D24.manager, &to, -1);
    to.value = from.value;
    fn_801F86C8(lbl_801E9D24.manager, &from, 1);
}
static inline void assignCopied(Handle_801F7F10& to, const NodeHandle1& from) {
    NodeCopy copy(from);
    assignNode(to, copy);
}
struct NodeSphere {
    NodePoint3 point;
    float radius;
    NodeSphere() : point(game_vec4_zero), radius(lbl_8037B330) {}
};
struct Node_802417BC {
    Resource_802E9E20 head;
    NodeHandle2 handle0C, handle10, handle14, handle18, handle1C, handle20;
    NodeHandle3 handle24, handle28;
    NodeHandle2 handle2C;
    float basis[9];
    char unknown54[0xB8 - 0x54];
    NodePoint3 position;
    int fieldC4;
    NodeQuat rotation;
    float velocity[3];
    int fieldE4;
    float fieldE8, fieldEC;
    int zeroF0, zeroF4, zeroF8, zeroFC, zero100, zero104, zero108, zero10C;
    NodeSphere bounds;
    int flags120;
    char* first;
    char* second;
    short firstIndex, secondIndex;
    NodeHandle2 handle130;
    int field134;
    Node_802417BC();
};
typedef char NodeSizeCheck[sizeof(Node_802417BC) == 0x138 ? 1 : -1];
typedef char NodeHeadSizeCheck[sizeof(Resource_802E9E20) == 0xC ? 1 : -1];

Node_802417BC::Node_802417BC()
    : handle0C((((NodeRootView*)&head)->table = lbl_802EC0A0, 0)) {
    assignNode(handle0C, NodeHandle2());
    assignNode(handle18, NodeHandle2());
    assignNode(handle14, NodeHandle2());
    assignNode(handle10, NodeHandle2());
    assignCopied(handle130, NodeHandle1());
    fn_8023EE7C(this, &NodeHandle2());
    fn_8023EE08(this, &NodeHandle2());
    assignNode(handle24, NodeHandle3());
    assignNode(handle28, NodeHandle3());
    position = game_vec3_zero;
    rotation = game_quat_identity;
    velocity[0] = lbl_8037B330;
    velocity[1] = lbl_8037B330;
    velocity[2] = lbl_8037B330;
    flags120 = 0x40000;
    field134 = -1;
    fieldE4 = -1;
    fieldC4 = -1;
    memset(basis, 0, 0x24);
    basis[0] = lbl_8037B330;
    basis[4] = lbl_8037B330;
    basis[8] = lbl_8037B330;
    firstIndex = fn_801C9E3C(lbl_801E9D24.pool);
    secondIndex = fn_801C9E3C(lbl_801E9D24.pool);
    first = lbl_801E9D24.pool->banks[lbl_801E9D24.pool->active] + firstIndex * 0x40;
    second = lbl_801E9D24.pool->banks[lbl_801E9D24.pool->active] + secondIndex * 0x40;
    fieldEC = lbl_8037B32C;
    fieldE8 = lbl_8037B32C;
    zeroF0 = 0; zeroF4 = 0; zeroF8 = 0; zeroFC = 0;
    zero100 = 0; zero104 = 0; zero108 = 0; zero10C = 0;
}

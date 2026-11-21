#include "Game/engine_node_cleanup.h"

typedef char NodeCleanupObjectSize[(sizeof(NodeCleanupObject) == 0x138) ? 1 : -1];

static inline void nodeCleanupAssign(NodeCleanupHandle& to, const NodeCleanupHandle& from) {
    fn_801F86C8(lbl_801E9D24.manager, &to, -1);
    to.value = from.value;
    fn_801F86C8(lbl_801E9D24.manager, &from, 1);
}

static inline void nodeCleanupAssignCopied(NodeCleanupHandle& to, const NodeCleanupHandle1& from) {
    NodeCleanupCopy copy(from);
    nodeCleanupAssign(to, copy);
}

extern "C" NodeCleanupObject* fn_80241344(NodeCleanupObject* self, short deleting) {
    if (self) {
        self->table = lbl_802EC0A0;
        nodeCleanupAssignCopied(self->handle130, NodeCleanupHandle1());
        nodeCleanupAssign(self->handle0C, NodeCleanupHandle2());
        nodeCleanupAssign(self->handle18, NodeCleanupHandle2());
        nodeCleanupAssign(self->handle14, NodeCleanupHandle2());
        nodeCleanupAssign(self->handle10, NodeCleanupHandle2());
        fn_8023EE7C(self, &NodeCleanupHandle2());
        fn_8023EE08(self, &NodeCleanupHandle2());
        nodeCleanupAssign(self->handle24, NodeCleanupHandle3());
        nodeCleanupAssign(self->handle28, NodeCleanupHandle3());
        if (lbl_801E9D24.pool) {
            fn_801C9E10(lbl_801E9D24.pool, self->firstIndex);
            fn_801C9E10(lbl_801E9D24.pool, self->secondIndex);
        }
        self->first = 0;
        self->second = 0;
        self->handle130.~NodeCleanupHandle2();
        self->handle2C.~NodeCleanupHandle2();
        self->handle28.~NodeCleanupHandle3();
        self->handle24.~NodeCleanupHandle3();
        self->handle20.~NodeCleanupHandle2();
        self->handle1C.~NodeCleanupHandle2();
        self->handle18.~NodeCleanupHandle2();
        self->handle14.~NodeCleanupHandle2();
        self->handle10.~NodeCleanupHandle2();
        self->handle0C.~NodeCleanupHandle2();
        if (self) {
            self->table = __vt__17Resource_802E9E20;
            __dt__12BaseObject_ZFv(self, 0);
        }
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}

#include "Game/engine_tree_records.h"

extern "C" void fn_8023D120(EngineTreeNode* self, const EngineTreeVector* point, const EngineTreeQuaternion* orientation)
{
    fn_8023D258(self, point);
    EngineTreeNode* parent = engineTreeResolve(self->parent);
    engineTreeRefreshTransposeBasis(parent);
    EngineTreeMatrix3 copy = parent->transposeBasis;
    EngineTreeMatrix3 other;
    EngineTreeQuaternion output;
    fn_801F1CD8(orientation, &other);
    fn_801F223C(&copy, &other);
    fn_801F20F4(&output, &copy);
    self->orientation.x = output.x;
    self->orientation.y = output.y;
    self->orientation.z = output.z;
    self->orientation.w = output.w;
}

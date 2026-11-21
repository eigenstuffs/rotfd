#include "Game/engine_tree_records.h"

extern "C" void fn_8023D9B8(EngineTreeNode*, EngineTreeNode*, EngineTreeNode*);

static inline EngineTreeNode* engineTreeGroupNode(int group)
{
    if (group != -1)
        return engineTreeResolve(lbl_801E9D24.groups->items[group]);
    return 0;
}

extern "C" void fn_8023DE28(EngineTreeNode* self)
{
    EngineTreeNode* group = engineTreeGroupNode(self->group);
    EngineTreeNode* parent = engineTreeResolve(self->parent);
    fn_8023D9B8(self, group, parent);
}

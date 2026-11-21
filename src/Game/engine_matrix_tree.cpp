#include "Game/engine_matrix_tree.h"

extern "C" void fn_8024C338(EngineMatrixTreeOwner* self)
{
    EngineMatrixTreeContext* context = &lbl_801E9D24;
    EngineMatrixTreeManager* manager = context->manager;
    EngineMatrixTreeNode* parent = engineMatrixTreeResolve(manager, self->root);
    EngineMatrixTreeNode* node;
    engineMatrixTreeAssign(node, manager, parent->child);
    EngineMatrixTreeNode* nodes[32];
    EngineMatrixTreeNode* parents[32];
    int depth = 0;
    EngineMatrixTreeContext* bufferContext = &lbl_801E9D24;
    do {
        if (depth) {
            depth--;
            node = nodes[depth];
            parent = parents[depth];
        }
        do {
            EngineMatrixTreeNode* child = engineMatrixTreeResolve(context->manager, node->child);
            if (child) {
                parents[depth] = node;
                nodes[depth++] = child;
            }
            lbl_80378010++;
            node->local = &bufferContext->buffers->banks[bufferContext->buffers->active][node->index];
            fn_8027B508(node, parent);
            node->flags |= 0x60;
            engineMatrixTreeAssign(node, context->manager, node->next);
        } while (node);
    } while (depth);
}

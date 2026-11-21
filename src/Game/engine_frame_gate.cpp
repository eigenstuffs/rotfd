#include "Game/engine_frame_gate.h"

static inline EngineFrameGateNode* resolve(const EngineFrameGateHandle* handle,
                                          EngineFrameGateManager* manager)
{
    EngineFrameGateEntry* entry = manager->entries + handle->index;
    return entry->tag == handle->tag ? entry->object : 0;
}

extern "C" signed char fn_8020C0F8(void)
{
    const char* messages = registry_No_Comment;
    EngineFrameGateContext* context = &lbl_801E9D24;
    fn_801FA014(context->console, messages + 0x6B8);
    fn_8020B908();
    if (lbl_80377FB4)
        fn_801FA1F0(context->console, messages + 0x6C8);
    else
        fn_801FA1F0(context->console, messages + 0x6DC);
    lbl_80377FB4 = 0;

    do {
        EngineFrameGateNode* node;
        EngineFrameGateManager* manager;
        while (lbl_80377FF0) {}
        manager = lbl_801E9D24.manager;
        node = resolve(&lbl_801E9D24.root->handle, manager);
        if (node) {
            node = resolve(&node->target, manager);
            if (node)
                node->slot38(lbl_8037AA40);
        }
        fn_8020C248();
    } while (!fn_801EBCC8());
    fn_8020B078();
    return 1;
}

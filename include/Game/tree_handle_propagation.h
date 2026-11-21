#ifndef GAME_TREE_HANDLE_PROPAGATION_H
#define GAME_TREE_HANDLE_PROPAGATION_H

struct Handle_801F7F10 {
 union{unsigned long value;struct{signed int tag:8,index:24;}bits;};
 Handle_801F7F10();~Handle_801F7F10();
};

extern "C" void fn_8023D66C(void*, const Handle_801F7F10&, const Handle_801F7F10&);

#endif

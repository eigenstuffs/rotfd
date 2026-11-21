#include "Game/engine_owner_dirty_propagation.h"
extern "C" void fn_8023D400(OwnerDirtyNode*self,OwnerDirtyWord flags){
    fn_8023CD28(self,flags);
    OwnerDirtyNode*parent=fn_8023C1C8(fn_8023D640(self));
    if(parent&&!(fn_8023D638(parent)&1))fn_8023D400(parent,1);
}

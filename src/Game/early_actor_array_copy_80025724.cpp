#include "Game/early_actor_array_copy_views.h"
Array_80025634::Array_80025634(const Array_80025634&other){count=0;capacity=0;data=0;fn_80025898(this,other.count);for(int i=0;i<other.count;++i)append(other.data[i]);}

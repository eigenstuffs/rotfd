/* CQSnailMove destructor; the class hierarchy is in include/Game/move_classes.h. */
#include "Game/move_classes.h"
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource_800CC6CC {virtual ~Resource_800CC6CC();};
CQSnailMove::~CQSnailMove() {
    for (int i = 0; i < 4; i++) delete reinterpret_cast<Resource_800CC6CC**>(callbacks)[i];
    operator delete(callbacks);
}

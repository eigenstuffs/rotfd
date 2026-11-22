/* CHookMove destructor; the class hierarchy is in include/Game/move_classes.h. */
#include "Game/move_classes.h"
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct FactoryCallback {virtual ~FactoryCallback();};
CHookMove::~CHookMove() {
    for (int i = 0; i < 3; i++) { FactoryCallback* p = reinterpret_cast<FactoryCallback**>(callbacks)[i]; if (p) delete p; }
    operator delete(callbacks);
}

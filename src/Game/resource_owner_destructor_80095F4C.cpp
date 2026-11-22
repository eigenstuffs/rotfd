/* CYellowJfishMove destructor; the class hierarchy is in include/Game/move_classes.h. */
#include "Game/move_classes.h"
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource_80095F4C {virtual ~Resource_80095F4C();};
CYellowJfishMove::~CYellowJfishMove() {
    for (int i = 0; i < 9; i++) delete reinterpret_cast<Resource_80095F4C**>(callbacks)[i];
    operator delete(callbacks);
}

#include "objects_owner_internal.h"

Activable_Z::~Activable_Z() {
    if (lbl_801E9D24.list) {
        OwnerHandle h = IdentityHandle(getIdentity());
        fn_80212AA0(lbl_801E9D24.list, &h);
    }
}

// Native construction retains the original empty-handle assignment lifetimes.
#include "owner_list_internal.h"

OwnerList_80213824::OwnerList_80213824() {
    head = ListHandle();
    tail = ListHandle();
    mode8Only = 0;
}

#ifndef GAME_HANDLE_MEMBER_DISPATCH_INTERNAL_H
#define GAME_HANDLE_MEMBER_DISPATCH_INTERNAL_H

#include "Game/handle_list_operations_internal.h"

struct DispatchVirtualBase { char unknown00[8]; };
struct DispatchVirtual : DispatchVirtualBase {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
};
struct DispatchMember18 { char unknown00[0x18]; Handle handle; };
struct DispatchMember04 { int unknown00; Handle handle; };

#endif

#include "Game/engine_controller_shutdown.h"

typedef char ShutdownRecordSize[(sizeof(ShutdownRecord) == 12) ? 1 : -1];
typedef char ShutdownReservedSize[(sizeof(ShutdownReserved) == 20) ? 1 : -1];
typedef char ShutdownFourHandlesSize[(sizeof(ShutdownFourHandles) == 32) ? 1 : -1];
typedef char ShutdownGlobalsSize[(sizeof(ShutdownGlobals) == 0x170) ? 1 : -1];

extern "C" void fn_8020B078() {
    fn_801EA0FC();
    fn_801FB0F4(lbl_801E9D24.log);
    lbl_801E9D24.log->slot10();
    delete lbl_801E9D24.service150;
    lbl_801E9D24.service150 = 0;
    fn_80263B08(lbl_801E9D24.service14C, 1);
    lbl_801E9D24.service14C = 0;
    delete lbl_801E9D24.owner144;
    lbl_801E9D24.owner144 = 0;
    delete lbl_801E9D24.pool128;
    lbl_801E9D24.pool128 = 0;
    delete lbl_801E9D24.pool12C;
    lbl_801E9D24.pool12C = 0;
    delete lbl_801E9D24.pool130;
    lbl_801E9D24.pool130 = 0;
    delete lbl_801E9D24.service11C;
    lbl_801E9D24.service11C = 0;
    lbl_801E9D24.service114->slot10();
    delete lbl_801E9D24.service114;
    lbl_801E9D24.service114 = 0;
    delete lbl_801E9D24.four;
    lbl_801E9D24.four = 0;
    fn_801B5D04(lbl_801E9D24.service148, 1);
    lbl_801E9D24.service148 = 0;
    fn_801C9DA0(lbl_801E9D24.service160, 1);
    lbl_801E9D24.service160 = 0;
    lbl_801E9D24.service154->slot0C();
    delete lbl_801E9D24.service134;
    lbl_801E9D24.service134 = 0;
    fn_801EF610(lbl_801EF5C8, lbl_801E9D24.buffer168);
    lbl_801E9D24.buffer168 = 0;
    delete lbl_801E9D24.service120;
    lbl_801E9D24.service120 = 0;
    delete lbl_801E9D24.pair;
    lbl_801E9D24.pair = 0;
    if (lbl_801E9D24.owner158) {
        if (!lbl_801E9D24.controller->flag)
            lbl_801E9D24.owner158->slot44();
        lbl_801E9D24.owner158->slot08();
        delete lbl_801E9D24.owner158;
    }
    lbl_801E9D24.owner158 = 0;
    lbl_801E9D24.service15C->slot10();
    delete lbl_801E9D24.service15C;
    lbl_801E9D24.service15C = 0;
    delete lbl_801E9D24.service16C;
    lbl_801E9D24.service16C = 0;
    fn_8007F33C();
    lbl_801E9D24.controller->slot08();
    fn_801B57F4(lbl_801E9D24.controller);
    delete lbl_801E9D24.controller;
    lbl_801E9D24.controller = 0;
}

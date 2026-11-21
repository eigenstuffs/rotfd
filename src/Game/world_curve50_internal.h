#ifndef GAME_WORLD_CURVE50_INTERNAL_H
#define GAME_WORLD_CURVE50_INTERNAL_H
#include "world_action_curve_internal.h"
struct CurveRecord50_802F15C0 : CurveRecordBase_802E9E08 {
    WorldCurve<40> curve0C;WorldCurve<20> curve1C,curve2C;
    WorldActionCurve_801F7560 curve3C;
    CurveRecord50_802F15C0(){}
    ~CurveRecord50_802F15C0();
    virtual void reset();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
typedef char CheckWorldActionCurve[sizeof(WorldActionCurve_801F7560)==0x14?1:-1];
typedef char CheckCurveRecord50[sizeof(CurveRecord50_802F15C0)==0x50?1:-1];
#endif

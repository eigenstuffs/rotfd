#ifndef GAME_LATE_SCREEN_VIRTUAL_TABLE_H
#define GAME_LATE_SCREEN_VIRTUAL_TABLE_H

#include "Game/engine_late_callback_selectors.h"
struct ScreenBase_800B9368;
struct EngineStreamLayerView;
struct CallbackRelatedOwner;

/* Complete native table at 802EC588. Receiver views follow the existing
 * callable providers; a full original ScreenBase class is not asserted. */
struct NativeScreenTable {
    const void *typeInfo;
    long offsetToTop;
    ScreenBase_800B9368 *(*destroy)(ScreenBase_800B9368 *, short);
    void (*stream)(EngineStreamLayerView *, void **);
    void (*slot10)(); void (*slot14)(); void (*slot18)();
    signed char (*related)(CallbackRelatedOwner *);
    unsigned int (*getGroup)();
    void (*setGroup)(void *, unsigned int);
    void (*forward)(void *, void *);
    int (*query)(void *, void *);
    void (*slot30)(); void (*slot34)();
    int (*selectors[6])(LateSelectorOwner *, int, LateCallback *);
    void (*slot50)(); void (*slot54)(void *); void (*slot58)();
    void (*slot5C)(const void *); void (*slot60)();
    void (*slot64)(const void *); void (*slot68)(void *);
};

extern "C" {
extern NativeScreenTable __vt__19ScreenBase_800B9368;
ScreenBase_800B9368 *__dt__19ScreenBase_800B9368Fv(ScreenBase_800B9368 *, short);
void slot0C__12BaseObject_ZFUl(EngineStreamLayerView *, void **);
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot18__12BaseObject_ZFv();
signed char fn_802537A8(CallbackRelatedOwner *);
unsigned int fn_8025347C();
void fn_80253484(void *, unsigned int);
void fn_8025348C(void *, void *);
int fn_802534B0(void *, void *);
void fn_80035224(); void fn_80035228();
void fn_802534E8(); void fn_802535D8(void *); void fn_800C07D0();
void fn_802534EC(const void *); void fn_800C07D4();
void fn_80253584(const void *); void fn_80253540(void *);
}

#endif

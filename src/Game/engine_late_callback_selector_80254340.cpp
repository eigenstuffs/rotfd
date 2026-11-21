#include "Game/engine_late_callback_selectors.h"

/* The borrowed member-pointer pool retains its original data ownership. */
extern "C" {
extern const struct LateMemberPool {
    char unknown00[0x84];
    LateMemberPointer entries[5];
} lbl_802EC3D8;
extern const char lbl_802AEB5C[];
}

extern "C" int fn_80254340(LateSelectorOwner* self, int event, LateCallback* callback) {
    const LateMemberPool* members = &lbl_802EC3D8;
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, members->entries[0], -1);
        return 1;
    case 1:
        fn_8025EEB4(self, members->entries[1]);
        return 1;
    case 2:
        fn_8025EB70(self, members->entries[2]);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, members->entries[3]);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, members->entries[4]);
        if (callback)
            return (signed char)(callback->flags28 & 1);
        return 0;
    case 5:
        return 1;
    case 6:
        if (callback)
            return callback->index2A;
        return -9999;
    }

    lbl_8037808C = 0;
    lbl_80378090 = 0;
    lbl_80378094 = -1;
    if (event == 8 || event == 7)
        fn_8025F4F4(callback, 4, lbl_802AEB5C);
    if (event == 11 && callback->index2A == -1)
        return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14)
        action = event + callback->index2A * 2;
    else
        action = event;
    switch (action) {
    case 7:
        fn_8025F694(callback, lbl_8037808C);
    case 8:
        break;
    case 14:
        result = fn_8025E9FC(self, 0x4C);
        break;
    case 15:
        self->slot58();
        break;
    default:
        result = 2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}

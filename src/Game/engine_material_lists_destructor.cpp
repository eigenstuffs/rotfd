#include "Game/engine_material_lists_destructor.h"

typedef char MaterialListsKeySize[(sizeof(MaterialListsHandleKey) == 8) ? 1 : -1];
typedef char MaterialListsCurveSize[(sizeof(MaterialListsCurve<MaterialListsHandleKey>) == 16) ? 1 : -1];
typedef char MaterialListsObjectSize[(sizeof(MaterialListsObject) == 0xBC) ? 1 : -1];

extern "C" MaterialListsObject* fn_80239D30(MaterialListsObject* self, short deleting) {
    if (self) {
        self->table = __vt__21MaterialAnim_802EC000;
        self->handle.~MaterialListsHandle2();
        self->curveA0.~MaterialListsCurve<MaterialListsElement<8> >();
        self->curve90.~MaterialListsCurve<MaterialListsElement<8> >();
        self->curve80.~MaterialListsCurve<MaterialListsElement<8> >();
        self->curve70.~MaterialListsCurve<MaterialListsElement<8> >();
        self->curve60.~MaterialListsCurve<MaterialListsElement<16> >();
        self->curve50.~MaterialListsCurve<MaterialListsElement<16> >();
        self->curve40.~MaterialListsCurve<MaterialListsElement<8> >();
        self->curve30.~MaterialListsCurve<MaterialListsElement<12> >();
        self->curve20.~MaterialListsCurve<MaterialListsElement<12> >();
        self->curve10.~MaterialListsCurve<MaterialListsHandleKey>();
        if (self) {
            self->table = __vt__17Resource_802E9E20;
            __dt__12BaseObject_ZFv(self, 0);
        }
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}

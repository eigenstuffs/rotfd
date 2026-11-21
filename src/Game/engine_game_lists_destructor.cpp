#include "Game/engine_game_lists_destructor.h"

typedef char GameListsHandleSize[(sizeof(GameListsHandle3) == 4) ? 1 : -1];
typedef char GameListsBitSetSize[(sizeof(BitSet_80207EE8) == 16) ? 1 : -1];
typedef char GameListsObjectSize[(sizeof(GameListsObject) == 0x9C) ? 1 : -1];

extern "C" GameListsObject* fn_8022A1A0(GameListsObject* self, short deleting) {
    if (self) {
        self->table = __vt__20ObjectsGame_802EB900;
        self->buffer90.~GameListsBuffer();
        self->buffer84.~GameListsBuffer();
        self->buffer78.~GameListsBuffer();
        self->array6C.~GameListsArray<GameListsHandle3>();
        self->array60.~GameListsArray<GameListsHandle3>();
        self->array54.~GameListsArray<GameListsHandle2>();
        self->bits.~BitSet_80207EE8();
        self->array38.~GameListsArray<GameListsElement>();
        self->array2C.~GameListsArray<GameListsHandle3>();
        self->handle.~GameListsHandle1();
        if (self) {
            self->table = __vt__13Manipulator_Z;
            __dt__11Activable_ZFv(self, 0);
        }
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}

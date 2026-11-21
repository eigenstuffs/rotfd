#ifndef GAME_INGAME_MANIPULATOR_NATIVE_INTERNAL_H
#define GAME_INGAME_MANIPULATOR_NATIVE_INTERNAL_H
#include "manipulator_callbacks_internal.h"
struct InGameHandle1 : Handle_801F7F10 {
    InGameHandle1() { value = 0; }
    ~InGameHandle1() {}
};
struct InGameHandle2 : InGameHandle1 {
    InGameHandle2() { value = 0; }
    ~InGameHandle2() {}
};
struct InGameHandle3 : InGameHandle2 {
    InGameHandle3() { value = 0; }
    ~InGameHandle3() {}
};
struct InGameHandle4 : InGameHandle3 {
    InGameHandle4() { value = 0; }
    ~InGameHandle4() {}
    InGameHandle4& operator=(const Handle_801F7F10& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
struct InGameObjectsManipulator_802128A0 : Manipulator_Z {
    InGameHandle4 handle20;
    InGameObjectsManipulator_802128A0();
    virtual ~InGameObjectsManipulator_802128A0();
    virtual void slot38(float);
    virtual void slot40(const Handle_801F7F10&);
    virtual const Handle_801F7F10* slot44() const;
    virtual unsigned long slot48();
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
typedef char CheckInGameSize[sizeof(InGameObjectsManipulator_802128A0) == 0x24 ? 1 : -1];
#endif

#include "Game/handle_list_operations_internal.h"

struct PairCallbackBase { char unknown00[8]; };
struct PairCallbackObject : PairCallbackBase {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void invoke();
};
struct PairCallbackView {
    char unknown00[0x9F0];
    Handle* first;
    Handle* second;
    int count;
};

extern "C" void fn_8027224C(PairCallbackView* self) {
    for (int i = 0; i < self->count; ++i) {
        ((PairCallbackObject*)resolved(self->second[i]))->invoke();
        ((PairCallbackObject*)resolved(self->first[i]))->invoke();
    }
}

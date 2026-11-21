/* Curve Handle action and packed encoding reconstruction; see docs/notes/game-curve-handle-encoding.md. */
typedef unsigned long CurveActionWord;

struct CurveActionNodeStorage {
    CurveActionWord unknown00[2];
};

struct CurveActionNode : CurveActionNodeStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
};

struct CurveActionHandle {
    CurveActionWord value;
};

struct CurveActionKey {
    short time;
    short unknown02;
    CurveActionHandle handle;
};

struct CurveActionTrack {
    short type;
    short unknown02;
    int count;
    int capacity;
    CurveActionKey* keys;
};

extern "C" CurveActionNode* fn_801F7EB8(const CurveActionHandle*);

extern "C" void fn_801B0E28(CurveActionTrack* self) {
    for (int i = 0; i < self->count; ++i) {
        if (fn_801F7EB8(&self->keys[i].handle)) {
            fn_801F7EB8(&self->keys[i].handle)->slot1C();
        }
    }
}

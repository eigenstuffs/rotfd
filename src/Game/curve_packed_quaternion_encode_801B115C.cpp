/* Curve Handle action and packed encoding reconstruction; see docs/notes/game-curve-handle-encoding.md. */
struct CurvePackedQuaternionComponent {
    signed short value : 12;
    unsigned short unused : 4;
};

struct CurvePackedQuaternionKey {
    short time;
    CurvePackedQuaternionComponent x;
    CurvePackedQuaternionComponent y;
    CurvePackedQuaternionComponent z;
    CurvePackedQuaternionComponent w;
};

struct CurvePackedQuaternionInput {
    float w;
    float x;
    float y;
    float z;
};

extern "C" const float lbl_8037A210;

extern "C" void fn_801B115C(CurvePackedQuaternionKey* self,
                              const CurvePackedQuaternionInput* value) {
    self->x.value = lbl_8037A210 * value->x;
    self->y.value = lbl_8037A210 * value->y;
    self->z.value = lbl_8037A210 * value->z;
    self->w.value = lbl_8037A210 * value->w;
}

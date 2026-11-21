/* Curve Handle action and packed encoding reconstruction; see docs/notes/game-curve-handle-encoding.md. */
struct CurvePackedVectorsKey {
    short time;
    short first[3];
    short second[3];
    short third[3];
};

struct CurvePackedVectorsInput {
    float x;
    float y;
    float z;
};

extern "C" const float lbl_8037A214;

extern "C" void fn_801B12DC(CurvePackedVectorsKey* self,
                              const CurvePackedVectorsInput* first,
                              const CurvePackedVectorsInput* second,
                              const CurvePackedVectorsInput* third) {
    self->first[0] = (int)(lbl_8037A214 * first->x);
    self->first[1] = (int)(lbl_8037A214 * first->y);
    self->first[2] = (int)(lbl_8037A214 * first->z);
    self->second[0] = (int)(lbl_8037A214 * second->x);
    self->second[1] = (int)(lbl_8037A214 * second->y);
    self->second[2] = (int)(lbl_8037A214 * second->z);
    self->third[0] = (int)(lbl_8037A214 * third->x);
    self->third[1] = (int)(lbl_8037A214 * third->y);
    self->third[2] = (int)(lbl_8037A214 * third->z);
}

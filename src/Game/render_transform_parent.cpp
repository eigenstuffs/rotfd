// Partial transform-owner layout recovered from fn_8027B508.
extern "C" {
void fn_801F1D90(void*, void*);
extern const float lbl_8037B758;
}

struct ParentTransformMatrix3;
extern "C" void fn_801F2170(ParentTransformMatrix3*, const ParentTransformMatrix3*, const ParentTransformMatrix3*);
struct ParentTransformMatrix3 {
    float m[3][3];
    ParentTransformMatrix3() {}
    ParentTransformMatrix3(const ParentTransformMatrix3& left, const ParentTransformMatrix3& right) {
        fn_801F2170(this, &left, &right);
    }
};
struct ParentTransformMatrix4 {
    float m[4][4];
};
struct ParentTransformOwner {
    char unknown00[0x30];
    ParentTransformMatrix3 rotation;
    char unknown54[0x24];
    ParentTransformMatrix4 matrix;
    float position[4];
    char transform[0x10];
    float scale[3];
    char unknownE4[0x40];
    ParentTransformMatrix4* output;
};

extern "C" void fn_801F1080(ParentTransformMatrix4*, const ParentTransformMatrix4*, ParentTransformMatrix4*);
static inline ParentTransformMatrix4 parentProduct4(ParentTransformMatrix4& left, const ParentTransformMatrix4& right) {
    ParentTransformMatrix4 result;
    fn_801F1080(&left, &right, &result);
    return result;
}
static inline ParentTransformMatrix3 parentProduct3(const ParentTransformMatrix3& left, const ParentTransformMatrix3& right) {
    return ParentTransformMatrix3(left, right);
}

extern "C" void fn_8027B508(ParentTransformOwner* self, ParentTransformOwner* parent) {
    fn_801F1D90(self->transform, &self->matrix);

    ParentTransformMatrix3 rotation;
    rotation.m[0][0] = self->matrix.m[0][0];
    rotation.m[1][0] = self->matrix.m[1][0];
    rotation.m[2][0] = self->matrix.m[2][0];
    rotation.m[0][1] = self->matrix.m[0][1];
    rotation.m[1][1] = self->matrix.m[1][1];
    rotation.m[2][1] = self->matrix.m[2][1];
    rotation.m[0][2] = self->matrix.m[0][2];
    rotation.m[1][2] = self->matrix.m[1][2];
    rotation.m[2][2] = self->matrix.m[2][2];

    self->matrix.m[0][0] *= self->scale[0];
    self->matrix.m[1][0] *= self->scale[1];
    self->matrix.m[2][0] *= self->scale[2];
    self->matrix.m[3][0] = self->position[0];
    self->matrix.m[0][1] *= self->scale[0];
    self->matrix.m[1][1] *= self->scale[1];
    self->matrix.m[2][1] *= self->scale[2];
    self->matrix.m[3][1] = self->position[1];
    self->matrix.m[0][2] *= self->scale[0];
    self->matrix.m[1][2] *= self->scale[1];
    self->matrix.m[2][2] *= self->scale[2];
    self->matrix.m[3][2] = self->position[2];
    self->matrix.m[0][3] *= self->scale[0];
    self->matrix.m[1][3] *= self->scale[1];
    self->matrix.m[2][3] *= self->scale[2];
    self->matrix.m[3][3] = lbl_8037B758;

    *self->output = parentProduct4(*parent->output, self->matrix);
    self->rotation = parentProduct3(parent->rotation, rotation);
}

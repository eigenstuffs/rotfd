// Partial transform-owner layout recovered from fn_8027B2E4.
extern "C" {
void fn_801F1D90(void*, void*);
extern const float lbl_8037B758;
}

struct TransformMatrix3 {
    float m[3][3];
};
struct TransformMatrix4 {
    float m[4][4];
};
struct TransformCopyOwner {
    char unknown00[0x30];
    TransformMatrix3 rotation;
    char unknown54[0x24];
    TransformMatrix4 matrix;
    float position[4];
    char transform[0x10];
    float scale[3];
    char unknownE4[0x40];
    TransformMatrix4* output;
};

extern "C" void fn_8027B2E4(TransformCopyOwner* self) {
    fn_801F1D90(self->transform, &self->matrix);

    TransformMatrix3 rotation;
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

    *self->output = self->matrix;
    self->rotation = rotation;
}

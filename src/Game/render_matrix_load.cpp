struct LoadMatrix { float value[12]; };
struct LoadMatrixView { char unknown00[0x2E0]; LoadMatrix matrix; };
extern "C" {
void fn_800F6D38(const LoadMatrix*, LoadMatrix*);
void fn_800F6D6C(const LoadMatrix*, LoadMatrix*);
void GXLoadPosMtxImm(const LoadMatrix*, unsigned int);
void GXLoadTexMtxImm(const LoadMatrix*, unsigned int, int);
void GXLoadNrmMtxImm(const LoadMatrix*, unsigned int);
void GXSetCurrentMtx(unsigned int);
}

extern "C" void fn_80272EA0(LoadMatrixView* self, const LoadMatrix* matrix) {
    LoadMatrix normal;
    fn_800F6D38(matrix, &self->matrix);
    GXLoadPosMtxImm(matrix, 0);
    GXLoadTexMtxImm(matrix, 33, 1);
    fn_800F6D6C(matrix, &normal);
    GXLoadNrmMtxImm(&normal, 0);
    GXSetCurrentMtx(0);
}

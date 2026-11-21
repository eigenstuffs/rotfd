/* Particle-system object constructor (fn_80252B54), called by the
 * Particles_Z.h factory with a 0x18C-byte allocation (factories_801EB254):
 * resource base (fn_80243F28) and table, thirteen 16-byte curves
 * (CurveBase_801B1088 + empty row array, flags 2), a three-layer zeroed
 * Handle at 0x188, then the scalar defaults.
 *
 * Matching note: the original inlined real member constructors, whose `this`
 * is a compiler temporary kept in a saved register across the external base
 * constructor call. The helpers model that with a self-assigned parameter,
 * which makes the inliner materialize the argument instead of substituting
 * self+offset into every store. A placement-new form reproduces the members
 * but adds the null test of the whole object. */
typedef unsigned long Word;

extern "C" {
    void fn_80243F28(void*);
    void __ct__18CurveBase_801B1088Fv(void*);
    void __ct__15Handle_801F7F10Fv(void*);
    extern char lbl_802EA6C0[];
    extern const float lbl_8037B500; /* 1.0f */
    extern const float lbl_8037B504; /* 0.0f */
}

struct ParticleCurve {
    unsigned short flags, unknown02;
    int count, capacity;
    void* data;
};
inline void initCurve(ParticleCurve* curve)
{
    curve = curve; /* constructor `this` temporary */
    __ct__18CurveBase_801B1088Fv(curve);
    curve->count = 0;
    curve->capacity = 0;
    curve->data = 0;
    curve->flags = 2;
}

inline void initHandle(Word* handle)
{
    handle = handle; /* constructor `this` temporary */
    __ct__15Handle_801F7F10Fv(handle);
    *handle = 0;
    *handle = 0;
}

struct Particles {
    char unknown00[8];
    const void* table;
    char unknown0C[0x60];
    unsigned short kind, flags;
    char unknown70[4];
    unsigned short field74;
    char unknown76[6];
    float field7C;
    char unknown80[4];
    float field84, field88, field8C, field90;
    float field94, field98, field9C, fieldA0;
    char unknownA4[0xC];
    float fieldB0;
    int fieldB4;
    ParticleCurve curves[13];
    Word handle188;
};

typedef char ParticlesSize[sizeof(Particles) == 0x18C ? 1 : -1];

extern "C" Particles* fn_80252B54(Particles* self)
{
    fn_80243F28(self);
    self->table = lbl_802EA6C0;
    initCurve(&self->curves[0]);
    initCurve(&self->curves[1]);
    initCurve(&self->curves[2]);
    initCurve(&self->curves[3]);
    initCurve(&self->curves[4]);
    initCurve(&self->curves[5]);
    initCurve(&self->curves[6]);
    initCurve(&self->curves[7]);
    initCurve(&self->curves[8]);
    initCurve(&self->curves[9]);
    initCurve(&self->curves[10]);
    initCurve(&self->curves[11]);
    initCurve(&self->curves[12]);
    initHandle(&self->handle188);
    self->kind = 0x12;
    self->field7C = lbl_8037B500;
    self->field84 = lbl_8037B504;
    self->field88 = lbl_8037B504;
    self->field8C = lbl_8037B504;
    self->field90 = lbl_8037B504;
    self->field94 = lbl_8037B500;
    self->field98 = lbl_8037B500;
    self->field9C = lbl_8037B500;
    self->fieldA0 = lbl_8037B500;
    self->fieldB0 = lbl_8037B500;
    self->fieldB4 = 1;
    self->field74 = 0x100;
    unsigned short enabledFlags = self->flags;
    enabledFlags |= 0x60;
    self->flags = enabledFlags;
    return self;
}

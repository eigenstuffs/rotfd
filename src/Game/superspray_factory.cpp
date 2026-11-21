// Recovered SuperSpray factory and PlayParticles lifetime fragment.
// Virtual-table storage is an observed prefix; the tables remain external.
typedef unsigned long u32;
extern "C" {
extern char lbl_801EF5C8[];
void* fn_801EFA1C(void*, u32, const char*, const char*, int, int);
void fn_801EF610(void*, void*);
void __ct__13Manipulator_ZFv(void*);
void __dt__11Activable_ZFv(void*, short);
extern const char lbl_802AE024[];
extern const char lbl_802AE078[] = "SuperSpray_Z.h";
extern const char lbl_802EB040[], lbl_802EB090[], __vt__13Manipulator_Z[];
extern const float lbl_8037AA40;
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct HandleLayer : Handle_801F7F10 {
    HandleLayer() { value = 0; }
    ~HandleLayer() {}
};
struct ParticleHandle : HandleLayer {
    ParticleHandle() { value = 0; }
    ~ParticleHandle() {}
};
struct ParticlePrefix {
    u32 prefix[2];
    const void* vtable;
    char unknown0C[0x20 - 0xC];
    ParticlePrefix() { __ct__13Manipulator_ZFv(this); vtable = lbl_802EB090; }
    ~ParticlePrefix() {
        vtable = __vt__13Manipulator_Z;
        __dt__11Activable_ZFv(this, 0);
    }
};
struct PlayParticles_8020949C : ParticlePrefix {
    ParticleHandle reference20;
    u32 unknown24;
    ParticleHandle reference28;
    PlayParticles_8020949C() {}
    ~PlayParticles_8020949C();
    static void operator delete(void* memory) {
        fn_801EF610(lbl_801EF5C8, memory);
    }
};
struct SuperSpray : PlayParticles_8020949C {
    float field2C, field30;
    SuperSpray() {
        vtable = lbl_802EB040;
        field30 = lbl_8037AA40;
        field2C = lbl_8037AA40;
    }
    static void* operator new(u32 size) {
        return fn_801EFA1C(lbl_801EF5C8, size, lbl_802AE024, lbl_802AE078, 28, 4);
    }
};

PlayParticles_8020949C::~PlayParticles_8020949C() { vtable = lbl_802EB090; }

extern "C" void* fn_802093D8()
{
    return new SuperSpray;
}

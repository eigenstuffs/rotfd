// CacheBase_802EA868::bind has no cached slot and reports 0xFFFF. The unit also
// owns the adjacent platform-array method tables: the derived and base
// PlatformArrays vtables and the startup cleanup table installed by
// fn_801ECB84/fn_801ECBE0. MWCC emits implicit vtables after all explicit data,
// so the CacheBase vtable is spelled out with the others to keep their order.
extern "C" {
void __dt__23PlatformArrays_802EA874Fv();
void __dt__23PlatformArrays_802EA884Fv();
void advance__23PlatformArrays_802EA884Ff();
void fn_801ECBE0();

unsigned short bind__18CacheBase_802EA868FRC15Handle_801F7F10Us(void*, const void*, unsigned short) {
    return 0xffff;
}

extern __declspec(section ".data") const void* const __vt__18CacheBase_802EA868[3] = {
    0,
    0,
    (const void*)bind__18CacheBase_802EA868FRC15Handle_801F7F10Us,
};

extern __declspec(section ".data") const void* const __vt__23PlatformArrays_802EA874[4] = {
    0,
    0,
    (const void*)__dt__23PlatformArrays_802EA874Fv,
    (const void*)advance__23PlatformArrays_802EA884Ff,
};

extern __declspec(section ".data") const void* const __vt__23PlatformArrays_802EA884[4] = {
    0,
    0,
    (const void*)__dt__23PlatformArrays_802EA884Fv,
    (const void*)advance__23PlatformArrays_802EA884Ff,
};

extern __declspec(section ".data") const void* const lbl_802EA894[3] = {
    0,
    0,
    (const void*)fn_801ECBE0,
};
}

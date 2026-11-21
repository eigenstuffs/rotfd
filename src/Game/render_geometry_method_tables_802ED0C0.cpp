// Native menu/object or platform virtual-method records. Each named table retains its complete original extent.
extern "C" {
void __dt__15Object_80260C7CFv();
void fn_800C0814();
void fn_800C081C();
void fn_800C0824();
void fn_800C082C();
void fn_800C0834();
void fn_800C0838();
void fn_800C083C();
void fn_800C0840();
void fn_800C0844();
void fn_800C0848();
void fn_800C084C();
void fn_801E8B10();
void fn_801E8C08();
void fn_801E8E2C();
void fn_80238F5C();
void fn_8025FD00();
void fn_80260BFC();
void fn_80260F64();
void fn_80260FF4();
void fn_802642C4();
void fn_8026464C();
void fn_802646EC();
void fn_8026A710();
void fn_8026B038();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot18__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802ED0C0[20] __attribute__((aligned(4))) = {
    0,
    0,
    (const void*)__dt__15Object_80260C7CFv,
    (const void*)fn_80260FF4,
    (const void*)fn_80260F64,
    (const void*)fn_80260BFC,
    (const void*)fn_8025FD00,
    (const void*)fn_800C0814,
    (const void*)fn_80238F5C,
    (const void*)fn_800C081C,
    (const void*)fn_800C0824,
    (const void*)fn_800C082C,
    (const void*)fn_800C0834,
    (const void*)fn_800C0838,
    (const void*)fn_800C083C,
    (const void*)fn_800C0840,
    (const void*)fn_800C0844,
    (const void*)fn_800C0848,
    (const void*)fn_800C084C,
    0,
};

extern "C" __declspec(section ".data") const void* const lbl_802ED110[8] __attribute__((aligned(4))) = {
    0,
    0,
    (const void*)fn_802646EC,
    (const void*)fn_802642C4,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)slot18__12BaseObject_ZFv,
    (const void*)fn_8026464C,
};

// Six faces, four vertex indices per face; fn_80267748 reads them with lbz.
extern "C" __declspec(section ".data") const unsigned char lbl_802ED130[6][4] __attribute__((aligned(4))) = {
    { 0, 1, 2, 3 },
    { 4, 5, 6, 7 },
    { 1, 2, 5, 6 },
    { 0, 1, 4, 5 },
    { 2, 3, 6, 7 },
    { 0, 3, 4, 7 },
};

extern "C" __declspec(section ".data") const void* const lbl_802ED148[8] __attribute__((aligned(4))) = {
    0,
    0,
    (const void*)fn_8026A710,
    (const void*)fn_801E8E2C,
    (const void*)fn_801E8C08,
    (const void*)fn_801E8B10,
    (const void*)slot18__12BaseObject_ZFv,
    (const void*)fn_8026B038,
};

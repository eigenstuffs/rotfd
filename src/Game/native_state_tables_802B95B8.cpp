// Native state operation tables and their two-base runtime lists.
// Each seven-slot table preserves one runtime type, a destructor,
// and the four behavior slots observed in the executable.
typedef unsigned long u32;
struct NativeBase { const void* type; u32 adjustment; };
struct NativeBaseList2 { NativeBase bases[2]; u32 terminator; };
extern "C" {
void __dt__15Object_80094A2CFv();
void __dt__15Object_80095378Fv();
void __dt__15Object_80095414Fv();
void __dt__15Object_800954ACFv();
void __dt__15Object_80095544Fv();
void __dt__15Object_800955DCFv();
void __dt__15Object_80095674Fv();
void __dt__15Object_8009570CFv();
void fn_80094B14();
void fn_80094BA4();
void fn_80094BA8();
void fn_80094C04();
void fn_80094C60();
void fn_80094C64();
void fn_80094CC0();
void fn_80094D1C();
void fn_80094D20();
void fn_80094D7C();
void fn_80094DD4();
void fn_80094DD8();
void fn_80094E3C();
void fn_80094E40();
void fn_80094E8C();
void fn_80094EF0();
void fn_80094F58();
void fn_80094F84();
void fn_80094FE8();
void fn_80095370();
void fn_80095374();
void fn_80095410();
void fn_800957A4();
void fn_800957A8();
void fn_800957AC();
extern char lbl_80374C50;
extern char lbl_80374C58;
extern char lbl_80374C60;
extern char lbl_80374C68;
extern char lbl_80374C70;
extern char lbl_80374C78;
extern char lbl_80374C80;
extern char lbl_80374C88;
extern char lbl_80374C90;
}

extern "C" __declspec(section ".data") const void* const lbl_802B95B8[7] __attribute__((aligned(4))) = {
    &lbl_80374C60,
    0,
    (const void*)__dt__15Object_80095378Fv,
    (const void*)fn_80094FE8,
    (const void*)fn_80095370,
    (const void*)fn_80095374,
    (const void*)fn_80095410,
};

extern "C" __declspec(section ".data") const NativeBaseList2 lbl_802B95D4 __attribute__((aligned(4))) = {
    { {&lbl_80374C50, 0}, {&lbl_80374C58, 0} }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B95E8[7] __attribute__((aligned(4))) = {
    &lbl_80374C68,
    0,
    (const void*)__dt__15Object_80095414Fv,
    (const void*)fn_80094EF0,
    (const void*)fn_80094F58,
    (const void*)fn_80094F84,
    (const void*)fn_80095410,
};

extern "C" __declspec(section ".data") const NativeBaseList2 lbl_802B9604 __attribute__((aligned(4))) = {
    { {&lbl_80374C50, 0}, {&lbl_80374C58, 0} }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B9618[7] __attribute__((aligned(4))) = {
    &lbl_80374C70,
    0,
    (const void*)__dt__15Object_800954ACFv,
    (const void*)fn_80094E3C,
    (const void*)fn_80094E40,
    (const void*)fn_80094E8C,
    (const void*)fn_80095410,
};

extern "C" __declspec(section ".data") const NativeBaseList2 lbl_802B9634 __attribute__((aligned(4))) = {
    { {&lbl_80374C50, 0}, {&lbl_80374C58, 0} }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B9648[7] __attribute__((aligned(4))) = {
    &lbl_80374C78,
    0,
    (const void*)__dt__15Object_80095544Fv,
    (const void*)fn_80094D7C,
    (const void*)fn_80094DD4,
    (const void*)fn_80094DD8,
    (const void*)fn_80095410,
};

extern "C" __declspec(section ".data") const NativeBaseList2 lbl_802B9664 __attribute__((aligned(4))) = {
    { {&lbl_80374C50, 0}, {&lbl_80374C58, 0} }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B9678[7] __attribute__((aligned(4))) = {
    &lbl_80374C80,
    0,
    (const void*)__dt__15Object_800955DCFv,
    (const void*)fn_80094CC0,
    (const void*)fn_80094D1C,
    (const void*)fn_80094D20,
    (const void*)fn_80095410,
};

extern "C" __declspec(section ".data") const NativeBaseList2 lbl_802B9694 __attribute__((aligned(4))) = {
    { {&lbl_80374C50, 0}, {&lbl_80374C58, 0} }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B96A8[7] __attribute__((aligned(4))) = {
    &lbl_80374C88,
    0,
    (const void*)__dt__15Object_80095674Fv,
    (const void*)fn_80094C04,
    (const void*)fn_80094C60,
    (const void*)fn_80094C64,
    (const void*)fn_80095410,
};

extern "C" __declspec(section ".data") const NativeBaseList2 lbl_802B96C4 __attribute__((aligned(4))) = {
    { {&lbl_80374C50, 0}, {&lbl_80374C58, 0} }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B96D8[7] __attribute__((aligned(4))) = {
    &lbl_80374C90,
    0,
    (const void*)__dt__15Object_8009570CFv,
    (const void*)fn_80094B14,
    (const void*)fn_80094BA4,
    (const void*)fn_80094BA8,
    (const void*)fn_80095410,
};

extern "C" __declspec(section ".data") const void* const lbl_802B96F4[7] __attribute__((aligned(4))) = {
    &lbl_80374C58,
    0,
    (const void*)__dt__15Object_80094A2CFv,
    (const void*)fn_800957A4,
    (const void*)fn_800957A8,
    (const void*)fn_800957AC,
    (const void*)fn_80095410,
};

typedef char CheckNativeBaseList2Size[sizeof(NativeBaseList2) == 20 ? 1 : -1];

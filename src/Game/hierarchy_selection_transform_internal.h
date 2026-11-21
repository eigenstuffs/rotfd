// Private recovered state and virtual slots for scalar/vector selection commands.
#ifndef ROTFD_HIERARCHY_SELECTION_TRANSFORM_INTERNAL_H
#define ROTFD_HIERARCHY_SELECTION_TRANSFORM_INTERNAL_H
typedef unsigned long u32;
struct Handle { union { u32 value; struct { signed int generation:8; signed int index:24; } bits; }; };
struct Handle_801F7F10 { Handle_801F7F10(); ~Handle_801F7F10(); Handle token; };
// The observed inherited default constructors each clear the handle word.
struct SelectionHandle0 : Handle_801F7F10 {};
struct SelectionHandle1 : SelectionHandle0 { SelectionHandle1() { token.value = 0; } };
struct SelectionHandle2 : SelectionHandle1 { SelectionHandle2() { token.value = 0; } };
struct SelectionHandle3 : SelectionHandle2 { SelectionHandle3() { token.value = 0; } };
struct SelectionHandle4 : SelectionHandle3 { SelectionHandle4() { token.value = 0; } };
struct SelectionHandle5 : SelectionHandle4 { SelectionHandle5() { token.value = 0; } };

struct Vector3 {float x,y,z; Vector3(float xx,float yy,float zz):x(xx),y(yy),z(zz){}};
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void command(int, float);
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void setVector(const Vector3&);
};
struct ResourceEntry { Object* object; u32 unused[2]; signed char generation; char padding[3]; };
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Groups {char unknown[0x10];signed char flags[4];};
struct ConsoleArguments {
    char unknown[0x860]; int argc;
    char unknown864[0x8A5-0x864]; signed char arg1IsNumeric, arg2IsNumeric, arg3IsNumeric, arg4IsNumeric;
    char unknown8A9[0x8B8-0x8A9]; float arg1Value, arg2Value, arg3Value, arg4Value;
};
struct Game { char unknown[0x214]; signed char count; };
struct Globals {
    char unknown[0x110]; ConsoleArguments* console; Game* game; Manager* manager;
    char unknown11C[0x20]; Groups* groups;
};
extern "C" Globals lbl_801E9D24;
static inline Object* resolve(const Handle& h) {
    ResourceEntry* e = lbl_801E9D24.manager->entries + h.bits.index;
    return e->generation == h.bits.generation ? e->object : 0;
}
extern "C" u32 fn_801F7EB8(const void*);
extern "C" void fn_801FE6BC(Groups*, int, SelectionHandle5*, SelectionHandle3*, SelectionHandle2*);
extern "C" const float lbl_8037A928;
typedef char SelectionHandleSizeCheck[sizeof(SelectionHandle5) == 4 ? 1 : -1];
extern "C" { extern const char lbl_802AD984[]; int sprintf(char*, const char*, ...); void fn_801FAB38(ConsoleArguments*, const char*); }
#endif

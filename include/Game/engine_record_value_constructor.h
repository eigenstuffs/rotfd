// Native construction view with a single 64-bit value at +0x38.
#ifndef GAME_ENGINE_RECORD_VALUE_CONSTRUCTOR_H
#define GAME_ENGINE_RECORD_VALUE_CONSTRUCTOR_H

typedef unsigned long u32;
struct Manager;
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F86C8(Manager*, const void*, short);
}
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
struct RecordValueConstructorHandle1 : Handle_801F7F10 {
    RecordValueConstructorHandle1() { value = 0; }
    ~RecordValueConstructorHandle1() {}
};
struct RecordValueConstructorHandle2 : RecordValueConstructorHandle1 {
    RecordValueConstructorHandle2() { value = 0; }
    ~RecordValueConstructorHandle2() {}
    RecordValueConstructorHandle2& operator=(const Handle_801F7F10& other) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = other.value;
        fn_801F86C8(lbl_801E9D24.manager, &other, 1);
        return *this;
    }
};
struct RecordValueConstructorHandle3 : RecordValueConstructorHandle2 {
    RecordValueConstructorHandle3() { value = 0; }
    ~RecordValueConstructorHandle3() {}
};
struct RecordValueConstructorVector { float x, y, z; };
struct Record_80209EA0 {
    RecordValueConstructorVector position, velocity;
    float field18;
    char unknown1C[8];
    float field24, field28;
    char unknown2C[0xC];
    unsigned long long value38;
    RecordValueConstructorHandle2 handle40;
    RecordValueConstructorHandle3 handle44, handle48, handle4C;
    u32 field50;
    char unknown54[0x54];
    Record_80209EA0(const Handle_801F7F10&, unsigned long long);
    ~Record_80209EA0();
};
extern "C" void fn_80209F80(Record_80209EA0*);
typedef char RecordSizeCheck[sizeof(Record_80209EA0) == 0xA8 ? 1 : -1];

#endif

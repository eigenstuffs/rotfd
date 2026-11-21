// Private construction view of the accepted Record_80209EA0 layout.
#ifndef GAME_RECORD_CONSTRUCTOR_INTERNAL_H
#define GAME_RECORD_CONSTRUCTOR_INTERNAL_H

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
struct RecordConstructorHandle1 : Handle_801F7F10 {
    RecordConstructorHandle1() { value = 0; }
    ~RecordConstructorHandle1() {}
};
struct RecordConstructorHandle2 : RecordConstructorHandle1 {
    RecordConstructorHandle2() { value = 0; }
    ~RecordConstructorHandle2() {}
    RecordConstructorHandle2& operator=(const Handle_801F7F10& other) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = other.value;
        fn_801F86C8(lbl_801E9D24.manager, &other, 1);
        return *this;
    }
};
struct RecordConstructorHandle3 : RecordConstructorHandle2 {
    RecordConstructorHandle3() { value = 0; }
    ~RecordConstructorHandle3() {}
};
struct RecordConstructorVector { float x, y, z; };
struct Record_80209EA0 {
    RecordConstructorVector position, velocity;
    float field18;
    char unknown1C[8];
    float field24, field28;
    char unknown2C[0xC];
    u32 field38, field3C;
    RecordConstructorHandle2 handle40;
    RecordConstructorHandle3 handle44, handle48, handle4C;
    u32 field50;
    char unknown54[0x54];
    Record_80209EA0(const Handle_801F7F10&, u32, u32);
    ~Record_80209EA0();
};
extern "C" void fn_80209F80(Record_80209EA0*);
typedef char RecordSizeCheck[sizeof(Record_80209EA0) == 0xA8 ? 1 : -1];

#endif

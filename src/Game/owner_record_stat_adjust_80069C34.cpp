/* Update the current record's signed channel counter. The native routine reads
 * the replaceable records pointer for both the read and the write. */
struct Record {
    char unknown00[0x30];
    short channels[8];
    char unknown40[0x54];
};
struct Mode {
    char unknown00[0xF0];
    int current;
    char unknownF4[0x44];
    Record* volatile records;
    short get(unsigned char index) { return records[current].channels[index]; }
    void set(unsigned char index, short value) { records[current].channels[index] = value; }
};
struct Scene {
    char unknown00[0x15058];
    Mode* mode;
    Mode* get() { return mode; }
};
extern "C" struct Globals {
    char unknown00[0x124];
    Scene* scene;
    Scene* get() { return scene; }
} lbl_801E9D24;

extern "C" void fn_80069C34(void*, unsigned char index, int amount)
{
    lbl_801E9D24.get()->get()->set(index,
        amount + lbl_801E9D24.get()->get()->get(index));
}

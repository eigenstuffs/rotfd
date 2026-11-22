typedef unsigned long u32;

struct Handle_801F7F10 {
    u32 word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct H1 : Handle_801F7F10 {
    H1() { word = 0; }
    ~H1();
};
struct H2 : H1 {
    H2() { word = 0; }
    ~H2();
};
struct Handle_80024844 : H2 {
    Handle_80024844();
    ~Handle_80024844();
};

Handle_80024844::Handle_80024844() { word = 0; }

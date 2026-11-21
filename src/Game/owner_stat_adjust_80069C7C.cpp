/* Adjust one signed scene statistic. */
struct Stats {
    char unknown000[0x148];
    short values148[50], values1AC[50];
};
struct Scene {
    char unknown000[0x15058];
    Stats* stats;
    Stats* get() { return stats; }
};
extern "C" struct Globals {
    char unknown000[0x124];
    Scene* scene;
    Scene* get() { return scene; }
} lbl_801E9D24;

extern "C" void fn_80069C7C(void*, unsigned char index, short amount)
{
    lbl_801E9D24.get()->get()->values148[index] =
        amount + lbl_801E9D24.get()->get()->values148[index];
}

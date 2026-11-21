/* The native selection key sign-extends its low short before combining it. */
struct SceneMode;

extern "C" int fn_800596E4(SceneMode*, short first, short second) {
    return (int)(((unsigned long)first << 16) | (unsigned long)second);
}

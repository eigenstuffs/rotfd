/* Embedded Python frozen-module registry. The serialized code remains in the
 * original object; the signed size marks __phello__ as a package. */
struct _frozen {
    char* name;
    unsigned char* code;
    int size;
};

extern char lbl_802DE754[10];
extern unsigned char lbl_802DE6F8[90];

char lbl_802DE760[11] = "__phello__";
char lbl_802DE76C[16] = "__phello__.spam";

struct _frozen lbl_802DE77C[4] = {
    {lbl_802DE754, lbl_802DE6F8, 90},
    {lbl_802DE760, lbl_802DE6F8, -90},
    {lbl_802DE76C, lbl_802DE6F8, 90},
    {0, 0, 0},
};

struct _frozen* PyImport_FrozenModules = lbl_802DE77C;

typedef char FrozenRecordSizeCheck[sizeof(struct _frozen) == 12 ? 1 : -1];

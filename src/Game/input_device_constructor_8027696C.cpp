/* Controller input-device constructor (original __ct__20InputDevice_8027696CFv).
 *
 * This is a real C++ constructor; its mangled name is
 * __ct__20InputDevice_8027696CFv, so the symbol __ct__20InputDevice_8027696CFv must be renamed
 * to that name before integration (see the worker report).
 *
 * The base part stores its operations table (offset 0x1C, after the two
 * record arrays) before the arrays are constructed, as a native vtable
 * pointer declared after the arrays would.  The arrays have destructors, so
 * CodeWarrior keeps the subobject this-pointer copies (mr r4,r31; mr r10,r4)
 * even with exceptions disabled.  The derived constructor then installs the
 * controller table and registers the AddInputDevice console command.
 */
extern "C" {
extern const char lbl_802AF134[]; /* "AddInputDevice" */
extern const char lbl_802AF144[]; /* "Adds a gamepad." */
extern char lbl_802ED740[];       /* base device operations table */
extern char lbl_802ED6F8[];       /* controller operations table */
int fn_80276A08(void*);
void fn_801FAC64(void* console, const char* name, int (*handler)(void*), const char* help);
extern struct InputDeviceContext_8027696C {
    char unknown00[0x110];
    void* console;
} lbl_801E9D24;
}

struct PollRecord;

struct InputRecordArray_8027696C {
    int count;
    int capacity;
    PollRecord* data;
    InputRecordArray_8027696C(int) : count(0), capacity(0), data(0) {}
    ~InputRecordArray_8027696C();
};

struct InputDeviceBase_8027696C {
    InputRecordArray_8027696C first;
    InputRecordArray_8027696C second;
    int unknown18;
    void* table;
    InputDeviceBase_8027696C() : first((table = lbl_802ED740, 0)), second(0) {}
    ~InputDeviceBase_8027696C();
};

struct InputDevice_8027696C : InputDeviceBase_8027696C {
    char unknown20[0xE0 - 0x20];
    unsigned long valueE0;
    unsigned long valueE4;
    InputDevice_8027696C();
};

InputDevice_8027696C::InputDevice_8027696C() {
    table = lbl_802ED6F8;
    fn_801FAC64(lbl_801E9D24.console, lbl_802AF134, fn_80276A08, lbl_802AF144);
    valueE0 = 0;
    valueE4 = 0;
}

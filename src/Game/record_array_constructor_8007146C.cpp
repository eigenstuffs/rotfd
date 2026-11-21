/* Native record-owner construction and exception cleanup; tables remain external. */
typedef unsigned long RecordWord;

extern "C" {
void fn_80072AF8(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       RecordWord, RecordWord);
}

struct RecordRootPrefix { RecordWord unknown00[2]; };
struct BaseObject_Z : RecordRootPrefix {
    virtual ~BaseObject_Z();
    virtual void slot0C(unsigned long);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};
struct ContainerBase_802563CC : BaseObject_Z {
    char unknown0C[0x60 - 0xC];
    ContainerBase_802563CC();
    virtual ~ContainerBase_802563CC();
};
struct ContainerLayer_80044168 : ContainerBase_802563CC {
    ContainerLayer_80044168() {}
    virtual ~ContainerLayer_80044168();
};
struct OwnerRecord20 {
    short index;
    char unknown02[2];
    void* pointer;
    float vector[3];
};
struct Object_80071358 : ContainerLayer_80044168 {
    short ids60[6];
    RecordWord field6C;
    unsigned char flags70, flags71;
    char unknown72[2];
    OwnerRecord20 records74[9];
    char unknown128[0x38C - 0x128];
    RecordWord field38C;
    Object_80071358();
    virtual ~Object_80071358();
};
typedef char RecordBaseSize[sizeof(ContainerLayer_80044168) == 0x60 ? 1 : -1];
typedef char RecordSize[sizeof(OwnerRecord20) == 20 ? 1 : -1];
typedef char RecordOwnerSize[sizeof(Object_80071358) == 0x390 ? 1 : -1];

Object_80071358::Object_80071358() {
    ids60[0] = 0;
    ids60[1] = 0;
    ids60[2] = 0;
    ids60[3] = 0;
    ids60[4] = 0;
    ids60[5] = 0;
    field6C = 0;
    flags70 = 0;
    flags71 = 0;
    __construct_array(records74, fn_80072AF8, 0, sizeof(OwnerRecord20), 9);
    field38C = 0;
}

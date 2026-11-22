extern "C" {

float fn_800949BC(const void *object) { return *(const float *)((const char *)object + (892)); }

void fn_800949C4(void *object, float value) { *(float *)((char *)object + (892)) = value; }
}

/* Inferred partial virtual view; original full tables retain ownership. */
namespace OwnerHookLayout_800949CC {
struct Prefix {unsigned long unknown00[2];};
struct Primary:Prefix {virtual ~Primary();char unknown0C[0x30C];};
struct Secondary {virtual ~Secondary();virtual void hook_800949CC();char unknown04[0x28];};
}
struct Object_80090360:OwnerHookLayout_800949CC::Primary,OwnerHookLayout_800949CC::Secondary {
 virtual void hook_800949CC();
 virtual ~Object_80090360();
 void**resources;
};
void Object_80090360::hook_800949CC(){}
typedef char CheckPrimarySize[(sizeof(OwnerHookLayout_800949CC::Primary)==0x318)?1:-1];
typedef char CheckSecondarySize[(sizeof(OwnerHookLayout_800949CC::Secondary)==0x2C)?1:-1];

extern "C" {
}

/* Inferred partial virtual view; original full tables retain ownership. */
namespace OwnerHookLayout_800E12EC {
struct Prefix {unsigned long unknown00[2];};
struct Primary:Prefix {virtual ~Primary();char unknown0C[0x15C];};
struct Secondary {virtual ~Secondary();virtual void hook_800E12EC();char unknown04[0x28];};
}
struct Object_800E102C:OwnerHookLayout_800E12EC::Primary,OwnerHookLayout_800E12EC::Secondary {
 virtual void hook_800E12EC();
 virtual ~Object_800E102C();
 void**resources;
};
void Object_800E102C::hook_800E12EC(){}
typedef char CheckPrimarySize[(sizeof(OwnerHookLayout_800E12EC::Primary)==0x168)?1:-1];
typedef char CheckSecondarySize[(sizeof(OwnerHookLayout_800E12EC::Secondary)==0x2C)?1:-1];

extern "C" {
/* Original leaf operations. Provisional names and text-only ownership.
 * See docs/notes/game-leaf-continuation.md. */

void fn_800E31C0(void) { }
}

/* Inferred partial virtual view; original full tables retain ownership. */
namespace OwnerHookLayout_800E31C4 {
struct Prefix {unsigned long unknown00[2];};
struct Primary:Prefix {virtual ~Primary();char unknown0C[0x30C];};
struct Secondary {virtual ~Secondary();virtual void hook_800E31C4();char unknown04[0x28];};
}
struct Object_800E2A8C:OwnerHookLayout_800E31C4::Primary,OwnerHookLayout_800E31C4::Secondary {
 virtual void hook_800E31C4();
 virtual ~Object_800E2A8C();
 void**resources;
};
void Object_800E2A8C::hook_800E31C4(){}
typedef char CheckPrimarySize[(sizeof(OwnerHookLayout_800E31C4::Primary)==0x318)?1:-1];
typedef char CheckSecondarySize[(sizeof(OwnerHookLayout_800E31C4::Secondary)==0x2C)?1:-1];

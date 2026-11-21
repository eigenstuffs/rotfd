extern "C" {
/* Original leaf operations. Provisional names and text-only ownership.
 * See docs/notes/game-leaf-continuation.md. */
}

/* Inferred partial virtual view; original full tables retain ownership. */
namespace OwnerHookLayout_8009A9C4 {
struct Prefix {unsigned long unknown00[2];};
struct Primary:Prefix {virtual ~Primary();char unknown0C[0x30C];};
struct Secondary {virtual ~Secondary();virtual void hook_8009A9C4();char unknown04[0x28];};
}
struct OwnerHookVirtualView_8009A9C4:OwnerHookLayout_8009A9C4::Primary,OwnerHookLayout_8009A9C4::Secondary {
 virtual void hook_8009A9C4();
 virtual ~OwnerHookVirtualView_8009A9C4();
 void**resources;
};
void OwnerHookVirtualView_8009A9C4::hook_8009A9C4(){}
typedef char CheckPrimarySize[(sizeof(OwnerHookLayout_8009A9C4::Primary)==0x318)?1:-1];
typedef char CheckSecondarySize[(sizeof(OwnerHookLayout_8009A9C4::Secondary)==0x2C)?1:-1];

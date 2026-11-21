# Platform owner destructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`PlatformOwner_8028C1E8::~PlatformOwner_8028C1E8` reconstructs the original
152-byte destructor at `0x8028C1E8`. It restores the derived dispatch table,
runs the virtual cleanup slot, repeats cleanup through the inline base
destructor with its own table, then releases heap storage for a deleting
call. The compiler emits the original null guards and signed deletion
condition.

The private dispatch view records the observed eight-byte object prefix
and virtual slot at table offset `0x10`. Using ordinary virtual dispatch
reproduces the native `r12` call sequence; the initial explicit function
pointer probe had four register differences and remains uncredited.
The class names and layouts describe the observed ABI without claiming
recovered original source names or complete types.

`src/Game/platform_owner_destructor.cpp` emits exactly 152 original text
bytes and seven actual external relocations, without weak helpers or any
other allocated section. Full original exception-index and startup scans
contain no references to this function. No compiled source or header uses
the provisional original entry name. The integration will give its native
destructor symbol the same original address, preserving assembly table
references. The manifest is in
`scratch/game_platform_owner_lifecycle/final_integration.json`.
Production linking and the original DOL hash check remain pending.

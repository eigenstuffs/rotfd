# Class callback registration

The verified linked set covers 117 functions / 11,828 code bytes, 2,856
exception/index bytes and 28 jump-table bytes across 71 fragments. The generated
report and integration evidence record current ownership. QSnail construction,
destruction, initialization, event dispatch and derived registration are recovered;
remaining methods, complete class data and isolated unregistered candidates remain
outside source credit.

Fourteen isolated C++ hooks reproduce 1,456 bytes of code and 504 bytes of
exception tables. Each clears a class-specific registration state, invokes
its base-class hook, constructs a temporary object, registers a member-function
pointer, and destroys the temporary. The automatic destructor also reproduces
the original exception cleanup. Constructor, destructor, callback descriptor,
registration state and registration implementation remain external.

The original factory calls establish each temporary object's size. All fourteen
hooks place the object at stack offset `0x18`, after the 12-byte member-pointer
argument at `0x08`; an opaque storage union expresses the observed eight-byte
alignment. It does not claim that any specific field is a double. Address-based
class names avoid treating header names as proof of complete class identities.
The opaque declarations model these isolated call boundaries only.

| Hook | Factory header | Temporary bytes |
| --- | --- | ---: |
| `8002B58C` | ActorAgent.h | 144 |
| `8002CF08` | CameraAgent.h | 104 |
| `8003522C` | ProjectileAgent.h | 136 |
| `8003CAB4` | RtcInGameAgent_Z.h | 384 |
| `800440B0` | VolumeAgents.h | 112 |
| `8004E8A4` | VolumeAgents.h | 120 |
| `8004FA80` | VolumeAgents.h | 104 |
| `800524B8` | GlobalAgent.h | 800 |
| `80062DB0` | ActorScriptAgent.h | 512 |
| `800646DC` | SpringboardAgent.h | 112 |
| `80073770` | WaterBallAgent.h | 144 |
| `800C6150` | QSnailAgent.h | 168 |
| `800E31E8` | SBPantsAgent.h | 120 |
| `800E3730` | SBPantsAgent.h | 136 |

The compiler is GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions on
-use_lmw_stmw on`. Every function is 104 bytes; each exception record is
24 bytes plus its 12-byte index. The strict isolated verifier resolves all
140 ELF relocations and compares all allocated bytes with the protected DOL.
No cleanup or byte edits are needed. The dependency symbols use the compiler's
ordinary C++ constructor/destructor names; existing factory declarations retain
the same ABI addresses and are checked again by the canonical full build.

These are complete matching fragments, not complete class translation units.
The current generated progress report and each candidate's integration evidence
record their canonical build status. Scratch inventory records the exact source
factory, allocation arguments, addresses, and independent verification results.

## Lifetime-only initialization

Thirty-five additional hooks reproduce 2,100 code bytes plus 700 exception/index
bytes. They clear class registration state, call the base hook, construct an
opaque stack object and immediately invoke its destructor with the observed
`-1` complete-object flag. There is no intervening callback call and no destructor
cleanup action in the original exception table. Explicit constructor/destructor
ABI calls preserve this behavior without asserting unseen class definitions.

Every object size comes from its retained factory allocation, including projectile
variants, jellyfish variants, collectables, springboards, movement agents and
water helmets. The strict `--lifetime` verifier checks all 210 relocations and
all allocated bytes, including each 8-byte exception record and 12-byte index.
All units use the same GC/1.3.2 exception-enabled flags as the callback hooks.

Thirteen lifetime fragments also recover their adjacent 32-byte base-initializer
forwarders. Keeping the wrapper definition after its caller preserves the
original non-inlined call with ordinary compiler settings. These extend the
lifetime set to 48 functions / 2,516 code bytes and 960 exception/index bytes.
The verifier compares exact symbol name/address/size sets independent of ELF
symbol-table order, in addition to exact physical section contents.

## Inlined derived lifetime

Six more hooks in three fragments recover 512 code bytes and 120 exception/index
bytes. Five SpongeBob variants construct a 160-byte object and preserve the
intermediate derived/base vtable stores during inline destruction. The tile-agent
hook constructs a 176-byte object and restores its vtable before the base
destructor call. Factory allocations prove both extents; the vtable is at offset
8. Ordinary inline helpers naturally retain the repeated stores. All 58
relocations and every owned byte match without volatile accesses or byte edits.

## Additional callback and collectable variants

Four hooks with two callback registrations add 592 code bytes and 144
exception/index bytes. Their factory-proven object extents and ordinary
C++ member-function arguments reproduce both temporary descriptors and the
single destructor cleanup action. The strict `--multi` verifier checks all
52 relocations. The actual object sizes remain recorded in each scratch
inventory entry; no complete member layout is asserted.

Thirteen collectable-variant hooks add 1,716 code bytes and 260 exception/index
bytes in ten contiguous fragments. They initialize a base variant's registration
state and temporary object, then initialize a second temporary with the derived
vtable. Each 152-byte object's allocation is established by the retained
collectable factories. Inlined construction/destruction preserves all intermediate
vtable stores. The strict `--collectable` verifier checks 195 relocations.
Nine adjacent reset methods add 576 code bytes and 180 exception/index bytes.
They call the shared collectable reset, enable flag bit 2 and set the tile variant
index at offset 0x90 to 0 through 8. These fragments require `-opt nopeephole`
to preserve the original ordering of saved-register reloads. The same option
preserves every byte of the preceding registration function. All 22 functions
in this extended set pass complete section and relocation verification.


## QSnail base lifetime

`qsnail_agent_lifetime.cpp` recovers the 68-byte constructor and 132-byte deleting
destructor at `0x800C61B8..0x800C6280`. The shared private declaration also serves
the existing callback hook, preserving its size, alignment and exact code. The
constructor initializes the Reefblower base, installs the QSnail vtable and
zeros the field at offset `0xA0`. Destruction restores that vtable, clears the
field, destroys the base, and conditionally releases the allocation.

The class-specific `operator delete(void*) throw()` reproduces the original
exception specification and active-catch records, including the `__unexpected`
path. `-O4,s -use_lmw_stmw on` emits the original bulk register save/restore in
the frame-pointer destructor. The constructor's eight-byte exception record,
the destructor's forty-byte record and both twelve-byte indices are exact.
All 200 code bytes, 72 metadata bytes and 14 relocations pass without padding
cleanup, fabricated exception data or object edits. The private class name is
address-based; observed factory and registration strings identify QSnailBase.


Two adjacent QSnail callbacks reproduce 76 code bytes and twenty metadata bytes.
One is the original empty callback. The other calls the base update, binds its
resource object to the agent and resets the resource state at offset `0x318`.
It uses `-opt nopeephole` for the observed epilogue order; the strict verifier
checks all five relocations and every owned byte. The initialization is recovered below; the following behavior methods remain
original until independently verified.

## QSnail initialization and derived registrations

`qsnail_agent_initialize.cpp` recovers the 336-byte initialization method at
`0x800C6280`, with 24 exception-table bytes and a twelve-byte index. Its named
resource factory returns a nontrivial four-byte handle through the ABI's hidden
result pointer. Declaring both its constructor and destructor reproduces the
compiler's temporary lifetime, including the destructor call with flag -1 and
its cleanup record. The method checks the handle's signed 24-bit index and
signed generation byte, updates the agent's 64-bit flags, invokes virtual slots
0x5C and 0x60, and initializes five scalar resource fields. The `-O4,s` source
passes every byte and all sixteen relocations; no exception records are supplied
as source data. The ordinary destructor identity is now
`__dt__15Handle_801F7F10Fv` at its original address `0x801F7F10`.

`qsnail_variant_registry.cpp` recovers all fifteen 212-byte derived registration
hooks at `0x800C68B8..0x800C7524`: 3,180 code bytes and 540 exception/index
bytes. A normal inline base-registration helper establishes the original order
of the two stack temporaries; ordinary inline constructors and destructors
reproduce all intermediate vtable and resource-pointer stores. The original
0xA8-byte allocation remains the object extent. No manual stack placement,
assembly, forced register names, or byte edits are used.

The compiler also emits a weak copy of the already recovered base destructor.
With `-O4,s`, its 132 code bytes and 52 metadata bytes independently match the
original strong definition too. The strict derived verifier checks **every
allocated byte** through its recorded original address, including that duplicate,
and all 324 relocations. Normal linker strong/weak resolution retains the
existing lifetime unit's definition; the duplicate owns no additional source
range and receives no additional progress credit. This is recorded explicitly
in the candidate's `duplicate_definitions` and `duplicate_policy` fields.

The remaining QSnail behavior method is `0x800C641C` (528 bytes).
It has a semantic candidate under
`scratch/game_qsnail/behavior.cpp`: its true branch matches, but the compiler
eliminates repeated handle lookups in the false branch, leaving 500 rather than
528 bytes under `-O4,s`. It remains unregistered and uncredited.


`qsnail_agent_events.cpp` additionally recovers the full 652-byte event handler,
including the switch cases missing from the historical decompiler output. It
registers or queries member callbacks, reads event flags and indices, applies
adjusted event codes, and invokes the agent's virtual slot 0xB0. A typed view of
the six existing twelve-byte callback descriptors preserves the shared pool base;
that 72-byte pool remains external. The compiler emits the exact seven-entry
jump table at `0x802BFE70`, plus the original eight-byte exception record and
twelve-byte index. All 27 relocations and every owned byte match. The full DOL
and native source audit pass for initialization, derived hooks and event handling.

Two adjacent accessors at `0x800C7524` and `0x800C752C` read and replace the
shared QSnail registration state. Their sixteen bytes extend the same derived
registration source range, with no additional data or exception ownership.

## TeleportVolume registration candidate

The three-callback hook at `0x800C7534` has an isolated exact reconstruction in
`src/Game/class_registry_800C7534.cpp`: 184 code bytes, 36 exception/index bytes
and three twelve-byte member-function constants. The factory at `0x800BA9BC`
proves the 0xC0-byte object size. Actual C++ virtual member-pointer expressions
for slots 0x94, 0x98 and 0x9C reproduce the original compiler-generated pool and
its cached base register; an external-array spelling rematerializes addresses.
The twelve relocations and all allocated bytes pass the strict `--triple` verifier.

This source remains **unregistered and uncredited**. Its 36-byte constant prefix
belongs to an original 96-byte pool also addressed by the remaining TeleportVolume
methods. Recover those consumers and establish complete pool ownership before
promoting this fragment. Its constructor/destructor aliases are isolated verifier
inputs only; central symbol identities remain unchanged.

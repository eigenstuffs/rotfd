# Timed actor event and state control (`800C152C`)

The new independent source `src/Game/timed_actor_event_control_800C152C.cpp`
reconstructs the original 576-byte C entry `fn_800C152C`. Its retained compiler
output matches the original text, 44-byte exception record at `800126B8`, and
12-byte exception index at `8001CBA8` after all 18 actual relocations resolve.
The parent integrator must still establish full native placement, the original
DOL hash, and no regressions before counting it as matching source.

The function subtracts elapsed time from field `410`. When mode `414` and state
`415` are both one and the timer has expired, it sets state two, copies the
self Handle at `24`, and sends event `9A/8D` to its resolved object. State four
clears velocity `144` using the existing global zero vector. It forwards the
same elapsed time to `8007F860`, then clears flag `20000` when state and field
`320` are zero, and sets the flag otherwise.

Private declarations describe only observed offsets: Owner contains Handle
`24`, velocity `144`, field `320`, timer `410`, and adjacent bytes `414/415`.
The first byte uses plain `char`, whose compiler promotion reproduces the
original `cmpwi` without a sign-extension instruction; the second uses
`unsigned char` and reproduces `cmplwi`. No signedness inference beyond the
observed comparisons is required. The resolved object's flags at `38` are a
64-bit value: the clear path reads and writes both words, including the
original high-word AND. Entries have stride 16, object at zero, signed tag at
`0C`; the Handle has signed 8-bit tag and signed 24-bit index. Manager entries
are at `08` and the global manager pointer is at `118`. These are partial
layout views, not a claim that the full original types have been recovered.

The actual Handle construction initializes seven empty layers before copying
and retaining the original member. Its base and completed-local exception
lifetimes use the existing external native destructors
`__dt__15Handle_800C17F8Fv` (136 bytes) and
`__dt__15Handle_800C176CFv` (140 bytes). Their accepted dictionary canonicals,
source, recursive quoted header, production objects, fresh compiler objects,
raw hashes, GLOBAL symbol extents and complete actual relocations were checked
independently. Declaring these destructors externally reproduces the original
completed-local call with argument `-1`; defining the small bodies inline
would call the primitive destructor with argument zero instead. Gekko flags
are necessary for the original exception FPR format. Naming the zero vector's
y and z values before the ordinary Point setter closes the final two load
order words. No instructions or relocations are patched or masked.

Six unique private `EventZero_C152C` destructor backups contain 516 bytes of
uncredited text and 120 bytes of uncredited exception metadata. Every emitted
allocation, symbol, raw digest and all 24 backup relocations are inventoried.
There are no retained references to any backup, and no defined-weak override
authorizations. The unchanged strict object/EH gate accepts the production
object. An actual isolated MWLD link with the two accepted destructor inputs
selects the GLOBAL definitions and discards all 18 backup text/EH/index
allocations; a wrong fixture basename is rejected. The original full-game
native map/ELF proof remains a parent acceptance requirement.

The full original exception-index table, constructor table and destructor
table were scanned. Only the function's stated exception record/index belong
to this split; it has no constructor or destructor table slot. All 501,416
possible four-byte pointer positions across the original initialized data
sections were checked, including unaligned positions. Two existing pointers
target the unchanged C entry, one in the owned exception index and the other
remaining externally owned. All seven original text sections were scanned
for direct callers. The accepted `800C1988` forwarding source remains unchanged
and its exact snapshot/hash is included. A census of 43,314 source/header and
private C/C++ files found no prior body or registered split overlap. All
external literals, the zero vector, remaining original data and neighboring
functions retain their existing ownership and identity.

Compiler: GC/1.3.2, `-proc gekko -fp hardware -enum int -str reuse -common off
-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`. Frozen proposed splits,
configuration, strict verification, supplementary external strong-owner proof,
native link/discard proof and original ownership audit are in
`scratch/game_timed_actor_event_control_leaf/`. Central metadata and all prior
frozen sources, verifier cores and handoffs are unchanged.

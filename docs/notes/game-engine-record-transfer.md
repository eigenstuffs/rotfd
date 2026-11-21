# Engine transformed record transfer

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: two ordinary C++ functions, 476 text bytes, zero data
and three real call relocations. Sources are
`src/Game/engine_record_transfer_801BC99C.cpp` (260 bytes) and
`src/Game/engine_record_transfer_801BCAA0.cpp` (216 bytes). They emit no extra
code, weak functions, allocated data or padding. Exact integration, source
SHA-256, quoted-header hashes (none), emitted allocations and real relocations
are in `scratch/game_engine_record_transfer_continuation/final_integration.json`,
with adjacent split/configuration proposals and original `ownership_audit.json`.
Existing external names are unchanged.

The record starts at owner +78. All copied fields are directly established:
object pointer +0, four three-float vectors at +4/+10/+1C/+28, pointer +34,
two scalar floats +38/+3C, 64-bit flags +40, pointers +48/+4C and float +50.
The record has 84 bytes of fields and eight-byte alignment, giving an 88-byte
local result. Vector assignment explicitly copies its three float components;
record assignment copies both scalar coordinates as floats and preserves the
64-bit flags' low-word then high-word store order.

`fn_801BCAA0` calls the original `fn_801BCB78` to populate a local record, then
copies all observed fields into the owner. `fn_801BC99C` initially copies the
record's +4/+1C/+28 vectors to the three caller outputs. When the record has an
object, that object's word +120 has bit 0x800 set, and the record's 64-bit flags
contain bit 48, it invokes `fn_8023EEF0`, copies the two coordinate words into a
local value, and asks the original `fn_801D5DF8` to replace the second output.
It returns the record's current object pointer. An explicit first pointer local
before the coordinate copy reproduces the observed argument-load order.
Unknown vector and scalar meanings retain offset-based private names.

GC/1.3.2 uses ordinary `-O4,p` flags with C++ exceptions off. All production
sources were recompiled after private naming and formatting. The copied strict
verifier applies actual relocation targets, compares every original byte and
exact function extent, and checks every emitted allocated section. The complete
original exception index and constructor table were audited; neither function
has an exception record or startup constructor entry. Original split ownership
is text only; other functions and referenced objects keep existing ownership.

`verify.py` passes both units. Root must pass the complete DOL hash, native
match regression and extent checks before promotion. No central metadata or
full build was changed by this agent.

## Uncredited matrix-slot probe

`fn_801C9E3C` finds a free index with original `fn_80207B94`, sets its occupancy
bit, clears each selected 64-byte matrix and assigns the four identity diagonal
values. Its private observed layout and bounded ordinary C++ probes are preserved
in scratch. The generated register allocation remains different, so there is
no production source or source credit for this function. The bit-search routine
itself remains outside this work and uncredited.

2026-10-12 matrix-slot continuation: a private narrowed `SlotIndex` value class
and direct `arrays[i][index].identity()` call now reproduce the native 196-byte
extent and every native GPR assignment. Frozen best candidate
`scratch/game_frontier_20261012_b/matrix_view_mat_direct.cpp` still differs in
four words because its single identity-value load is scheduled before, rather
than after, the three integer bitmask instructions. All other code and three
actual relocations match. Scalar constructors/conversions, row-array views,
inline claim helpers and supported optimization variants did not close that
remaining schedule difference. This remains uncredited research.

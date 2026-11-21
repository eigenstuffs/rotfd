# Scene resource transition at 80031328

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated production proposal recovers the existing C entry `fn_80031328`
at `80031328..80031650` (808 bytes), its original 56-byte exception record
at `80007554..8000758C`, and its 12-byte index at `80016C20..80016C2C`.
Parent integration and full original-DOL acceptance remain pending. The source
is a partial original translation-unit reconstruction; surrounding routines,
all context storage, and both small-data values remain externally owned.

The routine resets sound/UI state, enters state 13, updates nonselected UI
entries, conditionally applies an empty layered Handle, resets scene-owner
state and mode services, clears the owner's active byte, then forwards the
resolved resource and its value before returning one. Inferred private views
preserve observed offsets rather than claiming full recovered class layouts:
owner Handle fields at 0x60/0x7C, selected/mode at 0x64/0x68, active at 0x94;
resolved node count/value at 0xDC/0xE4; scene owner pointer at 0x15058; context
manager/scene/sound/mode/UI at 0x118/0x124/0x154/0x158/0x164. Entries have
16-byte stride and a signed generation byte at 0xC.

Root's exact ordinary C++ probe caches `const Entry *entries` during inline
resolution. This preserves the original saved context registers, closing the
last 12 operand differences. The production source preserves the probe body,
with a documentation comment and unique names for the three source-private
Zero helper classes. `private_helper_identity_proof.json` proves every allocated
byte and every actual relocation unchanged under only those private symbol
renames. Existing accepted C callers in the 8003387C selector remain untouched;
they ignore the result, while the recovered entry correctly returns one.

GC/1.3.2 uses `-proc 750 -fp hardware -enum int -str reuse -common off -O4,s
-inline auto -Cpp_exceptions on -use_lmw_stmw on`. The unchanged strict ELF/EH
core verifies every retained byte, all 39 retained relocations, all 26 discarded
relocations, and the complete emitted allocation inventory. Exception pointers
resolve to accepted GLOBAL strong destructors Handle_8002DE2C (124 bytes) and
Handle_8002B67C (112 bytes). Both canonical manifests, production objects,
source/recursive header hashes, independent recompiles, original owned sections,
actual relocations, and strong ELF binding/type/extent are verified.

The compiler also emits five weak backup bodies totaling 476 bytes and their
164 bytes of exception metadata/index. They are uncredited: the two native
Handle backups and three private TransitionZero helpers. The actual isolated
MWLD link selects both accepted strong definitions and discards all 15 backup
allocations. A wrong fixture basename is rejected. This proves native selection
and complete discard, while original placement and the full-game hash remain
mandatory parent acceptance checks.

The complete original extabindex table, constructor/destructor tables, and all
initialized DOL pointer words were audited. The sole original pointer into this
text extent is its owned exception index. No constructor/destructor entries,
new data pools, dependency identity migrations, aliases, or assembly thunks are
introduced. The original `fn_80031328` identity and accepted consumer files are
preserved. Root's initial and all private variants remain in the scratch folder.

Frozen evidence: `scratch/game_scene_resource_transition_80031328/` contains
`final_integration.json`, complete raw allocation/relocation inventories,
independent strong proofs, verification and native-link reports, exact proposed
split/config text, full pointer ownership audit, and `handoff.json`.

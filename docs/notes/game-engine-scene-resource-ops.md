# Scene resource position operation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_scene_resource_ops_800356DC.cpp` reconstructs the ordinary
C-entry function `fn_800356DC`, original `800356DC..80035850` (372 bytes), with
its complete 44-byte exception table `80007730..8000775C` and 12-byte exception
index `80016CF8..80016D04`. The parent integrator owns promotion and full
original-placement DOL acceptance. Earlier frozen setup batches remain unchanged.

The retained function matches its first ordinary C++ probe. GC 1.3.2 uses the
established `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` profile,
with complete flags and source/header hashes frozen in
`scratch/game_engine_scene_resource_ops_continuation/final_integration.json`.

## Behavior and established storage

The owner contains handles at `+0x58` and `+0x70`. Resolving its latter handle
produces a resource through the unchanged context manager at `+0x118`. Entries
have stride 16, object pointer at zero and signed generation byte at `+0xC`.
The four-byte handle has signed 8-bit generation and signed 24-bit index fields.
A mismatched generation falls back to null, preserving the original unchecked
resource accesses.

The function clears two resource vectors at `+0x144` and `+0x15C` to the original
external float `lbl_80378420`, copies the saved vector at `+0x3F0` into a local,
and makes a retained typed copy of the owner's `+0x58` handle. It calls the
original `fn_8023D100` with that resolved handle and local vector, then
`fn_8023DE28` with the independently resolved handle, and `fn_8007D6A0` on the
first resource's embedded component at `+0x318` with argument 3. Private views
expose only these observed offsets; no storage is allocated from their sizes.
The explicit ordinary point assignment performs floating loads/stores in the
original order. A named const reference to the source handle preserves the
original saved source-pointer lifetime.

## Real native destructor overrides

The genuine four-byte hierarchy is native `Handle_801F7F10`, then the zeroing
`Handle_8001FF78` base, then retained-copy `Handle_80020B90`. Empty inline
destructors preserve the original normal cleanup call to native Handle's
destructor with delete flag zero. Retained exception metadata refers to the
original strong destructors of both typed layers: partial-base cleanup uses
`__dt__15Handle_8001FF78Fv`, and completed local cleanup uses
`__dt__15Handle_80020B90Fv`.

The compiler emits trailing weak backup definitions of those two native
symbols, 112 and 116 bytes, with 104 total bytes of backup exception metadata.
Those 332 allocated bytes and their 14 relocations receive no credit. The
retained function and 56 metadata bytes contain 13 actual relocations.
Every allocation, raw hash, binding, symbol extent and real relocation is
inventoried using the unchanged adopted `weak_override.py` core.

`strong_owner_proof.json` independently pins the accepted canonical manifests,
source files, recursive quoted headers, production objects and fresh recompiles
of both original strong owners. Every strong-owner allocated section and actual
relocation matches the original, and fresh compiler outputs match accepted
production object hashes. No existing owner source, header or canonical file
was modified.

`native_800356DC/proof.json` records a real MWLD link with both accepted strong
owner objects and the actual runtime/small-data objects. The unchanged native
checker proves all six backup text/exception/index allocations discarded and
both real strong symbols selected. A wrong fixture basename is rejected. The
initial private link without the original small-data constant owner was rejected
by MWLD's genuine SDA21 rules; that diagnostic is preserved under
`native_800356DC-failed_sda`. The successful proof includes the actual original
`auto_11_803781C0_sdata2.o`, preserving the constant's small-data section semantics.
No absolute aliases are substituted for SDA data.

The final full-game integration must repeat the complete native map/ELF audit,
including backup text and metadata discard and original strong-owner placement.
This uses only the existing standard weak-override schema and checker, with no
new adapters or verifier-core changes.

## Complete original ownership audit

`ownership_audit.json` verifies the true original assembly extent and full
exception-index table `80015F60..8001F2C0` (stride 12). It confirms exactly the
44-byte table and 12-byte index owned by this entry. Full constructor
`80299920..80299980` and destructor `80299980..802999A0` scans (stride 4) find no
startup or termination pointer. Original callback/type-table references stay in
their unchanged assembly owners; entry identity remains `fn_800356DC`.
Dependencies include only actually undefined ELF symbols, excluding defined
local metadata and backed weak symbols. `complete_allocated_inventory.json`
records the entire emitted ELF allocation and all actual relocations.

## Excluded neighbor and handoff

The neighboring `8003543C` remains private and uncredited. Its ordinary source
currently emits 608 rather than original 640 bytes because it reuses several
nested handle lookups. Explicit vector setter forms and bounded compiler-option
probes do not recover the original load/reload pattern. Its source/object/diff
and failed anonymous-structure experiment are preserved without source promotion.

`final_integration.json`, `final_splits.txt`, `final_config.txt`, `verify.py` and
`native.py` are the isolated integration proposal and reproducible checks.
`handoff.json` pins the exact production source, this note, strong-owner proofs,
all native-link evidence and the complete research directory. Shared metadata,
accepted sources and all old frozen gates remain untouched.

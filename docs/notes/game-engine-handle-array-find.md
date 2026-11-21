# Handle array key search

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_handle_array_find.cpp` reconstructs the complete 316-byte
`fn_8023A8C0` extent 8023A8C0..8023A9FC as ordinary C++. It first assigns a
new empty handle to the output, then scans a snapshot of the array count.
For each valid handle it resolves the generation-tagged entry and compares
the object's first word with the supplied key. On a match it releases the
previous output, copies the selected handle and retains the source.

Two inherited inline zero-initialization stages account for the repeated zero
stores after the native handle constructor. Their temporary's destructor
naturally calls the native base destructor with mode zero. Naming the resolved
object fixes the key-load ordering. A separately declared byte offset initialized
after the element index reproduces the original induction registers and zero
initialization order; the successful assignment still uses typed element indexing.

GC/1.3.2 with standard O4,p/auto inline, exceptions off and
`-use_lmw_stmw on` emits 316 exactly matching retained bytes with nine actual
relocations. Two unused weak destructor backups occupy 172 additional bytes
with four relocations. The strict manifest inventories their contiguous extents,
weak binding and raw hashes; no retained reference targets them. They must be
discarded and earn no progress credit. No data, BSS, metadata or padding is owned.

The complete original extabindex allocation 80015F60..8001F2C0, including its
trailing descriptor and zeros, and full .ctors/.dtors allocations
80299920..80299980 / 80299980..802999A0 contain no references to this extent.
All neighboring original functions and data remain outside this partial text split.
The original function identity and dependency spellings are retained.

`scratch/engine_handle_array_find_20261010bt` preserves the bounded probes,
strict verifier, full original table audit, frozen source/header hashes and
NonMatching registration/split snippets. Run `verify.py` there. This handoff
establishes isolated source matching; central integration owns the final DOL
hash, regression and generated-progress acceptance.

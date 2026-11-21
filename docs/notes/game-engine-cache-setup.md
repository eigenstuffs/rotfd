# Engine surface cache setup continuation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: three ordinary C++ units, three original functions,
1,300 retained text bytes, zero owned data and 48 retained real relocations.
The row constructor emits one trailing unused weak key destructor, 84 bytes
with two relocations. Those bytes receive no source credit, and its symbol
`__dt__12Key_801EAC8CFv` must be absent from the final linked ELF.

Sources are `src/Game/engine_cache_setup_*.cpp`. Exact integration is in
`scratch/game_engine_cache_setup_continuation/final_integration.json`, with
`final_splits.txt`, `final_config.txt` and `ownership_audit.json`. Production
source SHA-256 and recursive quoted-header hashes (none) are frozen. Every
emitted allocated byte, function binding, extent, unused weak raw byte hash,
and both retained and unused real relocation lists are recorded. Existing
external function names remain unchanged.

| Function | Retained bytes | Real relocations | Observed behavior |
| --- | ---: | ---: | --- |
| fn_801EAA94 | 368 | 12 | Construct ten-slot surface cache with 32-byte-aligned backing storage |
| fn_801EAC8C | 560 | 24 | Resize handle rows to requested count plus two sentinel rows; initialize links |
| fn_801EAEBC | 372 | 12 | Construct 900-slot surface cache with the same per-slot buffer partition |

The cache prefix has signed count/capacity, row pointer, block stride, block
pointer and table at +0/+4/+8/+C/+10/+14. Constructors install base table
`lbl_802EA868`, clear count/capacity and both pointers, then install their derived
table (`lbl_802F1490` or `lbl_802F149C`). The existing cache reset routine
`fn_801EAC04` establishes the requested row count and a block stride of one.
The raw surface allocation has 0x240 bytes per slot, aligned to 32 bytes.
Each four-pointer block partitions that allocation at +0/+C0/+180/+1C0.

Each slot is removed from its current doubly linked chain and prepended to the
chain headed by row zero. Rows are 12 bytes: native handle at +0, slot index at
+4, opaque halfword at +6, previous/next indices at +8/+A. Inline access through
an unsigned-short slot helper reproduces the original indexing and register
allocation. These observations agree with the separately accepted cache binding
layout; the new sources keep private declarations to avoid affecting it.

The resize routine grows or shrinks the row storage to requested count plus two.
Growing constructs the native handle, assigns an empty packed handle using the
existing assignment method, destroys that temporary and sets the slot index to
0xFFFF. Shrinking destroys rows in reverse order, then resizes their allocation.
An empty derived row layer preserves the two observed null checks before native
handle destruction. An inline indexed accessor and destruction helper reproduce
the original address evaluation and shrink iterator allocation. Link setup
clamps previous/next indices using original `fn_801EC764` and `fn_801EC778`.

## Verification and ownership

GC/1.3.2 uses the ordinary `-O4,p` flags, C++ exceptions off. The resize routine
also uses `-use_lmw_stmw on`; constructors use standard register-save settings.
All production sources were recompiled after private naming and formatting.
The copied strict verifier applies actual relocation targets, compares every
retained original byte and exact function extent, and accounts for every emitted
allocated section. No retained relocation references the unused weak function.
There is no relocation masking or source credit for discarded cleanup code.

The full original exception index and constructor table were audited. None of
these functions has an exception record or startup constructor reference. Their
original units own only text. Other original functions and all externally
referenced tables, strings, allocator globals and native handle methods retain
their current ownership outside these partial text splits.

`python3 scratch/game_engine_cache_setup_continuation/verify.py` passes all three
production units. Root integration must check the unused weak symbol's absence,
the original DOL hash, native match regression and source extents before source
promotion. No shared metadata or full build was changed by this agent.

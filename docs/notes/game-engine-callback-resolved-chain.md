# Callback resolved-Handle chain dispatchers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

This isolated tranche reconstructs `fn_8004CE8C` (1,240 bytes) and
`fn_8004D364` (1,552 bytes) as ordinary C++. Each production object contains
exactly its original function, eight-byte exception header, twelve-byte
exception index, and twenty-eight-byte compiler jump table. The complete
2,792 code bytes and 96 metadata/data bytes match with all 70 actual
relocations resolved. There are no weak helpers or discarded allocations.
Integration and the complete native DOL hash remain the integrator's check.

Both functions retain the established callback registration/query cases and
follow the context's link at `13C`, Handle pointer at `1C`, resolved object's
Handle pointer at `B0`, and next object's Handle member at `70`. The final
resolved object has a Handle member at `1AC`; its virtual method at `9C(0)`
returns a Handle pointer. The private views establish only these observed
fields, the existing signed generation/index encoding, sixteen-byte manager
entry stride, entry object pointer at zero, and signed generation byte at
`0C`. A byte-backed view for the second nested manager lookup preserves the
original second entry-pointer load without imposing a larger shared layout.

`8004CE8C` records validity in byte `65` and the resolved final object in
pointer `68`, clearing that pointer when invalid. Its signed-char local is
assigned to the member before the conditional; this ordinary source form
reproduces the original boolean value and promoted condition register.
`8004D364` records current validity in byte `66` and updates pointer `6C`
when valid. The original leaves `6C` untouched on the false path. Modes zero
through three compare the saved and current pointers/validity bytes and call
the existing `fn_8004D974(self,0x8B)` for the corresponding transition.

The original five-record member-pointer pools at `802B3E1C..802B3E58` and
`802B3E74..802B3EB0` remain assembly-owned. Their five complete records are
respectively `{0,0x78,8}` and `{0,0x7C,8}`, consistent with the retained native
member-pointer runtime layout. The broader relocation anchor
`lbl_802B3708` keeps its original seventy-two-byte identity. The opaque
prefix in each private external declaration expresses the observed address
displacement to the borrowed records; it does not claim ownership or enlarge
the original global. No data symbol partition, new global, retention rule,
identifier migration, or alias is requested.

The naturally eight-aligned switch tables start at `802B3E58` and `802B3EB0`.
Their seven original local code pointers each resolve exactly; the compiler's
section alignment is retained. Original virtual table entries at `802B4530`
and `802B4534` still target the unchanged C entry names. The ownership audit
scans the complete original exception-index table, both startup/shutdown
pointer tables, and initialized data references. Each function has exactly
one owned exception record, no constructor/destructor table entry, and no
existing compiled source caller requiring a change.

`scratch/game_engine_callback_resolved_chain_continuation/handoff.json`
freezes sources, raw objects, original probes, strict verifier, complete
allocated/symbol inventory, actual relocations, member-pointer provenance,
source consumers, exact split/config proposals and hashes. `verify.py`
recompiles both production sources and checks every emitted allocation and
actual relocation. Central metadata and previous frozen handoffs are unchanged.

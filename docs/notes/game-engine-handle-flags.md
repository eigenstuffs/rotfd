# Engine nested handle query and flag research

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `scratch/game_engine_handle_flags_continuation/final_integration.json`.
The retained source for `fn_801D7CDC` reproduces **268 original text bytes**, zero data and **four actual relocations** under standard GC/1.3.2 flags. Production recompilation passes the strict verifier. Every emitted allocated byte is accounted; there are no weak helpers. The manifest freezes the production source SHA256 and empty recursive quoted-header inventory. Central integration/full DOL acceptance remain pending with the integrator.

The function scans 0x90-byte records at owner offset 0xAC, using count at 0xA4. Each record's packed handle is at 0x88. For the first handle accepted by `fn_801F7EB8`, it resolves the record's resource, resolves the resource's nested handle at 0xB8, and returns that target's float at offset 0x18. With no live record it returns original constant `lbl_8037A4B8`. Resolution uses manager pointer at original globals+0x118, 16-byte manager entries, object pointer at entry+0 and signed generation byte at entry+0xC. The original performs the same unchecked index access and generation comparison; the private ordinary C++ accessors preserve them.

The entire original fragment is `.text 0x801D7CDC..0x801D7DE8`, with no owned data. Complete original extabindex and constructor scans find no record or constructor reference. Fixed original symbol names and dependencies are preserved. Exact split/config proposals and section audit are adjacent to the manifest.

Uncredited bounded research: `fn_801C0BC4`, `fn_801C0CC8`, `fn_801C17DC`, and `fn_801C18F0` call their setup routine, resolve a child handle, invoke virtual selector 0x9C, resolve its returned handle, and apply/clear saved bits at target+0x120. Private original field offsets and all virtual/handle operations are established. Their closest ordinary probes have exact extents and differ in one commutative AND word each: original `and r0,r0,r3`, compiler `and r0,r3,r0`. An ordinary generic 64-bit mask parameter emits the original load/negate/AND shape; a 32-bit mask folds to a shorter rotate/mask. Operand reversal, signed/unsigned widths, bounded flags and inline mask wrappers did not resolve that raw-word difference. All remain scratch-only, with no production source or matching credit.

2026-10-12 structural continuation: private probes under
`scratch/game_frontier_20261012_b/owner_flag*` retain the same one-word AND
failure. Physical four-byte flag storage wrappers, const-reference scalar mask
and condition classes, inline by-value result helpers, and supported lifetime,
propagation and deferred-inlining options did not resolve it. A reference to a
literal 64-bit mask also emits an unmatched `.sdata` constant and is rejected.
The target flag field at +120 remains a four-byte word; the 64-bit type is the
generic helper parameter, not a newly claimed eight-byte field. No new code or
storage is credited by these experiments.

# Middle engine scalar operations

This continuation reconstructs **18 original functions and 744 text bytes
in ten bounded fragments** under `src/Game/scalar_middle_*.c`. It retains
the versioned original entry names and standard Game GC/1.3.2 flags. Native
SDK/runtime register-saving, dispatch, cache, and paired-single matrix
assembly are excluded.

The source includes ordered float-vector copies, scalar vector arithmetic,
a bounded bit query, an indexed bit clear, an integer clamp, a scalar reset,
a halfword-validity query, and an indexed record invalidation. Vector math
at `0x801D7EFC..0x801D8068` forms one contiguous group of nine complete
functions. Its scalar operations use an ordinary inlined three-float setter
to preserve the original argument evaluation and load-before-store behavior.
It does not emit paired-single instructions or include instruction assembly.

The bounded bit query at `0x801C1744` validates a signed index against zero
and the limit at object offset `0x19C`, then reads the indexed bit from the
word array at offset `0x194`. The bit clear at `0x801C9E10` preserves the
signed halfword argument, arithmetic word index, and low five-bit shift.
The record invalidation at `0x801CDB3C` preserves the `0xFFFF` sentinel,
manager pointer at the global object's offset `0x130`, entry pointer at
manager offset eight, 12-byte entry stride, and halfword at entry offset
four. It updates entry `index + 1` before replacing the object's halfword
at offset `0x20` with the sentinel.

The canonical handoff is
`scratch/game_scalar_middle_continuation/final_integration.json`;
`final_splits.txt` and `final_config.txt` provide exact integration entries.
No symbol edits are needed. `ownership_audit.json` records the active
original fallback unit and all section extents for every selected function.
Every selected original unit owns zero non-text bytes: constructors, original
data, and exception ownership are untouched. Each source contains only a
contiguous recovered range; larger original units remain partial fallbacks.

`python3 scratch/game_scalar_middle_continuation/verify.py` recompiles all
production sources, checks all complete function extents and bindings,
rejects extra functions and unsupported allocated sections, applies the
two actual address-half relocations, and compares every emitted text byte
against the supported DOL. No relocation bits are masked. The full native link, original DOL hash, and objdiff regression checks pass.

Six addressing variants remain scratch-only because their code differs:
`0x801B5190`, `0x801C0DCC`, `0x801C0DE8`, `0x801C1790`, `0x801C17C0`, and
`0x801C2F5C`. Their behavior is understood, but these source variants are
not included in the final manifest or matching totals. Earlier standalone
probe manifests are superseded by the final grouped manifest.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.

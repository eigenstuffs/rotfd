# Original allocator storage at 0x801EF5C8

The 44 bytes at .text:0x801EF5C8..0x801EF5F4 are eleven original zero words,
accessed as allocator state through the original global label `lbl_801EF5C8`.
The baseline and session-start native reports contain no function in this
range. Original allocator code accesses fields through offset 0x28; the active
object census finds 2,972 address relocations and no direct branches here.

Splitting the preceding 400-byte animation-frame constructor leaves this range
in its own original fallback unit. DTK 1.8.3 adds a synthetic 44-byte function
at the start of that unit. That adds a function and 44 code bytes to the native
report even though no original function was discovered.

`tools/normalize_text_storage.py` corrects only this generated symbol's extent
and type, from LOCAL FUNC/44 to LOCAL NOTYPE/0. A versioned contract pins the
complete generated and corrected object hashes. Structural checks require
exactly the original 44 zero bytes, no relocations, the unchanged GLOBAL
NOTYPE/0 original label, and the exact synthetic LOCAL symbol. Only two ELF
metadata bytes change. A different object or wider correction fails closed.

The legacy MWLD linker crashes if that corrected symbol replaces its raw input,
including when the synthetic symbol is removed or retains FUNC with size zero.
The complete generated object therefore remains the link input. The split rule
runs `tools/normalize_text_storage_v2.py` to write a separate reporting copy;
the unchanged normalization core performs the exact two-byte correction there.
Only that unit's native objdiff target points to the copy. Both objects have
identical section payloads, relocation contents and original global labels.
The copy is a declared split output and an explicit report dependency, so a
missing copy causes regeneration.

The native report still includes the original unclassified fallback unit and
its complete 44-byte .text section, without matching or source credit. The
report itself is never edited. Both native links must preserve every byte and
the original global label, and their complete function address/extent inventory
must equal the protected baseline's 8,803 entries. Original executable inputs,
expected hashes, other unknown units and all source payloads are preserved.

The isolated DTK probes, rejected object-classification alternatives, original
reference census, and independent review remain under
`scratch/game_anim_frame_gap_metadata_probe/`. Native linker control and crash
probes remain under `scratch/game_anim_frame_gap_native_probe/`. Both failed
checkpoints and their logs remain under `scratch/continuation_20261010/`.

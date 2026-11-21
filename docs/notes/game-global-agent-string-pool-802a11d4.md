# Global-agent and diagnostics string pool at 802A11D4

The prior original-only interval `802A11D4..802A17B0` contains 67 printable,
NUL-terminated strings in their original order. It includes event names,
audio diagnostics, and other game identifiers. The strings, the three-byte
alignment before them, two neighboring script-manager names, and the adjacent
208-byte diagnostic pool are now one compiler-owned `.rodata` section in
`src/Game/agent_header_names_802A0E78.cpp`. The full source extent is
`802A0E78..802A18A8` (2,608 bytes). It remains a partial data split; no
original code or complete translation unit is claimed.

GC/1.3.2 emits every byte and all 116 global objects at their original
addresses. Seventy objects lie in the transferred interval; the native ELF
preserves each name, size, binding and address. `symbols.txt` now records
their individual boundaries instead of the two broad provisional pool
objects. Internal zero alignment is compiler-generated; there are no source
padding arrays for the 67 new strings. `#pragma force_active` retains strings
without direct relocations. The three previously separate neighboring source
files are preserved in `scratch/game_global_agent_string_pool_20261020/`.

This transfer adds 1,510 matched data bytes: 1,500 from the original-only
string pool and ten from its former external alignment gaps. The measured
data denominator remains 1,030,936 bytes. The rebuilt DOL matches its
original SHA-1; `ninja changes` shows no regressions, the source extent audit
passes, and all 66 repository tests pass. The earlier
[agent-header handoff](game-agent-header-names.md) records its frozen smaller
boundary and does not itself claim this continuation.

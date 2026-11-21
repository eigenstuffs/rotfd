# Two related game/engine routines

`src/Game/fn_801AC7FC.c` reconstructs 444 bytes at
`0x801AC7FC..0x801AC9B8`. Both functions and all 14 relocations match with
GC/1.3.2, `-O4,p`, `-inline auto`, hardware floating point, and Gekko code
generation. The standard full-DOL build also passes the original SHA-1.
The original names and complete translation-unit boundaries remain unknown;
this is a partial text split with no owned data.

The first routine calls a descriptor helper, transfers two bytes into the
object's field at offset 4, and invokes a key-array loader on four 16-byte
headers. The second resolves a signed 8-bit tag and signed 24-bit index through
the descriptor's entry table, evaluates each nonempty array, and writes floats
at target offsets `0x120`, `0x11C`, `0xB8`, and `0xB4`. Invalid tags produce a
null target; the original code does not add a check before the subsequent
writes. Field and helper roles are inferred; offsets and emitted instructions
are verified. The key-array header layout is supported by the loader at
`0x801B2354` and evaluator at `0x801B0AA0`.

The registry is referenced through the existing label `lbl_801E9D24`, with the
descriptor at offset `0x118`. Declaring that location as an independent small
global incorrectly changes CodeWarrior's addressing mode. The source preserves
the observed aggregate access and leaves the registry outside this split.

Ghidra's historical output truncates the second function at the paired-single
floating-point save instruction. Its actual 300-byte symbol extent is verified
from the original DOL and generated assembly. The save/restore instructions
come from ordinary compiled C; no assembly replacement is used.

Reproduce the isolated check using the command in
`scratch/game_factory/match_1.3.2_c.txt`, then
`python3 scratch/game_factory/verify.py`. Build acceptance still requires
`ninja` and the original executable hash.

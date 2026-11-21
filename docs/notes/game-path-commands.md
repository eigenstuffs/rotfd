# Path and file console callbacks

`src/Game/path_commands.cpp` reconstructs four consecutive callbacks at
`0x802074F4..0x802077B4`: read/write mode selection, a manager load request,
project-name update, and root-path update. Field and class names describe the
observed operations; the original source names and wider TU boundary remain
unestablished.

The complete emitted TU verifies with GC/1.3.2 and the flags recorded in
`config/GSQE78/candidates/game-path-commands.json`: 704 text bytes, 39 rodata
bytes, 18 sdata2 bytes, and all 41 relocations have zero differences after real
relocation. Run `python3 scratch/game_path_commands/verify.py` to reproduce.
The verifier checks every allocated section, emitted alignment, and the
protected DOL SHA-1. The full DOL, native objdiff code/data checks and original-source regression audit pass.

The diagnostic strings occupy `.rodata` `0x802ADCC8..0x802ADCEF`; the read,
write, and separator strings occupy `.sdata2` `0x8037A968..0x8037A97A`.
Only compiler-emitted interior alignment bytes are included. Trailing bytes
through `0x802ADCF0` and `0x8037A97C` remain outside this candidate. The global
state located at `0x801E9D24` remains an external dependency in original storage.

The manager's virtual pointer is at offset 0x24 and load method at virtual
offset 0x24. Signed read/write bytes are at 0xC8/0xC9. A boolean comparison
and cached manager pointer reproduce the conversion and store sequence. In
the path callback, caching the path after resolution and using a signed-char
value cast reproduce the indexed load and final-separator removal. The source
uses ordinary C++ calls and a native virtual dispatch, with no assembly,
instruction patching, or ignored relocation differences.

The earlier nine-byte near match remains in
`scratch/game_path_commands/nine_differences.cpp` for compiler evidence; it is
not used or credited by the candidate.

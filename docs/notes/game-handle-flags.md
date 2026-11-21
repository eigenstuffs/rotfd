# Handle registry flag access

`src/Game/handle_flags.cpp` reconstructs the two adjacent flag accessors:
`fn_801F8C88` at `0x801F8C88..0x801F8CF0` (104 bytes) and
`fn_801F8CF0` at `0x801F8CF0..0x801F8D50` (96 bytes).

Each extracts the signed 24-bit handle index and signed eight-bit generation.
It checks the original upper index bound and compares the record generation at
byte 12 of a 16-byte entry. There is no additional nonnegative-index test.
The getter returns byte 13 of a valid record, or zero; the setter updates that
byte only for a valid record. These operations support the already recovered
root-object once-only guard. The record's complete meaning remains provisional.

The source preserves the indexed byte accesses and integer validity temporary
also established in the root object's name update. Neither method references an
external symbol or owns data. GC/1.3.2 with the recorded normal Gekko flags and
`-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on` emits exactly 200
allocated text bytes, two strong global functions and zero relocations.
`python3 scratch/game_handle_flags/verify.py` compares every emitted byte against
the protected original DOL and checks the complete section/function extents.
The strict result is zero differences, with no unused helpers or padding.
The candidate is `config/GSQE78/candidates/game-handle-flags.json`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 200/200 code bytes and 2 matching functions;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.

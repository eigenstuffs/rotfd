# Group capacity query

`src/Game/group_capacity.cpp` reconstructs `fn_801FF9C8` at
`0x801FF9C8..0x801FFA58`: 144 code bytes, one function, zero owned data.
The private field names in the shared view are provisional. The routine begins
with four available entries, resolves every group handle, and subtracts the
integer at object offset `0xE0` when the object exists and its signed offset
at `0xE4` is nonnegative. It returns the remaining count without clamping.

The global manager pointer is captured once before the loop; its resource table
and each group handle are read on each iteration. This ordinary local reproduces
the original register allocation. An otherwise equivalent expression repeatedly
naming the global manager produced a register swap in nine bytes. Both forms
were preserved in the private scratch directory; only the exact version is
accepted. No shared header was changed.

Run `python3 scratch/game_group_capacity/verify.py`. GC/1.3.2 with the recorded
`-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on` flags emits exactly
one strong global function and one 144-byte allocated text section. The strict
probe applies both real relocations, checks all allocated bytes against the
protected original DOL, and finds zero differences. No weak helper, literal,
BSS, metadata or alignment tail is claimed. The acceptance manifest is
`config/GSQE78/candidates/game-group-capacity.json`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 144/144 code bytes and 1 matching function;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.

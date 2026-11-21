# Occupied record release

`src/Game/record_pool_release.cpp` reconstructs the complete, integrated 168-byte `fn_80209DF8` at `0x80209DF8..0x80209EA0`. The accepted incoming `record_pool_internal.h` is included unchanged; the three bitset helpers are local to this source.

The method tests the requested slot's occupancy bit. An occupied slot invokes the native record destructor, clears that bit, decrements the live count and returns one; an unoccupied slot returns zero. The reconstruction preserves the original lack of a new bounds check, the 168-byte record stride, and the native destructor calling convention.

The previous `clear_store.cpp` candidate already had the correct 168-byte extent and complete cleanup sequence. Its remaining differences were the early mask/index calculation and word-pointer load ordering. The matching source combines a const word-reference accessor with a local base pointer:

```cpp
static inline const u32& occupiedWord(const BitSet_80207EE8& occupied, int index) {
    const u32* base = occupied.data;
    return base[index];
}
```

Returning a reference through this local base reproduces the original pointer load before the masked-bit calculation. Returning a value changes that ordering. The occupancy test keeps its ordinary `condition ? 1 : 0` signed-byte result, preserving the original boolean-materialization instructions. Clearing keeps the previously established local mask, word load, `word &= ~mask`, and store. No compiler switches, assembly, register bindings, artificial dependencies or binary patches are added.

`python3 scratch/game_record_release/verify.py` checks the original DOL SHA-1, the exact retained strong function, every allocated output byte, and the single actual ELF relocation to `__dt__15Record_80209EA0Fv` at `0x80209EA0`. Result: **168 code bytes, one relocation, zero differences**. The object contains only the retained `.text` and emits no data, BSS, metadata, padding or unused helper bodies. It references no external data. The relocation is recorded in `scratch/game_record_release/relocations.json`.

The compiler remains `GC/1.3.2` with the established Gekko `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on` game flags. The candidate is `config/GSQE78/candidates/game-record-pool-release.json`; it records the unchanged shared-header hash. `scratch/game_record_release/full_word_ref.cpp` also preserves the accessor in the original four-function scratch context: diagnostic comparison retains all 257 instructions across the four functions, including the already exact pool destructor and record lifecycle. That diagnostic check is separate from the strict relocated-byte acceptance of this 168-byte unit.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 168/168 code bytes and one exact function,
with zero owned data. The source-section extent guard and generated progress
checks pass. Together with the adjacent accepted pool destructor and record
lifecycle, the four routines now cover 1,028 exact code bytes. The documented
baseline accounting corrections remain preserved.

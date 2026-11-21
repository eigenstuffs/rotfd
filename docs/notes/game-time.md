# Game timing

`src/Game/time.cpp` reconstructs two contiguous routines at `801F45D8..801F4728`, with all 336 text bytes, 40 bytes of float/double literals at `8037A740..8037A768`, and 16 relocations verified exactly. Full-DOL SHA1 and native objdiff code/data integration pass. Original class and method names and the full source-unit extent are not claimed.

The first routine converts `OSGetTick` to seconds using the bus clock at the SDK hardware address `0x800000F8`. It preserves the original intermediate milliseconds division and subsequent division by 1,000. The second routine updates a previous-milliseconds field at object offset `0x218` and returns a frame delta in seconds. A nonzero fixed-step value at `0x214` advances the timestamp by `1000 * fixedStep / 60`; otherwise the routine reads the hardware clock. Negative or greater-than-half-second deltas become `1/30` seconds. The integer conversions and ordering are retained exactly.

The volatile read represents the actual SDK hardware clock field. All emitted conversions and floating-point operations are ordinary C++; no instruction intrinsics, assembly, or binary patches are used. GC/1.3.2 with the file group's O4,p, inline-auto and bool-off flags reproduces the complete object, including its literal-pool order and double conversion biases.

`scratch/game_file_io/verify.py time` checks the original SHA1, all allocated sections, complete function coverage and every relocation. The proof transcript is `scratch/game_file_io/time_verification.txt`, and the integration manifest is `config/GSQE78/candidates/game_time.json`.

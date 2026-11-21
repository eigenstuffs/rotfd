# Dolphin SDK audio system initialization

`src/dolphin/os/OSAudioSystem.c` reconstructs both original C functions: `__OSInitAudioSystem` at `0x800F1F94` (444 bytes) and `__OSStopAudioSystem` at `0x800F2150` (216 bytes), ending at `0x800F2228`. The unit also owns the complete 128-byte DSP bootstrap at `.data` `0x802C9958..0x802C99D8`.

The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSAudioSystem.c) supplies the matching initialization algorithm and bootstrap. The hardware registers use the SDK's Metrowerks absolute-address declaration, `volatile u16 __DSPRegs[] : 0xCC005000`, documented in the referenced `hw_regs.h`; a constant pointer macro changes register allocation and does not match.

The original DSP handshake waits for the high mailbox word, consumes the low word, and validates the combined message against `0x80544348U`. Expressing that direct comparison reproduces the compiler's preserved 16-bit temporary and matches every instruction. The reference's transformed arithmetic comparison and unrelated no-op workaround are not used. This reconstructs a meaningful mailbox validation expression while preserving the original release behavior, where the diagnostic assertion is disabled.

GC/1.2.5n flags are `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off`. `scratch/OSAudioSystem/verify.py` resolves all code/data relocations and compares directly against the DOL: `TEXT 660 660`, `.data 128 EXACT`. Both functions are C; no assembly substitution or unowned padding is counted. The candidate includes explicit local scope for `DSPInitCode`; whole-DOL SHA-1 remains the integration check.

Reference provenance and file hashes are retained in `reference/melee-sdk/PROVENANCE.md`.

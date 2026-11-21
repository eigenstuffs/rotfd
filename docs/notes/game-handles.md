# Engine reference handles

`src/Game/handle_access.cpp` recovers the object lookup and actual C++ default constructor at `801F7EB8..801F7F10`: 88 text bytes and two relocations. Every allocated section matches after relocation; no data or BSS is claimed. The native compiler is GC/1.3.2 with the Game flags recorded in `config/GSQE78/candidates/game_handle_access.json`. The central build passed the complete original DOL SHA-1 and native objdiff code/data checks.

`Handle_801F7F10` uses a four-byte packed representation with an eight-bit signed generation and a signed 24-bit slot index. Lookup compares the handle generation with the slot generation and returns the stored object only on equality. The default constructor clears the complete packed word, producing the original single store; separate bit-field assignments produce read/modify/write instructions. The actual constructor symbol is `__ct__15Handle_801F7F10Fv`, corresponding to the former `fn_801F7F04`. The destructor's canonical ABI name is `__dt__15Handle_801F7F10Fv`, as established by recovered caller lifetimes.

The source names and whole original translation-unit boundary remain unknown. The source view matches the observed ABI and does not claim complete original C++ class identity. Transcript: `scratch/game_handles/handle_access_verification.txt`.

## Shared lifetime recovery

`scratch/game_handles/handles_adjust.cpp` preserves the current complete ordinary C++ reconstruction of assignment (`801F7914`,928 bytes), copying (`801F7CB4`,516), destruction (`801F7F10`,516), ID export (`801F84D4`,500), and reference adjustment (`801F86C8`,484), alongside the two exact access routines. These retain the original sizes and control flow. Their last 28 byte differences are generation-byte load/sign-extension register choices, plus the destructor's initial context-base register. They remain original fallback and are excluded from matched progress.

The observed registry owns 16-byte slots containing an object pointer, name hash, two signed short fields, a generation byte, and an active byte. A short reference count wrapping to zero can trigger destruction when the registry's destruction flag is set. Cleanup removes the object's key, invokes its virtual destructor, resets its hash through `801F948C`, advances the generation while skipping zero, clears the pointer, and pushes the slot index onto the free stack. The free-stack array `operator[]` is necessary to preserve increment-before-pointer-load ordering. Declaring the shared empty name as an external one-byte array preserves the original small-data address instruction.

`Context::valid(const Handle&)` preserves the separate inline scope needed for the second assignment cleanup's saved-register allocation. Directly passing scalar index and generation parameters swaps two saved registers. All nearby candidates and compiler/source variants are durable under `scratch/game_handles`; no original bytes, assembly substitutions, or shared build configuration were changed.

The bounded `handle_access.cpp` candidate is now integrated: both source functions, all relocations and the full original DOL pass. The ordinary default constructor identity is `__ct__15Handle_801F7F10Fv` at `0x801F7F04`; existing callers retain the same instruction bytes. The lifetime/assignment candidates remain unregistered.


The adjacent pool growth and activity accessors at `801F88AC..801F8D50` are also reconstructed in durable scratch. `pool_indexlong.cpp` retains the closest 988-byte growth body with 34 differing bytes in the final unrolled free-stack fill loop; the 104-byte activity getter and 96-byte setter each retain the shared generation-byte discrepancy. These three are not promoted. Compiler version, optimization-level, local-type, accessor, declaration-order, and scope probes are preserved for comparison. The original slot allocation/resize/constructor portion of the growth body already matches completely.

## Pool setup and attachment

`src/Game/handle_pool_setup.cpp` recovers the two contiguous functions at `801F93FC..801F948C`: a 36-byte object-handle attachment wrapper and the 108-byte pool initializer. Both compile exactly, together with the complete 24-byte virtual table at `802EAAB8..802EAAD0`, after seven relocations. The initializer clears both typed dynamic-array headers, the free count and limit, enables automatic destruction, and requests the initial 16,384 slots. The wrapper delegates to the existing handle assignment function at `801F7914`.

The partial class ABI is represented explicitly; the original class identity and complete translation unit remain unknown. The table's three function pointers, two leading null fields and trailing null field are preserved as ordinary C++ data. Strict isolated validation is saved in `scratch/game_handles/handle_pool_setup_verification.txt`; central full-DOL integration, native objdiff source checks, and the original-source regression audit pass.


## Copy continuation, 2026-10-15

`src/Game/native_handle_copy_801F7CB4.cpp` now reconstructs all 516 bytes of the
copy entry with its original GLOBAL identity and all four actual code
relocations. It uses the already verified manager validity and reference
adjustment structure. Its adjacent 928-byte assignment remains original
assembly. The strict proof preserves the full former 1,444-byte provider and
nine calls across six complete caller functions. Both native links and all
acceptance checks pass; see
`scratch/continuation_20261012_b/world-record-copy-acceptance.json`.

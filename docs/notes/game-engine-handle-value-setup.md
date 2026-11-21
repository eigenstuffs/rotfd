# Handle value construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five bounded routines recover 524 text bytes and 200 EH/index bytes with GC 1.3.2 and established container-base flags. All actual relocations, emitted allocations and symbols are strictly verified. No table/global ownership or accepted source/header changes are proposed.

Three existing C entries are ordinary nontrivial Handle-valued getters. The compiler supplies the original hidden return pointer rather than treating the first register as an ordinary explicit parameter. They return a `Copy` value whose inline constructor initializes its native Handle base, copies the source word, and calls retain(manager, &source, 1). 800312D4 (80 bytes) reads the member at owner offset 0x60 and has the native base Handle_801F7F10. 8004A6C8 (100) reads the same offset after four zeroing layers, with native Handle_8004A72C cleanup. 800BCEF8 (96) reads the source Handle pointer at scene offset 0x15054 after two zeroing layers, with native Handle_80020834 cleanup. Private layouts record only observed offsets. Existing C entry names are preserved.

80040920 and 80040B14 (124 bytes each) are native copy-constructor shapes: eight default zeroing layers with native Handle_8004099C base cleanup, followed by word copy/retain and the constructor's native self-pointer return. They have no accepted source/header callers under their old C names. The proposed guarded migrations are fn_80040920 to __ct__19HandleCopy_80040920FRC15Handle_801F7F10 and fn_80040B14 to __ct__19HandleCopy_80040B14FRC15Handle_801F7F10. These provisional private class names describe the observed operation without assigning an unknown original class name. Their exact original-symbol mappings are in the frozen function manifest and require root guarded integration. All original fallback callers/table references continue to target the same addresses.

Intermediate zeroing-layer destructors are declared-only and do not become undefined dependencies unless actually referenced; only the original native base destructor appears in each retained EH record. No helper code or metadata is emitted. The full original extabindex/ctors/dtors registration tables are audited; each routine owns its original 28-byte extab plus twelve-byte index, and no registration entry is transferred. These are bounded fragments; final original DOL hash acceptance remains required for credit.

8006C620 remains a separate uncredited temporary-Handle investigation until its destructor lifetime and any genuine weak override metadata are completely verified.

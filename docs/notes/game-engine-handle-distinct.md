# Engine distinct-handle dispatch

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/engine_handle_distinct.cpp` reconstructs the complete 432-byte ordinary
C++ routine `fn_802459DC`, at `802459DC..80245B8C`, with global scope. It uses
standard Game GC/1.3.2 options plus `-use_lmw_stmw on`. The dedicated new header
is `include/Game/engine_handle_distinct.h`; no existing shared declaration changes.

The owner stores signed count at 0x20 and packed-handle array at 0x28. If its
count is nonzero, the routine resolves the first handle and dispatches virtual
slot 0x24 with the supplied argument. Starting at index one, it resolves each
adjacent pair. When the two object pointers differ and the current handle passes
existing validity function 801F7EB8, it resolves the current handle again and
dispatches slot 0x24. Consecutive handles resolving to the same object are skipped.
The first dispatch follows the native unconditional behavior.

Handles contain signed eight-bit generation and signed 24-bit index fields.
The context's manager at 0x118 points to 16-byte entries through offset 8. An
entry stores object at zero and signed generation at 0xC. The ordinary inline
resolver retains logical index and generation accessors; the adjacent comparison
helper preserves first-then-second resolution. A separate inline apply helper
for the initial handle reproduces the original initial register allocation.
All helpers inline completely. Declaration-only C++ virtual methods place the
vptr at offset 8 and emit no table or definitions.

`scratch/engine_handle_distinct_20261010q/final_integration.json` records full
extent, binding, flags and all three actual address relocations. Fresh production
compilation and strict verification pass: every relocated byte equals the
protected original DOL without masking; additional functions and unexpected
allocated sections are rejected. The original whole-function extent and full
3,141-entry extabindex, 24-entry ctor, and 8-entry dtor scans pass with no
references to this function. Source data, BSS, exception and startup ownership
are zero. Original context data, callees, neighboring text and other original
sections retain their current owners. Central NonMatching registration and
final DOL/native regression acceptance remain the integrator's promotion steps.
Private near-matches and all diagnostic artifacts remain preserved and uncredited.

# Engine path and handle dispatch fragment

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/engine_handle_paths.cpp` reconstructs the two adjacent complete
functions `fn_8023ADB8` (128 bytes) and `fn_8023AE38` (204 bytes). Its text-only
split is `8023ADB8..8023AF04`, totaling 332 bytes with no owned data. It uses the
standard Game GC/1.3.2 flags without additions. Both original symbols require
global scope. The dedicated declarations in `include/Game/engine_handle_paths.h`
do not change any existing header.

Both routines check the argument context's count at offset 0x860, requiring at
least two entries. They copy its path at 0x868 into a 128-byte local buffer,
append the original five-byte suffix object `lbl_8037B30C`, and call the original
path-preparation operation `fn_801F459C`. The first dispatches device virtual
slot 0x4C. The second initializes two empty typed handle temporaries through the
original base constructor and two observed packed-word clears, dispatches slot
0x48 with mode 2 and those temporaries, and destroys them in reverse order using
the original destructor. Both return 1 after dispatch and 0 for the count guard.
The source preserves these observed operations and buffer size.

The global argument and device pointers are at context offsets 0x110 and 0x158.
The observed device interface's virtual pointer is at 0x7C. Declared virtual
methods have no bodies; no replacement tables or methods are emitted. Handle
initialization inlines completely and generates no additional helper function.
The original suffix, manager/device context, constructors/destructor, and all
neighboring functions and data keep their existing owners. This partial text
split does not establish an original translation-unit boundary.

`scratch/engine_handle_list_20261010h/final_integration.json` records all complete
function bounds, symbol bindings, compiler options, and 20 real relocations.
The strict verifier recompiles the formatted production source, rejects extra
allocated sections/functions, applies all REL24/HA/LO/SDA21 relocations to their
versioned targets, and compares every owned byte directly to the protected DOL
without masking or instruction substitution. Both `verify.py` and `audit.py`
pass. Original assembly verifies both full function extents; the complete
3,141-entry `.extabindex`, 24-entry `.ctors`, and 8-entry `.dtors` scans find no
references into this text. The source owns no exception, startup, data, or BSS
bytes. Central NonMatching registration and original DOL/native comparison
acceptance remain the integrator's promotion steps.

The directory name records the original list-iteration research. The list
loops `fn_8023A9FC`/`fn_8023AAAC` and indexed wrappers `fn_8023B35C`/`fn_8023B418`
retain instruction differences in their private probes. Alternate typed forms
also change emission order. These artifacts are preserved and earn no source
credit; only the two path functions are in the production manifest.

The later dedicated genuine-lifetime source for `fn_8023B35C` is accepted at
[Indexed device dispatch](game-indexed-device-dispatch.md). The earlier private
C ABI probes remain untouched. Its adjacent `fn_8023B418` still differs in six
stack-slot instructions and remains outside matching source.

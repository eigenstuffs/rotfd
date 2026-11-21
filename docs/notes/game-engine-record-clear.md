# Engine record flag reset

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/engine_record_clear.c` reconstructs the complete 332-byte ordinary C
function `fn_8024A6B4` at `8024A6B4..8024A800`, using standard Game GC/1.3.2
options without additions. It requires global scope. Its dedicated new header
is `include/Game/engine_record_clear.h`; no shared existing declarations change.

The routine resolves each packed handle in the owner's array at 0x6C with count
at 0x64. For each resolved object, it clears bit 2 in the flags word at 0xC and
walks the corresponding 12-byte row from the owner's row array at 0x78. Each row
contains signed count, capacity, and an integer-index pointer. Each index selects
a packed handle from the target array at owner offset 0x28; resolving that
handle yields the node whose flag 0x1000 at 0x120 is cleared. After both loops,
the routine calls existing `fn_8024A120` with the original six-byte `HIDE_` prefix
object `lbl_8037B438` and mode zero, then existing `fn_8024C5D4`.

Handle resolution uses the original context manager at 0x118, its entry pointer
at 8, and 16-byte entries with object pointer at zero and signed generation byte
at 0xC. Packed handle generations are signed 8-bit values and indices signed
24-bit values. The row-processing helper is ordinary inline C and emits no
additional function. Separating that logical row operation preserves the native
inner-loop register allocation, which differed in the initial direct-loop probe.
The original prefix, manager/context data, callees, neighboring text, and
translation-unit data retain their existing owners.

`scratch/engine_record_clear_20261010n/final_integration.json` records the full
extent, symbol binding, flags, and all five actual REL24/HA/LO/SDA21 relocations.
Fresh production compilation and strict verification pass: every relocated
byte equals the protected original DOL without masking, and extra functions or
unexpected allocated sections are rejected. The original extent and complete
3,141-entry extabindex, 24-entry ctor, and 8-entry dtor scans pass with no records
referencing this text. Source data, BSS, exception, and startup ownership are
zero. This is a partial text split; central NonMatching registration and
original DOL/native regression acceptance remain the integrator's promotion
steps. All private probes remain preserved and uncredited.

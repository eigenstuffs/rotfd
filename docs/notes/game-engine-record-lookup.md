# Engine numbered-name and key lookup

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Two text-only source fragments reconstruct three complete ordinary C functions:

| Source | Complete functions | Text range | Bytes |
| --- | --- | --- | ---: |
| `src/Game/engine_record_lookup_names.c` | `fn_8024A094`, `fn_8024A120` | `8024A094..8024A1AC` | 280 |
| `src/Game/engine_record_lookup_key.c` | `fn_8024A86C` | `8024A86C..8024A934` | 200 |

Both use standard Game GC/1.3.2 flags plus `-use_lmw_stmw on`. All three symbols
require global scope. They total 480 text bytes, zero data bytes, and 11 actual
relocations. `include/Game/engine_record_lookup.h` is a dedicated new header.

The first two routines format names for suffixes 01 through 16 using the
original seven-byte `%s%02d` format object `lbl_8037B430` and a 128-byte stack
buffer. Each initializes a four-byte key through existing `fn_801F948C`, calls
existing `fn_8024A1AC` or `fn_8024A430` with that key and the input mode, and
returns the number of nonzero signed-byte results. Declaring the external format
object's observed size preserves native SDA21 addressing; an unbounded array
declaration produces different address materialization and register allocation.
No replacement string data is emitted.

The key lookup walks the owner's packed-handle array at 0x6C with signed count
at 0x64. For each handle accepted by existing `fn_801F7EB8`, it resolves through
the original context's manager at 0x118 and compares the resulting object's key
word at offset zero to the input key. The packed handle carries a signed 8-bit
generation and signed 24-bit index. Manager entries are 16 bytes with object
pointer at zero and signed generation byte at 0xC. The routine returns the first
matching index or -1. An ordinary inline key comparison preserves native
operand-load order and emits no extra helper.

`scratch/engine_record_lookup_20261010l/final_integration.json` records complete
bounds, symbol bindings, compiler flags, and all real relocations. Final
production recompiles pass strict verification: all allocated sections and
function definitions are accounted for, all REL24/HA/LO/SDA21 relocations are
applied to their versioned targets, and every owned byte equals the protected
DOL without masking. `audit.py` confirms complete original assembly extents and
scans all 3,141 original extabindex entries, 24 ctor entries, and 8 dtor entries,
with no references into these extents. Source data, BSS, exception, and startup
ownership are zero. Original format, manager/context data, neighboring functions,
and translation-unit data retain their existing owners. Central NonMatching
registration and original DOL/native regression acceptance remain the
integrator's promotion steps.

Private row-index lookup `fn_8024A800` retains counted-loop and instruction
allocation differences; its variants are preserved and uncredited. The separate
`fn_8024A6B4` is only inventoried, not included. Only the three complete functions
listed above enter this handoff. No frozen previous source or shared central
configuration was modified.

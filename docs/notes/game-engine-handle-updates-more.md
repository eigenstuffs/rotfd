# Additional engine handle updates

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Three complete ordinary C++ routines reconstruct 1,236 text bytes in independent
partial text splits. They use standard Game GC/1.3.2 flags without additions:

| Source | Function | Original text |
| --- | --- | --- |
| `src/Game/engine_handle_update_pair.cpp` | `fn_8020EC48` (272 bytes) | `8020EC48..8020ED58` |
| `src/Game/engine_handle_update_fixed.cpp` | `fn_80211300` (520 bytes) | `80211300..80211508` |
| `src/Game/engine_handle_update_triple.cpp` | `fn_8022AE2C` (444 bytes) | `8022AE2C..8022AFE8` |

All functions require global scope. The dedicated new header is
`include/Game/engine_handle_updates_more.h`; no existing declarations change.
Each routine first calls the existing root predicate at 80207414, returning
zero on its false signed-byte result. A successful routine dispatches virtual
slot 0x1C on resolved handles and returns one.

The pair routine visits handles at owner offsets 0x20 and 0x28, each guarded
by existing validity function 801F7EB8. The fixed routine visits individually
guarded handles at 0x44 and 0x50, three guarded handles at 0x54, then the guarded
handle at 0x48. This observed order is preserved. The triple routine visits
three dynamic arrays whose counts are at 0x2C, 0x60 and 0x6C and pointers at
0x34, 0x68 and 0x74; it directly resolves and dispatches each element. The shared
logical index variable preserves native allocation across those three loops.

Packed handles have signed eight-bit generation and signed 24-bit index fields.
The original context manager at 0x118 holds 16-byte entries via its pointer at
8; entries contain object pointer at zero and signed generation byte at 0xC.
The ordinary inline resolver compares generations and yields object or null.
Declaration-only virtual methods place the vptr at offset 8 without emitting
methods or tables. Original context data, callees and neighboring sections retain
their current owners.

`scratch/engine_handle_updates_more_20261010s/final_integration.json` records
full extents, bindings, flags and all 21 actual address relocations. Fresh
production compilation and strict verification pass: every relocated byte
equals the protected original DOL without masking, and extra functions or
unexpected allocated sections are rejected. Complete original extents and full
3,141-entry extabindex, 24-entry ctor and 8-entry dtor scans pass with no records
referencing the selected text. Source data, BSS, exception and startup ownership
are zero. Central NonMatching registration and final DOL/native regression
acceptance remain the integrator's promotion steps. All research artifacts are
preserved.

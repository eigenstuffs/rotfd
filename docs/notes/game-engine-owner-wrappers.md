# Owner flag and forwarding wrappers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Nine complete ordinary C/C++ functions match 628 bytes of original GSQE78 text in isolated production-source verification. All units are text-only, global, and compiled with standard GC/1.3.2 flags without additional options. Central full-DOL acceptance is still required before progress credit.

| Function | Text range | Bytes |
| --- | --- | ---: |
| `fn_8021E8B8` | `8021E8B8..8021E8FC` | 68 |
| `fn_80224B34` | `80224B34..80224B74` | 64 |
| `fn_80227F4C` | `80227F4C..80227F98` | 76 |
| `fn_8022A160` | `8022A160..8022A1A0` | 64 |
| `fn_8022D1D8` | `8022D1D8..8022D218` | 64 |
| `fn_8022D218` | `8022D218..8022D264` | 76 |
| `fn_8022D264` | `8022D264..8022D2B0` | 76 |
| `fn_80230700` | `80230700..80230740` | 64 |
| `fn_80230978` | `80230978..802309C4` | 76 |

Sources are `src/Game/engine_owner_wrapper_<address>.c`, except the genuine C++ virtual forwarder `engine_owner_wrapper_8021E8B8.cpp`. Dedicated declarations are in `include/Game/engine_owner_wrappers.h`. The bitset wrapper includes the existing `Game/engine_bitset_find.h` unchanged.

`8021E8B8` forwards a record's link, the record itself, its 64-bit mask, and an additional argument through virtual slot 0x64, then returns 1. Genuine C++ virtual dispatch reproduces the original r12/CTR sequence. The 64-bit argument's ABI alignment also reproduces the original register gap and final argument in r9; no manual register or assembly code is used.

`80224B34` searches from the next index if it remains below the outer count, calling the existing exact bitset finder for a set bit. `80227F4C` invokes the existing owner operation and resets four float fields from their original constants. `8022D1D8` resets the base owner, selects category 4, and clears a word. The remaining wrappers invoke an existing operation and update a 64-bit flags field with ordinary `|=` or `&=` expressions. These expressions preserve the native two-word mask lowering where present.

The frozen handoff is `scratch/engine_owner_wrappers_20261010au/final_integration.json`, with generated split/config/scope instructions, strict verifier, original ownership audit and SHA256 frozen-file map. Fresh compilation requires exact whole text sections and function bindings, rejects every unexpected allocation, applies all 13 real REL24/SDA21 relocations, and compares all emitted bytes to the original DOL. There are zero emitted or owned data bytes, extra functions, exception records, or startup records.

Full raw table scans cover extabindex `80015F60..8001F2C0` at stride 12 (3,141 records plus descriptor and trailing padding), ctors `80299920..80299980` at stride 4 (24 slots), and dtors `80299980..802999A0` at stride 4 (8 slots). No entry refers to these retained ranges. All original neighboring functions, tables, constants and startup/exception ownership remain with existing units. The audit records original unit allocation ranges.

The additional private probe `fn_80224BB4` remains uncredited: native 68 bytes versus current 64. Its first 44 bytes match, but the compiler selects a branchless 0/1 conversion instead of the original two-return control flow. Signed/unsigned/int/bool/local/if-else and bounded option probes are preserved; no production source or split was created for it.

Validation: current production recompilation and strict actual relocation, binding, section extent and allocation comparison passed for all nine functions, 628 text bytes and zero data. Full raw ownership scans passed. No shared metadata or build configuration was edited in this handoff.

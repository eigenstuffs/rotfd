# Owner and indexed-record flag controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `scratch/engine_owner_flag_controls_20261011ex/final_integration.json`.

Four ordinary C++ units reproduce six complete original functions, totaling 340 text bytes:

| Source | Original range | Functions | Bytes |
| --- | --- | --- | ---: |
| `engine_owner_flag_mask.cpp` | `8021F208..8021F23C` | `fn_8021F208` | 52 |
| `engine_owner_flag_queries.cpp` | `8021F2D0..8021F340` | `fn_8021F2D0`, `fn_8021F308` | 112 |
| `engine_owner_flag_position.cpp` | `8021F568..8021F59C` | `fn_8021F568` | 52 |
| `engine_indexed_flag_controls.cpp` | `80224B7C..80224BF8` | `fn_80224B7C`, `fn_80224BB4` | 124 |

The mask wrapper calls virtual slot `A8` with the two original word arguments, `0x100000` and zero. The position wrapper forwards its third incoming argument to virtual slot `BC` with a zero second argument. The shared partial owner view places its vtable at `+8` and flags at `+30`. The virtual declarations describe only the observed calling interfaces; their bodies and original tables remain external.

The two owner queries test flag bits 2 and 1. An explicitly assigned signed-char result with both `if` and `else` arms reproduces the original branch and immediate-return blocks. A direct `if` followed by `return 0` instead produces a branchless boolean conversion and is not equivalent at the instruction level. The indexed pair clears or tests a supplied 64-bit mask in the flags at `+38` of an `A8`-byte record. Byte-backed storage expresses the original `index * A8 + 38` address calculation; a typed array folds the field offset into loads and does not match.

Production GC/1.3.2 compilation uses ordinary Game `-O4,p`, exceptions off, plus `-use_lmw_stmw on`. All four emitted objects contain only the retained `.text`; no initialized data, BSS, weak helpers, exception records, startup entries, or actual ELF relocations are emitted. Strict verification compares every allocated byte and every nonzero symbol extent. The full original `80015F60..8001F2C0` exception-index allocation, `80299920..80299980` constructor allocation, and `80299980..802999A0` destructor allocation have no references to these ranges, including complete descriptor/padding scans.

This is a partial text-only split. Adjacent functions, original vtables, and all original data allocations keep their existing owners. Existing global C entry spellings remain unchanged; there are no consumer or central metadata edits in this handoff. Root must register these four sources NonMatching and complete native build/hash acceptance before progress credit.

Evidence: `allocation_audit.json`, `original_full_tables.json`, `verify.py`, production objects, original assembly copies, and the earlier isolated source variants remain in the scratch namespace. The earlier contact-selection investigation remains separate and uncredited in `scratch/engine_related_contact_select_20261011ew/`.

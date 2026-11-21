# Engine record copies, retained detach, and image output

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `scratch/game_engine_record_output_continuation/final_integration.json`.
Four ordinary C++ sources reproduce **1,084 original text bytes**, no data, and **26 actual retained relocations**. Production recompilation passes strict byte/relocation checks. All source SHA256 values and recursive quoted-header inventories (empty) are frozen. Central native integration/full DOL acceptance remain the integrator's responsibility.

| Function | Text bytes | Actual relocations | Behavior |
| --- | ---: | ---: | --- |
| `fn_801C0E40` | 244 | 1 | Builds the same transformed 0x58-byte result established by the earlier BCaa0 record-transfer recovery, then assigns all observed fields into a 0xA8-byte indexed slot at owner+0x188, result offset +0x50. |
| `fn_801C4BC4` | 180 | 9 | For a nonnegative owner index at +0x5C, retains a temporary copy of the identity handle at +4, detaches it from the corresponding 0x4C-byte viewport, destroys the temporary, then resets the owner. |
| `fn_801C6C94` | 332 | 3 | Resolves owner handle+0x44, resets the owner, then walks the resource's 0x14-byte index records and follows two more handles to set bit 0 of each target's flags at +0xC. |
| `fn_801C932C` | 328 | 13 | Opens a file for writing, emits an 18-byte uncompressed image header, writes width-sized pixel rows, flushes/closes, and destroys the file object. Open failure logs the original message and destroys the file. |

The record assignment uses explicit scalar float/vector members, pointer words and the observed 64-bit flag member. The native image-file object is the established 23-word/0x5C-byte view from accepted file I/O and console sources. Its header stores width/height low and high bytes, caller pixel depth and descriptor 0x20; row bytes are `width * (bits >> 3)`. The original field accesses, integer arithmetic and branch behavior are preserved.

The detach source uses the actual `Handle_801F7F10` native constructor/destructor, two ordinary zero-initializing layers and a retained copy constructor. An explicit reference to the owner's identity is evaluated before constructing the copy, preserving its original saved address and register allocation. Its object emits **three unreferenced weak destructors totaling 264 bytes and six actual relocations**. Each exact weak symbol, binding, offset, size and raw SHA256 is separately recorded in `unlinked_functions`; each unused relocation is explicit. These bytes receive no source credit and **all three weak symbols must be absent from the final ELF**. Retained code has no references to them. Other units emit no helpers or extra allocations.

All units use standard GC/1.3.2 flags; image output additionally uses `-use_lmw_stmw on`. Exact source splits and configuration proposals are in `final_splits.txt` and `final_config.txt`. All original externally referenced names remain fixed.

These are documented partial text splits. The original fragments own no data, and complete extabindex/constructor-table scans found no metadata for any retained function. Functions outside the retained splits remain in their original assembly ownership: C0E40's original fragment continues with C0F34 and C109C; C4BC4's fragment contains the remaining draw/update routines; C6C94's fragment retains its surrounding setup/update routines; C932C's fragment continues with C9474 and its small following routine. `ownership_audit.json` records their exact complete original ranges and retained function extents.

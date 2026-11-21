# Early resource assignment and setup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The two partial source units recover `fn_80061DD8` (252 text bytes) and `fn_80061F0C` (652 text bytes), using GC/1.3.2 with `-O4,s -Cpp_exceptions on`. Strict isolated verification proves all 904 retained text bytes and 200 retained exception/index bytes, with actual relocation resolution. Central native-link acceptance remains pending.

The assignment routine obtains a genuine by-value raw Handle from `fn_801B52EC`, constructs the one-clearing-layer typed copy, assigns it to the resource handle at 0x1F4 with native release/copy/retain operations, and destroys both temporaries at the full-expression boundary. It then clears the script at 0x60, invokes virtual slots 0xD8 and 0xDC with zero arguments, and sets bit 39 of the owner's 64-bit flags at 0x38. The compiler reproduces the original 76-byte EH record, including both simultaneous temporary cleanup paths.

The setup routine uses three copied resource handles as separate full-expression temporaries. It binds the input owner to the resource through `fn_802001D4`, gives the resolved resource the owner's handle at 0x58 through virtual slot 0x84, and clears bit 9 of the resolved resource's 64-bit flags at 0x30. An inline helper accepting the third temporary reproduces the native stack ordering (0x10, 0x0C, 0x08). A named third temporary rotates the three stack slots despite otherwise identical code.

Setup then sets owner flag bit 17, invokes virtual slot 0x34, allocates an 0x8C-byte callback record with the original heap/debug labels, and initializes the observed record view. The callback vtable at 0x802B60F0 and duration literal at 0x803786D8 stay external. The initialization helper reproduces the native register reuse in the 30-pointer clearing loop. The callback view establishes observed fields only; it neither claims a recovered callback class identity nor introduces a compiler-generated vtable.

Retained EH function pointers refer to compiler-defined weak native Handle destructors. The adopted bounded override audit verifies accepted strong owners and resolves two retained EH references for the assignment routine (Handle_80021C40 and Handle_80021BCC) and five for setup (Handle_80021BCC and Handle_80021B54). All actual local EH/index names, initialized bytes, relocations and emitted allocated extents are frozen. The assignment emits 228 uncredited weak text bytes plus 104 backup EH/index bytes; setup emits 348 plus 156. These backups must be discarded by the final native link and receive no progress credit.

The full original extabindex, constructor-array and destructor-array ranges are audited. There are no startup/shutdown pointers, literal allocations, BSS, or padding allocations. Original text padding 0x80062198..0x8006219C and exception bytes 0x8000B394..0x8000B39C remain outside these partial units.

Manifests and recheck scripts: `scratch/game_early_resource_setup/manifest-list.json`. Handoff: `scratch/game_engine_batch86/HANDOFF.md`.

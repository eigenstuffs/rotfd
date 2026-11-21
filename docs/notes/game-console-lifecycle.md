# Console lifetime and resource callbacks

`src/Game/console_lifecycle.cpp` reconstructs the four contiguous routines at `801FB1E8..801FB4B0`. All 712 retained text bytes and the complete 48-byte virtual table at `802EAF10..802EAF40` match the protected original after all 43 ELF relocations are applied. Strict isolated verification is recorded in `scratch/game_console_lifecycle/verification.txt`; the candidate manifest is `config/GSQE78/candidates/game_console_lifecycle.json`. Central full-DOL identity and native objdiff code/data checks pass; both unused inline helpers are normally dead-stripped.

| Routine | Bytes | Recovered behavior |
| --- | ---: | --- |
| `801FB1E8` | 236 | Console destructor: installs the observed table, destroys/releases line-array storage, and conditionally frees the object. |
| `801FB2D4` | 100 | Console constructor: initializes array storage, history indices, mode and selected counters/pointers. |
| `801FB338` | 68 | Prints the manager's handle count through the console logger. |
| `801FB37C` | 308 | Validates an argument, formats a `DB:>` TGA resource name, obtains a reference-counted handle, and passes a valid resource to the game's virtual picture-setting method. |

The source uses GC/1.3.2 with `-O4,p -inline deferred -use_lmw_stmw on`, read-only string pooling and disabled C++ exceptions/RTTI; the manifest records the complete flags. The shared callback messages already belong to `console_render.cpp`, so this unit owns no new string pool or padding. The virtual table retains its existing global identity and ten observed method relocations.

The console's line array occupies offsets `0xC..0x18` with eight-byte entries, and its virtual-table pointer is at `0xB10`. The typed array destructor naturally emits the original empty element-destruction loops and repeated storage null checks. The remaining unknown fields use offset-based names; their broader meaning is not asserted.

The resource callback uses the actual `Handle_801F7F10` constructor/destructor ABI. A nontrivial handle returned by the manager's virtual method uses the hidden result pointer at stack offset eight. A derived handle with one inline zero-initialization layer preserves the separate saved pointer, zero store and reference adjustment before destroying that temporary. Its automatic lifetime emits the original base-destructor calls on both success and failure. This extends the verified handle pattern from the adjacent script-interpreter callback, which requires two initialization layers.

Two unused local inline destructors totaling 172 bytes are emitted after the retained text. The verifier proves no retained allocated relocation references them and records their exact extents in the manifest for ordinary linker dead stripping; they earn no progress. No raw assembly, instruction patches, masked comparisons, volatile workarounds or original-byte changes are used. The original complete source-file extent and reconstructed type/method names are not claimed as recovered identities.

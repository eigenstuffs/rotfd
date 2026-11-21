# MSL/alloc.c

The complete retained allocator unit is reconstructed in `src/MSL/alloc.c`: ten functions and 3,560 code bytes at `0x80121104–0x80121EEC`. It contains the MSL `malloc` and `free` APIs, fixed-pool allocation and deallocation, fixed-block construction, variable-pool allocation and soft allocation, block splitting/search, block relinking, and next-block coalescing. Small requests use six fixed-size classes; larger requests use variable-size blocks.

The source names the APIs `__msl_malloc` and `__msl_free` because central symbols already use `malloc` and `free` for game wrappers at `0x8001F2C0` and `0x8001F35C`. Backing storage comes through the original hooks at `0x801EFC50` (`__sys_alloc`) and `0x801EFC24` (`__sys_free`). The separate custom game allocator is outside this candidate. No separate `realloc`, `calloc`, `__pool_realloc`, or `__pool_alloc_clear` body is retained in this unit; no placeholder implementations are supplied or counted.

The primary structural reference is the complete allocator reconstruction in [Strikers](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/alloc.c), cross-checked against the free-side reconstruction in [Wind Waker](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/alloc.c). These are community reconstructions, not an official MSL SDK source release. Unchanged reference files, their pinned revisions, and upstream license notices are preserved under `reference/strikers-msl/` and `reference/tww-msl/`. The Strikers notice distinguishes contributor-owned material from reconstructed third-party runtime material; no blanket relicensing is asserted here.

GSQE78 retains a standalone `FixBlock_construct` with arguments `(block, tail, head, class_index, first_subblock, usable_bytes)`. The linked Strikers implementation inlines the corresponding loop. Here ordinary C keeps the first-subblock pointer intact while a separate cursor walks the block. The target's `Block_subBlock` returns immediately when there is no available subblock; it does not clear the block's maximum-size field on that path. Small-allocation local declaration order and removal of a redundant class-table alias reproduce the original compiler register allocation. All other helpers that disappear through inlining remain ordinary C.

The source owns 81 data bytes: 24 initialized bytes and 57 zero-initialized bytes. The following seven alignment bytes are separate original storage and receive no source credit. The exact boundaries are:

| Section | Address range | Ownership |
| --- | --- | --- |
| `.rodata` | `0x802ABAD8–0x802ABAF0` | Six 32-bit class sizes: 4, 12, 20, 36, 52, 68 |
| `.bss` | `0x8033D350–0x8033D388` | The 56-byte function-local `protopool` |
| `.sbss` | `0x80377D08–0x80377D09` | The one-byte function-local initialization flag |
| External `.sbss` padding | `0x80377D09–0x80377D10` | Seven original zero alignment bytes; no source credit |

`protopool` reserves fourteen pointers (56 bytes), while initialization clears the 52-byte internal pool object. Both sizes are intentional. The initialization flag is already correctly sized at one byte. The padding audit found that the source split still included the seven bytes following it. The corrected source split ends at `0x80377D09`; the separate original padding retains `gap_10_80377D09_sbss`, with explicit symbol and split alignment of one byte. Compiler-generated local suffixes are recorded in the manifest and do not imply original source names.

The preceding routine is `abort`, part of `abort_exit.c`. The routines beginning at `0x80121EEC` operate on stdio state and form the next retained unit. Those boundaries are supported by the complete source order, retained calls, section sizes, and exact relocated comparison.

Run `python3 scratch/msl_alloc/verify.py` to compile with GC/1.3 and `-O4,p -inline deferred -pool off -use_lmw_stmw on`; the manifest contains the full flag list. The verifier applies all 40 ELF relocations at recovered link addresses and compares all 3,560 text bytes and 24 initialized data bytes without masking. It also checks all 57 owned zero-initialized bytes and seven alignment bytes against the original DOL BSS range. The original DOL SHA-1 is `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The unchanged source previously passed full-DOL and native objdiff integration. The corrected source extent and explicit external-padding checks pass in isolation; central integration of the seven-byte attribution correction passes the original DOL hash and native objdiff. No source or headers changed. Exact mappings and verification hashes are in `config/GSQE78/candidates/msl-alloc.json`; project progress remains in [PROGRESS.md](../../PROGRESS.md).

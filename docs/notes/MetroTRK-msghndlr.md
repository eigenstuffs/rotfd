# MetroTRK message command handlers

The original C unit spans 0x801190E0..0x8011B940 and contains 19 linked functions. Two source fragments recover 18 functions and 9,296 code bytes. The memory-read handler remains original fallback.

| Source fragment | Original text | Functions | Code bytes | Owned data |
| --- | --- | ---: | ---: | --- |
| msghndlr_commands.c | 0x801190E0..0x8011A8B4 | 8 | 6,100 | .data 0x802CFDE8..0x802CFE04, 28 bytes |
| msghndlr_control.c | 0x8011ACC4..0x8011B940 | 10 | 3,196 | .bss 0x8033AA78..0x8033AA7C, 4 bytes |

The first fragment handles options, stop, single-step/range-step, continue, cache flushing, register access and memory writes. The second handles CPU/version/support information, connection state, reset, unsupported commands and standard acknowledgements. The [Melee C implementation](https://github.com/doldecomp/melee/blob/master/src/MetroTRK/msghndlr.c) supplies the protocol algorithm and error mappings. The [Pikmin 2 reference](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/TRK_MINNOW_DOLPHIN/msghndlr.c) corroborates connection state and the serial-I/O option, while this target's serialized three-byte option request and error acknowledgement flow are reconstructed from its original instructions. Source provenance and hashes are under reference.

This target has ordinary stack arrays for the memory-transfer buffer; Melee's 32-byte local alignment is absent. Local declaration order reproduces the original request-field stack locations. Ordinary inline C implements reply construction and up to three send attempts. The target's optional serial-I/O command acknowledges a read error and then still emits the final normal acknowledgement; this observed behavior is preserved. GetTRKConnected and SetTRKConnected belong to this original source family and share its private IsTRKConnected state.

Both fragments use GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto,deferred -sdata 0 -sdata2 0 -pool off -use_lmw_stmw on -rostr -i src/MetroTRK -Cpp_exceptions off`. Isolated probes verify every code byte, branch/address relocation and the complete memory-write error jump table. The initialized table is compiler-local @619, 28 bytes with .data alignment 8. The neighboring 28-byte memory-read jump table at 0x802CFE04..0x802CFE20 stays fallback; there is no inserted padding between these two original tables. The private IsTRKConnected BSS symbol has size 4 and section alignment 8. Original bytes 0x8033AA7C..0x8033AA80 are external alignment padding before the saved exception ID, not an enlarged state variable.

The complete near-match is retained in src/MetroTRK/msghndlr.c for research and is not configured. Its TRKDoReadMemory at 0x8011A8B4..0x8011ACC4 has the exact 1,040-byte extent but two instruction differences: the candidate forwards the returned 16-bit length from a register before the error branch, while the original branches and reloads the stored halfword. This function and its table remain outside recovered-C coverage. No volatile or assembly workaround was introduced. The fragment helpers and private protocol header are shared without changing the previously integrated trk_abi.h.

Verification scripts are scratch/MetroTRK/compile_msghndlr_{commands,control}.py and verify_msghndlr_{commands,control}.py. Full-DOL equality and native objdiff are integration checks.

Both registered source fragments now pass the complete DOL SHA-1, direct byte equality, native objdiff code/data checks, and the original-source regression audit. The four-byte BSS tail remains a separate original-padding split with no C source credit.

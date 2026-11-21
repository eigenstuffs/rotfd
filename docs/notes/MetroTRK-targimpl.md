# MetroTRK target control and register access

Two exact C fragments recover 21 functions and 5,120 text bytes from the original target implementation. They also own all 136 bytes of its read-only memory map and instruction templates.

| Source | Text range | Functions | Text bytes | Read-only range |
| --- | --- | ---: | ---: | --- |
| targimpl_control.c | 0x8011C754..0x8011CBF4 | 8 | 1,184 | None |
| targimpl_access.c | 0x8011CCEC..0x8011DC4C | 13 | 3,936 | 0x802AB930..0x802AB9B8 (136 bytes) |

The algorithms and register layout follow the [Melee target implementation](https://github.com/doldecomp/melee/blob/master/src/MetroTRK/targimpl.c) and the [Pikmin 2 target implementation](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/TRK_MINNOW_DOLPHIN/targimpl.c), checked against the target's original instructions. Local reference provenance records include file hashes. The sources handle memory and register access, exception preservation, stop notifications, trap-based file support, stepping decisions after interrupts, and target capabilities.

This build reports kernel version 0.9 and protocol 1.10. Its file traps include open, close and seek, using the earlier compact protocol already recovered in support.c. The command local is a 32-bit value containing an explicitly masked byte; retaining that source type reproduces the original allocation. Stop notifications append 32 GPR and 32 FPR entries after the standard stop information, each first truncated to an unsigned 16-bit value. The original overwrites the append result each iteration without stopping early on errors. FPSCR access masks the upper 32 bits; there is no native FPSCR access call in this branch. These target-specific behaviors are preserved.

The source generates ten-word register-access instruction arrays as data, patches the appropriate instruction slots, places a return instruction in the final slot, flushes 40 bytes, then invokes the array. Their three original read-only templates are each 40 bytes. They are counted as initialized data only. The SPR template at 0x802AB940 and FP template at 0x802AB990 were compiler-local in the whole original unit; named const structs, gTRKSPRTemplate and gTRKFPTemplate, permit the C fragments to reference their original allocations. All read-only data belongs to the access fragment, preserving original section order without creating a link-order cycle. Its ordinary struct copy compiles identically to the original local array initialization. The paired-single template at 0x802AB968 remains compiler-local. The one-entry gTRKMemMap occupies 16 bytes at 0x802AB930. The rodata section has alignment 8 and no owned padding.

The three initialized mutable globals at `0x802CFE20..0x802CFE50` are now
linked from [matching source](MetroTRK-mutable-state.md). The compiled
processor-state layout is 0x430 bytes: floating registers start at offset
0x98, extended registers at 0x1A8, paired-single registers at 0x32C, and the
transport return address at 0x42C. The saved register/state blocks remain
separate from the initialized globals.

TRKTargetStepOutOfRange (0x8011CBF4..0x8011CC74) and TRKTargetSingleStep (0x8011CC74..0x8011CCEC) remain unmatched. The current whole-source research version forwards the just-written step-type byte and eliminates comparisons that the original retains. It is 16 bytes shorter across the pair. No volatile accesses or assembly substitutions were introduced to conceal this discrepancy. The native exception, MSR and cache routines surrounding the C group remain original assembly fallback, outside recovered C coverage. The whole research source targimpl.c is not registered as a matching source.

GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto,deferred -sdata 0 -sdata2 0 -pool off -use_lmw_stmw on -rostr -i src/MetroTRK -Cpp_exceptions off` reproduces all 5,120 selected text bytes and 136 read-only bytes after resolving every relocation. Selected no-inline pragmas preserve the original function boundaries. The private helper for setting the stopped flag preserves original inlining across the new fragment boundary. Compile and verification scripts are under scratch/MetroTRK; both complete function/object manifests are in config/GSQE78/candidates/MetroTRK-targimpl-*.json. The integrated source passes whole-DOL byte equality, native objdiff code/data checks, and the original-source regression audit.

The four zero bytes at 0x8011DC4C..0x8011DC50 are original text alignment before the support-trap stubs. They are external to the access fragment and are not a function or recovered C. DTK initially inferred a function there; the build split ends at 0x8011DC50, while the source extent ends at 0x8011DC4C. The following original native startup split has alignment eight, so normal linker alignment recreates the four zeros. They add no code or data credit. A separate data split at the start of a code section triggers a DTK 1.8.3 padding-symbol overlap; the aligned native boundary avoids that limitation without modifying tools or source.

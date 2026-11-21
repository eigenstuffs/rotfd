# Engine matrix tree traversal

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/engine_matrix_tree.cpp` reconstructs the complete 472-byte ordinary
C++ function `fn_8024C338` at `8024C338..8024C510`. It requires global scope and
standard Game GC/1.3.2 options with `-use_lmw_stmw on -opt nocse`. Its dedicated
new declarations are in `include/Game/engine_matrix_tree.h`. Source data,
startup, BSS, and exception ownership are zero.

The routine resolves the owner's root handle at 0x2C through the original
context's manager at 0x118, then starts at that root's child handle at 0x10. Each
packed handle carries a signed 8-bit generation and signed 24-bit index. Manager
entries are 16 bytes with an object pointer at zero and signed generation byte
at 0xC. A 32-entry node stack and 32-entry parent stack preserve deferred child
chains. The routine processes the current sibling chain through handle 0x18,
then pops deferred child chains until the depth returns to zero. The native
initial chain is processed with a do/while loop; the source preserves that
control flow.

For each node, it resolves and pushes the child when present, increments the
original global counter `lbl_80378010`, selects a local 64-byte matrix from the
original context's buffers at 0x134 using active-bank byte 0x18 and the node's
signed index at 0x12C, calls existing `fn_8027B508` with that node and its parent,
and sets flags 0x60 at offset 0x120. It reloads the original current manager for
subsequent handle resolutions. The two context pointers and the initial shared
manager preserve observed pointer lifetimes across external calls.

Ordinary inline resolution helpers, a post-increment stack push, and explicit
context reuse reproduce the native allocation without emitted helper functions.
The `nocse` option retains the original entry-array loads. Earlier probes had
an extra initial-chain guard, reversed local-array layout, or different pointer
induction and resolution assignment. Their artifacts remain private and
preserved; only the exact complete production routine is in the manifest.

`scratch/engine_matrix_traverse_20261010m/final_integration.json` records complete
bounds, symbol binding, compiler flags, and seven actual REL24/HA/LO/SDA21
relocations. Fresh production compilation and strict verification pass: every
relocation is applied to its real versioned target, every owned byte equals the
protected original DOL without masking, and all function definitions and
allocated sections are accounted for. The ownership audit checks complete
original assembly bounds and all 3,141 original extabindex entries, 24 ctor
entries, and 8 dtor entries, with no references into this text. All original
counter, context, manager, matrix, neighboring text, and translation-unit data
retain their existing owners. This is a partial text split; central NonMatching
registration and original DOL/native regression acceptance remain the
integrator's promotion steps.

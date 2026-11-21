# Actor pose application, 800E466C

The ordinary C++ source matches the complete 1,632-byte function at
800E466C..800E4CCC, its eight-byte exception record at80014A24 and its
twelve-byte exception index at8001E900. The production object has exactly
these three allocations and22 actual relocations. There are no emitted weak
helpers, literal pools, initialized data, BSS or startup entries.

When actor input flag5 is set, the function checks and resets two target
objects, transforms a resolved model position through its matrix, and applies
that position to the first target. It then transforms a second node's offset
through the actor basis, prepares a four-component rotation record using the
original sine/cosine and normalization helpers, and applies the position plus
offset and rotation to the second target. The other branch invokes the
original target-disable helper for both handles.

The header uses partial offset views. The actor's virtual handle getter is
slot9C and its vector-returning getter is slotB0. Concrete model, transform
and node entry types share a union manager view at global offset118; this
retains the original manager/entry reloads between nested resolutions. It does
not assert that these views recover the complete original class hierarchy.

The first matrix transform needs named x/y/z scalar results followed by the
ordinary vector set(x,y,z) helper. Direct constructor-return and output-field
forms reorder11 component operands. The named-scalar setter reproduces every
original instruction without register constraints or forced instructions.
The rotation's zero-valued component is assigned before the cosine component
to preserve the original load/store ordering.

This is a partial original translation unit. GLOBAL float constants
lbl_803797C8, lbl_803797CC and lbl_803797D4 remain borrowed at their original
addresses and retain their existing consumers. No shared pool is relabeled or
credited. Complete original exception/startup tables are audited, including
the descriptor and trailing zeros. A bytewise initialized-data scan finds one
real entry pointer in the exception index and four unaligned interior-looking
byte patterns; all5,686 active inputs and132,564 real relocations confirm that
those four patterns are not relocation pointers. There are no active interior
references to the function.

Two fresh production compiles, complete allocation/symbol/actual-relocation
verification and11 negative strict-verifier guards pass. The original failed
overstrict byte-pattern audit and its corrected relocation classification are
preserved separately. Frozen research and source evidence is under
scratch/engine_control_pose_apply_20261011kp. Full DOL acceptance and matching
credit remain pending the root integrator.

# Scalar three-by-three matrix operations

Three C++ functions at `0x801F2124..0x801F230C` reproduce 488 bytes: transpose,
multiply into an output matrix, and multiply in place. Multiplication computes
a temporary matrix before assigning it to the destination, preserving the
original behavior when input and output storage overlap.

The normal inline six-argument dot-product helper is significant to the
compiler's floating-point allocation. Expanding its expressions directly in
the loop produces identical arithmetic with different registers. A structured
matrix assignment emits the original word-copy sequence after the scalar loop.

GC/1.3.2 with `-O4,p -inline auto -fp_contract on` and normal scalar-save game
flags matches every byte. Fused multiply-add contraction is required; the
default emits six extra instructions per multiplication routine. There are
no relocations, owned constants or BSS. Function names remain address-based
because original class/method identifiers have not been recovered.

`scratch/game_matrix3/verify.py` verifies the exact 488-byte extent. The
candidate manifest records subsequent full-DOL and native objdiff acceptance.
Paired-single routines surrounding this scalar fragment remain separate.

# Scalar game math

Six reconstructed functions (1,072 bytes), 24 bytes of shared float literals, the four-byte constructor entry and 64 bytes of zero-initialized object storage are integrated. Full-DOL SHA1 and native objdiff both pass. All 15 original relocations and every allocated object section were independently checked before integration.

| Source | Original text range | Functions | Code bytes |
| --- | --- | ---: | ---: |
| `src/Game/math_inverse.cpp` | `801F230C..801F25E8` | 2 | 732 |
| `src/Game/math_multiply_assign.cpp` | `801F2788..801F27BC` | 1 | 52 |
| `src/Game/math_transform.cpp` | `801F295C..801F29E0` | 1 | 132 |
| `src/Game/math_globals.cpp` | `801F29E0..801F2A4C` | 1 | 108 |
| `src/Game/quaternion_matrix_assign.cpp` | `801F20F4..801F2124` | 1 | 48 |

These are reconstructed names and partial units, not a claim about the original source filenames or full translation-unit boundaries. The original game algorithms were recovered directly from the local executable and disassembly. No game source was copied from an external reconstruction.

## Compiler and source findings

Use GC/1.3.2, `-proc gekko -fp hardware -fp_contract on -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off`. Fused arithmetic is required for the scalar inverse and transform. Compiler-generated Gekko floating-register saves are ordinary compiled C++ output; handwritten paired-single arithmetic remains in the original fallback.

The affine inverse computes the determinant and adjugate of the upper 3×3, transforms the translation with its negative inverse, and restores the homogeneous final column. The rigid inverse transposes the rotation, computes the negative transformed translation and restores that column. Expressing its transpose as **nested loops** reproduces the original register allocation exactly after full unrolling. Nine equivalent explicit assignments differ in the register chosen for the first load/store.

The assignment wrapper calls the original native matrix multiplication primitive with the destination as both its first and third arguments, then returns that destination. The point transform computes three coordinates with the matrix translation and writes homogeneous `w=1`. The quaternion wrapper calls the unresolved matrix-to-quaternion routine and returns its destination.

The global initialization uses ordinary C++ constructors for an integer zero vector, float zero vectors and the identity quaternion. The compiler reproduces the original constructor, pooled BSS offsets and `.ctors` entry exactly. The zero-sized `...bss.0` symbol is an internal compiler section anchor and must not replace the first real object in central symbols.

## Shared storage

| Address | Object | Bytes |
| --- | --- | ---: |
| `8037A6FC` | `game_math_zero` (`float0`) | 4 |
| `8037A700` | `game_math_epsilon` (`float1e-6`) | 4 |
| `8037A704` | `game_math_one` (`float1`) | 4 |
| `8037A708` | `game_math_negative_one` (`float-1`) | 4 |
| `8037A70C` | `game_math_half` (`float0.5`) | 4 |
| `8037A710` | `game_math_two` (`float2`) | 4 |
| `80340B48` | `game_int3_zero` | 12 |
| `80340B54` | `game_vec3_zero` | 12 |
| `80340B60` | `game_vec4_zero` | 16 |
| `80340B70` | `game_quat_identity` | 16 |
| `80377FD0` | `game_vec2_zero` | 8 |
| `80299954` | pointer to compiler constructor | 4 |

The constants are named objects at the end of `src/Game/random.cpp` because native fallback routines also reference this shared original literal pool. The four zero bytes at `8037A714..8037A718` and subsequent double literals stay fallback. They are not counted as a fabricated zero constant. The integrated symbol mappings preserve the native fallback references to those global objects.

## Remaining reconstruction

Durable candidates are under `scratch/game_math`; none of these unresolved functions is counted as matched code:

- `fn_801F1E78` (`636` original bytes), matrix3-to-quaternion conversion. `quaternion.cpp` recovers the trace and largest-diagonal branches, the three Newton refinements in the SDK-style square root, and final approximate normalization. Current output is `644` bytes. One extra move occurs when reusing the negative-branch root; one extra `frsp` occurs on the final reciprocal-square-root estimate. The target keeps the raw estimate in a floating register. Correctly typed `__frsqrte(double)` assigned to a float inserts `frsp`; a double variable and direct float-output multiplication instead produce double `fmul` plus `frsp` per component. Float-return inline helpers do not eliminate the rounding. This is evidence of an original native fast-rsqrt helper, but its original source boundary is not established. No assembly was introduced to force a match.
- `fn_801F25E8` (`416` bytes), composing translation, quaternion rotation and scale. `rotation.cpp` reproduces all operations and size; remaining differences are floating-register assignments in the initial rotation construction. `graph_48.cpp` is a closer 61-byte-difference variant with explicit quaternion-component locals. `probe_decl.py`, `probe_rotation_graph.py`, `probe_compose_struct.py` and `probe_compose_loops.py` record the tested declaration, expression and helper structures. No mismatching body has been promoted as matching source.
- `fn_801F27BC` (`416` bytes), constructing a quaternion between two vectors. Disassembly identifies cross product, approximate cross length, small-angle identity fallback, an `asin` half-angle branch selected by the dot product, and scalar `sin`/`cos`. Its raw `frsqrte` immediately followed by `fres` has the same intrinsic rounding boundary. A complete ordinary C++ candidate is still needed.
- The negative-trace lookup table `{1,2,0}` at`802EAA70` and remaining shared constants `double0.5` at`8037A718`, `double3` at`8037A720`, and`floatpi` at`8037A728` remain fallback.

The exploratory square-root helper follows the same three-step algorithm documented in the already pinned MSL reference `reference/sms-msl/math.h`; that reference's provenance and license remain in `reference/sms-msl`. No external source is used in the promoted game math units.

## Reproduction

`scratch/game_math/promote_partial.py` records the extraction/compilation of the six final sources. `scratch/game_math/verify_partial.py UNIT` checks the final object for that unit: original SHA1, complete allocated-section inventory and exact sizes, relocated text/data bytes, BSS bounds and symbols, and complete function coverage. It writes the individual candidate manifest. `scratch/game_math/partial_verification.txt` contains the successful results. The exploratory `check.py` is not the final verification gate: it maps anonymous constants by value and supports partially reconstructed bodies.

Original DOL SHA1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

## Integrated storage ordering

The exact C++ constructor and its global object layout now pass the full-DOL and native-objdiff checks unchanged. Their storage precedes the random unit's storage, while the constructor follows its code. The parent resolved that ordering by moving random state into `src/Game/random_state.c` and expressing the existing signed-byte one-time initialization in `src/Game/random.cpp`. The original 860 bytes of random code remain exact. This preserves the compiler's ordinary pooling of the math globals and avoids object-file rewriting.

The six shared float constants now follow the original 28-byte constant pool in `src/Game/random.cpp`, preserving their original alignment and addresses. The standalone `math_constants.c` candidate is superseded. Earlier unsuccessful attempts to split the constructor's external storage remain in scratch for reproducibility; they are not active build sources.

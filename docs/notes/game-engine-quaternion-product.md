# Quaternion product

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_quaternion_product.cpp` reconstructs the complete ordinary C++ function `fn_801F1C64`, `801F1C64..801F1CD8` (116 text bytes). Its four floats are ordered `w`, `x`, `y`, `z`. It returns the Hamilton product of two input quaternions by value, using the CodeWarrior hidden result pointer ABI. The inline four-argument constructor preserves the original evaluation and register allocation; an equivalent C function with four scalar temporaries did not match.

Frozen evidence is in `scratch/engine_quaternion_ops_20261010al/`. GC/1.3.2 uses the standard Game flags plus `-fp_contract on`, reproducing the original fused single-precision operations. `freeze.py` and `verify.py` compile current production source, verify its single global ELF function and complete extent, reject additional functions or allocated sections, and compare every emitted byte to the normalized reference DOL. There are no relocations and no comparison bits are masked.

`audit.py` checks all 3,141 original exception index entries, 24 constructors and eight destructors. None references the selected text. The split owns no data, BSS, exceptions, constructors or destructors. All neighboring arithmetic and original unit data retain their existing ownership. This is a partial text-only split, not a complete original translation unit.

`final_integration.json`, `final_splits.txt`, `final_config.txt`, `scope_edits.txt`, and `ownership_audit.json` provide the central integration record. Register NonMatching with the extra contraction flag, preserve global scope for `fn_801F1C64`, then promote only after full native DOL hash and regression acceptance. Isolated verification alone earns no project progress.

The saved multiplication assignment, vector rotation, normalization and matrix-conversion research remains uncredited. The closest rotation is 148 bytes with 30 instruction differences; the three-by-three conversion has 31 differences. None of those variants enters the production manifest.

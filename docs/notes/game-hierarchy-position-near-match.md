# Hierarchy positioning probe (not matched)

The bounded original function at `0x802008C8..0x80200C38` is 880 bytes.
Its implementation is preserved in `scratch/game_hierarchy_position/initial.cpp`,
with the original disassembly, compiler probe, readable instruction comparison,
and alternative vector/call models in that directory. **Nothing from this
function is counted as matching source or added to the link.**

The observed operation validates indexed assigned/secondary handles and the
owner handle; copies a handle from a 0x4C-byte game record at offset 0x14;
transforms `(0,0,1)` by the resolved object's 3x3 orientation at offset 0x30;
and gets its body/transform pointer at 0x124. It casts a downward ray from
`body.position + direction * 3 + (0,5,0)` with direction `(0,-1,0)` and length
50. The ray query receives owner, request, result, body, and flags `0,2,4,8`.
On success it resolves the assigned object's virtual slot 0x9C result through
a copied owning handle and forwards the hit result to `fn_8023D100`.

Original constants at `0x8037A8D8..0x8037A8F0` are the six floats
`1,0,3,5,-1,50`; these remain original data. The request's confirmed fields are
origin at 0, length at 0xC and direction at 0x10. The result has at least
0x44 bytes, including initialized words at 0x28..0x38 and signed-byte status
at 0x3C; untouched fields remain opaque. Ghidra's isolated tiny-function
metadata for `fn_80269230` is misleading: original split disassembly contains
the real full ray-query body and confirms these result offsets.

Native base/derived handle constructors and destructors reproduce the control
flow and hidden temporary-address lifetime. Remaining problems are the inline
vector expression's temporary placement, floating register allocation and
scheduling, plus one pair of final handle-copy saved registers. With GC/1.3.2,
`-O4,p -inline deferred -fp_contract on`, the straightforward operator model
emits 856 bytes and eliminates the original direction/position stack stores.
GC/1.3 and GC/2.0 emit the same code. Matrix-side operators, value/reference
parameters, named return vectors, constructor/copy forms, explicit output
helpers and natural ray temporaries are recorded by the probe scripts. Some
880-byte variants exist, but size equality does not establish a match.

Original stack evidence: final selected handle +0x8, game handle +0xC,
transformed direction +0x10, copied body position +0x1C, request +0x28,
result +0x48, saved registers starting +0x90, frame size 0xA0. These are
observations for diagnosing compiler source semantics, not hard-coded storage
or assembly replacements. No volatile barriers, register directives, altered
original bytes, relocation masks, or machine-code arrays were introduced.

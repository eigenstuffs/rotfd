# Related owner transform dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_related_transform_dispatch.cpp` reconstructs `fn_80222E64`,
`0x80222E64..0x8022312C` (712 bytes), using standard GC 1.3.2 flags and a
source `fp_contract on` pragma for the native fused multiply-add operations.

The function resolves owner handle `0x1F8`. If it is non-null, it forwards the
requested point and rotation to that related owner's virtual slot `0xC0`,
obtains the primary handle at virtual slot `0x9C`, and refreshes the primary
object with `fn_8023DE28`. It follows the primary's parent handle at `0x20`,
the first handle in that parent's array at `0x28`, and the selected handle in
the resulting object's array. The selected index comes from context offset
`0x144`, then selector offset `0x94`, then selection offset `0x18`.

It composes the two objects' rotation bases at `0x30` using `fn_801F2170`,
converts the result with `fn_801F20F4`, and transforms the selected object's
matrix translation by the primary object's 4x4 matrix. Matrix pointers are at
object offset `0x124`. The resulting point and rotation are dispatched to
`fn_8021F8F4`. The point reference accessor in the return path retains the
native result-then-argument copy lifetime; named z, y, and x translation
components preserve native scalar load order. If the related handle resolves
to null, the original arguments go directly to `fn_8021F8F4`. Finally, a valid
secondary handle at `0x1AC` also forwards the original arguments to
`fn_8022352C`.

`python3 scratch/game_owner_related_transform_dispatch/verify.py` recompiles
frozen production source, validates all 11 actual relocations, and compares
all 712 retained bytes to the hash-verified original DOL. Its sole allocated
section is exactly 712 bytes of text, with no helper tails, data, BSS, or owned
padding. Complete original extabindex, constructor, and destructor table
scans contain no entries owned by the retained range. The original containing
engine translation unit remains incomplete. Central integration and final
DOL hash acceptance are parent-owned.

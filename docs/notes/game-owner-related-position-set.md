# Related owner position setter

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_related_position_set.cpp` reconstructs `fn_8022312C`,
`0x8022312C..0x80223448` (796 bytes), with standard GC 1.3.2 flags and a
source `fp_contract on` pragma for the native fused multiply-add operations.

This position-only companion of `fn_80222E64` resolves owner handle `0x1F8`,
forwards the position to related-owner virtual slot `0xBC`, resolves the primary
object, refreshes it, then follows its parent and selected descendant handle.
The handle array and selection chain use the established offsets `0x20`,
`0x28`, and context `0x144 -> 0x94 -> 0x18`. It transforms the selected object's
matrix translation by the primary matrix and forwards that point to
`fn_8021F990`. A null related owner forwards the original position directly.

When the secondary handle at `0x1AC` is valid, a separate inline helper converts
the owner's primary basis at `0x30` with `fn_801F20F4` and forwards its returned
quaternion pointer together with the original position to `fn_8022352C`.
The inline helper's quaternion lifetime reproduces the native quaternion and
point argument stack-slot order. The converter declaration agrees with the
existing recovered implementation in `src/Game/quaternion_matrix_assign.cpp`:
it returns its output pointer. No existing declaration or source was changed.

`python3 scratch/game_owner_related_position_set/verify.py` recompiles frozen
production source, checks all 10 actual relocations, and compares the complete
796-byte function to the hash-verified original DOL. The sole allocated section
is exactly 796 bytes of text. There are no weak helpers, initialized data, BSS,
or owned padding. Complete original extabindex, constructor, and destructor
table scans contain no retained ownership. The original engine translation
unit remains incomplete. Central integration and final DOL hash acceptance
are parent-owned.

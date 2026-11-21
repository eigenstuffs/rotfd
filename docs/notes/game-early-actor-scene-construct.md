# Early actor scene constructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8008A758` is an ordinary C++ reconstruction of 216 text bytes, with its
8-byte extab at 8000E378, 12-byte index at 8001A400, and sole compiler-owned
8-byte conversion literal at 80378B48. GC 1.3.2, `-O4,s`, exceptions on produces
exact complete allocated bytes after applying all nine actual relocations.
Central original-DOL linking is still required before matching credit.

The constructor calls existing `fn_80090084`, installs the original intermediate
table 802B92B0, clears and assigns actor/controller words 8/C, then installs
derived table 802B8A6C. It clears six words 40..54, two bytes 58/59, and the
base enabled byte4. A three-element loop clears bytes 5A..5C and fills floats
60..68 from the signed index times borrowed float 80378B44. The function
returns its owner pointer. Existing C entry and external table identities remain
unchanged, with no consumer migration or alias.

The compiler emits actual local objects `@11` (.sdata2,8 bytes,alignment8),
`@12` (extab,8 bytes), and `@13` (extabindex,12 bytes). The literal bytes are
4330000080000000, the original signed-int-to-double conversion offset. The
strict verifier resolves the relocation through the locally defined .sdata2
symbol and original section address, ignoring unrelated global names such as
another original `@11`. A raw text diagnostic initially reported one operand
difference because its global lookup resolved that local name incorrectly;
no instruction masking is used in strict acceptance.

The frozen active object scan reads `build/GSQE78/config.json` and every listed
object, examining 119,086 actual relocations across 5,498 units. Exactly one
reference enters 80378B48..80378B50: the original fn8008A758 at text offset48.
There are no other assembly/source consumers, no missing objects, and no aligned
absolute DOL pointers to this range. The original global label `lbl_80378B48`
can therefore be retired when this local compiler-owned literal is split into
the new source. The neighboring 80378B44 float and 80378B50 string remain
outside this unit. No extra allocation or padding is emitted or owned.

The standalone production verifier pins source/object hashes, checks every
allocated section's alignment and exact symbol inventory, applies every real
relocation, compares all244 allocated bytes to the supported original DOL, and
scans the complete original extabindex80015F60..8001F2C0, ctors80299920..80299980,
and dtors80299980..802999A0. Only the single expected exception entry references
the retained function. There are no weak definitions, BSS, startup entries,
discarded sections, or headers. Shared metadata/global builds were not changed.

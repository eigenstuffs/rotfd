# Nested record handle release at 801ACFC0

`src/Game/nested_record_handle_release_801ACFC0.cpp` reconstructs
`fn_801ACFC0` at `801ACFC0..801AD094` (212 text bytes). It releases a handle
at owner offset `0x20`, then visits an array counted at `0x6C` with records of
stride `0x1C` and a handle at each record's `+4`. It next visits an array
counted at `0x7C`: each `0x10`-byte group contains a count at `+4` and a
pointer at `+0xC` to eight-byte nested records. It finishes by releasing the
owner's value at `0xA8`.

The handle visits call the existing `fn_801B3E54` with the manager pointer at
`lbl_801E9D24+0x118`; the final release calls `fn_801F6AF8`. The field and
type names are provisional partial views of this object. Reusing one outer
loop index and spelling the nested group address as `base + 16*i` preserved
the original register allocation and operand order.

The split claims only this function's text. Native objdiff confirms 212/212
bytes and all text relocations match, with no source-owned data or exception
metadata. The following `fn_801AD094` and any original data or other functions
from its translation unit remain under their existing owners. The standard
rebuild passes the original DOL SHA-1. No diagnostic probe scores are credited.

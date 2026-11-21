# Owner record property dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_record_property_dispatch.cpp` reconstructs `fn_8022E9D8`,
`0x8022E9D8..0x8022EBAC` (468 bytes), with standard GC 1.3.2 settings.

The function reads flags at `0x38` in the indexed 0xA8-byte record from owner
array `0x188`. Record masks `0x100000` and `0x200000` select position-only,
position-and-rotation, position-and-scale, or all-three virtual dispatches
through slots `0xBC`, `0xC0`, `0xC4`, and `0xC8`. The position is the second
input point. Rotation and scale arrays are owner offsets `0x1D8` and `0x1E4`;
the selected index is forwarded to the virtual operation. After dispatch,
it resolves owner-related handle `0x1A8`, obtains that owner's primary handle
through virtual `0x9C`, resolves the object, and calls `fn_8023D400` with mask
`0x10`. First/third point inputs and delta are unused in this method.

`python3 scratch/game_owner_record_property_dispatch/verify.py` recompiles
frozen production source, checks the three actual relocations, and compares
all 468 original bytes. The sole allocated section is exactly 468 bytes of
text. There are no weak helpers, data, BSS, or owned padding. Complete original
extabindex, constructor, and destructor table scans show no retained ownership.
The original containing engine translation unit remains incomplete. Central
integration and final DOL hash acceptance are parent-owned.

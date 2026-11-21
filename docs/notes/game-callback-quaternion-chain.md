# Callback quaternion chain

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_802524B4` reconstructs the complete 316-byte function at
`0x802524B4..0x802525F0`. It initializes the vector part of the owner's
virtual quaternion value from the supplied object's matrix translation
and sets its fourth component from the original constant. It then combines
the value with consecutive 20-byte records through `fn_801F0A20` while the
count is nonzero and the record's signed tag at `0x10` remains nonnegative.

A normal vector constructor and scalar assignment preserve three floating
values across the first virtual call. The virtual value getter occupies
slot `0x3C` with the vtable at object offset eight. A four-float local holds
each combined result before it is copied through the next getter call.
The count at `0x24`, records at `0x2C`, and supplied object's matrix pointer
at `0x124` are the only surrounding layout fields established here.

`scratch/game_callback_quaternion_chain/verify.py` checks all allocated
bytes, the exact function extent and every actual relocation without masks.
There are no extra allocated helpers, owned data or original startup/table
references. The constant, original combining function and neighboring
methods retain external ownership. Full executable acceptance is required
before matching credit.

# Owner record timeout visit

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_record_timeout_visit.cpp` reconstructs `fn_80226288`,
`0x80226288..0x80226434` (428 bytes), with standard GC 1.3.2 settings.

The function traverses active indices through virtual slots `0x90` and `0x94`.
For each index accepted by virtual slot `0x124`, it integrates the 0xA8-byte
record's position at `0x00` using velocity at `0x0C` and the supplied delta.
It reads the timeout at `0x18`; a nonnegative timeout is decremented. If the
stored timeout crosses below the external zero scalar, it releases record
handle `0x48`, assigns a default three-layer handle, retains that input, and
calls virtual slot `0x128` to erase the index. The record array is owner offset
`0x188`.

The timeout value accessor and local scalar preserve the first timeout load
for subtraction while the subsequent comparison rereads the stored array
value, reproducing the native alias and reload behavior. Point multiplication,
addition, and layered handle assignment are ordinary C++ operations.

`python3 scratch/game_owner_record_timeout_visit/verify.py` recompiles frozen
production source, verifies every actual relocation and all 428 original text
bytes, and accounts for all allocated emissions. The only allocated section
is text; its unused weak destructor backups are fully inventoried and must be
absent from the final ELF. No retained reference targets a discarded helper.
Complete original extabindex, constructor, and destructor table scans show no
retained ownership. Data, BSS, and owned padding are zero. This partial split
does not recover the containing engine translation unit. Central integration
and final DOL hash acceptance are parent-owned.

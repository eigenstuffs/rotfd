# Handle type collection

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/handle_type_collect.cpp` reconstructs `fn_8026A128`,
`0x8026A128..0x8026A494` (876 bytes), with standard GC 1.3.2 settings.
Every original byte and actual relocation matches in the isolated production
compilation; central integration is pending.

The function resizes its output handle array to zero, then traverses the
input owner's child array at `0xC/0x10/0x14`. It makes a retained child handle
copy and a retained copy of that child's resource handle at `0x1C`. A valid
resource with the requested unsigned type at `0x6C` causes the child handle
to be appended to the output. The output grows capacity by 32 and placement
constructs retained copies. Both local handles are cleaned up on every path;
the return value is the collected count.

The output's default handle construction stores two zeros and its retained
copy construction stores one, reproduced with an ordinary initializing base
class. Output resize keeps the native reverse destruction loop and negative
count construction path. The allocation helper leaves capacity assignment
to its caller: resize sets the requested capacity, while append reloads and
increments capacity after the allocator call. This closes the initial probe's
extra saved register and all 81 remaining register differences at the same
876-byte extent. No assembly or aliases are used.

Run `python3 scratch/game_handle_type_collect/verify.py` to reproduce the
frozen proof: 876 retained bytes and 32 actual relocations. All 1,048 allocated
text bytes are accounted, including two unused weak destructor backups totaling
172 bytes and four inventoried relocations. Neither has a retained reference,
and both must be absent from the final ELF. Original DOL SHA1 and complete
original extabindex/constructor/destructor table bounds are verified. No data,
BSS, padding, or original table ownership is retained.
This is a partial text split of its containing original translation unit.

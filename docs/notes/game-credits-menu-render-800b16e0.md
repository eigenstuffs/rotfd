# Credits backdrop and menu renderer

The accepted source is `src/Game/credits_menu_render_800B16E0.cpp`, compiled
with GC 1.3.2, `-O4,s`, exceptions enabled, RTTI disabled, and the existing
Gekko floating-point and inline settings. It reconstructs the credits backdrop,
particles and text at `800B16E0` (1,464 bytes), the existing four-byte leaf at
`800B1C98`, and the menu renderer at `800B1C9C` (4,148 bytes).

## Ownership and source findings

The group owns 5,616 text bytes, 764 exception-table bytes, 24 exception-index
bytes, 88 read-only string bytes and 184 small-data bytes. The menu parser pool
at `802A0250` now ends at `802A03A8`, preserving its 344-byte prefix. The two
sources together preserve all 616 previously matched data bytes. Six scalar
registrations and the leaf registration were retired; their source files and
historical receipts remain available.

The source uses a typed texture resolver, a widening helper for a control index,
the unchanged integer formatter, native Handle lifetimes, and explicit message
record access. Reusing zero coordinates yields the original register scheduling.
All 20 shared GLOBAL data definitions retain their names, sizes and addresses.
Fourteen old GLOBAL names become genuine compiler-local pools only after a
complete reference census establishes that their users are the two replaced
render bodies. Five surviving complete consumers and 31 borrowed-base strings
remain unchanged.

The complete compiler object contains 7,272 allocated bytes. Native linking
retains 6,676 and discards 420 weak code bytes plus 176 weak exception/index
bytes. All 244 actual and compiler-metadata relocation records are inventoried;
212 belong to retained sections. Forty-seven retained exception references
resolve to the three existing strong Handle destructor owners, each freshly
reproduced and checked in full. No compiler output was removed or patched.

## Verification

The frozen source and native proof are in
`scratch/menu_credits_render_800B16E0_20261020/`; the independent data closure is
in `scratch/menu_credits_data_closure_20261020_parallel/`. Integration receipts
are in `scratch/menu_credits_integration_20261020/`. The frozen packages remain
immutable; their read-only verifiers support checking current production.

The source was staged NonMatching, compiled, compared as a complete object and
then promoted. The standard build passes the original DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, with no baseline regressions,
all 66 unit tests passing, and all source extents valid. Both native mapped
outputs agree with the actual standard ELF at SHA-256
`b21d02cf003548ccda57cfed5657e0ccf1fadcc858aa29382feab6dd8030cb09`.

The net gain is **5,612 code bytes, two functions and 788 data bytes**. Generated
progress is 1,950,296 / 2,607,776 code bytes (74.7877%), 7,996 / 8,803 functions,
and 977,889 / 1,030,936 data bytes (94.8545%). Adjacent constructors, layout
functions, tables and unrelated data retain their prior ownership; this accepted
build unit does not establish a complete original translation-unit boundary.

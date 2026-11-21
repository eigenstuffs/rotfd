# Movie output records

`src/Game/movie_output_records.cpp` reconstructs `fn_80292950`, the 140-byte
initializer at `80292950..802929DC`. It initializes three `34`-byte output
records from three accepted `38`-byte plane records. Source and cursor share
the plane pointer at offset `04`; three caller-provided output buffers advance
by each plane's pixel count. Horizontal and vertical shifts determine the
per-record horizontal count and row-byte count; the plane scale fields provide
the remaining record strides. Unknown fields remain explicitly represented.

The source uses GC/1.2.5 with the ordinary movie flags (`-O4,p -inline auto`,
Gekko hardware FP, exceptions and RTTI off, `-use_lmw_stmw on`, and
`-fp_contract on`). A local source-pointer variable preserves the native single
load followed by two stores; assigning the second field from the first record
field would introduce an alias reload.

Run `python3 scratch/movie_worker_continuation/verify_output_records.py` for
the strict isolated check and candidate manifest. It verifies the normalized
original SHA-1 and all emitted allocated bytes, with only the 140-byte `.text`
section (alignment four), one global function, no allocated relocations, no
data, BSS, exceptions, helper functions or padding. The ordinary nonallocated
compiler metadata has one relocation to the function.

Integration owns only `.text 80292950..802929DC`, alignment four, and promotes
`fn_80292950` to explicit global scope. Register the new unit NonMatching first
with the movie GC/1.2.5 flags, validate it, then promote it. The surrounding
movie functions and original data remain outside this partial text split.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.

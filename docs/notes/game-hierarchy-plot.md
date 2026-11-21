# Hierarchy plot setup

`src/Game/hierarchy_plot.cpp` reconstructs the 572-byte method at
`0x802017D8..0x80201A14`. It first calls the existing hierarchy setup method with
a copy of the input handle. If that succeeds, it formats `Plot%d`, resolves the
owner, looks up that name and `Start_Base`, and invokes vtable offset `0x13C` on
the selected assigned member with the two handles and the owner handle.

The typed lookup result uses the native nontrivial C++ return-value ABI. Its
temporary destructor calls the native base destructor with the zero deletion
flag. Each owned handle calls the native base constructor, initializes its
wrapper layer, copies the returned value, and retains it through the manager.
Automatic destruction releases the lookup temporaries and the two local owned
handles in the original order. The private wrapper type names describe these
observed roles; the original type names are unknown.

The owner is resolved into a local pointer before each hash construction.
Passing `resolve(...)` directly to the lookup function changes argument
evaluation order and does not reproduce the original instructions. The existing
shared handle and virtual object layouts are reused without modification. The
private extended virtual declaration places the command method at its observed
offset; no new vtable data are emitted.

`scratch/game_hierarchy_plot/verify.py` compiles with GC/1.3.2, `-O4,p`,
`-inline auto`, and `-use_lmw_stmw on`. It verifies all 572 retained text bytes
and all 20 retained ELF relocations against the SHA-1-checked original DOL.
There are no owned data, BSS, or exception records. Existing literals at
`0x8037A8F0` (`%s%d`), `0x8037A8F8` (`Plot`), and `0x802AD910` (`Start_Base`)
remain external original storage, with no data credit in this candidate.

The compiler additionally emits three weak wrapper destructors totaling 256
bytes. The verifier checks their exact symbol extents and all six relocations,
and proves that retained code has no references into those bodies. They are
ordinary unreferenced output subject to linker dead stripping, excluded from
both the candidate's source range and its progress credit. The candidate is
`config/GSQE78/candidates/game_hierarchy_plot.json`; the central build passes the original full-DOL SHA-1, direct byte comparison
and complete native objdiff code/data checks.

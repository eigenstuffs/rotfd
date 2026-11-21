# Hierarchy named-world removal (RemoveGame)

`src/Game/hierarchy_selection.cpp` reconstructs `fn_802042EC` at
`0x802042EC..0x802043FC`: one 272-byte function, with no owned data.

The method returns false unless console `argc` at offset `0x860` is two: the
command token plus one world name. It hashes the original `WORLD` type name
and `argv[1]` at offset `0x868`, then looks up the corresponding object through
the manager. The global pointer at `+0x110` is the console, as established in
the [console argument layout](console-argument-layout.md).
An owned handle copy retains the lookup result. Invalid handles return false;
valid handles are passed to the global group-removal helper and return true.
The original command registration at `0x80206524` identifies this method as
`RemoveGame`, using the name at `0x802ADA0C` and ` WorldName ` help string at
`0x802ADA18`. The class name remains unknown.

The helper `fn_801FF24C` searches for the hierarchy whose related owner resolves
to the requested world, clears its associations, erases its group-list handle,
and removes the world from a second collection. Its search has no not-found
guard before list access. The earlier provisional selection label was incorrect;
this correction changes the description, with all matching instructions preserved.

The source models the observed hash-to-type copy and native C++ return-value
temporary. The temporary's base-handle destructor and the owned wrapper's
scoped cleanup preserve the original lifetime and reference-count operations.
The six-byte `WORLD` string at `0x8037A918` stays external original data; the
following alignment bytes are not included in its declaration or source credit.

CodeWarrior GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions off` and the
existing PowerPC flags reproduces every retained instruction. Run
`python3 scratch/game_hierarchy_selection/verify.py` to compile the production
source, apply all 17 retained relocations, and compare the complete retained
section with the protected original DOL. Two generated weak wrapper destructors
totaling 172 bytes have four relocations and no retained references. Their
full extents are checked, and ordinary linker dead stripping excludes them
from recovered-source credit.

Central integration passes the original DOL hash, direct whole-file comparison,
native objdiff, and the source-section extent guard. The native report records
272/272 code bytes and one matching function. The accepted manifest is
`config/GSQE78/candidates/game_hierarchy_selection.json`; the original SHA-1
remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

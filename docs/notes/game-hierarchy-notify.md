# Hierarchy related-object notification

`src/Game/hierarchy_notify.cpp` reconstructs the 256-byte method at `0x801FD3EC..0x801FD4EC`. The strict verifier `scratch/game_hierarchy_notify/verify.py` compiles with GC/1.3.2 and `-O4,p -inline deferred -use_lmw_stmw on`, checks allocated-section alignment and size, applies all four ELF relocations, and confirms every code byte equals the original. It owns no data. Full-DOL byte equality, native objdiff checks and the original-source regression audit pass.

The method resolves its target handle, resolves the handle at that target's `+0x58`, and calls `fn_80240120` with the resulting object and zero. It then resolves the hierarchy handle at `+0xC` and calls `fn_80269FE0`. The reconstruction preserves null results from generation mismatches and the original caller's lack of further null guards. Private names describe observed fields rather than established original class names.

Two explicit manager views preserve the original second load of the entry table at `+8`. Collapsing both lookup paths into one typed field lets the compiler cache that pointer, removing four bytes. The same view distinction produces exact code in the nearby five selection methods documented in `game-group-selection.md`; it remains an inference about source type structure. No volatile accesses, assembly replacements, masked comparisons, or binary edits are used.

Only this routine is claimed; the neighboring 1,228-byte and 2,164-byte methods remain original fallback. The protected DOL SHA-1 is `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The registered source passes complete DOL SHA-1 and byte equality, native objdiff source checks, and the preserved original-source regression audit.

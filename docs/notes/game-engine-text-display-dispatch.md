# Text renderer display-list dispatch

`fn_8027DC70` (`8027DC70..8027E1A0`) is an isolated ordinary C++ reconstruction
of the renderer's pending-record dispatcher. The 1,328-byte entry and every
allocated compiler byte match the original, including all 45 actual ELF
relocations. This handoff is not yet production acceptance.

The routine follows 168-byte linked records, detects material/flag changes,
selects the vertex-array and lighting setup for six flag paths, submits each
nonempty display list, and clears the pending marker. The `0x40` path adds
ambient and diffuse light vectors and clamps their converted RGB values.
The header supplies offset-based partial views rather than complete recovered
engine class definitions.

The matching source uses one `ByteColor` local across both color-producing
branches. An inline output-reference conversion fills that local. A genuine
`Vec3` addition returns a temporary bound to a `const Vec3&`; this preserves
the original three vector stores while retaining the calculated components
across the clamp calls. Forwarding `record->display` directly into the inline
submission helper preserves the final record and buffer register lifetimes.
The original RGB-only clamp path leaves the fourth color byte unchanged.

Build flags are the ordinary Game `GC/1.3.2 -O4,p` flags, plus
`-fp_contract on -use_lmw_stmw on`. The compiler emits exactly one global C
function and no helpers, data, BSS, tables, constructors or destructors.
The complete original extabindex, constructor and destructor tables contain
no ownership or references for this entry. A bytewise scan of all original
initialized data finds one aligned pointer to the entry and no interior
pointers. The active ELF inventory contains only the original body and that
data reference; there are no existing compiled source callers to migrate.
The original global C identity and all existing consumer files remain intact.

This is a text-only split of the larger `8027D850..8027F178` renderer family.
All adjacent entries and original data stay outside it. In particular, the
16-byte shared conversion pool `8037B7B8..8037B7C8` remains wholly original and
uncredited. This entry does not reference that pool; its only float loads
refer to existing external zero `8037B7B0` and scale `8037B7C8`.

Frozen evidence is in `scratch/engine_text_display_dispatch_20261011gy`:
`final_integration.json`, the complete allocation and consumer inventories,
original pointer/table audits, and source/header/object SHA-256 values.
`verify.py` recompiles the production source, checks every allocated byte,
all symbol extents and all resolved relocation targets, then checks the full
original tables and frozen hashes. The broader five-fragment exact proof in
`scratch/engine_text_projection_20261011gw` and all private full-family probes
in `scratch/engine_text_render_family_20261011gx` remain preserved separately.

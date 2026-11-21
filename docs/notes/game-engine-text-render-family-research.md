# Renderer family: preserved joint and contiguous research

The renderer family at `8027D850..8027F178` has 11 entries and 6,440 bytes.
The original 16-byte conversion pool is `8037B7B8..8037B7C8`. This research does
not claim complete source ownership of that family or pool.

Five ordinary bodies compile together with 2,776 exact text bytes and the
natural 16-byte local conversion pool: `D850`432, `DA00`424, `DBA8`200,
`E650`448 and `EC80`1272. The frozen joint proof in
`scratch/engine_text_projection_20261011gw` checks complete allocated bytes,
symbols and all 58 actual relocations at their original fragment placements.
It is a comparison proof; native discontiguous source integration has not
been established. All seven original references to the pool are inside
those five entries, and complete active ELF and bytewise original-data scans
find no additional reference or pointer consumer. The original pool remains
outside production source ownership.

The separate contiguous-recovery investigation is preserved in
`scratch/engine_text_render_family_20261011gx`. It produced a production-ready
independent match of `8027DC70..8027E1A0` (1,328 text bytes and 45 actual
relocations). Its frozen handoff is in
`scratch/engine_text_display_dispatch_20261011gy`; it owns no conversion pool.
Its vector and color lifetime findings are documented separately in
`game-engine-text-display-dispatch.md`.

The best four-vertex strip probe `strip_shared_bgr.cpp` has the original
1,132-byte extent and seven differing register operands. One shared
`ByteColor` output-reference conversion recovers the native floating-point
calculation and stack conversion order. The remaining differences are the
alpha-byte register and two green-component registers. Reversed channel
construction, separate alpha assignment, member construction, value/ref
helpers and full-expression lifetimes are all preserved as bounded probes.
No near probe receives source credit.

The bitmap-transfer path remains private. Byte-addressed framebuffer
advancement and decrementing pixel counts improve the native loop shapes.
The original RGB24 path repeatedly emits an explicit zero in r14, an indexed
`lwbrx` through that register, and a store of the loaded word into a stack
local without a corresponding reload. The supported compiler builtin is
`__lwbrx(void*, int)`, whose constant-zero form emits RA=0 and does not retain
that stack store. Ordinary local/volatile/byte-addressed loop alternatives
do not recover the complete original 1,192-byte entry. The explicit-register
sequence may originate in an inline helper, but this is an inference rather
than established source provenance. No assembly, fixed registers, aliases,
object mutation or synthetic data was used.

The full-range census also revealed three already owned empty entries:
`leaf_late_8027E648.c` owns `E648..E650` (two entries), and
`leaf_late_8027E810.c` owns `E810..E814` (one entry). These sources and their
ownership remain untouched. Any eventual contiguous replacement must account
for those original accepted owners without duplicate credit. All original
exception/table allocations remain outside the new display text split; the
complete original table audits contain no entry referring to this family.

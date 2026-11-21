# Message-box drawing and layout at 800C293C

`message_box_draw_layout_800C293C.cpp` reconstructs the adjacent drawing routine
at `800C293C` (892 bytes) and text/button layout routine at `800C2CB8` (2,752
bytes). The compiler emits their complete shared conversion and float pool,
14-entry switch table, and exception metadata.

| Section | Native range | Bytes |
| --- | --- | ---: |
| Code | 800C293C..800C3778 | 3,644 |
| Switch table | 802BF618..802BF650 | 56 |
| Scalar pool | 80379538..80379560 | 40 |
| Exception records | 80012940..80012950 | 16 |
| Exception index | 8001CCA4..8001CCBC | 24 |

All 3,780 allocated bytes match with 131 real relocations and two native
compiler metadata references. No weak definitions, extra allocations or
unowned literals are emitted. Both data sections have native alignment eight;
code and exception sections have alignment four. The compiler is GC/1.3.2 with
O4,s, exceptions enabled, RTTI disabled and floating-point contraction enabled.

The draw context is read-only, expressed with an ordinary const pointer. A
private inline getter returns a genuine function-local static half constant.
Named integer locals, separate name-construction and copied argument temporaries,
and a complete right-edge expression reproduce native lifetimes. The existing
`fn_800C1B0C(void*, const int*)` ABI is preserved. No shared headers change.

The ownership audit checks 6,875 active inputs and sixteen unique strong
external providers. Every used undefined symbol is GLOBAL. All 45 references
into the newly local scalar range originate in these two original functions.
A scan of every four-byte window in initialized original data found no raw
pointer to that pool. The GLOBAL -1612 float at `80379538` retains its identity
for existing neighboring consumers; their bytes and addresses remain intact.

The 40 scalar bytes were already credited. They transfer from the end of
`timed_actor_800C152C_constants.c`, two retired eight-byte scalar units, and the
start of `scalar_constant_80379550.c`. The retained prefix is 80 bytes and tail
20 bytes; all 140 prior scalar bytes remain covered. The tail's one-byte string
alignment is naturally compiler-owned. Retired source files and historical
receipts remain preserved, with new canonical manifests describing current
ownership. Shared string and neighboring scalar providers remain external.

New credit is **3,644 code bytes, two functions and 96 data/exception bytes**.
This pair and its compiler data form a complete matching build unit; other
functions from the original translation unit remain separate.

The immutable handoff and caller/ownership evidence are under
`scratch/message_box_layout_800C2CB8_20261020/`. Production object/native checks
and baseline acceptance results are recorded under
`scratch/message_box_integration_20261020/` and the normal generated reports.

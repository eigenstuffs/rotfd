# Clock-action callback selector and original vtable

The previously exact private HN/HO selector body at `8025D874..8025DB30`
(700 bytes) now has an integration-ready ordinary C++ ownership proposal.
This recovers its physical data alignment; it is not a fresh body discovery.
The new production object matches all 700 text bytes, the complete 168-byte
data allocation at `802ECEC0..802ECF68`, and all 62 actual relocations.
Full production registration and original-DOL acceptance remain with root.

The function implements the established seven-event callback protocol, shared
scratch initialization, indexed action dispatch and callback finalization.
Action 14 queries owner flag `0x1F`; action 15 invokes virtual slot `0x80`.
The dedicated header describes the known physical owner prefix, callback and
member-pointer layouts. It does not claim complete original class definitions.

Original GLOBAL `lbl_802ECEC0` is a complete 140-byte vtable: two zero header
words and 33 original function pointers. An ordinary writable typed storage
record retains its identity, extent, attributes and all 33 kind-1, zero-addend
relocations. The generic pointer type describes storage; no code calls through
that partial storage type, and complete method signatures or a native class
identity are not claimed. No aliases, payload rewriting or consumer changes
are involved.

The compiler naturally places LOCAL `@54`, the 28-byte switch table, immediately
after that real vtable at `802ECF4C`. The complete data section starts at the
original eight-byte-aligned address and ends exactly at the independently owned
indexed-action table. This resolves the old standalone switch table's physical
alignment conflict without any synthetic prefix, gap or alignment adapter.
There are no weak helpers, exception sections, ctors, dtors, BSS, small-data
allocations, padding ownership or additional allocated sections.

Fresh current-identity and canonical-section checks find no source ownership
overlap. Full original exception-index, constructor and destructor table scans
find no references requiring ownership. The active consumer census scans
10,234 ELF inputs selected by `objdiff.json`, excluding stale assembly, and
includes numerical relocation targets inside the owned ranges. All 33 original
vtable targets have active defined providers. The two existing source consumers
and their four original/source objects retain every vtable HA/LO reference;
their shared constructor header remains unchanged. The local switch table has
only this function's own zero-addend HA/LO pair.

A bytewise scan of every initialized original data section finds nine pointers
into the function: seven owned switch entries and two function-entry pointers.
It finds no external interior function pointer or initialized pointer into the
local switch table or global vtable. Full original text scans find no external
direct branch into the function.

The final HN verified object's resolved text and switch-table bytes are identical
to this proposal. Every preserved HN/HO source, header, note and research artifact
is inventoried and checked unchanged. The older HN base diagnostic used slot
`0x88`; the final HN verified object and this production source both use the
exact slot `0x80` body. Borrowed member-pointer pool `lbl_802ECE30`, message
`lbl_802AEC64`, shared scratch globals and all adjacent accepted sources retain
their original identities and ownership. This remains a partial original
translation unit.

Frozen production, complete allocation, original ownership, preserved-body and
consumer evidence is under `scratch/engine_callback_clock_action_20261011jw/`.

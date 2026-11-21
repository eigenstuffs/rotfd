# Queued dispatcher original record-tail ownership

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

This separately frozen proposal prepares the 21 queued variant/action
dispatchers for native linking. Their old production sources and handoffs remain
unchanged. All 21 original objects were recompiled and strictly verified.
Eleven switch tables already satisfy the compiler's eight-byte section
alignment; their source and data ownership stay unchanged. The other ten gain
new independent sources named `engine_dispatch_pool_backlog_<address>.cpp`.

Each new source owns exactly the five complete original member-pointer records
used by its original dispatcher, immediately before its 28-byte switch table.
The three-word records are the established ABI tuples copied by the original
calls: zero, virtual slot offset, eight-byte object adjustment. Each new `.data`
section emits exactly 88 bytes at an original eight-byte-aligned address. There
is no arbitrary padding, sliced record, extra helper, or extra allocation.

| Dispatcher | New global five-record object | Original pool prefix retained in assembly | Slot |
| --- | --- | --- | --- |
| `80022384` | `lbl_802AFBB8`, 60 bytes | `lbl_802AFBAC`, 12 bytes | `98` |
| `80048C54` | `lbl_802B3AF0`, 60 bytes | `lbl_802B3AE4`, 12 bytes | `8C` |
| `8004A7A8` | `lbl_802B3BB8`, 60 bytes | `lbl_802B3BAC`, 12 bytes | `8C` |
| `8004E604` | `lbl_802B3ED8`, 60 bytes | `lbl_802B3ECC`, 12 bytes | `8C` |
| `8004F7E0` | `lbl_802B3FA0`, 60 bytes | `lbl_802B3F94`, 12 bytes | `8C` |
| `800512A8` | `lbl_802B4068`, 60 bytes | `lbl_802B405C`, 12 bytes | `8C` |
| `800626A0` | existing `lbl_802B6098`, 60 bytes | entire original 60-byte object transferred | `DC` |
| `800C9B18` | existing `lbl_802C1418`, 60 bytes | entire original 60-byte object transferred | `8C` |
| `80045F34` | `lbl_802B38B0`, 60 bytes | `lbl_802B388C`, 36 bytes | `98` |
| `800623FC` | `lbl_802B6040`, 60 bytes | `lbl_802B6034`, 12 bytes | `D8` |

All named objects retain or acquire global visibility at their exact original
addresses. The eight divided original pool symbols retain their original
names/addresses; only their bounded sizes change to the complete original
prefix shown above. In particular, the 96-byte `802B388C` pool retains three
complete records, not a single twelve-byte prefix. The two existing 60-byte
objects keep their full sizes and identities.

The ten adopters retain 6,784 original text bytes, 200 exception/index bytes,
and 280 switch-table bytes. They propose 600 additional original record bytes.
All instructions, EH, index, and table bytes are identical to the old objects
after applying real relocations. All 301 retained relocation addresses,
symbols, resolved targets, kinds, and addends remain identical. The local
table's object offset changes from zero to 60 while its executable address
stays unchanged. No function identity or source consumer identifier changes.
No matching credit is claimed before central acceptance.

The complete 21-unit layout map and original pool contents are preserved in
`layout_audit.json`. The eleven unchanged table starts are `802B2E38`,
`802B2E90`, `802B3750`, `802B3AC8`, `802B3B90`, `802B3C58`, `802B62B8`,
`802B15B0`, `802B2C80`, `802B37C0`, and `802B3E00`. No Matching source owns any
of the proposed record bytes. Source identifier consumers, existing original
split owners, initialized-data pointer consumers, and actual external pool
relocations from 3,491 current compiled source objects are inventoried. There
are eleven current compiled pool-consumer objects and no missing source object.

The unchanged dispatchers load their records through their original broader
external pool bases, so the new globals are not directly referenced by ELF
relocations. Central adoption must add supported `config.yml` `force_active`
entries for exactly these ten record globals and prove their presence,
addresses, sizes, and bytes in the native map/ELF. The preceding three-unit
adoption checkpoint already demonstrated this supported native retention
mechanism with the original DOL hash; this ten-unit proposal still requires
its own complete original hash and regression checks.

`adoption_proofs.json` records exact before/after source/object hashes, full
symbol partitions, original record words, every retained real relocation,
and complete allocated inventories. `final_integration.json` contains only
the ten new adopters; root must replace those ten old source ownership paths
in the two queued profiles and preserve the eleven safe original units.
`verify.py` independently recompiles all ten and checks exact emitted bytes,
symbol extents/bindings/types, original addresses, actual relocations, and
eight-byte section alignment. Frozen old handoffs are left intact.

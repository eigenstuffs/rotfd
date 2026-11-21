# Early event dispatch and target flag operations

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four ordinary C++ routines are exact in isolated production recompiles, with
full-DOL linking and promotion remaining integrator checks.

| Entry | Text bytes | Exception table + index bytes |
| --- | ---: | ---: |
| `fn_80025F40` | 316 | 8 + 12 |
| `fn_8003D3D4` | 200 | 8 + 12 |
| `fn_80061224` | 472 | 8 + 12 |
| `fn_8006F6CC` | 472 | 8 + 12 |

Total: 1,460 text bytes, 80 exception metadata bytes and28 actual relocations.
GC1.3.2 uses established `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`
flags. Every original allocated byte, function/local-metadata symbol and real
relocated target matches. Objects emit only `.text`, `extab` and `extabindex`;
there are no extra functions, weak helpers, literals, data, BSS, padding,
identifier migrations or verifier adapters.

3D3D4 handles selected eventsD8/D9 through the existing event query/accessor.
Its observed event contains code0, payload8 and words24/28. EventD8 performs the
original payload lookup, invokes virtual slot38, the existing helper802554F4,
and virtual slot78(word28,word24) when a node exists. EventD9 invokes the
original payload removal helper. The virtual object has an8-byte nonvirtual
prefix before its native vptr. All external entry identities stay unchanged.
This routine was exact on its first ordinary probe.

61224 and6F6CC have identical ordinary behavior and original instructions except
address-dependent branches: event83 plus owner flags38 bit44 selects setting
target flags30 bit60 when clear; absent event83 clears that target bit when set.
The target is independently resolved from owner Handle70 for each original
query/update. The64-bit flags and inline mask predicates preserve the original
full two-word tests and updates, including identity high/low operations.

25F40 tests event9A and signed actor bytes354/355. It starts actor callback1
when bit7 is set in the target flags120, or in the further target resolved from
that target's HandleC. Owner actor8 and controlC, control Handle58 and embedded
actor controller318 are the only other exposed fields. Other bytes are opaque.

The registry layout is the previously established manager pointer at global118,
entries pointer8,16-byte entries, object0 and signed generationC. Handle encoding
is signed generation8/index24. Separate ordinary bitfield and byte-backed registry
views for subsequent lookup preserve the original repeated Handle and entries
loads. A single shared view permits CSE to remove original reloads: first probes
for the472-byte pair were416 bytes. Typed read/write lookup views recover exact
original extents, registers and all targets under standard compiler flags;
no volatile qualifier or instruction forcing is used. Their native class names
are not claimed. The initial probes, bounded alternatives and flag experiments
remain privately preserved and uncredited.

Every original assembly function extent and all initialized-data references
were checked. Complete original extabindex80015F60..8001F2C0, ctor80299920..
80299980 and dtor80299980..802999A0 tables show one owned exception record per
function and no startup/termination reference. Original external callback/type
tables retain their assembly owners. `ownership_audit.json` records full table
references and unchanged source/header consumers. Dependencies include actual
undefined ELF symbols only. Adjacent original functions/data remain outside
these four bounded partial translation units.

`scratch/game_engine_early_event_flags_continuation/final_integration.json`
records source/header hashes, exact sections, local exception symbols, flags
and actual relocations. `final_splits.txt`/`final_config.txt` are proposals only.
`allocated_inventory.json` inventories every raw allocation and defined symbol;
`verify.py` performs strict fresh production recompiles. `handoff.json` freezes
all evidence and this note. Central metadata, shared declarations, accepted
source and frozen verifier cores were not changed.

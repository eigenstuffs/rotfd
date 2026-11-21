# Callback dispatcher setup operations

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four ordinary callback dispatchers match all emitted allocations in isolation:
`8002D608` (824 bytes), `800425CC` (808), `800428F4` (800), and
`800477FC` (800), for 3,232 code bytes. Each owns its original eight-byte
exception record, twelve-byte exception index, and 28-byte compiler switch
table. All 151 real relocations resolve exactly. There are no weak backups,
additional helpers, constructor entries, or identifier migrations.

The established event zero through six operations copy five original
three-word member pointers from their existing external pools. Query, callback
index, scratch-global, optional event-seven/eight setter, and final callback
completion behavior follow the earlier dispatcher units. All borrowed pools,
strings, constants, globals, and original callable tables keep their ownership.

`8002D608` queries selectors `51/52` for action nine. Action fifteen operates on
the controller returned by `8007D074`, whose observed state word is at `D0`:
states one/two may trigger `8007705C`, state zero may call `8007626C(1)`, and
state three may trigger `8007705C` after selector `A1`. The query calls and
short-circuit expressions reproduce the original control flow directly.

`800425CC` and `800428F4` query selectors `66` and `67`, respectively. Their
action-fifteen paths enable that selector, resolve the signed 24-bit handle
index and signed eight-bit generation at object offset `70` through manager
`118` and its sixteen-byte entries, and call `8007D6A0` on the resolved object
plus `318`. They obtain an object from virtual slot `B8`, then pass it to the
service at global context offset `164` with their respective global argument.
The first also clears `80377640`. Naming the service pointer before the
virtual call reproduces its original saved-register lifetime and closes the
otherwise four-byte-short direct-argument probe. Both initial near probes and
the exact named-service versions remain preserved in scratch.

`800477FC` compares control value zero with the original external float at
`80378570`. The positive path calls virtual slot `90(0,0)`, converts control
value one to the unsigned word at `74`, and converts values two/three through
ordinary signed-int then byte conversion into offsets `60` and `64`.
The other path calls slot `90(1,0)`; both clear callback flag bit two.

The compiler emits eight-byte alignment for these four switch-table sections.
Their original table starts are already aligned: `802B1808`, `802B2CD8`,
`802B2D30`, and `802B3A18`. Each section is exactly 28 bytes, with no added pool
ownership or alignment storage. The frozen manifests record alignment eight.

The dedicated `ownership_audit.json` independently scans the full original
exception-index, constructor, and destructor tables and inventories original
initialized-data references and compiled source callers. `final_integration.json`
records every emitted symbol, exact source hash, section range, actual
relocation, and undefined dependency. `verify.py` recompiles all four production
files and rechecks the complete allocation and relocation inventories.
The root integrator must still verify the original complete DOL hash and no
match regressions before these units earn progress.

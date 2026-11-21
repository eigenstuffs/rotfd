# Scene record stream controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three ordinary C++ routines match in isolated production recompiles. Full
original-DOL acceptance remains the parent integrator's check.

| Entry | Original text | Exception table + index | Actual relocations |
| --- | ---: | ---: | ---: |
| `fn_8003E5D0` | 96 | 8 + 12 | 6 |
| `fn_800401FC` | 80 | 8 + 12 | 5 |
| `fn_8003FA74` | 332 | 8 + 12 | 21 |

Total: 508 original text bytes, 60 exception metadata bytes and 32 actual
relocations. The established GC 1.3.2 -O4,s -inline auto -Cpp_exceptions on
-use_lmw_stmw on profile reproduces every emitted allocation and symbol, raw
byte and actual relocated target. All three first ordinary probes were exact.
There are no weak helpers, new data pools, padding, renames, migrations or gates.

E5D0 captures the first scene target at +15058 and performs the original reset
and indexed operation for each of nine slots. 401FC forwards its object to the
original base helper, invokes virtual slot +80 through its derived vptr at +8,
then calls the original empty hook and final setup helper. The private object
view uses a nonpolymorphic opaque eight-byte prefix before the derived vptr;
unknown virtual slot signatures are only declarations and are never invoked.
All existing C entry identities are preserved, including external empty hooks.

FA74 is the companion to the record readback control FBC8. It prepares the first
target, invokes the render service's original virtual slots +44/+24/+8 and tests
the first target's signed byte +319. If clear, it logs using the existing
eight-byte small-data object, serializes the target into the second target's
record at +D4 and writes the observed 0x3B5C record extent. Otherwise it allocates
eight bytes through the original allocator with unchanged source/debug strings,
obtains floats from render virtual slots +34/+3C, and writes both floats.
The renderer view preserves its original derived vptr +7C. The record is opaque
storage of the observed read/write size; no unstated fields are reconstructed.
All constant strings and allocator/debug metadata remain externally owned.

Complete original exception-index 80015F60..8001F2C0, constructor
80299920..80299980 and destructor 80299980..802999A0 scans identify exactly one
owned exception record per entry and no startup/termination references. Original
function extents, initialized-data references with enclosing original objects,
and unchanged compiled source/header caller hashes are recorded in
ownership_audit.json. All other original functions, data, callback tables and
constants keep their existing owners. Only actual undefined ELF symbols are
published as dependencies.

The fresh namespace is scratch/game_engine_scene_record_stream_continuation.
final_integration.json pins sources, flags, sections, symbols and actual
relocations; split/config fragments are proposals only. allocated_inventory.json
covers every allocation and defined symbol. verify.py performs strict fresh
production recompiles. No central metadata, shared header, older matching source
or frozen verifier core was changed.

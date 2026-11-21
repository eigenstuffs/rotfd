# Additional early construction and setup entries

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Sixty-five ordinary C++ fragments match 4,184 original text bytes and 1,300
original exception/index bytes. They call one established constructor/setup
routine, then perform directly observed table, word, and byte assignments.
Current entry names and native identities remain unchanged. Existing native
`Agent_80064744`, `Agent_800E3250`, and `Agent_800E3798` entries use actual C++
constructor definitions; other entries keep their established C names.

Most bodies update the table at zero or eight, optionally clear observed fields,
or set an observed byte. The related `fn_800A4CF0`, `fn_800A4DAC`, and
`fn_800A4E70` roots and their callers preserve the incoming opaque word forwarded
to `fn_800A374C`. Callers of `fn_800949E0` and `fn_80081378` explicitly forward
both incoming opaque words. These arguments are part of the observed callable
interface, even where the wrapper only forwards them and does not store them.
Private views expose only observed field offsets and do not infer complete
class layouts or additional ownership semantics.

`fn_800761F0` is an ordinary void setup wrapper: it calls `fn_80237924`, sets
byte `0xC4` to one and word `0xC8` to 70. Its original r3 value follows from
that store sequence; no additional returned-object or integer-return move is
introduced. `fn_8005BFC4` updates its table at eight, sets words `0x90` and
`0x94` to minus one, and clears both observed words of external global
`lbl_80377694`. That global storage retains its original owner.

The GC 1.3.2 established container-base `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` flags emit each original text extent,
eight-byte exception record, and twelve-byte index. All final private probes
and fresh production compiles match every allocated byte, exact function/object
extent, and actual relocation. There are no weak helpers, emitted vtables,
added allocations, assembly aliases, or masked acceptance scores.

The frozen source manifest, hashes, strict verifier, split/config suggestions,
and ownership audit are under
`scratch/game_engine_early_setup_more_continuation/`. Full original extabindex
and constructor/destructor table audits confirm exactly the expected exception
pair and no ctor/dtor references per body. Dependencies contain only actually
referenced undefined ELF symbols. Other original code, external globals and
tables, and neighboring data retain their owners. Each address remains a bounded
partial fragment. Root performs full native executable acceptance.

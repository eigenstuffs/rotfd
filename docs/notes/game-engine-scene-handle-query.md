# Scene typed Handle queries

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ routines are exact in strict isolated production recompiles.
Original full-DOL acceptance remains the parent integrator's check.

| Entry | Original text | Original EH + index | Retained relocations |
| --- | ---: | ---: | ---: |
| `fn_8003F338` | 324 | 60 + 12 | 15 |
| `fn_8003F4F0` | 260 | 60 + 12 | 13 |

Total: 584 original text bytes, 144 original exception metadata bytes and
28 retained actual relocations. The established GC 1.3.2 -O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on profile reproduces all retained bytes and
real relocated targets. There are no data/literal pools, aliases, native renames,
consumer migrations, instruction edits, masked scores or verifier adapters.

Both commands resolve the scene Handle at +1506C, then invoke manager virtual
slot +28 with the argument string at +868. The manager's derived vptr is +24,
after its nonpolymorphic count/capacity/entry-array view. Its returned native
Handle_801F7F10 is genuinely nontrivial, so the compiler supplies the original
hidden return pointer and temporary cleanup. A Handle_8003F47C local first
constructs Handle_8001FF78, then copies the returned word and retains its source.
The input temporary is destroyed with -1 before the original target control
fn_800C4404 is called; the retained local finally destroys its native base with
zero. The original BASE and LOCAL exception actions match exactly.

F338 requires at least three arguments, captures float +8BC and uses the
existing default float constant unless a fourth argument supplies +8C0.
It forwards mode zero and the truncated second float as an integer. F4F0
requires at least two arguments and forwards the original constant, mode one,
and integer zero. A named argument-string local before target resolution
recovers F4F0's original early source load and GPR allocation. Its direct initial
source is preserved and uncredited. F338's first ordinary source was exact.
Private generation/index bitfields and 16-byte entries reproduce signed
24-bit indexing and signed generation comparison; other storage stays opaque.

Each object emits two uncredited native weak destructors: Handle_8003F47C
116 bytes and Handle_8001FF78 112 bytes, plus 104 total EH/index bytes.
Across both objects the backups total 456 text bytes, 208 metadata bytes, and
28 actual relocations. Retained EH references resolve to existing accepted
strong owners at 8003F47C and 8001FF78. Fresh independent recompiles match each
accepted production object and every original allocation and actual relocation.
Canonical, source, recursive header and production hashes are pinned.
The unchanged strict weak/EH core accounts for every emitted allocation,
including raw backup text, EH, indices, symbols and all real relocations.

Actual isolated MWLD links select both original strong destructors and discard
all six backup allocations per source; both reject a wrong fixture basename.
Parent acceptance must repeat actual full-game map/ELF backup discard, original
strong placement and original DOL hash checks. No backup receives matching credit.

Complete original extabindex 80015F60..8001F2C0, ctor 80299920..80299980,
and dtor 80299980..802999A0 scans show exactly one owned original exception
record per command, with no startup or termination references. Original function
extents, initialized-data references and original enclosing objects, plus
unchanged compiled source/header caller hashes are frozen in ownership_audit.
All external table/constant ownership remains unchanged; these are partial
original translation-unit recoveries.

The new namespace is scratch/game_engine_scene_handle_query_continuation.
final_integration.json records exact ownership, all actual relocations and strong
proofs. Split/config files are proposals only. verify.py recompiles retained
and strong sources; native.py freezes actual link/discard proofs.
complete_allocated_inventory.json covers all raw allocations and ELF symbols.
No central metadata, shared header, earlier matching source or old gate changed.

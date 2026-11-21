# Actor timed callback controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three ordinary C++ routines are exact in isolated production recompiles.
Promotion and original full-DOL linking remain parent integrator checks.

| Entry | Text bytes | Original exception table + index |
| --- | ---: | ---: |
| `fn_8008B534` | 908 | 8 + 12 |
| `fn_8008CD8C` | 92 | 8 + 12 |
| `fn_8008D750` | 208 | 8 + 12 |

Total: 1,208 text bytes, 60 exception metadata bytes, 49 actual relocations.
GC 1.3.2 uses the established `-O4,s -inline auto -Cpp_exceptions on
-use_lmw_stmw on` profile. All allocated code and exception bytes, all defined
symbols and all real relocated targets match. There are no extra allocations,
weak helpers, data/literal pools, padding, renames or verifier adapters.

B534 accumulates float elapsed time, queries the original callback sequence,
reads input via the existing service at global +164 and selects callbacks 26,
27 or E. Private owner fields are state +40, phase +44, unsigned input byte +48,
signed armed byte +49 and floats +4C/+50/+54. Actor callbacks are embedded at
+318; observed signed actor flags are +406/+40C and the 64-bit flags field is
+30. The final threshold/actor-state condition resets state and bit 31 before
starting the original actor-query callback. Other storage remains opaque.
The first probe was 912 bytes: its combined `query(26) || query(27)` early return
emitted an additional branch. Two independent ordinary early returns produce
the original 908-byte body, including all original branch offsets. The original
912-byte source is preserved privately and receives no credit.

CD8C tests event 8D, conditionally invokes its original owner helper, then
forwards the actor and double delta to the existing motion update. D750
accumulates float time +40, invokes the original periodic helper at its threshold,
tests event 8D and dispatches the original control helper, then checks the
signed service byte +2E before starting the queried actor callback and forwarding
motion. The distinct double/float arguments reproduce original plain FP versus
paired-single nonvolatile save/restore metadata directly. Both first probes
were exact. External function, scalar constant and global identities stay intact.

Every original assembly function extent was checked. Complete exception-index
80015F60..8001F2C0, ctor 80299920..80299980 and dtor 80299980..802999A0 scans
show exactly one owned exception record per function and no startup/termination
references. The original external callback tables remain assembly-owned; full
initialized-data references and source/header consumer inventory are preserved
in `ownership_audit.json`. Only actual undefined ELF symbols are dependencies.

The fresh namespace is `scratch/game_engine_actor_timed_controls_continuation`.
`final_integration.json` records source hashes, exact sections/symbols/relocations
and flags; `final_splits.txt`/`final_config.txt` are proposals only.
`allocated_inventory.json` records every raw allocation and defined symbol.
`verify.py` performs strict fresh production recompiles. `handoff.json` pins
all sources, this note and isolated evidence. No central metadata, shared header,
prior matching source or frozen verifier core was changed.

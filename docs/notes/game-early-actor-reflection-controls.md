# Early actor reflection controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two independent source units match with GC1.3.2, `-O4,s`, and C++ exceptions:
`fn_80083BDC` (120 text bytes) clears actor byte40C, clears the wide state bit,
and notifies the second monitor; `fn_800854F0` (160 bytes) initializes the owner
base/table, actor/controller references, vector and speed, then copies actor
speed into the owner. They use a new isolated declaration header and preserve
all original external identities.

Strict production validation accounts for280text bytes plus16extab and24index,
14actual retained relocations, all compiler local EH symbols, and complete
original exception/constructor/destructor table ownership. No weak helper,
data, BSS, padding or consumer migration is introduced. Frozen handoff:
`scratch/game_engine_batch121/HANDOFF.md`; full linking remains central.

Adjacent reflection172 and target-setup536 probes are preserved privately;
the latter's native Handle return hierarchy closes RVO/destructor flags but
leaves one commuted FPR multiply. Separate record visibility600/524 probes also
remain uncredited; see the frozen findings in this batch.

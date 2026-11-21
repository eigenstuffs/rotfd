# Early scene mode actions at 8004FE14

The preserved C entry `fn_8004FE14` matches all 800 original text bytes at
8004FE14..80050134, all 112 exception bytes at 80009978..800099E8, and the
12-byte original index at 80017D0C..80017D18. Strict isolated production
recompiles verify every actual relocation and every emitted allocation. Parent
full-game original-DOL acceptance remains required.

The ordinary controller tests event codes 8A, 8B, and 5C. The first records
self selection +64 in the existing global; the second clears it. The third
obtains a nontrivial returned scene Handle, makes a retained local copy, and
selects one of four operations from the existing global. The first case updates
the resolved target, forwards the scene owner's child values +17C and +178,
updates the first scene owner, forwards a retained self Handle to UI, and clears
the global. The other cases reset a second scene object or invoke the target
operation with modes one, two, or three. No jump table or new owned data emits.

Private layouts retain opaque storage: self Handle +4, target Handle +60,
selection +64; manager entries +8, 16-byte entry object +0 and signed generation
+C; context manager +118, scene +124 and UI +164; scene first owner +15058 and
second object +1505C; first owner child +EC; child integer values +178/+17C.
Handles use the observed signed eight-bit generation and signed 24-bit index.
These partial views do not claim complete original class layouts or names.

GC1.3.2 proc750 with O4,s, inline auto, exceptions on and lmw/stmw on reproduces
the original. The Handle_80020834 default construction has two genuine zeroing
layers after the native base constructor. Handle_8003E120 copies through that
base and retains the source. A named self-Handle reference preserves its native
saved-register lifetime. Naming the child and then its second/first integer
values in that order reproduces the original argument-loading schedule. The
initial direct source and all bounded variants remain private; only the exact
ordinary source is proposed for production.

There are 38 retained and 25 uncredited backup actual relocations. Four weak
backup destructors total 424 text and 176 exception/index bytes: the accepted
native Handle_80020834 (116), Handle_8003E120 (120), Handle_80020478 (112), and
private InitZero_FE14 (76). None earns credit. The three retained native weak
references resolve to accepted original GLOBAL strong owners. Their complete
canonical, source, recursive headers, production objects, fresh recompiles,
original sections and actual relocations are independently verified and frozen.
The unchanged standard object/EH/native cores accept the proposed source.

The actual isolated MWLD link discards all twelve backup text/extab/extabindex
allocations and selects all three exact accepted strong destructor inputs. A
wrong fixture basename rejects. Parent acceptance must repeat all complete
actual-game backup-discard/strong-selection checks and original placement/hash.

Full original extabindex 80015F60..8001F2C0, ctors 80299920..80299980, dtors
80299980..802999A0, and initialized-data pointer scans identify only the owned
index reference, with no startup or termination ownership. Existing source/header
consumers and the original C entry are preserved. This is partial original
translation-unit recovery; all other original functions and data keep their
existing ownership. No shared headers, configuration, symbols, splits, old gates,
expected executable hash, or pre-existing artifacts were changed.

The handoff is scratch/game_early_scene_mode_actions_continuation/handoff.json.
final_integration.json contains exact retained ranges, all emitted allocations,
raw hashes, real relocations and strong-owner proofs. verify.py recompiles the
production source and accepted strong owners. native.py preserves actual linker
proofs; ownership_audit.json and original_pointer_audit.json preserve full-table
and consumer evidence. Split/config files are proposals for the parent only.

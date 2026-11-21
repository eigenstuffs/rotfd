# Callback list controls

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Three accepted partial source units reconstruct 416 complete original code
bytes: pending-list insertion at `8025EAB0` (192), callback active-flag clearing
at `8025EB70` (128), and key-based enabling-flag clearing at `8025ECD8` (96).
The canonical manifest is `config/GSQE78/candidates/game-callback-controls.json`.

Insertion allocates a pending record, stores its key, assigns the handle through
the original helper, copies the observed global clock value and supplied float,
and appends to the pending list. It changes the state to three unless the state
is two. Active-flag clearing searches by native member-function-pointer equality
and clears bit zero on the first matching record. Key clearing visits enabled
nodes and clears bit two when their eight-byte key records contain the requested
key. Field and class names are provisional.

The pointer search is expressed as an inline function returning the matching
node or null. GC/1.3.2 reproduces its native by-value member-pointer copy and
`__ptmf_cmpr` call. All allocated sections, complete function extents and actual
relocations are checked by:

```
python3 scratch/game_callback_controls/verify.py
```

Original exception-index, constructor and destructor tables were independently
scanned. No owned nontext bytes or weak helpers accompany these functions.
Adjacent code and referenced global tables retain their original owners.
Full executable acceptance passes the original SHA-1, no-regression report,
source-extent/progress checks and all 26 unit tests.

The 196-byte excluded-key filter remains a private register-allocation near
match in the same scratch directory. Its identical length does not qualify it
for matching credit. The separate callback-activation probe also remains
uncredited; its best legitimate form has six instruction differences.

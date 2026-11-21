# Resource-pointer and storage-owner destruction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twenty-one ordinary C++ destructor fragments, containing 4,920 code bytes and
1,504 original exception/index bytes, reproduce fixed resource-pointer
cleanup, multiple-base destruction, original exception actions, and two storage
owner variants. The frozen manifest gives each original code and metadata
extent independently; intervening routines remain outside the splits.

Nineteen owners assign their primary and secondary tables, virtually delete
each pointer in a fixed-size collection, and release the pointer storage.
Ordinary non-throwing global deletion supplies the original shared exception
action for pointer-storage release and final owner deletion. The typed bases
supply the observed secondary-base offsets and destruction order. One owner
also clears two words in their original assignment order. Another has an inline
Root layer before the external ObjectsOwner destructor. The 80027A08 body
preserves an explicit element guard in addition to the language's delete guard.

The external secondary Object_8007D594 has only its observed prefix represented
here. Different earlier fragments contain larger opaque spans; those spans did
not establish a complete original class size. Opaque bytes, external tables,
resource destructor definitions, and base definitions receive no new ownership
or data credit from these splits.

800AC150 releases raw storage, clears its storage/count pair, and destroys a
two-layer Handle and a pool of empty 58-byte records before the external Root
call. 800C1A54 uses an array of elements with an external constructor and trivial
destruction: native array deletion accounts for the original 16-byte cookie.
Its array and owner deletion functions preserve separate non-throwing exception
actions. The initial nontrivial element probe, which introduced a runtime
destruction helper, remains private and uncredited.

Each production fragment accounts for every allocated byte, symbol extent and
actual relocation without masks, aliases, assembly, or encoded instruction
data. Full original exception/startup table audits verify the owned exception
records. Every native entry migration checks that the old provisional name has
no compiled source/header callers. Frozen strict proofs and source hashes are
in `scratch/game_resource_owner_lifetime/final_integration.json`; `verify.py`
recompiles all production sources. Full executable acceptance is pending.

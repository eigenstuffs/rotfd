# ObjectsMove native destruction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The genuine C++ `ObjectsMove::~ObjectsMove()` entry at `80227B08..80227C30` reproduces all 296 original bytes and actual relocations with the established GC/1.3.2 flags. Source: `src/Game/objects_move_destructor.cpp`. Strict verifier: `python3 scratch/game_objects_move_destructor/verify.py`. No other allocated section, helper function, original table record, owned data, BSS or padding is claimed.

The explicit destruction view retains the observed vptr at +8 and the constructor-established handle and pool offsets. It installs the external ObjectsMove table, checks mode +170 and the external resource manager, repeatedly obtains the virtual index at table +90 and passes that index to record release at +12C, then releases the mode resource. Native member destruction emits the pool deleting destructor, two/one handle null-check layers, the external base destructor with flag zero, and the custom allocator only for a positive native delete flag. The compiler supplies the null guard, short flag test and returned this pointer.

The virtual call view is never instantiated and emits no partial vtable. Original ObjectsMove data and the complete virtual interface remain external. The pool view claims only its already verified 36-byte extent. The observed construction and destruction views do not establish complete original source class declarations.

The external base identity `__dt__20ObjectsBase_802EB3F8Fv` replaces provisional `dtor_80026F28` at its unchanged address and 772-byte extent. This agrees with the existing constructor view and vtable identity; the base function and original exception metadata are now separately owned by [the accepted ObjectsBase unit](game-objects-base-destruction.md), with no additional credit from this ObjectsMove fragment. The old spelling has no compiled source/header callers. The frozen rename evidence is `scratch/game_objects_move_destructor/external-base-rename.json`; central registration preserves original attributes and regenerates fallback assembly references. No alias or thunk is introduced.

Earlier raw-table and inline-base-wrapper probes are preserved privately. Native virtual dispatch plus the ordinary integer index argument resolves both required return-value copies and scheduling. The separate external base destructor removes the extra null test produced by an inline wrapper. Central production/full executable acceptance and final progress remain required.

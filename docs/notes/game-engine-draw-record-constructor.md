# Draw record native construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_draw_record_ctor.cpp` recovers the complete144-byte constructor
at `8021118C..8021121C` as `DrawRecord_802EB0E0::DrawRecord_802EB0E0()`. Its private
construction interface preserves established native ObjectsRoot and
ManipulatorDraw identities and known virtual argument/return declarations.
Address-based derived naming does not claim an original source class name.

Genuine virtual base construction keeps the original intermediate and final
vtable writes through separate aliases. A three-word storage member at20 is
cleared, a two-zero native handle at30 is constructed, and the body assigns
six to2C. Full virtual construction solves the old raw-table probe's missing
28 bytes. Both the first genuine probe and corrected known virtual interface
match all retained instructions; older artifacts remain untouched.

`scratch/engine_draw_record_ctor_20261010cg/verify.py` applies six actual retained
relocations and checks every144 retained byte with standard GC/1.3.2 flags.
Two unused weak handle destructor backups account for172 additional bytes and
four relocations, with no retained reference. No data, BSS, padding, vtable,
exception or startup allocation is emitted. Full raw original extabindex,
ctors and dtors audits include descriptors and zero tails and have no refs.

The existing native ManipulatorDraw table identity is reused. The guarded
function and80-byte EB0E0 table migrations preserve original addresses,
extents, attributes and data ownership. Consumers are continuation-added
`src/Game/engine_record_owner_destroy.cpp` and initial-snapshot
`src/Game/factories_80209554.cpp`. Root alone retains original snapshots/copies,
performs identifier-only replacements and proves unchanged allocated bytes and
resolved targets. This agent changes no consumer or central metadata; no
alias/thunk. The frozen isolated proposal awaits central NonMatching,
original-hash, regression and native allocation acceptance.

# Screen base factory

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/screen_base_factory.cpp` reconstructs `fn_80261708`,
`0x80261708..0x802617A0` (152 bytes), with standard GC 1.3.2 settings.
The isolated production compilation matches every original byte and actual
relocation. Central integration and complete executable checks are pending.

The factory requests `0x50` bytes from the tagged allocator with the native
source strings, line 7 and alignment 4. Successful allocation placement
constructs the already recovered `ScreenBase_800B9368` class: the native
`Object_8025F0D8` constructor, screen base table at offset 8, and three-layer
default handle at `0x48`. Allocation failure returns null.

The genuine virtual class constructor reproduces the native saved pointers
for allocation, object construction and handle construction. An explicit
opaque table assignment folded these pointers together and shortened the
function to 128 bytes; it was preserved as a private diagnostic. Existing
screen construction/destruction sources establish this class and virtual
slot layout. The screen destructor and virtual method remain external, so
this object does not emit a replacement table. Private names distinguish
its unused handle destructor backups from already linked strong definitions.
No assembly or aliases are used.

Run `python3 scratch/game_screen_base_factory/verify.py` for the frozen proof:
152 retained text bytes and 11 actual relocations. All 440 allocated text
bytes are accounted, including three unused weak destructor backups totaling
288 bytes and 12 inventoried relocations. No retained code refers to those
backups; they must be absent from the final ELF. Their allocator-address
relocations are individually audited against the frozen complete relocation
identity table. No data, BSS, padding, or original table ownership is retained.
The verifier checks the original DOL SHA1 and all entries in the complete
extabindex, constructor and destructor tables. This is a partial text split.

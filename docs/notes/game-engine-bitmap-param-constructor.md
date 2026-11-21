# Bitmap parameter constructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_bitmap_param_ctor.cpp` reconstructs the complete 132-byte
`fn_80238ED8` extent 80238ED8..80238F5C as the genuine C++ constructor
`Bitmap_802EBEE0::Bitmap_802EBEE0(int, int, unsigned char)`, emitted as
`__ct__15Bitmap_802EBEE0FiiUc`. It constructs the existing Root/Resource prefix,
installs the Bitmap table, invokes virtual slot 0x18, then calls `fn_80238BA8`
with width, height and format.

The private declaration follows the already accepted Bitmap factory's native
class layout and table identities. Its six Root virtual slots, Resource and
Bitmap destructor declarations, and 0x48-byte Bitmap size are preserved.
There are no table definitions and no aliases or thunks. The accepted factory,
its declaration and original bitmap initialization/cleanup sources remain intact.
The two vtables and Root constructor already use their native identities, so
only this function's old global spelling requires migration.

GC/1.3.2 with standard O4,p/auto inline, exceptions off and
`-use_lmw_stmw on` emits exactly 132 matching bytes and six actual relocations.
There are no other allocated functions, objects, weak backups, data, BSS,
metadata or padding. The full original extabindex allocation
80015F60..8001F2C0, including trailing descriptor/zeros, and full .ctors/.dtors
allocations 80299920..80299980 / 80299980..802999A0 contain no references to
this function. Neighboring original functions/data remain outside the split.

The strict manifest, source/header hashes, real relocation comparison, full
original table audit and old-spelling reference inventories are frozen in
`scratch/engine_bitmap_param_ctor_20261010bv`. `verify.py` recompiles and checks
all emitted allocations. No compiled source/header refers to the old function
spelling. Central integration owns the guarded identity migration and final
original-DOL hash, regression and generated-progress acceptance.

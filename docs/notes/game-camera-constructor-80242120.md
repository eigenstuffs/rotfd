# Camera constructor at 80242120

`src/Game/camera_constructor_80242120.cpp` reconstructs the 268-byte constructor
at `80242120..8024222C`, using GC/1.3.2 and the frozen flags in
`config/GSQE78/candidates/game_camera_constructor_80242120.json`.

The source models the resource base, eight Vector3 members, two layers of
handle initialization, a temporary handle assignment, and scalar settings.
A named unsigned-short flags value reproduces the final member update and
native epilogue schedule. The `Camera_Z.h` factory string supports the inferred
Camera name. Other class details remain partial layout views.

The original function identity is migrated to `__ct__15Camera_80242120Fv`.
An audit of all active native link inputs finds one factory call and no data
references or additional aliases. Changing that call's symbol spelling retains
all 792 caller bytes and all 72 actual relocation targets. Its canonical
manifest is updated with the migration and production hashes.

The constructor has eighteen retained relocations and no owned data, EH or
BSS. Two address-qualified unused weak destructors (172 bytes, four relocation
records) are accounted for and absent from the native linked ELF; they receive
no credit. The original DOL hash passes, `ninja changes` is empty, and all 66
tests pass. Evidence is in `scratch/camera_constructor_80242120_20261020/`.

After this constructor and the simultaneous scalar batch, code is
1,921,852 / 2,607,776 bytes (73.6970%), with 7,972 / 8,803 functions.

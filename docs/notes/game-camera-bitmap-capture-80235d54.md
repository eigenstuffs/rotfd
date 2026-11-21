# Camera bitmap capture lifecycle at 80235D54

`src/Game/camera_bitmap_capture_80235D54.cpp` reconstructs the five contiguous
capture lifecycle functions through 80236BF4. The new completion and update
functions add 3,328 code bytes. Three existing functions totaling 416 bytes
retain their original code. The complete 156-byte scalar pool and 265-byte
string pool also match, adding 20 scalar bytes while preserving 401 previously
matched data bytes.

The source initializes capture controls, samples collision geometry, fills the
bitmap legend, saves the completed bitmap, and reports elapsed time. It uses
the accepted bitmap constructor header and the verified reverse-sphere return
class. Partial object views describe only fields and virtual slots used here.

All 4,165 retained allocated bytes and 132 actual relocations match. The full
compiler inventory includes seven unused weak functions totaling 688 bytes,
their 14 relocations, and all 12 compiler category entries. Native MWLD selects
the existing strong handle destructors for two duplicates and removes the five
unused helpers. Every used undefined symbol has GLOBAL binding. No exception
metadata is allocated by this group.

The ownership audit found all 54 references to the localized literal identities
inside the five functions. The twelve retained suffix-string GLOBAL identities
remain available to neighboring consumers. All initialized original data was
checked for pointers into the localized ranges. The original 3,008-byte code
suffix at 80236BF4 and four scalar bytes at 8037B2A4 remain outside the source.

The frozen package is `scratch/camera_bitmap_scan_80236120_20261020/`.
Production verification is recorded in
`scratch/camera_capture_integration_20261020/production-verification.json`.
The standard DOL hash, `ninja changes`, source extent audit and all 66 tests
pass. A normal link with a map reproduces the entire production ELF exactly.

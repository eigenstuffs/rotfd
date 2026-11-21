# Dolphin CARDDelete

`src/dolphin/card/CARDDelete.c` recovers 3 linked C functions and 508 text bytes.

| Function | Address | Size |
| --- | --- | --- |
| DeleteCallback | 0x8010CD34 | 0xA4 |
| CARDDeleteAsync | 0x8010CDD8 | 0x110 |
| CARDDelete | 0x8010CEE8 | 0x48 |

The [public SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/card/CARDDelete.c) supplies the matching source algorithms. The API resolves the filename, checks whether the file is open, clears the directory entry to 0xFF, persists the directory and frees the allocation chain in its completion callback. Original callback delivery, error propagation and synchronous waiting are retained. The unlinked CARDFastDelete and CARDFastDeleteAsync APIs are omitted.

No initialized data or BSS is owned. State belongs to CARDBios and the caller's file information structures. The shared CARD ABI and previously integrated sources are unchanged. GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches all 508 text bytes after relocation in `scratch/CARDDelete`. Reference files and SHA-256 hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.

# Bitmap resource factory

`src/Game/factory_8020AD70.cpp` reconstructs the complete, integrated 148-byte factory at `0x8020AD70..0x8020AE04`. The registration names the resource `Bitmap`; the allocation diagnostic identifies `Bitmap_Z.h`, line 189. Address-suffixed class names are private reconstruction names.

The factory allocates 72 bytes through the existing engine allocator with `Anonymous New` and alignment 4. Native placement construction preserves the original null-allocation branch. The constructor calls the accepted Root constructor, sets the original Resource and Bitmap virtual tables, and invokes virtual slot `+0x18` to initialize the object. The existing Bitmap table points that slot to `0x80238D28`; this factory does not recover or claim the callback itself.

The partial native class declarations reuse the Root and Resource ABI established by the adjacent Txt factory. The private Bitmap view reserves the remaining 60 bytes without inventing field meanings. Its native constructor preserves the original separate allocation and constructor pointers in `r31` and `r30`; the compiler emits the original virtual dispatch directly from `slot18()`.

The compiler-generated table references remain ordinary external ELF symbols:

| Compiler symbol | Original identity | Address |
| --- | --- | --- |
| `__vt__17Resource_802E9E20` | `lbl_802E9E20` | `0x802E9E20` |
| `__vt__15Bitmap_802EBEE0` | `lbl_802EBEE0` | `0x802EBEE0` |

Central integration reconciles these native names with the original identities. No virtual table, RTTI, diagnostic string, allocator object or other external storage belongs to this source. The native class declarations emit no metadata or unused helper bodies.

`python3 scratch/game_bitmap_factory/verify.py` checks the original DOL SHA-1, the exact strong global function extent, all allocated output, and all 12 actual ELF relocations before comparing every retained byte. Result: **148 code bytes, 12 relocations, zero differences**. The complete object contains only the retained `.text`; it emits no data, BSS, metadata, padding or weak tails. Every relocation is saved in `scratch/game_bitmap_factory/relocations.json`.

The compiler is `GC/1.3.2` with the established Gekko `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on` game flags. No assembly, forced registers, binary patches or new compiler options are used. The candidate is `config/GSQE78/candidates/game_bitmap_factory.json`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 148/148 code bytes and one exact function,
with zero owned data. The source-section extent guard and generated progress
checks pass; reconciled external names preserve the original addresses and
linked bytes. The documented baseline accounting corrections remain preserved.

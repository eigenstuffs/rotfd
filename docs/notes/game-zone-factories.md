# CameraZone and Occluder factories

`src/Game/factories_8020AB58.cpp` reconstructs two adjacent factories at `0x8020AB58..0x8020AC68`. The complete 272-byte fragment is integrated and exact. Registration and allocation diagnostics identify CameraZone and Occluder as SplineZone-derived resources; address-suffixed class names describe the recovered ABI without claiming complete original type declarations.

| Function | Bytes | Allocation | Diagnostic | Observed initialization |
| --- | ---: | ---: | --- | --- |
| `fn_8020AB58` | 140 | `0xF0` | `CameraZone_Z.h:52` | Construct SplineZone, install CameraZone table, clear two 12-byte array descriptors, set kind to 11 |
| `fn_8020ABE4` | 132 | `0xE8` | `Occluder_Z.h:46` | Construct SplineZone, install Occluder table, initialize the embedded 16-byte hash table, set kind to 10 |

Both factories use the existing allocator with `Anonymous New` and alignment 4. Ordinary placement construction preserves the original null-allocation branches. The base is 216 bytes, with a two-byte kind field at `0x6C`; derived members begin at `0xD8`. The hash member's cursor/capacity/count/slots layout agrees with the accepted `hash_init.cpp` and `hash_table_internal.h`, which were read without modification. Its initialization remains a call to the accepted `fn_80207FC4`.

Native C++ construction provides the original virtual-table stores and saved-pointer lifetimes. CameraZone matches with an allocation local. Occluder matches when allocation is passed directly to placement construction; a separate allocation local causes the compiler to emit an extra move and a 136-byte function. Both source forms and their diagnostic results are preserved under `scratch/game_zone_factories/`. No forced registers, assembly, binary patches or compiler-option changes are used.

Central integration reconciles the following ordinary external ELF identities:

| Compiler symbol | Original identity | Address |
| --- | --- | --- |
| `__ct__19SplineZone_8024E5CCFv` | `fn_8024E5CC` | `0x8024E5CC` |
| `__vt__19CameraZone_802EA180` | `lbl_802EA180` | `0x802EA180` |
| `__vt__17Occluder_802EA3E8` | `lbl_802EA3E8` | `0x802EA3E8` |

The existing standalone SplineZone factory independently confirms its constructor and allocation size. The private classes represent only the prefix and member storage needed by these factories; unobserved virtual methods and base details remain outside the reconstruction. Neither existing 88-byte derived table, any RTTI, nor the base constructor or shared diagnostic strings receive coverage from this source.

`python3 scratch/game_zone_factories/verify.py` verifies the original DOL SHA-1, both strong global function extents, every allocated byte, and all 21 actual ELF relocations. Result: **272 code bytes, 21 relocations, zero differences**. The object contains only the two retained functions, with no data, BSS, metadata, padding or unused helper bodies. All relocated operands are recorded in `scratch/game_zone_factories/relocations.json`.

The compiler is `GC/1.3.2` with the established Gekko `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on` game flags. The candidate is `config/GSQE78/candidates/game_zone_factories.json`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 272/272 code bytes and two exact functions,
with zero owned data. The existing standalone SplineZone factory caller now uses
the reconciled native constructor spelling and remains byte-exact. The
source-section extent guard and generated progress checks pass, with the
documented baseline accounting corrections preserved.

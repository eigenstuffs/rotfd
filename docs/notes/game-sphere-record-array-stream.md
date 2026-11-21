# Sphere record array stream reader

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Isolated ordinary C++ reconstruction of `fn_801DA8C0..801DAAB8` in `src/Game/sphere_record_array_stream_801DA8C0.cpp`: 504 matching text bytes and24 actual relocations. GC1.3.2 Gekko/O4,p/exceptions off. The first probe and final typed global-vector variant match; two fresh production recompiles pass the unchanged strict all-allocation/actual-relocation verifier. Complete native integration remains pending.

After the existing base reader, the owner reads a count, resizes its104-byte record array at0x24, and reads the serialized records. Ordinary record construction copies the first three components of the external zero Vec4, sets the float at0x0C from its existing SDA owner, and sets the ushort at0x60 to0xFFFF. The empty destructor and typed placement construction reproduce the native growth/shrink loops. The zero vector `game_vec4_zero[16]` and `lbl_8037A4D8[8]` remain borrowed original allocations; the candidate allocates only its primary text and has no weak backups.

The full original extabindex/ctors/dtors audit finds no references. The complete active input scan covers5,575 objects/119,086 actual relocations and all777,360 initialized words. The sole original data pointer802EA614 remains inside external `lbl_802EA608[88]`. The accepted caller `engine_render_arrays_readback.cpp` and C entry identity are unchanged. No data, BSS, padding, startup ownership or consumer migration is claimed.

Frozen production source, strict reports, ownership proof and two fresh recompiles are in `scratch/game_sphere_record_array_stream_801da8c0/`, listed by batch232. Central metadata is root-owned and untouched.

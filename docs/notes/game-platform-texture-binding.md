# Platform texture initialization and binding

`src/Game/platform_texture_bind.cpp` reconstructs **936 code bytes** in
`80281830..80281BD8` and its **60-byte compiler-generated jump table** at
`802F14A8..802F14E4`. The table is emitted by the ordinary format switch;
its fifteen actual pointer relocations match, including repeated/default cases.
No handwritten table of addresses is used. Both neighboring cache binding
tables retain original ownership.

The 84-byte pool record now has verified native `GXTexObj` at `0`,
`GXTlutObj` at `+20`, another `GXTexObj` at `+2C`, object pointer at `+4C`
and signed byte flags at `+50/+51/+52`. The shared object view identifies
image/palette pointers at `+C/+10`, slot at `+2C`, 32-bit dimensions at
`+30/+34`, byte texture/palette formats at `+3C/+3E`, and flags at `+41`.
These are observed fields, not a claim that the original class ends there.
All four earlier pool/shutdown sources remain unchanged and byte-matched
with the SDK declarations and their verified include path.

A new object acquires a slot through the matching growth routine. The switch
maps formats 1/2 to C4/C8, 7/10 to RGB5A3, 8 to RGB565, 12/13 to RGBA8,
and 14 to CMPR. Indexed textures use palette format RGB565 when object
palette format is 2, otherwise RGB5A3; entry counts are 16/256 for C4/C8.
The texture unit is the CI palette name, and mipmap is disabled. Mask `04` in
the object's flag byte selects linear rather than nearest filtering. Existing
slots reuse their record. Every bind stores the object, sets its sweep mark,
loads a marked palette, updates wrapping and loads the texture. A set auxiliary
flag also loads the secondary object on texture unit 1. Unsupported formats
preserve the original switch fallthrough and record state.

GC/1.3.2 uses the established optimized flags. Ordinary pointer getters and
explicit palette-count branches reproduce the original evaluation/scheduling.
The strict production proof accounts for all **996 allocated code/data bytes**
and **36 actual relocations**, including both zero-constant SDA relocations
and all jump targets. There is no BSS, unused weak code, metadata, padding,
assembly or masked-probe credit. The constant remains original shared data.

The adjacent empty hook at `80281EA0..80281EA4` is now also reconstructed
in the existing pool-lifetime unit. Its ordinary empty C body emits the original
single return. The existing constructor/destructor retain their exact bytes;
584 unused weak-helper bytes remain absent and uncredited. The full seven-entry
`802816D0..802820B4` texture-pool code block now has **2,532 source bytes**
across four matching build units. This establishes contiguous code coverage,
not an original translation-unit boundary or complete neighboring table ownership.

Full integration is byte-identical to the protected DOL. All 678 source units
remain exact, all 23 tooling tests pass, and progress, source extent and source
assembly audits pass. The original baseline is unchanged. Evidence is in
`scratch/platform_texture_bind_checkpoint.json`,
`scratch/platform_pool_hook_checkpoint.json`, their linked/header proofs,
and the strict production verifiers under `scratch/game_platform_texture_bind/`
and `scratch/game_platform_pool_hook/`.

# Dolphin GX transforms

Three C fragments recover nine functions and 1,104 code bytes from the linked GXTransform unit:

| Fragment | Original range | Functions | Bytes |
| --- | --- | ---: | ---: |
| GXTransform_projection | 0x80116D38..0x80116EAC | 2 | 372 |
| GXTransform_current | 0x80116F4C..0x80116F84 | 1 | 56 |
| GXTransform_viewport | 0x80117038..0x801172DC | 6 | 676 |

The [Melee GXTransform reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXTransform.c) provides projection upload, matrix selection, viewport depth conversion, scissor bounds and clipping algorithms. GXSetProjectionv marks bpSent as 1 in this target, matching GXSetProjection; the older reference marks it 0. All other selected algorithms reproduce the target without changes. Unlinked APIs, including GXProject, projection/viewport/scissor getters and indexed matrix upload, are omitted.

GXLoadPosMtxImm at 0x80116EAC..0x80116EFC, GXLoadNrmMtxImm at 0x80116EFC..0x80116F4C and GXLoadTexMtxImm at 0x80116F84..0x80117038 contain inlined native paired-single upload assembly. The reference explicitly declares WriteMTXPS* as assembly. Their combined 340 bytes remain original fallback, outside recovered C coverage; the production sources contain no assembly.

The viewport fragment owns three 4-byte float constants (0.5, 342, 16777215) at .sdata2:0x80379938..0x80379944, alignment 8. Four external alignment bytes follow before the next original constant. Other fragments own no data, and no fragment owns BSS. Shared GX headers are unchanged.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off` reproduces all 1,104 code bytes and 12 initialized data bytes after relocation against the original DOL. The three compile/verification scripts and preserved original disassembly are under `scratch/GXTransform`. Individual function identities, object sizes and relocation targets are recorded in each candidate manifest. Full-DOL and native objdiff checks remain integration checks.

The central build now passes the original DOL SHA-1 and native objdiff code/data audit for these owned source fragments. All previously linked source units retain their matches.

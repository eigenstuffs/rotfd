# Sphere against transformed box: first improved hit

The isolated ordinary C++ reconstruction of `fn_801DFBC4` covers all 716 original code bytes. It transforms the eight original cube vertices by the supplied matrix, tests six quadrilateral faces with `fn_801B7C18`, and returns the first hit that improves the supplied result. The six actual relocations preserve the original cube BSS, face-index data, zero float and query callee. None of their storage belongs to this source.

The native call passes four named 16-byte vertex values by address. Const-reference declarations retain their lifetimes and reproduce the original ABI. Sequential x/y/z/w assignment in the vertex constructor and one reused loop counter reproduce the original scheduling without assembly or register directives. The fourth argument is a 64-bit mask in r7/r8, with the ABI alignment slot r6 unused.

The 48-byte query output is independently established: `fn_801B7C18` forwards its output on four paths to `fn_8027B140`, whose success path writes through offset 0x2C. Its fields after the normal are observed word/float stores with unknown meanings. The same native evidence supports the accepted grid triangle sweep. The result view preserves the observed validity byte at 0x3C and mask at 0x28; unobserved words remain unnamed.

The source and header are unregistered. A fresh production object is text-only, alignment 4, with one compiler category relocation and six actual relocations; every relocated byte matches. A private real MWLD link checks retention and actual assigned borrowed/SDA addresses. It does not replace the future full-game original-placement check. Complete original exception/startup tables show no ownership. Current complete consumer closure and root integration remain pending; this note claims no new progress yet.

Preserved probes and production evidence: `scratch/game_triangle_list_collision_801dfbc4/`. Existing oriented-box research remains separately uncredited and unchanged.

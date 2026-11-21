# MetroTRK memory helpers

`src/MetroTRK/mem_TRK.c` recovers the complete linked C memory unit: TRK_memset and TRK_memcpy in .init at 0x800033A8..0x800033FC (84 bytes), and TRK_fill_mem in .text at 0x8011C304..0x8011C3C0 (188 bytes). All three functions total 272 code bytes. There is no initialized data or BSS.

The [Melee MetroTRK memory source](https://github.com/doldecomp/melee/blob/master/src/MetroTRK/mem_TRK.c) supplies the exact algorithms. TRK_memcpy copies bytes forward; TRK_memset returns its original pointer after invoking the fill helper. TRK_fill_mem aligns the destination, expands the byte value to a word, writes eight words per large iteration, then handles remaining words and bytes. The reference's union of byte and word pointers is retained; it reproduces the original allocation where a cast-based runtime variant did not.

This unit requires GC/1.3 with the ordinary MetroTRK auto,deferred options. GC/1.3.2 emits a shorter final length-mask sequence; GC/1.3 reproduces the original immediate load followed by an AND. The selected no-inline pragma keeps the 188-byte helper separate from its initializer wrapper. Both section alignments are 4, with no owned padding. Every code byte and the cross-section call relocation match the original in the isolated verification. The complete candidate is config/GSQE78/candidates/MetroTRK-mem_TRK.json; compile and verification scripts are under scratch/MetroTRK.

The adjacent native TRK_flush_cache and machine-register helpers remain original fallback. This unit is entirely C and adds no native assembly coverage. The integrated source passes whole-DOL byte equality, native objdiff code/data checks, and the original-source regression audit.

The adjacent original interrupt-vector image is an explicitly named native fallback block. See [its boundary note](MetroTRK-interrupt-vector.md) for the additional previously unmeasured denominator bytes. The complete C memory unit remains linked; no original image bytes are included in its source ownership.

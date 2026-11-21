# Key-array loading templates

Nine functions at `0x801B1440..0x801B252C` match 4,332 bytes of game/engine
code. Their repeated
allocation, construction and reading patterns are reproduced by the ordinary
C++ templates in `include/game_curve_load.h`. The original names, full
translation unit and most key payload fields remain unknown. These are
partial text splits with no owned data.

The source reads a 16-bit mode and 32-bit element count, resizes a key array,
then reads the payload. Its header contains count at offset 4, capacity at 8,
and the allocated pointer at 12. Growth calls the observed allocator or
reallocator, then placement-constructs newly added elements. Shrinkage
destroys removed elements before changing storage. Empty destructors preserve
the otherwise empty loops emitted by this CodeWarrior version; they do not
invent extra work or replace instructions with assembly.

The eight matched instantiations have 12-, 8-, 16-, 8-, 20-, 40-, 20-, and
16-byte keys. All initialize the leading 16-bit timestamp to zero; one also
loads its offset-12 float from the original constant at `0x8037A218`.
Uninterpreted payloads remain explicitly unnamed. The allocator objects,
shared float, and external read helper remain outside these splits.

GC/1.3.2 with `-O4,p -inline auto -use_lmw_stmw on` reproduces all 195
relocations and code bytes across the three matching candidates. The compiler
emits the template wrappers in reverse source order. The final executable
hash remains the acceptance check after integration.

`0x801B17F0..0x801B1A14` initializes and destroys reference-bearing keys and
reads each reference through the descriptor table. Its loader body is a
regular function; expressing the entire body as another inlined template
changed register allocation. Keeping the shared resizing operations in the
template and the reference-reading loop in this function produces all 548
bytes exactly.

Verification scripts are `scratch/curve_load/verify_a.py` and
`verify_b.py`. The reference-bearing key unit uses `verify_reference.py`.

Two base operations at `0x801B1040..0x801B1094` also match 84 bytes from C:
conditional deallocation controlled by the signed destructor flag and
initialization of the leading mode word to one. They use the same compiler
without requiring multiple-register saves. The actual class names remain
unknown; the verified callers and array headers establish their relationship
to the loader family. Their verifier is `scratch/curve_base/verify.py`.

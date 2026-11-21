# Three engine flag arrays — `80232BB0`

`fn_80232BB0` resizes three contiguous count/capacity/data arrays to counts read
from its second argument at offsets `0x0C`, `0x18`, and `0x24`. Their element
sizes are 8, 16, and 2 bytes. It then resets every element, including those that
already existed: the first element type has three halfwords set to one and one
halfword set to zero, the second has eight halfwords set to one, and the third
has one halfword set to one.

The source reconstructs the shared reserve/resize operations with native C++
templates and placement constructors. Growth initializes new elements; shrink
runs empty native element destructors before reallocating. The heap routines,
allocator identity, signed count comparisons, count/capacity updates, constructor
null guards, and reset store order all match. Source array element types are
unknown here, so the second argument exposes only the observed count positions.

The reset method shares its loop index and count between arrays. An explicit
reference names the scalar element before resetting it. This ordinary C++ form
matches the original register allocation without assembly, fixed registers,
manual unrolling, or instruction encodings. The compiler emits the eight-element
unrolled reset loops itself.

Private verification uses GC/1.3.2, `-O4,p -inline auto`, C++ exceptions and RTTI
off, and `-use_lmw_stmw on`. It proves all **2,208 allocated text bytes** and
**54 actual relocations**, including equality with the original object's full
symbol names, bindings, relocation kinds, offsets and addends. The compiled
object defines exactly one global function at offset zero, size `0x8A0`, in
`.text` aligned to four bytes. There are no owned data sections, exception
records, compiler metadata relocations, weak backups, or additional allocations.

This is a partial text split from the automatic original range
`8023297C..802340F4`. The original function at `8023297C..80232BB0` and functions
at `80233450..80233944` and `80233944..802340F4` remain original. The existing
function identifier is preserved; no symbol migration or shared-header change
is required. Full native DOL and regression acceptance belong to integration.

## Accepted integration

The production object reproduces every allocated byte and all 54 original
symbolic relocations. The production build adds one non-allocated `.mwcats.text`
relocation to the same function; this metadata is accounted separately from
matching code. Final ELF placement, global binding and the complete 2,208-byte
function extent are verified.

The normalized DOL hash remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.
`ninja changes` is empty, source extents pass for 5,767 linked source units and
6,739 data/BSS sections, and all 66 tests pass. Generated progress is
1,924,724 / 2,607,776 code bytes (73.8071%), 7,978 / 8,803 functions, and
971,636 / 1,030,936 data bytes. The two new original residual units stay in the
denominator; total code, function and data denominators are unchanged.

Private immutable reconstruction evidence is under
`scratch/native_triple_array_reset_80232BB0_20261020_parallel/`; production
verification and pre-integration config/split backups are under
`scratch/triple_array_reset_integration_20261020/`.

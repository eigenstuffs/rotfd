# Platform array lifetime

Two partial source units reconstruct five functions and **480 code bytes**:

| Source | Original range | Bytes |
| --- | --- | ---: |
| `platform_arrays_derived.cpp` | `801EA210..801EA278` | 104 |
| `platform_arrays_base.cpp` | `801EC754..801EC8CC` | 376 |

The base fragment contains the virtual float accumulator at `801EC754`,
two signed integer min/max helpers, and the 320-byte native destructor.
The derived destructor resets its own table, invokes the native base
destructor with deletion disabled, and releases its allocation when requested.
Both use the native C++ destructor ABI and class-specific arena delete.
Names identify observed addresses; original class and file names are unknown.

The base has a vptr at zero, a float at `+10`, and two count/capacity/data
arrays at `+1C` and `+28`. The first array holds 24-byte records with trivial
cleanup. The second holds four-byte links. Original initializer `801ECA54`
writes signed 16-bit previous/next indices at link offsets zero and two.
A nested trivial link destructor reproduces the original simple counted
cleanup loop; the record loop retains the compiler's eight-way empty-loop
unrolling. The inheritance spelling is a reconstruction, not a recovered
original source name or proof of its exact template hierarchy. Unknown
record contents and remaining base fields are explicitly left unidentified.

The original 16-byte tables at `802EA874` and `802EA884` each contain two
zero header words, their respective destructor, and shared float accumulator
`801EC754`. Their final words are genuine method pointers, not padding.
They remain original-owned data. A full native virtual-class probe matches
both tables and all code in isolation, but its separately emitted eight-byte
aligned data sections cannot reproduce these positions inside the larger
original table group. The production declarations therefore use an explicit
vptr view, as in the existing native Manipulator destructor. Destructors
assign the original external table addresses; ordinary C++ still supplies
native deletion flags, null checks and base/member destruction. No replacement
table, assembly, altered object bytes, or alignment override is used.

The production compiler is GC/1.3.2 with the established `-O4,p -inline auto`
settings, exceptions/RTTI disabled and `-use_lmw_stmw on`.
`scratch/game_platform_array_lifetime/verify.py --production` accounts for all
480 emitted text bytes, five strong functions and **17 actual relocations**.
No weak helpers, data, BSS or padding are emitted or credited. The original
constructors, list operations, shared tables and neighboring cache classes
remain outside these partial splits. Native-table probes are preserved in
`scratch/game_platform_array_lifetime/`.

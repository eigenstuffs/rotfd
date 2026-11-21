# Private audio acquisition candidate

The private source `scratch/game_platform_audio_acquire/platform_audio_acquire.cpp`
reconstructs the 732-byte routine `80287178..80287454`. It is **uncredited**.

Its resource view uses a flag byte at `0C`, signed sample rate at `10`, identifier
at `1C`, and AX parameter-block pointer at `20`. After resolving the resource
handle and rejecting identifier minus one, it compares the global ARAM limit
against half of the parameter block's joined high/low loop address. The failure
diagnostic receives both capacity and required address as variadic arguments.

The generic setup helper receives a handle copied by value through a derived
physical handle view, preserving base construction, zeroing, copy/increment and
destruction. A successful index at least 32 is reduced by 32 once. AX address,
source, ADPCM and loop parameters are installed from offsets `0`, `10`, `1E`
and `46` in the native parameter block. The routine sets channel flags and
sample rate, applies the native option bits, clears the track timer, sets source
ratio, installs the address again and starts the voice. These layout names and
the complete class relationships are inferred, rather than original declarations.

`scratch/game_platform_audio_acquire/verify.py` verifies all 732 function bytes
using **24 actual relocations** and an exact eight-byte local compiler-generated
signed-conversion pool. It separately accounts for 172 weak destructor bytes
and four unlinked helper relocations. All allocated bytes and symbols are
accounted for, with no assembly or relocation masking used.

The local conversion pool belongs at `8037B8B8..8037B8C0`, which already has a
strong source definition in `platform_audio_constants.cpp`. The private
function body and pool agree with that native address, but linking both source
owners would duplicate storage. This candidate is not registered, has no
canonical manifest, and changes no progress totals. Its manifest explicitly
marks integration unavailable pending consistent source/data ownership.

A union-based conversion that borrows the existing double compiles to an extra
`frsp`; defining the double alongside an ordinary cast emits a second eight-byte
pool. The `gecko_float_typecons` pragma does not remove the union probe's extra
rounding instruction. Those alternatives remain private. Future integration
must preserve the scalar block, all existing callers, symbol visibility and
full DOL without counting duplicate data or changing the expected hash.

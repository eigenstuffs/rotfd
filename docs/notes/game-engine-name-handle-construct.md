# Name-backed Handle construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Original fn80084F00 is recovered as an ordinary two-argument native C++
constructor. Its isolated production object reproduces340 original text bytes,
120 extab bytes,12 index bytes and27 retained actual relocations. The established
GC1.3.2 space/inlining/EH/lmw-stmw flags are used. Central original DOL and full
native backup discard acceptance remain required.

An eight-byte Root constructor calls existing fn80090084. The next inline
Object800814D0 layer installs table802B92B0, clears words8/C and assigns the two
arguments. Its observed extent40 leaves an opaque tail from10. The complete
object installs table802B8ED4 and constructs the four-byte typed Handle at40,
whose default construction has four zeroing layers. Bytes44/45/46 are cleared
and the inherited enabled byte4 is set.

Two ordinary Name temporaries call the original string-to-name entry801F948C
using the original SDA and non-SDA strings. Existing fn801B550C is declared to
return the actual nontrivial native Handle value. This reproduces the hidden
return pointer at stackC. Inline typed assignment constructs a retained copy at
stack8, releases the owner Handle40, copies the word, retains the copy, and
destroys it. The native returned Handle is destroyed with flag-1. This genuine
C++ expression reproduces the full original register/stack lifetime and seven
exception PC states without explicit stack storage or ABI assembly.

The original Object800814D0 destructor name is retained. Exception actions also
reference the existing strong native Handle8002F6B0 and Handle80085054
destructors. Their canonical manifest/source/header hashes, original relocations,
production object hashes and independent identical recompilation proofs are
frozen. The compiler emits472 uncredited weak text bytes and208 uncredited
EH/index bytes, with28 backup relocations: two native destructor backups and two
unique private zero-layer backups. Every emitted allocation and real relocation
is inventoried with raw SHA256 by the adopted bounded strong-override gate.
Final native ELF/map verification must retain both strong owners at their
original addresses, discard all four backup text/EH/index groups and show both
private backup symbols absent. No backup bytes receive matching credit.

The proposed guarded identifier migration is fn80084F00 to
__ct__15Object_80084F00FUlUl. The complete source/include old-name audit found no
consumers. original_symbol and source hashes are frozen; the original C
identities of external setup calls remain unchanged. The original full
extabindex table80015F60..8001F2C0 contains one record at80019F68 referring to
extab8000DCB0 with the exact340-byte extent. Full ctors80299920..80299980 and
dtors80299980..802999A0 have no references. All retained compiler metadata is
owned by this source; no extra data is allocated. No shared metadata, prior
source, assembly extraction or frozen handoff was modified.

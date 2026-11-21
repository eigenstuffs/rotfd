# Early actor vector search

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8008D9DC` reproduces324text bytes,8extab bytes at8000E7B0, and12index bytes
at8001A688 with ordinary C++ under GC1.3.2,-O4,s,exceptionson. Five actual
retained relocations and all allocated bytes match the supported original DOL.
Central original-placement linking remains required before matching credit.

It resolves the controller's handle at64, then that object's related handle
at1F0. It visits the resulting group's handle array (count30,capacity34,items38)
until native validation fn801F7EB8 succeeds. The first valid object's vector at1C
is assigned to owner4C with the native three floating-point loads/stores, then
the loop exits. Both nested manager entries use the observed16-byte layout:
object pointer0,generation byteC; manager entry pointer is at8.

Using distinct typed entry/manager views for the second nested resolution
preserves the original entries reload through the retained manager pointer.
A single unified view lets CodeWarrior reuse the first entries pointer and
emits320bytes. The second view restores324bytes and all original instruction
operands without casts to volatile, assembly, or register forcing. The complete
loop and saved-register allocation then match exactly.

The production source is standalone and has no headers. It emits only one global
function and actual compiler-local extab/index objects. There are no owned
literals, data/BSS, padding, weak definitions, aliases, startup entries, external
identifier migrations, or existing consumer changes. The full original
extabindex80015F60..8001F2C0 and ctor/dtor tables80299920..802999A0 were audited;
only this function's expected single EH entry refers to the retained range.
The standalone verifier recompiles production, pins its hash, checks every
allocated extent and symbol, applies all actual relocations and compares all
original bytes. Shared metadata/global builds were untouched.

Independent private fn8008D420 quaternion spherical-interpolation research is
preserved under scratch/game_early_quaternion_interpolate and receives no credit.
Its ordinary source reconstructs the RVO result, sign-adjusted right quaternion,
clamped dot, sine weights, vector operators and external normalization. Enabling
native floating-point contraction and assigning vector then scalar components
recovers the532-byte original extent. The best bounded source has28 operand or
scheduling differences; variants retain532..544byte extents. Existing accepted
caller/source declarations are untouched.

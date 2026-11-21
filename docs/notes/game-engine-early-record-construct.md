# Early record construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated production candidate: `engine_early_record_construct_800E1A28.cpp`.
The unit compiles with GC 1.3.2, `-O4,s -inline auto -Cpp_exceptions on
-use_lmw_stmw on`, and reproduces all 140 original code bytes, 28 extab bytes,
12 extabindex bytes, and nine actual relocations. Central integration and full
original DOL acceptance remain the integrator's responsibility.

The observed root view has a table pointer at 0, an enabled byte at 4, and two
words at 8/C. A separate eight-byte Root constructor calls the existing original
C entry `fn_80090084`; the inline Object_800E172C constructor installs table
802C867C, clears the two words, then stores the two constructor arguments. This
ordinary two-level class hierarchy preserves the original separate root pointer
and complete-object pointer lifetimes, including `mr r0,r28` and the r28-r31
save range. Combining both root layers in one class was eight code bytes short;
its private initial probe is preserved and receives no matching credit.

The derived constructor installs table 802C8630 before constructing a 0x94-byte
opaque member at 0x10 via original C entry `fn_800219A8`. Existing destruction
source for the same table establishes this member's two four-byte handles at
relative offsets 8C and 90; no additional member interpretation is claimed.
After member construction, the observed word at A4 is cleared, enabled is set,
and the root word at C is copied into A4.

The original entry was `fn_800E1A28`; the proposed native constructor name is
`__ct__15Object_800E1A28FUlUl`. A complete source/include identifier audit found
no old-name consumers. The manifest records this original_symbol migration;
assembly callers and original table references retain their original addresses.
The original base destructor already has the accepted identity
`__dt__15Object_800E172CFv`, which is used unchanged by the compiler's genuine
DESTROYBASE exception action. No helper functions, aliases, or assembly are
emitted by this candidate.

The full extabindex table 80015F60..8001F2C0 has one record for this function,
8001E6CC, referring to extab800146F0. The complete ctors80299920..80299980 and
dtors80299980..802999A0 tables contain no references. Original section bounds,
true function extent, original unit identity, and remaining data ownership are
recorded in ownership_audit.json. All allocated output is exactly the retained
text, extab, and index; undefined ELF dependencies alone enter the dependency
list. Existing accepted source and all shared metadata remain untouched.

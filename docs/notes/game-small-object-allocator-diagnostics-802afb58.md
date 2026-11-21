# Small-object allocator diagnostics at 802AFB58

The original `.rodata` interval `802AFB58..802AFB98` contains the allocation
label `Anonymous Alloc`, source name `SmallObjAlloc_Z.cpp`, and the six-word
order table `{1, 2, 0, 2, 0, 1}`. The table's eight-byte alignment generates
the original four-byte gap after the two strings. The complete 64-byte block
is now owned by `src/Game/small_object_allocator_diagnostics_802AFB58.cpp`.

GC/1.3.2 produces three global symbols of sizes 16, 20, and 24, no
relocations, and every original byte. Existing allocator source refers to the
string identities. The full native DOL retains the original SHA-1; `ninja
changes` has no regressions, the source extent audit passes, and all 66 tests
pass. This adds 64 verified data bytes, without claiming adjacent original
data or allocator code.

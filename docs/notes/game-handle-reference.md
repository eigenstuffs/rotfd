# Handle reference count and automatic release

`src/Game/handle_reference.cpp` reconstructs `fn_801F86C8` at
`0x801F86C8..0x801F88AC`: one 484-byte function with zero owned data.
It verifies the signed handle index against the registry's upper bound and
compares its generation. The original does not add a lower-bound check.
A valid record's signed 16-bit reference count at offset 10 receives the delta.
If the wrapped count becomes zero and the manager's signed flag at offset
`0x20` is enabled, the method releases the object.

The inlined release checks the handle again, invokes the manager virtual slot
at vtable offset `0x10` on the object's identity at offset four, clears the
record flag at byte 13, sets its 16-bit link at byte eight to minus one, and
deletes the object through its native virtual destructor. It then hashes the
empty name, resets the reference count, increments the eight-bit generation
while skipping zero, clears the object pointer, and appends the original index
to the free-index stack. The free-count store precedes the free-array pointer
load. Ordinary C++ virtual dispatch and deletion preserve all original calls.

The record view uses typed lvalue access into the observed 16-byte storage.
A full entry view for the generation zero check reuses the same byte stride and
retains the exact indexed versus member accesses. A local records the old free
count before appending. These source-level storage and lifetime choices match
the original without register directives, assembly bodies or object changes.

The only declared constant is the observed first NUL at `0x8037A820`, exposed
as an external one-byte empty string. The original symbol's wider eight-byte
storage remains untouched and entirely outside source credit. The declaration
produces the original SDA relocation; no literal is manufactured or claimed.

`python3 scratch/game_handle_reference/verify.py` compiles the production source
with GC/1.3.2 and the recorded Gekko `-O4,p -inline auto -Cpp_exceptions off`
flags. It applies both actual ELF relocations and compares every allocated byte
to the protected original. All 484 bytes match. Exactly one strong global
function and no weak helper, data, BSS, exception record or padding are emitted.
The candidate is `config/GSQE78/candidates/game-handle-reference.json`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 484/484 code bytes and 1 matching function;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.

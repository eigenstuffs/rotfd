# Pool factory and repeated collection: unpromoted C++ recovery

Both bodies below retain original fallback and receive no source-match credit.
The originals and central build files were not edited. The exact Game compiler
flags used by these durable probes are GC/1.3.2, `-proc gekko -fp hardware -enum int
-str reuse -common off -O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`.

## Handle factory, 0x801F9144..0x801F93FC

`scratch/game_handle_factory/near-match.cpp` reconstructs the complete 696-byte
factory, together with the preceding four-byte empty hook at 0x801F9140. Nine
relocations resolve against current canonical symbols. Four instruction bytes
remain different, all in two generation-load/sign-extension pairs:

- 0x801F9240 / 0x801F924C: target loads raw generation in r4 then sign extends to
  r6; compiler loads directly into r6 and sign extends it in place.
- 0x801F92B0 / 0x801F92C0: the same register difference.

The native C++ return ABI is recovered: a four-byte nontrivial Handle is returned
through the hidden first parameter. The function grows the pool by 512 when its
free stack is empty, updates the object's name, pops and initializes a slot,
constructs a local packed handle from index and generation, attaches it to the
object, updates the name again, calls the object's initialization virtual, and
copies the local handle into the return result. The actual copy constructor
increments the reference count and performs the observed wrap-to-zero cleanup.
The local then invokes the native destructor with the compiler's complete-object
flag -1. This matches the entire original stack and lifetime flow.

Compiler variations, signed-byte/enum/value-wrapper locals, reference bindings,
record accessors, array index types and slot-bitfield layouts do not resolve the
last four bytes. The newly recovered root name-update helper's signed-byte local
was checked: here it exchanges the index and raw generation registers and gives
eight differences. All probes remain beside the best source.

## Repeated collection, 0x801F8D50..0x801F9140

`scratch/game_handle_collect/near-match.cpp` reconstructs the complete 1,008-byte
collector. Eleven relocations resolve; 27 differing bytes remain, all temporary
register choices within the two slot scans. There are no missing instructions,
changed branch destinations or altered operations.

The collector temporarily disables automatic destruction, repeatedly clears
activity for valid object identities, marks roots through the context and
several global systems, traverses the marked-handle list, invokes the context's
cleanup hook, and destroys inactive entries. Collection repeats until no
inactive object was processed; automatic destruction is then enabled again.
The original counts an inactive object even when its identity fails validation,
and this behavior is preserved.

The list traversal uses the observed bitset first/next operations, resolves
four-byte packed handles through 16-byte registry slots, and invokes virtual
slot 0x1C. A separate inline traversal helper with its own globals load restores
the target saved registers for that whole region. Reusing a scan index declared
at function scope restores the original zero-register copy before the final
scan. An explicit validity helper accepting index and generation also restores
the final destruction index's saved register. The complete deletion, hash reset,
generation increment (skipping zero), pointer clear and free-stack append tail
then matches.

The best source uses direct indexed field access in the scan bodies. Source
variants with native identity fields, named object/slot locals, signed-byte
validity locals, pointer/reference helpers, inline activity setters, alternate
array index types, and supported optimization/inlining settings are preserved.
They do not eliminate the remaining register choices.

Exploratory relocation-aware transcripts are the two `near-match.txt` files.
No matching candidate manifest was written, because these differences remain.

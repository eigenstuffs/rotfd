# Native fixed-record and memory-card construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ constructor fragments match all 388 code bytes, 108 original
exception/index bytes and 36 actual ELF relocations under GC/1.3.2 with the
established space-optimization and exception flags. They emit no extra code,
data, weak helpers or padding. Their original compiler metadata is owned with
the source; both complete true function extents and the full original exception,
constructor and destructor tables were audited.

| Entry | Native identity | Text | Exception/index bytes |
| --- | --- | ---: | ---: |
| 800E6DE0 | Object_800E6E68::Object_800E6E68 | 136 | 48 |
| 800E81C8 | Object_800E81C8::Object_800E81C8 | 252 | 60 |

Object_800E6E68 retains its already accepted native destructor identity. It has
an eight-byte header at offset04 and three Record_800E6A58 members at offset0C.
The established record stride is 0x3B5C and the complete object size is 0xB220.
A trivial header initializer installs the original table before native array
construction. The body writes the original shared five-byte `SBSP` literal
(including its terminator) into the eight-byte header, then clears bytes08..0A.
The byte-backed header view keeps the observed label/flag overlap within valid
array bounds. The original SDA literal and native table retain fallback data
ownership.

The native record constructor dependency at 800E65F4 is still original fallback:
the guarded declaration names it `__ct__15Record_800E6A58Fv`, consistent with its
existing native destructor and verified array stride. Its 1,008-byte body earns
no credit from this handoff. It had no accepted compiled-source callers before
this new fragment. The constructor pointer passed to `__construct_array` and
the destructor pointer in both code and exception metadata resolve to their
original addresses, without relocation masking.

Object_800E81C8 derives from the existing native 0x60 ContainerBase. Its trivial
StringFields initializer installs the final table before constructing the
native 0xB220 records member at C8. The original exception actions still target
that member's native destructor and ContainerBase's native destructor directly.
The body resets the observed trailing words/flags, copies four bounded strings,
allocates 12 bytes through the original allocator and invokes original setup
800E863C. Its complete 0xB310 size matches the accepted GCMemCardAgent.h:25
factory at 800BBF24. The factory is the sole compiled consumer requiring an
identifier migration; its frozen source/canonical hashes are in the manifest.

These are partial translation-unit splits. Native tables, string pointers,
shared format/data objects, original allocator/setup routines and the record
constructor's original body remain outside them. Existing accepted sources,
headers and metadata were not changed. The isolated verifier recompiles the
production fragments and checks every emitted allocation, symbol and actual
relocation. Full native link/hash and regression acceptance remain the
integrator's responsibility.

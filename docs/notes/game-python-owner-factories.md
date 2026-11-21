# Python owner creation wrappers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Eight ordinary C++ Python bindings reproduce 2,368 code bytes and 160 original
frame/exception-index bytes. They parse an empty argument tuple, allocate the
observed size with the original debug allocation parameters, invoke the native
Root, Hierarchy, ContainerBase or Agent constructor through placement new, and
return a Python pointer-name string. Failed allocation returns a new reference
to the existing Python None object.

The shared pointer encoder builds hexadecimal digits in reverse, prefixes the
result with an underscore, and appends the registered native type name. The
original 32-byte scratch buffer and 512-byte output buffer are reconstructed.
The one-byte empty string has its original small-data relocation. A constant
view of the existing shared string pool reproduces its saved address across
calls; native placement construction reproduces the constructor return value
flow. The initial raw constructor-call probes remain private and uncredited.

Class declarations expose only external constructors and opaque storage of the
observed allocation size. Constructor implementations, string pools, registered
types, None storage, allocator definitions and neighboring bindings remain
outside these splits. The new shared header is hashed with every source.

Each fragment owns its original eight-byte frame record and 12-byte exception
index. No other allocation, literal, weak helper, padding or BSS is emitted.
All 160 actual relocations, complete allocated extents and original table
ownership verify without masks, aliases or assembly. Existing C entry names
remain intact. Strict frozen manifests:
`scratch/game_python_owner_factories/final_integration.json`.
Full executable acceptance is pending.

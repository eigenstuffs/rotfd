# Spatial registry destructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/spatial_registry_destructor.cpp` reconstructs `fn_8024D160`, the 588-byte deletion entry at `8024D160..8024D3AC`. Its dedicated header describes the observed registry key, two removal contexts, two owned arrays and three empty derived Handle layers. The complete original translation unit and borrowed data remain external.

The destructor restores the original vtable, validates the signed 24-bit Handle index and generation through the established Manager field accessor, and passes the resulting key by address to both available removal contexts. It then destroys eight-byte empty records and layered Handle elements, frees their arrays, destroys the inner object and base, optionally frees `this` for a positive signed 16-bit deletion flag, and returns `this`.

The first typed-entry probe matched the full extent with fifteen differing words in key lookup. Restoring the already established generic field accessor, native Handle index method and Manager member key method resolves all remaining differences through ordinary C++ inlining. Private variants are preserved in `scratch/game_spatial_registry_destructor_8024D160`; no register forcing, assembly or object patching is used.

The isolated production source matches all 588 text bytes after 22 actual relocations. Its object has exactly one strong text function and no other allocated bytes or weak helpers. A complete scan of all 3,141 original exception records, constructor/destructor slots and exception terminal record finds no references requiring additional ownership. Native symbols, calls and borrowed vtables remain unchanged. Central full-DOL acceptance is pending.

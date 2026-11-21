# Sphere return layers

Two ordinary C++ wrappers are exact in isolated GC 1.3.2 production objects.

| Entry | Original extent | Text | Real relocations |
| --- | --- | ---: | ---: |
| `fn_8024673C` | `8024673C..80246798` | 92 | 1 |
| `fn_80246E14` | `80246E14..80246E64` | 80 | 2 |

The first transforms the sphere borrowed from owner+0xB0 through object matrix+0x124, copies the returned center/radius to its output, and returns1. The second transforms a matrix into a sphere through `fn_80246E64`, then forwards the original input and full-expression return temporary to `fn_801F0A20`. Both helpers retain their original C linkage; genuine C++ sixteen-byte Sphere return types reproduce the hidden output pointer ABI. The vector copy and sphere assignment use scalar fields. Names and owner fields remain provisional partial views.

Both first ordinary probes and both production sources match every allocated byte and actual relocation with unchanged `-O4,p -inline auto -Cpp_exceptions off` Game flags. Each object contains only its sole global function, totaling172 text bytes and three actual REL24 relocations. No weak helpers, data, literal pools, BSS, exceptions, startup entries or padding are emitted. Complete original extabindex `80015F60..8001F2C0`, constructors `80299920..80299980`, and destructors `80299980..802999A0` scans find no ownership. Existing callers, external helper owners and all original C identities remain unchanged.

Frozen evidence is in `scratch/engine_sphere_return_layers_20261011fp/`: original disassembly, exact source probes, complete symbol/allocation inventories, actual relocations, original table audits and `final_integration.json`. `python3 scratch/engine_sphere_return_layers_20261011fp/verify.py` recompiles both production sources and repeats complete strict verification plus frozen hashes. Root performs production integration and original DOL hash/regression acceptance before progress credit.

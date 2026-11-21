# Factories with explicit initialization

Eight additional factories compile to 956 exact code bytes. One early game
factory also emits twenty exception-table/index bytes. All 85 relocations
and every allocated section match the protected original in the isolated
verification. No code, data or diagnostic address is patched.

| Function | Diagnostic header | Bytes | Observed initialization |
| --- | --- | ---: | --- |
| `800BBF24` | `GCMemCardAgent.h` | 92 | Allocate `0xB310` bytes and call constructor |
| `801EB824` | `SkinGC_Z.h` | 120 | Base constructor, vptr, zero fields at `98/9C/A0` |
| `802092A8` | `ConsoleInterp_Z.h` | 128 | Base constructor, vptr, three zero fields and a `-1` field |
| `8020A4A4` | `DynamicAnim2_Z.h` | 132 | Intermediate/derived vptrs and three zero fields |
| `8020A528` | `DynamicAnim1_Z.h` | 136 | Intermediate/derived vptrs and four zero fields |
| `8020A6E4` | `Rtc_Z.h` | 84 | Allocate and construct, using a small-data filename |
| `8020A738` | `MaterialObj_Z.h` | 132 | Intermediate/derived vptrs and three zero fields |
| `8020A7BC` | `GameObj_Z.h` | 132 | Intermediate/derived vptrs and three zero fields |

`FactoryView` describes only the observed prefix, virtual-table pointer and
initialized word fields. Reserved byte ranges preserve offsets without
inventing member meanings or claiming complete class layouts. The source
retains allocation, null handling, base construction and derived
initialization in their original order. Constructors, virtual tables and
diagnostic strings remain external and earn no coverage from these fragments.

An ordinary inlined base-initialization helper preserves the intermediate
virtual-table store in the animation and object factories. This matches the
compiler's original inline-constructor behavior without volatile qualifiers
or assembly. Field assignments are separate statements so their original
store order is retained. The `Rtc_Z.h` declaration has its verified eight-byte
extent, allowing the compiler to emit the original small-data reference.

GC/1.3.2 uses the regular game flags; only the `800BBF24` object enables C++
exceptions. `scratch/factory_special/recover.py` records the reviewed
parameters, layouts and source emission. `scratch/factory/verify.py --special`
compiles the source, resolves all relocations, checks every function size and
allocated section, and compares with the original DOL. Candidate manifests
retain the per-function evidence. The standard DOL hash, direct binary
comparison and native objdiff remain required for integration.

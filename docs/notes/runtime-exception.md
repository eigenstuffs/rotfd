# Retained std::exception methods and metadata

The two C++ fragments recover both retained standard exception methods without changing accepted allocation or exception-runtime sources and headers.

| Source | Original text range | Code bytes | Initialized data |
| --- | --- | ---: | ---: |
| `Runtime/Exception_destructor.cpp` | `0x8011EE20..0x8011EE68` | 72 | 44 |
| `Runtime/Exception_what.cpp` | `0x8011EE68..0x8011EE74` | 12 | 10 |

The declarations and empty destructor/diagnostic bodies agree with the preserved `reference/strikers-msl/exception.h`. Both methods retain weak linkage corresponding to the reference's inline standard-library members. GC/1.3 with the existing allocation-runtime flags reproduces all 84 code bytes and all 54 owned initialized bytes. The destructor's vtable and exception records are generated normally by the C++ compiler; no instruction assembly, manual destructor control flow, or hand-written vtable was substituted.

The destructor owns these original metadata objects:

| Section/range | Object | Bytes |
| --- | --- | ---: |
| `extab`, `0x80015E80..0x80015E88` | Compiler-generated destructor exception record | 8 |
| `extabindex`, `0x8001F1DC..0x8001F1E8` | Compiler-generated exception index | 12 |
| `.data`, `0x802CFEB0..0x802CFEC0` | Compiler-generated `std::exception` vtable | 16 |
| `.sdata`, `0x80375E10..0x80375E18` | Recovered RTTI name/base-list record | 8 |

A prior standalone class definition also emitted the `"std::exception"` type-name string. That name begins at `0x802AB9EC` within the shared allocation-runtime pool, rather than at a standalone 8-byte section boundary. Declaring the verified RTTI record before the C++ class makes CodeWarrior use that record directly. The ordinary two-field definition contains the external name pointer and a null base-class list, reproducing both original words. Its mangled RTTI identity permits the compiler-generated vtable to reference it normally. This solves the ownership boundary without manufacturing an operator-new body, adding dummy metadata uses, overriding weak data, or modifying compiler output.

The original 15-byte name at `0x802AB9EC..0x802AB9FB` is independently verified as `"std::exception\0"`. It remains external fallback data under the descriptive export `std_exception_type_name`; the source does not claim its bytes or adjacent `bad_alloc` strings. The explicit RTTI record has global linkage in this partial reconstruction; the original record was local to the allocation unit. The separately accepted Gecko exception unit has its own local record with the same RTTI identity, which remains separate and unchanged.

The `what` method returns its original `"exception"` literal, owning exactly ten rodata bytes at `0x802ABA08..0x802ABA12`. Six following zero bytes before `__ptmf_null` at `0x802ABA18` remain external original alignment padding. This fragment emits no vtable, RTTI, exception record, or BSS. Both fragments pass the original full-DOL SHA-1, direct byte comparison, and complete native objdiff code/data matching after integration.

`scratch/runtime_exception/verify_destructor.py` applies all nine destructor/data relocations and verifies every allocated ELF section, plus the external name bytes separately. `verify_what.py` applies both diagnostic relocations and checks its complete text and literal. Section alignments are 4 for text and exception records, and 8 for rodata, vtable data, and RTTI small data. Neither source owns BSS or padding. Candidate manifests are `runtime-exception-destructor.json` and `runtime-exception-what.json`; the latter's accepted status must be preserved during later isolated rechecks.

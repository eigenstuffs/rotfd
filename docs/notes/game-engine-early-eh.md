# Early engine destruction with exception metadata

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: three ordinary C++ native destructors, 720 retained text bytes plus 156 original exception bytes, 41 actual relocations. Sources and `final_integration.json` are under the `engine_early_eh` prefix and `scratch/game_engine_early_eh_continuation`. GC/1.3.2 uses the established container-base flags: hardware Gekko, `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`; ordinary class operator delete is declared `throw()`. Production recompile passes strict original bytes, all allocated sections, function/object extents and actual relocations. Parent staging/full DOL/regression acceptance remain required.

| Original function | Compiler-native symbol | Text bytes | Actual relocations |
| --- | --- | ---: | ---: |
| 0x80020E58 existing native symbol | `__dt__14Agent_80021260Fv` | 212 | 12 |
| `fn_80021064` | `__dt__15Object_80021064Fv` | 164 | 10 |
| `fn_80021108` | `__dt__15Object_80021108Fv` | 344 | 19 |

Each owns one exact compiler-emitted 40-byte extab record and 12-byte extabindex pair. The records are respectively extab 0x80005940, 0x800059B8 and 0x800059E0, with extabindex 0x8001608C, 0x800160B0 and 0x800160BC. All original exception bytes and local metadata symbols are frozen in the manifest. No helpers, weak functions, BSS, padding or other data are emitted. Full original-table audits cover extabindex 0x80015F60..0x8001F2C0, ctors 0x80299920..0x80299980 and dtors 0x80299980..0x802999A0; no constructor/destructor table references exist.

Agent teardown destroys the observed two-layer handles at +0xBC, +0x8C and +0x88 before its external base destructor. The middle object destroys a three-layer handle at +0x70 before its external base. The lower object destroys the three-layer handle at +0x64 and two-layer handle at +0x60, then ordinary inline inherited teardown updates two native tables, destroys the two-layer handle at +0x58 and frees the four-byte-element array at +0x48 before calling the native object destructor. Private classes expose only observed lifetime/storage layouts; opaque gaps do not claim complete original class recovery.

Two native function renames carry explicit `original_symbol` mappings and have no accepted source/header callers. The Agent additionally needs a guarded **dependency-only** publication: original assembly `dtor_80020F2C` at 0x80020F2C becomes `__dt__15Object_80020F2CFv`. That address has no accepted source/header callers and remains entirely original assembly, earning zero source credit. Both the function and dependency mappings are recorded in the frozen manifest/audit. Protected `fn_80020FE8` and its accepted callback startup callers remain unchanged.

The 188-byte base at 0x80020F2C remains uncredited: explicit ordinary handle teardown plus protected base call produces a 168-byte variant with genuine repeated-null-test and EH-offset differences; its probe evidence is preserved. Native class-body recovery of that base would require a separate accepted design. Proposed splits/configuration are siblings of the manifest; original surrounding text and other tables/data remain under their original owners.

Dependency-scope correction: the original freeze incorrectly treated compiler-local exception symbols such as `@33` as globals when their names also appeared in the original symbol table. `dependency_symbols` now includes only referenced ELF symbols whose `section_index` is zero. Source, allocated bytes and actual relocation records are unchanged. Pre-correction scripts/manifests are preserved under `before_dependency_scope_fix/`; `dependency_scope_correction.json` records each removed local dependency. The strict verifier now checks the dependency set against the emitted ELF symbol bindings.

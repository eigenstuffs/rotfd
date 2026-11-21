# Early native member construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two native constructors recover 368 text bytes and 140 bytes of original exception/index records. Existing constructor and dependency names remain intact. No original accepted function/header or central metadata is edited. Private declarations reproduce observed layouts and native object lifetimes.

Agent_80021260 at 80021260 (232 bytes) derives from the existing Object_80020F2C view, size 0x88, whose inline constructor calls existing setup fn_80259354. It constructs two ordinary two-layer Handle members at 0x88 and 0x8C, initializes the quaternion at 0x90 from game_quat_identity and vectors at 0xA0/0xAC from game_vec3_zero, clears 0xB8, and constructs the final Handle at 0xBC. The first member initializer assigns the original derived table at offset 8. The final member initializer uses ordinary comma expressions to initialize preceding scalar/vector fields before that Handle construction. The native EH actions release Handle_80020B90 members and the native Object_80020F2C base at their established offsets.

Agent_80062E18 at 80062E18 (136 bytes) constructs the existing Agent_8002B5F4 primary base (0x90 bytes) and Object_8005E258 secondary base (0x160 bytes). The latter inline setup calls existing fn_8005E0D4; its secondary table is at offset 4 of that base. A normal six-layer zero-initialized Handle at 0x1F4 uses a member initializer expression to assign primary/secondary tables and byte flags before construction. The byte at 0x1F8 is cleared afterward. The EH records target the existing native destructors for both bases. The secondary-base extent and table locations agree with the earlier accepted multi-agent destruction view.

Intermediate inline Handle layers declare external destructors, which the retained constructor metadata does not reference. This preserves ordinary constructor behavior while avoiding unused compiler-generated weak destructor bodies/metadata. No such declared-only symbol becomes an ELF undefined dependency unless actually referenced. The first diagnostic probe with implicit intermediate destructors had exact retained bytes but extra weak output; it is preserved in report_first_cpp.json and is not accepted output.

GC 1.3.2 with the established container-base flags, including -O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on, emits only the two original functions and all owned EH/index bytes, with strict actual relocations. Full original registration-table audits find no ctors/dtors registrations. Root integration and original DOL hash acceptance are required for progress.

Native constructors 8004E90C and 8004FAE8 remain private, uncredited near-matches: the ordinary base/member initializer shape loses two pointer-copy instructions and a saved register compared with the reference. Bounded direct-call, composition, and inline-base variants preserve the same mismatch. Existing accepted functions and identities remain untouched. Agent_8002B5F4 itself remains unclaimed because its original base cleanup names the protected C entry dtor_80024E50; no alias or rename is introduced.

# Fixed record arrays and native lifetime

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three genuine C++ destructors recover 1,104 original code bytes plus all 156 associated compiler exception metadata bytes. The 904-byte owner at 800E6A58 contains seven groups of 464-byte records with observed 128-byte reset prefixes and a final wrapped fixed array of 300 two-byte records. Group sizes follow native offsets: five, three, four, four, four, five and four records. Its body clears seven observed words and 100 short indices. Automatic array/member/base destruction reproduces the original reset loops, member guards, eight __destroy_arr calls and real native element destructor pointers. The first probe lacked the final array wrapper; the preserved ordinary wrapper closes the final eight code bytes and all relocations.

The two 100-byte element destructors at 800E5F90 and 800E69E4 have empty bodies and genuine custom deletion. Their sizes are established by the original array strides; opaque storage preserves unobserved fields. Address-qualified type names do not assert original names or complete translation-unit recovery. The custom `operator delete throw()` naturally produces each original unexpected path, 40-byte exception record and 12-byte index using established GC/1.3.2 native exception settings.

Production source is `src/Game/fixed_array_lifetime_<address>.cpp`, with shared declarations in `include/Game/fixed_array_lifetime.h`. Run `python3 scratch/game_fixed_array_lifetime/verify.py`. The frozen manifest records complete sections, function/object extents, source/header hashes and all 42 actual relocations. No additional allocated helper, literal, BSS, padding, vtable or allocator data is emitted or credited. Original provisional names have no compiled source/header callers and can be replaced at their exact original addresses. No alias, thunk, object patch, assembly or mismatch mask is used. Central production and original executable acceptance remain required.

Subsequent original array destruction at 800E6E68 establishes a 0x3B5C complete owner stride. The 800E6A58 private destruction view ends at 0x3B58 because its final observed short array ends there; four trailing opaque bytes require no destruction. Consumers must retain the full 0x3B5C stride. This does not change emitted code or claimed source extent.

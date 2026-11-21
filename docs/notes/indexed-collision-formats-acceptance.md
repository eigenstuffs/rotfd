# Indexed handle, collision control, and format strings: accepted checkpoint

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 43 repository tests.

The `indexed-collision-formats` checkpoint adds two matching functions (620 code bytes) and fourteen ordinary C++ data units (10,646 initialized-data bytes). The code consists of the 32-byte indexed handle getter at 80235C08 and the 588-byte collision-height controller at 801BDCAC. The data retains 311 original GLOBAL string objects: 10,193 string/NUL bytes and 453 bytes of natural compiler alignment across 216 internal ranges.

The producer notes and all earlier checkpoints remain frozen. Full acceptance uses `scratch/continuation_20261010/accept_indexed_collision_formats_checkpoint_v36_v3.py`. It preserves every prior gate and verifies exact production objects and actual relocations, both complete native ELFs and their maps, all owned and borrowed symbol identities, full physical overlap and GLOBAL alias rejection, original neighbors, and complete original exception/startup tables. The current census covers 10,490 original/current inputs, 204,111 allocated relocations, and 501,416 initialized original data byte positions. The owned ranges have 1,291 reference records: 1,244 string references, thirteen getter branches, and 34 collision entry pointers. No reference targets internal or external padding.

An independently reviewed exact input-scope proof preserves all previous production inputs and the original bytes, relocations, and GLOBAL identities of the three repartitioned original objects. Exactly sixteen source objects are added; the two code objects account for all ten new actual relocations. The accepted after-inventory is preserved for subsequent checkpoint transition proofs. Four prior live-census audits have bounded, reviewed derivatives for the ten-relocation increase; their originals remain unchanged.

Eighteen existing original-only boundary identities totaling 34 zero bytes are split at explicit alignment one. They receive zero source credit. Both native ELFs preserve their sole original identities, bytes, map placement, and physical extents. The 216 internal alignment ranges have no synthetic GLOBAL aliases. Failed private split preparations, earlier audit versions, and the initial outer-review parser field mismatch are retained with their corrective derivative records; no failed attempt is represented as accepted.

Final verification passes the original DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`, `ninja changes`, source extent and progress checks, all 43 unit tests, all 174 native override cases, and 32 new dual-native unit cases. Accepted totals are 1,830,144 / 2,607,776 code bytes (70.180261%), 7,734 / 8,803 functions, and 511,842 / 1,030,936 matched data bytes (524,538 complete data bytes). The original baseline and all denominators are preserved.

The immutable route seal is `scratch/continuation_20261010/indexed-collision-formats-root-route-seal-v1.json`, SHA-256 `0ea664fb607c3290d97a8cb2c4fbb92e4478299e7f74797b499907886b5545b0`, with 16,459 pinned files. This remains a partial decompilation; unfinished original code and data remain in the denominator.

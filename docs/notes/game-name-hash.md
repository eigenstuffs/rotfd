# Engine name hashing

`src/Game/name_hash.cpp` reconstructs the two contiguous functions at `801F948C..801F9598`, together with the 1,024-byte CRC table at `802EAAD0..802EAED0` and the 256-byte case-folding BSS at `80340C00..80340D00`. GC/1.3.2 produces all 268 text bytes and initialized data exactly after six relocations; BSS dimensions and placement are verified. The central full-DOL build, native objdiff source checks, and original-source regression audit pass.

The hash ignores its first argument and accepts the string in the second argument, consistent with the observed name-hash wrapper. It starts with all bits set, folds characters through the initialized table, updates a reflected CRC-32 using polynomial `0xEDB88320`, and complements the result. The 256 explicit table values were independently regenerated with eight polynomial steps per index and compared against the original data. The initializer maps ASCII lowercase letters to uppercase and preserves other table entries. The original signed-character indexing is retained.

The two functions and complete data/BSS are recovered ordinary C++; no original source or whole translation-unit identity is claimed. Names remain address-based until stronger class/symbol evidence is available. Validation: `scratch/game_handles/name_hash_verification.txt`; manifest: `config/GSQE78/candidates/game_name_hash.json`.

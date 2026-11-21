# Sparse handle lookup by object key

`src/Game/sparse_handle_key_find.cpp` reconstructs `fn_8026BC50`, the 248 bytes
at `8026BC50..8026BD48`. It iterates occupied entries in a sparse handle pool,
resolves each handle and compares the object's leading pointer field with the
supplied key. It returns the first matching occupied index, or minus one.
The pool contains its handle storage at `08`, bitset at `0C`, limit at `1C`
and used count at `20`. First/next helpers retain the original limit checks
and calls to `fn_80207B94`.

GC/1.3.2 with standard optimized Game flags reproduces every byte after all
four actual relocations are applied. Run the complete object check:

```
python3 scratch/game_sparse_handle_key_find/verify.py
```

The only emitted allocated section is the exact 248-byte text function, with
one global symbol and no weak functions, constants, data, BSS, constructor or
destructor table, exception table, or padding. Original references are direct
calls; no original constructor entry or owned data accompanies this partial
text split. Adjacent functions and the external manager retain their existing
ownership. No original translation-unit boundary is claimed.

`candidate.json` and `actual_relocations.json` preserve the isolated evidence.
Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.

# Hierarchy nested-handle status queries

`src/Game/hierarchy_related_status.cpp` recovers the two adjacent methods at
`0x80206868..0x80206B44`: `fn_80206868` (440 bytes) and `fn_80206A20`
(292 bytes). Their original names and full translation unit boundary remain
unknown. The candidate is strictly verified in isolation; complete DOL and
native objdiff integration are pending.

The hierarchy's handle list has count/capacity/data at `0xD0`/`0xD4`/`0xD8`.
Each selected handle resolves through the global manager's 16-byte entries,
checks the signed generation byte, then follows another handle at object offset
`0x6C`. The final object exposes a signed flag byte at `0x18`. The private
`active` name describes the nonzero test; the flag's gameplay meaning is not
established.

`fn_80206868` returns that signed flag for a nonnegative index. A negative index
scans the list, checks each outer handle with `fn_801F7EB8`, and returns one on
the first nonzero related flag or zero when none is found. `fn_80206A20` returns
the signed-byte logical inverse of that scan. It does not modify the hierarchy.
The implementation preserves the original nested resolution and pointer-use
order without introducing extra validation.

The existing recovered `Manager`/`RelatedManagerView` distinction is important:
two ordinary typed table access paths preserve the second table load visible in
both methods. A single manager view lets the compiler reuse the table pointer
and removes four bytes. The indexed query uses an inline signed-byte
`getActive()` accessor; direct field access changes the final load and
sign-extension registers. The scan helper's signed-byte return preserves the
sign extension before logical inversion in `fn_80206A20`. Probe variants are
retained under `scratch/game_hierarchy_status/`.

The compiler is GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions off
-use_lmw_stmw on` and standard Gekko hardware-FP flags. Reproduce with:

```sh
python3 scratch/game_hierarchy_status/verify.py
```

The verifier compiles the production source, checks its recorded SHA-256,
accounts for both complete function extents and every allocated section, and
applies all eight actual ELF relocations at their original addresses. All 732
code bytes match the untouched DOL after relocation. No data, BSS, exception
records, padding, or unused weak bodies are emitted. The only external
identities are `lbl_801E9D24` and `fn_801F7EB8`. No instruction bytes or relocation
fields are ignored or patched after comparison.

The original DOL SHA-1 is
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`. The candidate manifest is
`config/GSQE78/candidates/game_hierarchy_related_status.json`; its exact
verification transcript is `scratch/game_hierarchy_status/verification.txt`.

Full integration passes: the native report credits both functions and all
732 code bytes, with no data attribution. The complete rebuilt DOL is
byte-identical to the protected original, and the source-section extent guard
passes. The distribution caller's prototype now reflects the recovered
signed-byte result; that caller still evaluates the query and discards it.

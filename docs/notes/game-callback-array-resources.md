# Callback arrays and resource assignment

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-callback-array-resources.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

Three partial text units reconstruct **448 bytes and four complete functions**.
The two resource assignment wrappers at `802585E8..80258654` and
`8025D588..8025D5F4` are 108 bytes each. They decrement the outgoing handle's
reference count, copy the incoming packed word into member `+10` or `+68`,
then increment the incoming reference count through original `fn_801F86C8`.
They preserve the original manager re-read after each call.

`callback_array_erase.cpp` owns `80255A90..80255B78`: clear (108 bytes) and
erase-by-value (124 bytes). The clear wrapper caches the initial array length
and repeatedly removes its first word. The erase wrapper searches in order,
decrements length on the first equal value, then copies subsequent words over
the removed word. Both preserve the original `memcpy` call and byte count;
they introduce no replacement library algorithm.

`scratch/game_callback_array_resources/integration.json` freezes source hashes
and complete function boundaries. `verify.py` recompiles all three production
sources and checks every allocated byte, symbol extent and actual relocation.
All 448 bytes match. No data, constants, exception sections, weak functions or
padding are emitted. Original manager and library bodies retain existing
owners. Full table ownership audit, DOL hash and regression checks remain the
central acceptance gate. Earlier array expression probes are retained without
credit; explicit local data and the original decrement expression reproduce
the native loads and scheduling.

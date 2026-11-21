# CodeWarrior byte-copy helper

`src/Runtime/CPlusLibPPC.cpp` reconstructs `__copy` at `0x8011EDA4..0x8011EDD4`. It copies the requested bytes when the destination and count are nonzero and returns the destination. The implementation follows the [pinned Wind Waker source](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/Runtime/Src/CPlusLibPPC.cp), preserved unchanged with the existing upstream license under `reference/tww-msl/`.

`python3 scratch/runtime_cpluslib/verify.py` produces exactly the original 48 code bytes with GC/1.3.2. There are no relocations, exception tables, or owned data. The manifest records precise flags and hashes. Full-DOL integration is a separate parent check.

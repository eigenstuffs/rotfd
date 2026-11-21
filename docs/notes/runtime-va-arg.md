# PowerPC variadic argument access

`src/Runtime/__va_arg.c` reconstructs the complete retained helper at `0x8011EC7C..0x8011ED44`. It advances the saved integer or floating-point register cursor, handles eight-byte argument alignment, and falls back to the caller's stack argument area when the appropriate registers are exhausted. Indirect arguments are dereferenced according to the compiler's argument type code.

The normal C implementation and twelve-byte argument-list structure follow the [pinned Wind Waker source](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/Runtime/Src/__va_arg.c), retained unchanged under `reference/tww-msl/` with its existing license. GC/1.3, `-O4,p`, and signed `char` reproduce all 200 original code bytes. There are no relocations or owned data.

Run `python3 scratch/runtime_va_arg/verify.py` to compile and compare the entire allocated object against the read-only original DOL. The candidate manifest records exact flags and hashes; full-DOL integration is checked separately.

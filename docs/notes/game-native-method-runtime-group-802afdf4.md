# Native method and runtime-base group at 802AFDF4

The former original-only `.data` interval `802AFDF4..802AFF80` consists of
two 160-byte method records around a 76-byte runtime-base list. The records
now extend `src/Game/runtime_base_lists_802AFC68.cpp`; its compiler-owned
`.data` extent is `802AFC68..802AFF80` (792 bytes). This is a partial data
split. The referenced methods, runtime type descriptors, and other original
translation-unit material retain their separate owners.

The source uses named function and runtime-type pointers and the established
`NativeRuntimeBaseList<9>` type. GC/1.3.2 emits the exact 792 original bytes
and all 132 actual relocations, including 87 in the newly transferred group.
The three new global objects retain their original addresses and sizes in
the final ELF. The private bounded probe and the pre-extension source are
preserved in `scratch/native_method_runtime_group_20261020/`.

The transfer adds 396 matched data bytes without changing the 1,030,936-byte
data denominator. The DOL passes the original SHA-1 check, `ninja changes`
shows no match regressions, the source extent audit passes, and all 66 tests
pass.

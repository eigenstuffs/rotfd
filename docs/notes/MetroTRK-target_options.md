# MetroTRK serial-console option

`src/MetroTRK/target_options.c` recovers GetUseSerialIO and SetUseSerialIO at `0x8011E62C..0x8011E648` (28 bytes). The [Pikmin 2 target-options source](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/TRK_MINNOW_DOLPHIN/target_options.c) supplies the same two accessors and static byte flag.

The source owns the original static `u8 bUseSerialIO` at `0x8033D238`, exactly one BSS byte. Its seven following alignment bytes at `0x8033D239..0x8033D240` remain in the original `padding/target_options.s` split and receive no source credit. Both the padding split and its explicit object symbol have alignment one. This symbol annotation matters: decomp-toolkit otherwise gives an object at relative offset zero four-byte alignment through its CodeWarrior comment metadata, even when the split itself requests byte alignment. No artificial padding array or object rewriting is used.

GC/1.3.2 with ordinary MetroTRK auto,deferred flags reproduces every instruction and the original reversed function order. `scratch/MetroTRK/compile_target_options.py` and `verify_target_options.py` check the code, relocations and one-byte BSS extent; the function manifest is `config/GSQE78/candidates/MetroTRK-target_options.json`. The full DOL matches byte for byte, and native objdiff confirms 28 code bytes, two functions and exactly one data byte from this source.

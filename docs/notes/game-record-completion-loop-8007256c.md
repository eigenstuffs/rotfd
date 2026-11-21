# Record completion loop at 8007256C

`early_record_completion_8007256c.cpp` checks pending work and the owner count,
then compares all eight record IDs with their corresponding node slots. On
completion it invokes the action, disables input, sends event 0xAA, clears the
owner state, and marks the current screen record complete.

A file-local inline accessor returns the node's slot by `const short&`. This
reproduces the original load and register order using the existing shared
`early_record_completion_views.h` declaration unchanged. There are no shared
header or caller edits.

The unit owns exactly 280 code bytes at 8007256C..80072684, eight exception
bytes at 8000C830 and a 12-byte index at 80019260. The natural LOCAL metadata
symbols are @31 and @32. It preserves all ten actual relocations and all five
undefined symbols have GLOBAL binding. There are no literals, BSS, padding,
weak functions or backup exception allocations.

Frozen source and reference evidence are in
`scratch/completion_loop_8007256C_20261020_parallel/`. Production receipts and
the strict object/native checker are in
`scratch/completion_loop_integration_20261020/`.

The production object and native linked bytes/bindings are exact. The original
DOL hash, `ninja changes`, source extent audit and all 66 unit tests pass.
Generated progress is 1,933,532 code bytes (74.1449%), 975,908 data bytes
(94.6623%), and 7,985 of 8,803 functions.

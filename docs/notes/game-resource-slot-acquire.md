# Named resource slot acquisition and setup

`src/Game/resource_slot_acquire.cpp` owns `fn_801E5FDC`, the complete
2,576-byte body at `801E5FDC..801E69EC`. It owns no original data.

The function obtains a resource handle through the global lookup service,
performs two retained conversions, and constructs the original temporary
string buffer. If the resource does not resolve it returns -1. Otherwise it
copies the reference at offset 1C to the output and retains the reference at
20 as a factory handle.

It searches occupied pool records for the requested name. On an existing
record, it expands the handle array and bitset only when the requested count
is larger, creates the newly added handles through virtual slot 30, and
clears their occupancy range with the existing bitset helper. It increments
the record reference count and returns its index. When no record exists, it
uses the recovered pool-growth routine, writes the name and reference count
of one, resizes both arrays, clears the bitset storage, creates all requested
handles, and returns the new index. Both retained local handles are cleaned
up on the applicable return paths.

Reference-returning field/array-size accessors and an explicit resolved
factory local reproduce the original lookup, resize and virtual-call order.
Both branches of the resize template share the same index variable. The
partial object/factory views and names are provisional; the existing global
string and original lookup/factory implementations remain externally owned.
No new guards or altered range endpoints are inserted into original behavior.

`scratch/game_resource_slot_acquire/verify.py --production` verifies all
2,576 bytes with 105 actual relocations. The compiler emits 2,836 text bytes;
three unused weak destructors total 260 bytes, are absent from the final ELF,
and receive no credit. There is no emitted data/BSS. All 656 source units
remain exact, the final DOL is byte-identical, and all source/object/header
hashes and 23 tests pass. Progress, extent and assembly audits pass; the
baseline remains unchanged. Existing `ninja changes` fallback/native-padding
warnings are unchanged and no source matches regressed. Evidence:
`scratch/resource_slot_acquire_checkpoint.json`.

The native pool destructor remains an uncredited 412-byte candidate with
13 register/scheduling differences. Later manager operations and shared
original data are outside this partial split.

# Indexed device dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The ordinary C++ entry `fn_8023B35C` matches all 188 bytes at `8023B35C..8023B418`, including actual relocations. For a nonnegative index, it receives the original returned handle by value, constructs a retained copy through one zeroing layer, destroys the returned temporary, dispatches device virtual slot 58 with the copy and original float constant, and destroys the copy. The private interface preserves the observed virtual pointer at offset 7C. Genuine nested handle lifetimes retain the original pointer register across native construction.

Source: `src/Game/indexed_device_dispatch.cpp`. The unit owns only this complete text range and uses standard GC/1.3.2 Game flags. It emits no data/BSS/padding. All trailing private weak cleanup backups are inventoried by full extent, binding, raw bytes, and relocations; retained code has no references to those helpers. Full central table, executable, baseline and progress checks are required for acceptance. Original device tables, handle implementations and neighboring code remain externally owned.

Isolated frozen evidence is under `scratch/game_indexed_device_dispatch/`. Earlier C ABI and shallow typed probes remain preserved under `scratch/engine_handle_list_20261010h/`; they receive no separate credit. The adjacent 240-byte function is still being investigated and is outside this source split.

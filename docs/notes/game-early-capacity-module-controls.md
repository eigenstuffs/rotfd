# Early record capacity and Python module-cache controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two separate ordinary C++ units preserve original C entry identities and own
only the following original code and exception records:

| Entry | Text bytes | extab | extabindex | Actual relocations |
| --- | ---: | --- | --- | ---: |
| fn_80025898 | 188 | 80006068..80006070 | 800163F8..80016404 | 12 |
| fn_800200F8 | 184 | 80005754..8000575C | 80016008..80016014 | 9 |

`early_capacity_module_80025898.cpp` implements capacity changes for the already
established 24-byte records in `engine_record_buffers.h`. Requests below the
logical count forward to original `fn_80025954(self,request,0)`. Other requests
resize an existing allocation, allocate a new one, or release it for zero
capacity, then store the requested capacity. The established external allocator
anchor `lbl_8028F698` and all allocator routines remain externally owned. This
label is in original `.text` and has no declared object size; passing its address
does not establish any additional storage extent. The private source wraps the
unchanged C-oriented header declarations in `extern "C"`.

`early_capacity_module_800200F8.cpp` imports `sys`, retrieves its `modules`
mapping, conditionally deletes the named entry, and releases the module followed
by the mapping. It reuses the observed Python reference-count/type/destructor
view and inline release helper from unchanged `early_python_event_views.h`.
The original `sys` (4 bytes) and `modules` (8 bytes) small-data strings remain
external with their complete confirmed extents. No literals or other data are
emitted by either new source.

GC1.3.2 with the recorded space flags (`-O4,s -inline auto -Cpp_exceptions on
-use_lmw_stmw on`) matches both first probes and separate production sources.
All emitted text, extab and index bytes match after every actual relocation;
all defined ELF symbols are inventoried, with no weak helpers, unused sections,
new ABI aliases or symbol migrations. The full original exception-index table
and ctor/dtor tables were audited. Existing source/header callers and original
external tables remain unchanged. Every quoted header has a recursive SHA256
pin in the manifests.

The frozen handoff lives in
`scratch/game_early_capacity_module_remove_continuation/final_integration.json`.
The isolated total is372 code bytes and40 original exception/index bytes across
two functions, with21 actual relocations. Parent integration must still pass
the full original DOL hash and regression checks before source credit is earned.

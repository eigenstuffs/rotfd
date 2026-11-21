# Retained C++ allocation release

`src/Runtime/New.cpp` recovers the retained weak `operator delete(void*) throw()` at `0x8011EDD4..0x8011EE20`. Its ordinary C++ body calls `__msl_free` for a non-null pointer. The exception specification generates the original unexpected-handler path and both exception records directly from source. GC/1.3 reproduces all 76 code bytes, 40 `extab` bytes, and 12 `extabindex` bytes, including four resolved relocations. This unit needs no exception-padding cleanup.

The body is recovered directly from the original function and its exception specification. The signature also agrees with the [official MSL C++ Reference, Dynamic Memory Management](https://www.nxp.com/docs/en/reference-manual/MSLCPPRM.pdf). Standard class declarations use the separately preserved runtime exception header.

This is a bounded portion of the original allocation translation unit. The adjacent `std::exception` destructor and `what`, their RTTI/vtable, and the otherwise-unused `bad_alloc` literal remain original fallback. Known class definitions reproduce the methods, but reproducing all original class data in the same source object requires further ownership and compiler-emission evidence. The available Xenoblade `New.cp` explicitly uses a dummy function for metadata; that placeholder is not used here, and no unverified operator-new implementation has been added to influence the string pool.

Run `python3 scratch/runtime_new/verify.py` for the isolated comparison. The original DOL is checked read-only against its protected SHA-1. The manifest records the precise partial scope and verified full-DOL integration.

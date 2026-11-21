# Python resource registration (8001F90C)

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The 468-byte routine creates a resource from its kind and name, records the original name hash in the Python dictionary, derives a suffix from the first period in its path, registers the original resource callback, and appends a 72-byte name/hash/value record to the original resource array. The array retains its original allocator and capacity growth of 16 entries.

The nested PyString creation preserves the original argument evaluation and saved-register lifetimes. A conditional suffix expression preserves the original branch order. Name construction and ordinary placement-copy construction reproduce the original default initialization and array copy loop. All Python objects, managers, callbacks, strings, array storage and allocators remain external. This source preserves the original C identity and callers, owns only text and exception metadata, and emits no weak helper or initialized data. Failed staged-argument and field-layout probes remain private and receive no matching credit.

Full original exception/startup table descriptors and padding, every initialized byte offset for function pointers, exact symbol/instruction extents and all actual relocations pass. This partial text split preserves original external tables, literals and callers. Complete production hash, regression and native checkpoint acceptance remain required.

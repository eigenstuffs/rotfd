# C runtime backing allocator hooks

Four functions at `0x801EFC24..0x801EFD30` reproduce 268 bytes of C code.
`__sys_free` and `__sys_alloc` connect the runtime allocator to the game's memory manager,
request 32-byte alignment, and return the allocation with the observed
12-byte offset. Oversized requests report a diagnostic and enter the original
fatal loop.

The format string at `0x802AD450` contains three integer substitutions: size,
alignment and heap size. Preserving all three variadic arguments is essential:
omitting the heap-size argument leaves the apparent behavior close but changes
the live compare register and four instruction bytes. The reconstructed
storage views identify only the accessed fields.

The adjacent minimum helper compares unsigned values. The global initializer
captures the OS arena bounds, initializes the memory manager, and registers
its destructor with the runtime. An ordinary function pointer in `.ctors`
recreates its four-byte startup entry at `0x8029994C`; the manager storage and
destructor registration block remain external.

GC/1.3.2 with ordinary scalar-save game flags matches all bytes and 26
relocations. The allocator implementation, diagnostic and global state remain
external. This split owns the constructor pointer and no BSS. The candidate manifest records the
full-DOL acceptance; `scratch/memory_hooks/verify_extended.py` checks isolated output.

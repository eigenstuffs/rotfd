# Early scalar setup and forwarding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four original C entries recover 504 bytes of text and 80 bytes of compiler-emitted exception/index metadata. Existing names and caller identities remain intact; fields are private views named by observed offsets.

* 80027DD0 forwards its original third argument to the existing first-record writer 8021F518 with index zero and returns zero. Its middle argument is unused.
* 8006D144 calls the existing no-argument active-object resolver 8007D074, stores the low byte of its second argument at result offset 0x1DC, and returns that object.
* 8009D964 initializes an object after base setup 8009A9D8, including primary/secondary table pointers, vectors, floats, words, and byte defaults through offset 0x3F5. The byte at 0x3F4 has a signed `-1` default; its signed-char declaration allows reuse of the same original `-1` constant as the adjacent word defaults. The diagnostic unsigned-byte variant adds an instruction and receives no credit. Existing global zero-vector and SDA float data remain externally owned.
* 800C19B8 initializes its name word to zero, assigns the hash from an ordinary inline `Name` temporary, clears byte 4, and returns self. `Name` has a normal constructor calling the existing CRC/name function 801F948C and stores its result. The eight-byte external empty-string object 803794F8 remains in its original SDA2 owner; the declaration uses its established full size. The C++ temporary explains both the original stack address passed to the hash function and its returned-value stack store without handwritten ABI manipulation.

GC 1.3.2 and the established container-base flags (`-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`) reproduce all text, exception tables, symbols, and actual relocations. All emitted allocations are accounted. A complete extabindex/constructor/destructor registration scan establishes exactly one original eight-byte extab plus twelve-byte index for each entry and no registration pointers. These bounded fragments do not claim complete original translation-unit recovery. No source/global data is replaced beyond the listed original extents. Root must still integrate and pass the original DOL hash before credit.

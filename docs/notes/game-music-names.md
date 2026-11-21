# Native music resource name table

`src/Game/music_names_8029ACA8.cpp` reconstructs the original GLOBAL read-only
`lbl_8029ACA8` object as thirteen twenty-byte character records. Ordinary string
initializers supply the original names and zero padding. The object emits exactly
260 bytes with native eight-byte alignment, without code, helpers, relocations,
exception metadata or startup code.

The ownership census scans all 10,388 original/current ELF inputs, 204,101 actual
allocated relocations and 501,416 initialized DOL data positions. It records 38
references to the array and no initialized data pointers into it. Full original
exception, constructor and destructor tables have no references into this range.
All consumers retain the same GLOBAL object, address, extent and contents.

This table provides zero source-matched code bytes and zero functions. Private
callback `8005B1FC` probes that motivated this check remain unaccepted. They do
not establish ownership of adjacent strings or any additional original data.
Full native linking, the original DOL hash, regression checks and the complete
existing acceptance chain are required separately before integration is accepted.

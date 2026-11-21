# Callback-owner native base-list continuation

Eleven original-only `ABC_Agent` runtime-base records now belong to the
immediately preceding callback-owner source objects. Each is a 12-byte
three-word record: a runtime-type pointer, a zero base offset, and a zero
terminator. The transferred addresses are `802B15CC`, `802B1824`,
`802B1D6C`, `802B4C64`, `802B62D4`, `802B6634`, `802B79B4`, `802B7D3C`,
`802BFE8C`, `802C16BC`, and `802C9124`.

The earlier `802B2AD4` and `802B2EAC` records already belonged to matching
callback source and were not transferred again. For each new record, the
compiler emits its original global symbol, exact bytes, and one pointer
relocation. Private probes compare each entire enclosing source object's
owned sections and relocations; the sources before extension and the failed
alignment experiments are preserved in
`scratch/native_single_base_lists_20261020/`.

The assembly fallbacks used one-byte section alignment. Independent compiled
source objects, or moving each record to the following runtime-base-list
source, inserted linker padding and failed the DOL hash despite exact object
bytes. Appending to the preceding source retains the original layout.

These partial splits add 132 matched data bytes. The final DOL passes the
expected SHA-1 check, `ninja changes` is empty, the source extent audit
passes, and all 66 tests pass. Referenced runtime descriptors retain their
existing owners.

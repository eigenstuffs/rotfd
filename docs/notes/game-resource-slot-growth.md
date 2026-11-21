# Resource pool record growth

`src/Game/resource_slot_growth.cpp` owns `fn_801E69EC` at
`801E69EC..801E6D24`: 824 code bytes, no data or unused emitted helpers.

The function searches for an unoccupied record, skipping the search when the
slot limit is zero, then increments the live count. If no slot exists, it
grows record capacity by 16 when needed, appends and constructs a 36-byte
record, expands occupancy storage and sets the new bit. Otherwise it
constructs the vacant record in place and sets its existing bit. It returns
the selected index.

Record construction zeros the name, calls the existing bitset initializer,
and zeros the handle-array size, capacity and pointer. The reference count
is left untouched here; the acquisition caller initializes it. The array
resize template uses placement construction and explicit destruction. Scalar
word construction/destruction naturally emits the original empty counted
loops. Bit storage uses `(bits >> 5) + 1` words when expansion is required;
this reproduces the original allocation rule, including exact multiples of 32.

The strict probe verifies every byte with 30 actual relocations. Final ELF
and full-DOL verification pass. At acceptance all 655 source units remained
exact, with current source/header/object hashes, 23 passing tests, and no
extent over-credit or source assembly. The original baseline and executable
are unchanged. The documented fallback/native-padding warnings in `ninja
changes` remain; no source match regressed. See
`scratch/resource_slot_growth_checkpoint.json`.

This is a partial text-only split. Shared declarations and names describe
verified layouts; original TU boundaries and broader class identities are
not claimed. The adjacent acquisition routine is documented separately.

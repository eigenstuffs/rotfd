# Python member pointer bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five ordinary wrappers at `800CE1B4`, `800CE2E4`, `800CEC94`, `800DF5EC` and
`800DFD2C` parse and convert their native owner, then encode its pointer or a
member address. All 1,520 code bytes and 100 exception/index bytes match,
including ninety-five actual relocations and full original table ownership.

The wrappers share the unchanged `python_indexed_pointer_encoding.h` header
with the four indexed bindings. Naming the pointer before the wrapper call
keeps the input live separately from the hexadecimal loop's integer copy;
declaring that copy before the inner null branch reproduces the original
ordinary compiler scheduling. Earlier six-word register near-matches and all
private variants remain preserved and uncredited.

No extra code, data, weak helper, padding or startup allocation is emitted.
Frozen proof is `scratch/game_python_indexed_pointer_bindings/member_final_integration.json`;
the corresponding source, object and full ownership checks remain alongside it.

# Scene timed state transition

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated production unit for `800E27D8` matches all 388 code bytes, 20 exception-table/index bytes and actual relocations. Integrated production acceptance has passed.

The update decrements its timer, changes the actor component state when time expires or the source passes below zero, otherwise conditionally restores the saved vector and dispatches the original event before applying the time-scaled vector. Signed-byte queries preserve the original comparison normalization. Vector assignment and addition use ordinary three-float values; retaining the actor pointer during addition reproduces the original register lifetimes and temporary copies.

The unit uses native Gekko flags and owns no data, padding, weak definitions or startup allocations. All four floating-point inputs remain borrowed original constants. Full original extabindex/startup-table scans, initialized-data word references and existing compiled consumers are frozen with the production allocation proof. Fresh production recompilation verifies all bytes, extents, native symbols and actual relocations.

Adjacent `800E54DC` remains private research only. Its best 308-byte candidate differs in four instructions that normalize a two-state query; bounded boolean, signed-byte, explicit-result and ternary variants did not close the difference. No matching credit is claimed for those probes.

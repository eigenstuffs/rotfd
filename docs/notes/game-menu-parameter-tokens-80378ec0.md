# Menu record parameter tokens and scalar continuation

Two complete source owners add 180 matching data bytes. The existing
`owner_motion_control_scalar_constants.c` grows from 116 to 120 bytes at
80378E40..80378EB8, adding the adjacent 0.5f constant. The new
`menu_record_parameter_tokens_80378EC0.c` owns 176 bytes at 80378EC0..80378F70.
Together the additions contain 21 strings, two floats, one double, and 37 bytes
of natural compiler alignment. All original GLOBAL names and full extents are
preserved.

The complete input census found 58 actual references in 17 unchanged consumers,
including 24 direct string references and five numeric references. Native LFS
loads establish the half and 255.0f scalars; the original signed conversion
sequence establishes the double. No raw initialized pointer enters the new
ownership. Both emitted objects contain only their complete small readonly
sections, with no relocations, weak definitions, or undefined symbols.

The two eight-byte ranges at 80378EB8..80378EC0 and 80378F70..80378F78 retain
original ownership. Unproved empty-name extent and conflicting space-string
declarations remain outside matching source. Their alignment bytes have explicit
original GLOBAL symbols. The source owners contribute 296 complete bytes and
the original residuals contribute 16, preserving the entire 312-byte neighborhood.

Frozen evidence is in `scratch/menu_parameter_tokens_20261020_parallel/`.
`scratch/menu_tokens180_integration_20261020/verify_production.py --linked`
checks the complete emitted objects, all native GLOBAL extents, unchanged
consumers, original residual ownership and DOL hash. The standard build,
`ninja changes`, source extent audit, and all 66 unit tests pass.

# Callback indexed rotation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80256F98` reconstructs the complete 648-byte function at
`0x80256F98..0x80257220`. It resolves the owner's handle at `0x64`, follows
the related handle at `0x1F0`, maps the supplied index through the original
record table at `0x144`, and resolves the selected handle in the array at
`0x28`. It also resolves the selected object's parent handle at `0x0C`.
The original performs both resolutions before testing the two pointers.

For valid objects, the callback constructs rotations around the X and Y
axes from the two float arguments and the original half-angle, zero and
one constants. It combines them with the input quaternion and the parent's
orientation using the original quaternion routines. A dirty parent matrix
is rebuilt from its basis when flag `0x40` is set, after which the flag is
cleared. The final quaternion is copied to the selected object's `0xC8`
member, and the callback returns one. Missing objects return zero.

The four quaternion locals, ordinary scalar assignments and inlined
axis constructors reproduce the native stack layout and float operations.
The partial object views include only fields accessed by this function.
Original constants, record mappings, manager storage and neighboring
functions retain external ownership.

`scratch/game_callback_indexed_rotation/verify.py` checks the complete
retained extent, all allocated bytes and every actual relocation without
masks. There are no extra allocated helpers or owned data. Full executable,
original table ownership and baseline checks are required before credit.

# Platform draw wrapper and native index-block interface

Verified source: `src/Game/platform_draw_helpers.cpp`, GC/1.3.2 with
standard `-O4,p` / `-inline auto`. The bounded source split owns all
`0x80283064..0x80283160` text (252 bytes, four functions) and the native
16-byte interface table at `0x802F1540..0x802F1550`. Nine actual code/data
relocations match. There are no weak functions, extra allocated sections or
owned padding.

- `fn_80283064`, 152 bytes, transfers the two observed output fields, performs
  cache maintenance on a 16-KiB stack buffer aligned to 32 bytes, invokes the
  virtual slot at table offset 58 with the BC state and buffer, then waits for
  GX drawing completion. The recovered Root inheritance puts its vptr at 08.
- `reset__27PlatformIndexBlock_8028310CFv`, 12 bytes, clears flag 00.
- `hook__27PlatformIndexBlock_8028310CFv`, four bytes, is empty.
- `__dt__27PlatformIndexBlock_8028310CFv`, 84 bytes, restores the native table
  at vptr offset 40 and performs conditional arena deletion through the native
  signed-short destructor flag ABI.

The index block has an opaque 64-byte storage prefix followed by the vptr.
Its two virtual methods are reset and hook; its destructor is nonvirtual.
The actual native table is two zero words followed by the reset/hook pointers.
A virtual destructor would put the wrong function in the first table entry.
Ordinary C++ inheritance, virtual dispatch and the nonvirtual destructor now
emit the correct code and strong table; no raw table replacement, alignment
padding or assembly bodies are used. The draw/output declarations are verified
physical views of the observed fields, not claims of complete original class
or translation-unit recovery. The remaining large draw routines stay original.

Evidence: `scratch/game_platform_draw_helpers/verify.py --production`,
`scratch/platform_draw_helpers_link_proof.json` and
`scratch/platform_draw_helpers_checkpoint.json`. The final linked code/table
addresses and bytes match, as does the complete DOL. All 686 source units,
683 current candidate hashes and 301 mapped header hashes pass. Source extent,
source-assembly and progress audits pass, all 23 tests pass, and the original
baseline and all earlier source files are unchanged.

This increment reaches 946,432 / 2,607,744 code bytes (36.2931%),
3,062 / 8,802 functions and 301,616 / 1,030,936 data bytes (29.2565%).

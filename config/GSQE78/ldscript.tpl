// Custom ldscript template for ROTFD (GSQE78).
//
// This is a dev-master build; its lcf places the MetroTRK db stack 0x200000
// above the main stack rather than the retail-standard 0x2000. Values were
// recovered from the shipped main.dol itself:
//   _stack_addr    = 0x8046B990  (matches dtk default formula with 0xF0000 stack)
//   _db_stack_addr = 0x8066B990  (loaded by InitMetroTRK via lis/ori)
//   __ArenaLo      = 0x8066B9A0  (loaded by OSInit)
// With the default 0x2000 offset the rebuilt DOL differed in exactly those
// four lis/addi/ori pairs.

MEMORY
{
    text : origin = $ORIGIN
}

SECTIONS
{
    GROUP:
    {
        $SECTIONS
        .stack ALIGN(0x100):{}
    } > text

    _stack_end = $LAST_SECTION_SYMBOL + SIZEOF($LAST_SECTION_NAME);
    _stack_addr = (_stack_end + $STACKSIZE + 0x7) & ~0x7;
    _db_stack_addr = (_stack_addr + 0x200000);
    _db_stack_end = _stack_addr;
    __ArenaLo = (_db_stack_addr + 0x1f) & ~0x1f;
    __ArenaHi = $ARENAHI;

    // End of the original four-byte DB jump image equals the following C entry.
    __OSDBJUMPEND = __OSSetExceptionHandler;

}

FORCEACTIVE
{
    $FORCEACTIVE
}

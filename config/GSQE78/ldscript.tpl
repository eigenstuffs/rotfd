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

    // C names for compiler adjustor thunks ("@N@target"), which C data cannot
    // spell; the native vtable tables in src/Game/data/native_rtti_neighbor_*.c
    // reference the thunks through these.
    thunk360___dt__15Object_80074D40Fv = "@360@__dt__15Object_80074D40Fv";
    thunk360___dt__15Object_80075618Fv = "@360@__dt__15Object_80075618Fv";
    thunk360___dt__15Object_800AA6E0Fv = "@360@__dt__15Object_800AA6E0Fv";
    thunk360___dt__15Object_800E102CFv = "@360@__dt__15Object_800E102CFv";
    thunk360_hook_800E12EC__15Object_800E102CFv = "@360@hook_800E12EC__15Object_800E102CFv";
    thunk360_setup__15Object_80074D40Fv = "@360@setup__15Object_80074D40Fv";
    thunk360_setup__15Object_80075618Fv = "@360@setup__15Object_80075618Fv";
    thunk360_setup__15Object_800AA6E0Fv = "@360@setup__15Object_800AA6E0Fv";
    thunk792___dt__15Object_80090360Fv = "@792@__dt__15Object_80090360Fv";
    thunk792___dt__15Object_800969F0Fv = "@792@__dt__15Object_800969F0Fv";
    thunk792___dt__15Object_8009731CFv = "@792@__dt__15Object_8009731CFv";
    thunk792___dt__15Object_8009798CFv = "@792@__dt__15Object_8009798CFv";
    thunk792___dt__15Object_80098518Fv = "@792@__dt__15Object_80098518Fv";
    thunk792___dt__15Object_80098A70Fv = "@792@__dt__15Object_80098A70Fv";
    thunk792___dt__15Object_800A2EE0Fv = "@792@__dt__15Object_800A2EE0Fv";
    thunk792___dt__15Object_800A402CFv = "@792@__dt__15Object_800A402CFv";
    thunk792___dt__15Object_800A49E8Fv = "@792@__dt__15Object_800A49E8Fv";
    thunk792___dt__15Object_800E2A8CFv = "@792@__dt__15Object_800E2A8CFv";
    thunk792_cleanup__32OwnerCleanupVirtualView_80027A08Fi = "@792@cleanup__32OwnerCleanupVirtualView_80027A08Fi";
    thunk792_cleanup__32OwnerCleanupVirtualView_80095F4CFi = "@792@cleanup__32OwnerCleanupVirtualView_80095F4CFi";
    thunk792_cleanup__32OwnerCleanupVirtualView_8009A8ACFi = "@792@cleanup__32OwnerCleanupVirtualView_8009A8ACFi";
    thunk792_cleanup__32OwnerCleanupVirtualView_800CC6CCFi = "@792@cleanup__32OwnerCleanupVirtualView_800CC6CCFi";
    thunk792_configureCallbacks__32OwnerCleanupVirtualView_80027A08Fv = "@792@configureCallbacks__32OwnerCleanupVirtualView_80027A08Fv";
    thunk792_hook_800949CC__15Object_80090360Fv = "@792@hook_800949CC__15Object_80090360Fv";
    thunk792_hook_80096518__32OwnerCleanupVirtualView_80095F4CFv = "@792@hook_80096518__32OwnerCleanupVirtualView_80095F4CFv";
    thunk792_hook_800CCED8__32OwnerCleanupVirtualView_800CC6CCFv = "@792@hook_800CCED8__32OwnerCleanupVirtualView_800CC6CCFv";
    thunk792_hook_800E31C4__15Object_800E2A8CFv = "@792@hook_800E31C4__15Object_800E2A8CFv";
    thunk792_hook__32OwnerCleanupVirtualView_8009A8ACFv = "@792@hook__32OwnerCleanupVirtualView_8009A8ACFv";
    thunk792_setup__15Object_800A2EE0Fv = "@792@setup__15Object_800A2EE0Fv";
    thunk792_setup__15Object_800A402CFv = "@792@setup__15Object_800A402CFv";
    thunk792_setup__15Object_800A49E8Fv = "@792@setup__15Object_800A49E8Fv";

}

FORCEACTIVE
{
    $FORCEACTIVE
}

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
    thunk360___dt__16CCollectableMoveFv = "@360@__dt__16CCollectableMoveFv";
    thunk360___dt__18CTreasureChestMoveFv = "@360@__dt__18CTreasureChestMoveFv";
    thunk360___dt__9CTileMoveFv = "@360@__dt__9CTileMoveFv";
    thunk360___dt__15WaterHelmetMoveFv = "@360@__dt__15WaterHelmetMoveFv";
    thunk360_hook_800E12EC__15WaterHelmetMoveFv = "@360@configureCallbacks__15WaterHelmetMoveFv";
    thunk360_setup__16CCollectableMoveFv = "@360@configureCallbacks__16CCollectableMoveFv";
    thunk360_setup__18CTreasureChestMoveFv = "@360@configureCallbacks__18CTreasureChestMoveFv";
    thunk360_setup__9CTileMoveFv = "@360@configureCallbacks__9CTileMoveFv";
    thunk792___dt__14CSpongeBobMoveFv = "@792@__dt__14CSpongeBobMoveFv";
    thunk792___dt__15CGreenJfishMoveFv = "@792@__dt__15CGreenJfishMoveFv";
    thunk792___dt__14CPinkJfishMoveFv = "@792@__dt__14CPinkJfishMoveFv";
    thunk792___dt__13CRedJfishMoveFv = "@792@__dt__13CRedJfishMoveFv";
    thunk792___dt__14CBlueJfishMoveFv = "@792@__dt__14CBlueJfishMoveFv";
    thunk792___dt__14CJellyfishMoveFv = "@792@__dt__14CJellyfishMoveFv";
    thunk792___dt__11CSimpleMoveFv = "@792@__dt__11CSimpleMoveFv";
    thunk792___dt__11CMediumMoveFv = "@792@__dt__11CMediumMoveFv";
    thunk792___dt__12CComplexMoveFv = "@792@__dt__12CComplexMoveFv";
    thunk792___dt__12CSBPantsMoveFv = "@792@__dt__12CSBPantsMoveFv";
    thunk792_cleanup__9CHookMoveFi = "@792@__dt__9CHookMoveFv";
    thunk792_cleanup__32OwnerCleanupVirtualView_80095F4CFi = "@792@__dt__16CYellowJfishMoveFv";
    thunk792_cleanup__8CNPCMoveFi = "@792@__dt__8CNPCMoveFv";
    thunk792_cleanup__11CQSnailMoveFi = "@792@__dt__11CQSnailMoveFv";
    thunk792_configureCallbacks__9CHookMoveFv = "@792@configureCallbacks__9CHookMoveFv";
    thunk792_hook_800949CC__14CSpongeBobMoveFv = "@792@configureCallbacks__14CSpongeBobMoveFv";
    thunk792_hook_80096518__32OwnerCleanupVirtualView_80095F4CFv = "@792@configureCallbacks__14CJellyfishMoveFv";
    thunk792_hook_800CCED8__11CQSnailMoveFv = "@792@configureCallbacks__11CQSnailMoveFv";
    thunk792_hook_800E31C4__12CSBPantsMoveFv = "@792@configureCallbacks__12CSBPantsMoveFv";
    thunk792_hook__8CNPCMoveFv = "@792@configureCallbacks__8CNPCMoveFv";
    thunk792_setup__11CSimpleMoveFv = "@792@configureCallbacks__11CSimpleMoveFv";
    thunk792_setup__11CMediumMoveFv = "@792@configureCallbacks__11CMediumMoveFv";
    thunk792_setup__12CComplexMoveFv = "@792@configureCallbacks__12CComplexMoveFv";

}

FORCEACTIVE
{
    $FORCEACTIVE
}

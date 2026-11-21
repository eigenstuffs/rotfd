/* Dolphin GBA SDK, GSQE78.
 * Adapted from the pinned PrimeDecomp reconstruction.
 * See docs/notes/gba.md and reference/prime-sdk/PROVENANCE.md.
 */
#include "GBA_abi.h"

/* Retained unit scope: GBAInit, its reset hook, and its private
 * initialization-only storage are absent from the original link. */


GBAControl __GBA[4];
BOOL __GBAReset = FALSE;

static void ShortCommandProc(s32 chan) {
  GBAControl* gba;
  gba = &__GBA[chan];

  if (gba->ret != 0) {
    return;
  }

  if (gba->input[0] != 0 || gba->input[1] != 4) {
    gba->ret = 1;
    return;
  }

  gba->status[0] = gba->input[2] & GBA_JSTAT_MASK;
}

s32 GBAGetStatusAsync(s32 chan, u8* status, GBACallback callback) {
  GBAControl* gba;
  gba = &__GBA[chan];
  if (gba->callback != NULL) {
    return GBA_BUSY;
  }

  gba->output[0] = 0;
  gba->status = status;
  gba->callback = callback;
  return __GBATransfer(chan, 1, 3, ShortCommandProc);
}

s32 GBAGetStatus(s32 chan, u8* status) {
  GBAControl* gba = &__GBA[chan];

  //
  s32 ret = GBAGetStatusAsync(chan, status, __GBASyncCallback);
  if (ret != GBA_READY) {

    return ret;
  }
  return __GBASync(chan);
}

s32 GBAResetAsync(s32 chan, u8* status, GBACallback callback) {
  GBAControl* gba = &__GBA[chan];
  s32 ret;
  if (gba->callback != NULL) {

    return GBA_BUSY;
  }
  gba->output[0] = 0xFF;
  gba->status = status;
  gba->callback = callback;
  return __GBATransfer(chan, 1, 3, ShortCommandProc);
}

s32 GBAReset(s32 chan, u8* status) {
  GBAControl* gba = &__GBA[chan];
  s32 ret;

  ret = GBAResetAsync(chan, status, __GBASyncCallback);
  if (ret != GBA_READY) {

    return ret;
  }
  return __GBASync(chan);
}


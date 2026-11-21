#ifndef GAME_TELEPORT_VIRTUAL_CALLBACK_RECORDS_H
#define GAME_TELEPORT_VIRTUAL_CALLBACK_RECORDS_H

/* Virtual-only CodeWarrior callback descriptor view. The runtime first adjusts
 * the receiver, loads its vptr at vptrByteOffset, then loads the function at
 * virtualFunctionByteOffset within that table. All eight records use this mode.
 * This is an explicit ABI record, not a C++ member-pointer initializer. */
struct TeleportVirtualCallback {
    long receiverAdjustment;
    long virtualFunctionByteOffset;
    long vptrByteOffset;
};
typedef char TeleportVirtualCallbackSize[sizeof(TeleportVirtualCallback)==12?1:-1];
extern "C" TeleportVirtualCallback lbl_802C1150[8];

#endif

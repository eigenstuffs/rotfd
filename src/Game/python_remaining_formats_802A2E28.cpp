
/* Original Python argument formats. See docs/notes/game-additional-python-format-strings.md. */
extern "C" const char lbl_802A2E28[31] = "OO:Game_Z_GetPlayerManipulator";
extern "C" const char lbl_802A2E48[25] = "OO:Game_Z_GetCameraAgent";
extern "C" const char lbl_802A2E64[27] = "OOO|O:Game_Z_AddGamePlayer";
extern "C" const char lbl_802A2E80[29] = "OO|O:Game_Z_RemoveGamePlayer";
extern "C" const char lbl_802A2EA0[36] = "OOO|O:Game_Z_AddGamePlayerUnlocated";
extern "C" const char lbl_802A2EC4[25] = "OO:Game_Z_ActivatePlayer";
extern "C" const char lbl_802A2EE0[27] = "OO:Game_Z_DeactivatePlayer";
extern "C" const char lbl_802A2EFC[27] = "OOOO:Game_Z_TeleportPlayer";
extern "C" const char lbl_802A2F18[20] = "OOO:Game_Z_StartRtc";
extern "C" const char lbl_802A2F2C[22] = "OO:Game_Z_GetRtcAgent";
extern "C" const char lbl_802A2F44[25] = "OO:Game_Z_GetRtcFromNode";
extern "C" const char lbl_802A2F60[26] = "OiOO|f:Game_Z_SendMessage";
extern "C" const char lbl_802A2F7C[38] = "OOOO:Game_Z_DeclarePlayerManipulators";


extern "C" const char lbl_802A2FA4[] =
    "OOO:Game_Z_IsObjectsManipulator\0" // +0x0
    "OOO:Game_Z_CreateAgentForSystemObject\0\0"; // +0x20

extern "C" const char lbl_802A2FEC[] =
    "OO:Game_Z_DeleteAgentFromSystemObject"; // +0x0

extern "C" const char lbl_802A3014[] =
    "OOO:Game_Z_DeclareObjectManipulators"; // +0x0

extern "C" const char lbl_802A303C[] =
    "OO|O:Game_Z_DeclareObjectManipulator"; // +0x0

extern "C" const char lbl_802A3064[] =
    "OO:Game_Z_DeclareSkelManipulator"; // +0x0

/* Original Python argument formats. See docs/notes/game-additional-python-format-strings.md. */
extern "C" const char lbl_802A3088[38] = "OO:Game_Z_DeclareParticlesManipulator";
extern "C" const char lbl_802A30B0[33] = "OO:Game_Z_DeclareNodeManipulator";
extern "C" const char lbl_802A30D4[28] = "OO:Game_Z_DeclareOtherAgent";
extern "C" const char lbl_802A30F0[29] = "OO:Game_Z_DeclareCameraAgent";
extern "C" const char lbl_802A3110[29] = "OO:Game_Z_UnRegisterFromGame";
extern "C" const char lbl_802A3130[37] = "OO:Game_Z_UnDeclareObjectManipulator";
extern "C" const char lbl_802A3158[35] = "OO:Game_Z_UnDeclareSkelManipulator";
extern "C" const char lbl_802A317C[40] = "OO:Game_Z_UnDeclareParticlesManipulator";

// Remaining Game_Z binding strings and the adjacent native names.
#pragma force_active on

extern "C" const char lbl_802A31A4[] = "OO:Game_Z_UnDeclareNodeManipulator";

extern "C" const char lbl_802A31C8[] = ":Game_Z_NewObject";

extern "C" const char lbl_802A31DC[] = "Game_Z.h";

extern "C" const char lbl_802A31E8[] =
    "OO:Game_Z_SetPersoCameraPos"; // +0x0

extern "C" const char lbl_802A3204[] =
    "OO:CScriptAgent_SetPythonInstance"; // +0x0

#pragma force_active reset


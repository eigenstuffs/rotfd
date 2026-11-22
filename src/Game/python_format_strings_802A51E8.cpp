extern "C" const char lbl_802A51E8[21] = "O:MovingAgent_Z_Init";
extern "C" const char lbl_802A5200[22] = "O:MovingAgent_Z_Reset";
extern "C" const char lbl_802A5218[25] = "OO:MovingAgent_Z_UseNode";
extern "C" const char lbl_802A5234[24] = "O:MovingAgent_Z_Suspend";
extern "C" const char lbl_802A524C[24] = "O:MovingAgent_Z_Restore";
extern "C" const char lbl_802A5264[31] = "OO:MovingAgent_Z_SetObjectMove";
extern "C" const char lbl_802A5284[] = "O:MovingAgent_Z_GetObjectMove";
extern "C" const char lbl_802A52A4[] = ":new_CCollectableAgent";
extern "C" const char lbl_802A52BC[] = "OO:CCollectableAgent_SetType";
extern "C" const char lbl_802A52DC[] = ":new_Throwable_Z";
extern "C" const char lbl_802A52F0[19] = "O:Throwable_Z_Init";
extern "C" const char lbl_802A5304[20] = "O:Throwable_Z_Reset";
extern "C" const char lbl_802A5318[37] = "O:Throwable_Z_ResetCollisionMessages";
extern "C" const char lbl_802A5340[48] = "OO:Throwable_Z_SetCollisionMessageContactActive";
extern "C" const char lbl_802A5370[49] = "OO:Throwable_Z_SetCollisionMessageContactPassive";
extern "C" const char lbl_802A53A4[48] = "OO:Throwable_Z_GetCollisionMessageContactActive";
extern "C" const char lbl_802A53D4[49] = "OO:Throwable_Z_GetCollisionMessageContactPassive";
extern "C" const char lbl_802A5408[25] = "O:Throwable_Z_ThrowBegin";
extern "C" const char lbl_802A5424[23] = "O:Throwable_Z_ThrowEnd";

// Adjacent Throwable and Breakable binding strings; alignment owns the boundary byte.
#pragma force_active on

extern "C" const char lbl_802A543C[] = "OO:Throwable_Z_GetThrowParameters";

extern "C" const char lbl_802A5460[] = ":new_Breakable_Z";

extern "C" const char lbl_802A5474[] = "O:Breakable_Z_Init";

extern "C" const char lbl_802A5488[] =
    "O:Breakable_Z_Reset"; // +0x0

extern "C" const char lbl_802A549C[] =
    "O:Breakable_Z_MarkHandles"; // +0x0

#pragma force_active reset

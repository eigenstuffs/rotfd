#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
extern NativeRuntimeBaseList<1> lbl_802BEF8C;
extern const char agent_type_registry_AnimatedAgent_Z[];
extern const char agent_type_registry_AnimatedMsgAgent_Z[];
extern const char agent_type_registry_BusTicket_CA[];
extern const char agent_type_registry_BusTicket_DN[];
extern const char agent_type_registry_BusTicket_GL[];
extern const char agent_type_registry_BusTicket_JF[];
extern const char agent_type_registry_CActorAgent[];
extern const char agent_type_registry_CBusTicketBase[];
extern const char agent_type_registry_CCollectableAgent[];
extern const char agent_type_registry_CRBObjBaseAgent[];
extern const char agent_type_registry_LodAgent_Z[];
extern const char agent_type_registry_MovingAgent_Z[];
extern const char agent_type_registry_QSnail10[];
extern const char agent_type_registry_QSnail11[];
extern const char agent_type_registry_QSnail12[];
extern const char agent_type_registry_QSnail13[];
extern const char agent_type_registry_QSnail14[];
extern const char agent_type_registry_QSnail15[];
extern const char agent_type_registry_QSnailBase[];
extern const char agent_type_registry_StreamAgent_Z[];
extern const char agent_type_registry_StreamBubbleAgent[];
extern const char agent_type_registry_StreamGameAgent[];
extern const char agent_type_registry_Throwable_Z[];
extern const char lbl_802A1794[];
extern const char lbl_802A17A4[];
extern const char lbl_802A17B0[];
extern const char lbl_802A17C0[];
extern const char lbl_803793B0[];
extern const char lbl_80379448[];
extern const char lbl_80379450[];
extern const char lbl_80379458[];
extern const char lbl_80379460[];
extern const char lbl_80379468[];
extern const char lbl_80379470[];
extern const char lbl_80379478[];
extern const char lbl_80379480[];
extern const char lbl_80379488[];

// Current platform error code; the original diagnostic prints it with %d.
int lbl_803754B8 = -1;

// BaseObject_Z
NativeRuntimeTypeInfo lbl_803754BC = { lbl_802A1794, 0 };

// ABC_Agent
NativeRuntimeTypeInfo lbl_803754C4 = { lbl_802A17A4, lbl_802BD930.entries };

// Agent_Z
NativeRuntimeTypeInfo lbl_803754CC = { lbl_803793B0, lbl_802BD93C.entries };

// AnimatedMsgAgent_Z
NativeRuntimeTypeInfo lbl_803754D4 = { agent_type_registry_AnimatedMsgAgent_Z, lbl_802BD950.entries };

// AnimatedAgent_Z
NativeRuntimeTypeInfo lbl_803754DC = { agent_type_registry_AnimatedAgent_Z, lbl_802BD96C.entries };

// MovingAgent_Z
NativeRuntimeTypeInfo lbl_803754E4 = { agent_type_registry_MovingAgent_Z, lbl_802BD990.entries };

// Throwable_Z
NativeRuntimeTypeInfo lbl_803754EC = { agent_type_registry_Throwable_Z, lbl_802BD9BC.entries };

// LodAgent_Z
NativeRuntimeTypeInfo lbl_803754F4 = { agent_type_registry_LodAgent_Z, lbl_802BD9F0.entries };

// CActorAgent
NativeRuntimeTypeInfo lbl_803754FC = { agent_type_registry_CActorAgent, lbl_802BDA2C.entries };

// CCollectableAgent
NativeRuntimeTypeInfo lbl_80375504 = { agent_type_registry_CCollectableAgent, lbl_802BDA70.entries };

// CBusTicketBase
NativeRuntimeTypeInfo lbl_8037550C = { agent_type_registry_CBusTicketBase, lbl_802BDAA4.entries };

// BusTicket_CA
NativeRuntimeTypeInfo lbl_80375514 = { agent_type_registry_BusTicket_CA, lbl_802BDAE0.entries };

// BusTicket_DN
NativeRuntimeTypeInfo lbl_8037551C = { agent_type_registry_BusTicket_DN, lbl_802BDBA8.entries };

// BusTicket_JF
NativeRuntimeTypeInfo lbl_80375524 = { agent_type_registry_BusTicket_JF, lbl_802BDC70.entries };

// BusTicket_GL
NativeRuntimeTypeInfo lbl_8037552C = { agent_type_registry_BusTicket_GL, lbl_802BDD38.entries };

// CRBObjBaseAgent
NativeRuntimeTypeInfo lbl_80375534 = { agent_type_registry_CRBObjBaseAgent, lbl_802BDE00.entries };

// QSnailBase
NativeRuntimeTypeInfo lbl_8037553C = { agent_type_registry_QSnailBase, lbl_802BDE4C.entries };

// QSnail1
NativeRuntimeTypeInfo lbl_80375544 = { lbl_80379448, lbl_802BDEA0.entries };

// QSnail2
NativeRuntimeTypeInfo lbl_8037554C = { lbl_80379450, lbl_802BDFB4.entries };

// QSnail3
NativeRuntimeTypeInfo lbl_80375554 = { lbl_80379458, lbl_802BE0C8.entries };

// QSnail4
NativeRuntimeTypeInfo lbl_8037555C = { lbl_80379460, lbl_802BE1DC.entries };

// QSnail5
NativeRuntimeTypeInfo lbl_80375564 = { lbl_80379468, lbl_802BE2F0.entries };

// QSnail6
NativeRuntimeTypeInfo lbl_8037556C = { lbl_80379470, lbl_802BE404.entries };

// QSnail7
NativeRuntimeTypeInfo lbl_80375574 = { lbl_80379478, lbl_802BE518.entries };

// QSnail8
NativeRuntimeTypeInfo lbl_8037557C = { lbl_80379480, lbl_802BE62C.entries };

// QSnail9
NativeRuntimeTypeInfo lbl_80375584 = { lbl_80379488, lbl_802BE740.entries };

// QSnail10
NativeRuntimeTypeInfo lbl_8037558C = { agent_type_registry_QSnail10, lbl_802BE854.entries };

// QSnail11
NativeRuntimeTypeInfo lbl_80375594 = { agent_type_registry_QSnail11, lbl_802BE968.entries };

// QSnail12
NativeRuntimeTypeInfo lbl_8037559C = { agent_type_registry_QSnail12, lbl_802BEA7C.entries };

// QSnail13
NativeRuntimeTypeInfo lbl_803755A4 = { agent_type_registry_QSnail13, lbl_802BEB90.entries };

// QSnail14
NativeRuntimeTypeInfo lbl_803755AC = { agent_type_registry_QSnail14, lbl_802BECA4.entries };

// QSnail15
NativeRuntimeTypeInfo lbl_803755B4 = { agent_type_registry_QSnail15, lbl_802BEDB8.entries };

// StreamAgent_Z
NativeRuntimeTypeInfo lbl_803755BC = { agent_type_registry_StreamAgent_Z, lbl_802BEECC.entries };

// StreamGameAgent
NativeRuntimeTypeInfo lbl_803755C4 = { agent_type_registry_StreamGameAgent, lbl_802BEEE0.entries };

// StreamBubbleAgent
NativeRuntimeTypeInfo lbl_803755CC = { agent_type_registry_StreamBubbleAgent, lbl_802BEEFC.entries };

// ABC_ScriptManager
NativeRuntimeTypeInfo lbl_803755D4 = { lbl_802A17C0, 0 };

// CScriptManager
NativeRuntimeTypeInfo lbl_803755DC = { lbl_802A17B0, lbl_802BEF8C.entries };

}

// Native command and diagnostic strings retain complete external storage ABI.

extern "C" const char lbl_802AD998[] =
    "CameraAgent_Z\0\0\0" // +0x0
    " WorldName NbPlayers [AgentCameraClassName=CameraGame]\0\0" // +0x10
    "ActivateGame\0\0\0\0" // +0x48
    " WorldName\0\0" // +0x58
    "DeactivateGame\0\0" // +0x64
    "RemoveGame\0\0" // +0x74
    " WorldName \0" // +0x80
    "SetMonoGame\0" // +0x8C
    "SwitchGameToMono\0\0\0\0" // +0x98
    "SwitchGameToMUlti\0\0\0" // +0xAC
    " WorldName NbVp\0" // +0xC0
    "AddGamePlayer\0\0\0" // +0xD0
    " WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS) PlayerName [TeamId=0]\0\0" // +0xE0
    "AddMenuPlayer\0\0\0" // +0x124
    "ReMoveGamePlayer\0\0\0\0" // +0x134
    " WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS)\0\0\0\0" // +0x148
    "REsetGame\0\0\0" // +0x178
    " VpId(1-MAX_VIEWPORT)\0\0\0" // +0x184
    "DeactivateGamePlayer\0\0\0\0" // +0x19C
    "ACtivateGamePlayer\0\0" // +0x1B4
    "PlayerGotoCoord\0" // +0x1C8
    "  X Y Z Viewport\0\0\0\0" // +0x1D8
    "SwitchCameraUser\0\0\0\0" // +0x1EC
    " ViewPortId\0" // +0x200
    "SetPersoCamera\0\0" // +0x20C
    "MakeCameraPatch\0" // +0x21C
    " ViewPortId PatchMax Step\0\0\0" // +0x22C
    "MakeCameraFrame\0" // +0x248
    " ViewPortId FrameRate Step\0\0" // +0x258
    "MakeCameraTexture\0\0\0" // +0x274
    " ViewPortId Step\0\0\0\0" // +0x288
    "EndCameraCapture\0\0\0\0" // +0x29C
    "ResetCameraZone\0" // +0x2B0
    " WorldName RtcNb\0\0\0\0" // +0x2C0
    " WorldName RtcId RtcName [AgentRtcClassName=RtcGame]\0\0\0\0" // +0x2D4
    " WorldName RtcId [ViewPortId]\0\0\0\0\0\0"; // +0x30C


// Native resource paths, parser tokens, type names and diagnostic text.
// Complete external NUL-separated arrays retain their original storage ABI.

extern "C" const char lbl_8029A0C0[] =
    "DB:>Definitions>menus2D>\0\0\0\0" // +0x0
    "menu2D_pause.txt\0\0\0\0" // +0x1C
    "MENU_PAUSE\0\0" // +0x30
    "GAMEMENU2D\0\0" // +0x3C
    "menu2D_world_status.txt\0" // +0x48
    "MENU_WORLD_STATUS\0\0\0" // +0x60
    "menu2D_options.txt\0\0" // +0x74
    "MENU_OPTIONS\0\0\0\0" // +0x88
    "menu2D_settings.txt\0" // +0x98
    "MENU_SETTINGS\0\0\0" // +0xAC
    "OptionsMenu2D\0\0\0" // +0xBC
    "menu2D_save.txt\0" // +0xCC
    "MENU_SAVE\0\0\0" // +0xDC
    "menu2D_load.txt\0" // +0xE8
    "MENU_LOAD\0\0\0" // +0xF8
    "menu2D_main_options.txt\0" // +0x104
    "MENU_MAIN_OPTIONS\0\0\0" // +0x11C
    "menu2D_main_load.txt\0\0\0\0" // +0x130
    "MENU_MAIN_LOAD\0\0" // +0x148
    "menu2D_main_extras.txt\0\0" // +0x158
    "MENU_MAIN_EXTRAS\0\0\0\0" // +0x170
    "CHudData\0\0\0\0" // +0x184
    "DB:>Prog>HudData.txt\0\0\0\0" // +0x190
    "NoCamera\0\0\0\0" // +0x1A8
    "CNoCamDraw\0\0" // +0x1B4
    "ALL_PATTIES\0" // +0x1C0
    "ALL_JELLIES\0" // +0x1CC
    "ALL_SANDDOLLARS\0" // +0x1D8
    "PANTS_COUNT\0" // +0x1E8
    "SANDDOLLARS\0" // +0x1F4
    "TASK_TEXT_1\0" // +0x200
    "TASK_TEXT_2\0" // +0x20C
    "TASK_TEXT_3\0" // +0x218
    "TASK_TEXT_4\0" // +0x224
    "TASK_TEXT_5\0" // +0x230
    "TASK_TEXT_6\0" // +0x23C
    "PAUSE_SND_VOL\0\0"; // +0x248

extern "C" const char lbl_8029A318[] =
    "PAUSE_SND_MUS\0\0\0" // +0x0
    "PAUSE_VIBRATION\0" // +0x10
    "PAUSE_SND_MONO\0"; // +0x20

extern "C" const char lbl_8029A348[] =
    "PAUSE_QUIT"; // +0x0


// Keep pause and menu labels that have no direct relocation consumer.
#pragma force_active on

extern "C" const char lbl_8029A354[] = "cat_game_freezed";

extern "C" const char lbl_8029A368[] = "PAUSE_OPTIONS";

extern "C" const char lbl_8029A378[] = "PAUSE_WORLD_STATUS";

extern "C" const char lbl_8029A38C[] = "PAUSE_SAVE";

extern "C" const char lbl_8029A398[] = "PAUSE_LOAD";

extern "C" const char lbl_8029A3A4[] = "PAUSE_SETTINGS";

extern "C" const char lbl_8029A3B4[] = "MSG_CONFIRM_QUIT";

extern "C" const char lbl_8029A3C8[] = "Menu Selected -- SAVE_1";

extern "C" const char lbl_8029A3E0[] = "Menu Selected -- SAVE_2";

extern "C" const char lbl_8029A3F8[] = "Menu Selected -- SAVE_3";

extern "C" const char lbl_8029A410[] = "Menu Selected -- LOAD_1";

extern "C" const char lbl_8029A428[] = "Menu Selected -- LOAD_2";

extern "C" const char lbl_8029A440[] = "Menu Selected -- LOAD_3";

extern "C" const char lbl_8029A458[] = "PAUSE_SB_TRAILER";

extern "C" const char lbl_8029A46C[] = "PAUSE_SB_OPEN";

extern "C" const char lbl_8029A47C[] = "PAUSE_SB_HINTS";

extern "C" const char lbl_8029A48C[] = "PAUSE_GALLERY";

extern "C" const char lbl_8029A49C[] = "PAUSE_CREDITS";

extern "C" const char lbl_8029A4AC[] = "CMainMenuAgent";

extern "C" const char lbl_8029A4BC[] = "BaseObject_Z";

extern "C" const char lbl_8029A4CC[] = "ABC_Agent";

// Original GLOBAL movement-class name; data-only partial split.
extern "C" const char lbl_8029A4D8[16] = "CProjectileMove";

#pragma force_active reset

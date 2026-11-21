#include "Game/platform_disc_status.h"
int lbl_80378168;
int fn_8028F4B4(void){int status=DVDGetDriveStatus();lbl_80378168=status;return status;}

#include "Game/platform_disc_status.h"
/* Former original/platform_disc_flags.s: three flag bytes after lbl_80378168
   (reverse definition order). */
unsigned char lbl_8037816E;
unsigned char lbl_8037816D;
unsigned char lbl_8037816C;
int lbl_80378168;
int fn_8028F4B4(void){int status=DVDGetDriveStatus();lbl_80378168=status;return status;}

/* Shared movie decode buffers, display state, and aligned read scratch. */
typedef unsigned long MovieWord;

/* This compiler allocates small uninitialized globals in reverse definition order. */
MovieWord* lbl_80378128[2];
char* lbl_80378124;
void* lbl_80378120;
MovieWord lbl_8037811C;
MovieWord lbl_80378118;
MovieWord* lbl_80378114;
MovieWord* lbl_80378110;
MovieWord* lbl_8037810C;
MovieWord* lbl_80378108;
MovieWord lbl_80378104;
MovieWord lbl_80378100;
int lbl_803780FC;
MovieWord* lbl_803780F8;
MovieWord lbl_803780F0[2];

typedef char MovieWordSizeCheck[sizeof(MovieWord) == 4 ? 1 : -1];
typedef char MoviePointerSizeCheck[sizeof(void*) == 4 ? 1 : -1];
typedef char MovieDirtyFlagsSizeCheck[sizeof(lbl_803780F0) == 8 ? 1 : -1];
typedef char MovieFrameBufferSlotsSizeCheck[sizeof(lbl_80378128) == 8 ? 1 : -1];

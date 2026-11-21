/* Callback group pointer and its adjacent, not yet typed state word. */
unsigned int lbl_80377620[2];

typedef char CallbackGroupSlotWordSizeCheck[sizeof(unsigned int) == 4 ? 1 : -1];

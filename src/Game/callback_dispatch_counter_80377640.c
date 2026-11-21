/* Shared callback dispatch counter and its adjacent state word. */
unsigned int lbl_80377640[2];

typedef char CallbackDispatchCounterWordSizeCheck[sizeof(unsigned int) == 4 ? 1 : -1];

// Native resource paths, parser tokens, type names and diagnostic text.
// Complete external NUL-separated arrays retain their original storage ABI.

extern "C" const char lbl_8029AAF8[] =
    "cat_default"; // +0x0

extern "C" const char lbl_8029AB04[] =
    "MSG_COSTUME_TENT_NOT_UNLOCKED"; // +0x0

struct CostumeTentMessages {
    char all[24];
    char noChangeAllowed[36];
};

extern "C" const CostumeTentMessages lbl_8029AB24 = {
    "MSG_COSTUME_TENT_ALL", "MSG_COSTUME_TENT_NO_CHANGE_ALLOWED"
};


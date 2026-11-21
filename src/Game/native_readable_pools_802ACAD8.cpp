// Native resource paths, parser tokens, type names and diagnostic text.
// Complete external NUL-separated arrays retain their original storage ABI.

extern "C" const char lbl_802ACAD8[] =
    "No Cameras in RTC"; // +0x0

// BigFile and stream diagnostics formerly retained in the original-only split.
// Keep each external name; the compiler supplies the intervening alignment.
#pragma force_active on

extern "C" const char lbl_802ACAEC[] = "PlayAnim";

extern "C" const char lbl_802ACAF8[] = "BigFile Aborted Time = %d:%d:%03d";

extern "C" const char lbl_802ACB1C[] = "BigFile Loading/Extract Time = %d:%d:%03d";

extern "C" const char lbl_802ACB48[] = "End Load";

extern "C" const char lbl_802ACB54[] = "Loading/Reading Time = %d:%d:%03d";

extern "C" const char lbl_802ACB78[] = "BigFile Init...";

extern "C" const char lbl_802ACB88[] = "Unable to open Stream %s...";

extern "C" const char lbl_802ACBA4[] = "Anonymous Alloc";

extern "C" const char lbl_802ACBB4[] = "StreamFile_Z.cpp";

extern "C" const char lbl_802ACBC8[] = "Wrong version of BigFile.. Rebuild them";

extern "C" const char lbl_802ACBF0[] = "Stream Init %s";

extern "C" const char lbl_802ACC00[] = "Size = %dSec, BlockSize = %do";

extern "C" const char lbl_802ACC20[] = "================================================";

// This array's original eight-byte alignment owns the trailing pool boundary.
extern "C" const char lbl_802ACC58[] __attribute__((aligned(8))) =
    "Unable to create file %s\0\0\0\0" // +0x0
    "Anonymous Alloc\0" // +0x1C
    "BitmapLoad_Z.cpp\0\0\0\0" // +0x2C
    "Anonymous New\0\0"; // +0x40

extern "C" const char lbl_802ACCA8[] =
    "PlayMOVie"; // +0x0

#pragma force_active reset

// Adjacent native text retains its complete external string identities.
#pragma force_active on
extern "C" const char lbl_802ACCB4[] = " MovieName";
#pragma force_active reset

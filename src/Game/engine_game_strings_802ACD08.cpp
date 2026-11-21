// Native class, event, resource and diagnostic strings.
// Pointer tables retain their separate owners.
extern "C" const char lbl_802ACD08[] = "Anonymous Alloc";
extern "C" const char lbl_802ACD18[] = "DynPtrArray_Z.h";
extern "C" const char lbl_802ACD28[] = "Anonymous New";
extern "C" const char lbl_802ACD38[] = "LodLoad_Z.cpp";
extern "C" const char lbl_802ACD48[] = "Anonymous New";
extern "C" const char lbl_802ACD58[] = "SurfaceLoad_Z.cpp";

// LOD, split and resource argument strings formerly in the original-only pool.
// Eight-byte alignment also absorbs the former external boundary bytes.
#pragma force_active on

extern "C" const char lbl_802ACD70[] __attribute__((aligned(8))) = "Invalid Parameter";

extern "C" const char lbl_802ACD84[] = "Split %d does not exists...";

extern "C" const char lbl_802ACDA0[] = "Parameter 1 is Invalid";

extern "C" const char lbl_802ACDB8[] = "Invalid Lod (1,%d)";

extern "C" const char lbl_802ACDCC[] = "Parameter 2 is Invalid";

extern "C" const char lbl_802ACDE4[] = "World %s does not exists...";

extern "C" const char lbl_802ACE00[] = "Parameter 1 Invalid";

extern "C" const char lbl_802ACE14[] = "SetSplitType";

extern "C" const char lbl_802ACE24[] = "No Comment";

extern "C" const char lbl_802ACE30[] = "SetWorldToSplit";

extern "C" const char lbl_802ACE40[] = "SetLodRender";

extern "C" const char lbl_802ACE50[] = "FitOnObject";

extern "C" const char lbl_802ACE5C[] = " [ObjectName] [VpId=0]";

extern "C" const char lbl_802ACE74[] = "DisplayImage";

extern "C" const char lbl_802ACE84[] = " [DB ImageName]";

// Retain the neighboring accepted names and their original alignment.
extern "C" const char lbl_802ACE98[] __attribute__((aligned(8))) =
    "Object Not Found..."; // +0x0

extern "C" const char lbl_802ACEAC[] =
    "Anonymous New"; // +0x0

#pragma force_active reset

// Adjacent native text retains its complete external string identities.
#pragma force_active on
extern "C" const char lbl_802ACEBC[] = "Viewport_Z.cpp";
#pragma force_active reset

#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
extern NativeRuntimeBaseList<3> lbl_802C9144;
extern const char lbl_802AB250[];
extern const char lbl_802AB260[];
extern const char lbl_802AB380[];
extern const char lbl_802AB390[];
extern const char lbl_802AB3A0[];
extern const char lbl_80379834[];
extern const char lbl_80379854[];

// Default names copied by the accepted record-string constructor.
const char* lbl_80375BA0 = lbl_802AB250;
const char* lbl_80375BA4 = lbl_802AB260;
const char* lbl_80375BA8 = lbl_80379834;

// BaseObject_Z
NativeRuntimeTypeInfo lbl_80375BAC = { lbl_802AB390, 0 };

// ABC_Agent
NativeRuntimeTypeInfo lbl_80375BB4 = { lbl_802AB3A0, lbl_802C9124.entries };

// Agent_Z
NativeRuntimeTypeInfo lbl_80375BBC = { lbl_80379854, lbl_802C9130.entries };

// CGCMemCardAgent
NativeRuntimeTypeInfo lbl_80375BC4 = { lbl_802AB380, lbl_802C9144.entries };

}

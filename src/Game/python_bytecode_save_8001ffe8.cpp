#include "Game/early_python_event_views.h"
struct File_801F3E1C { unsigned long words[23]; File_801F3E1C(); ~File_801F3E1C(); };
extern "C" {
    extern const char lbl_80299A00[0x6C],lbl_80299A6C[0x25];
    int sprintf(char*,const char*,...);
    void fn_80207A14(const char*,char*);
    signed char fn_801F3918(File_801F3E1C*,const char*,int);
    EventPyObject* PyMarshal_WriteObjectToString(EventPyObject*);
    int PyString_Size(EventPyObject*);
    char* PyString_AsString(EventPyObject*);
    void fn_801F2BD4(File_801F3E1C*,const void*,int);
    void fn_801F2B58(File_801F3E1C*);
    void fn_801F2A98(File_801F3E1C*);
}
extern "C" signed char fn_8001FFE8(EventPyObject* object,const char* name,const char* directory)
{
    char path[256],converted[256];
    signed char result;
    EventPyObject* bytes=0;
    sprintf(path,lbl_80299A00,directory,name);
    fn_80207A14(path,converted);
    File_801F3E1C file;
    result=fn_801F3918(&file,converted,2);
    if(result) {
        bytes=PyMarshal_WriteObjectToString(object);
        fn_801F2BD4(&file,PyString_AsString(bytes),PyString_Size(bytes));
        fn_801F2B58(&file);
        fn_801F2A98(&file);
    } else fn_801FA014(lbl_801E9D24.diagnostics,lbl_80299A6C,converted);
    releaseEventObject(bytes);
    return result;
}

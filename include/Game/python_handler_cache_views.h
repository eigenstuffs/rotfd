#ifndef GAME_PYTHON_HANDLER_CACHE_VIEWS_H
#define GAME_PYTHON_HANDLER_CACHE_VIEWS_H
struct CachedScriptObject;
struct PythonHandlerCache{char unknown00[0x40];CachedScriptObject*script;char unknown44[0xC8];CachedScriptObject*handlers[17];};
extern "C" {
int PyObject_HasAttrString(CachedScriptObject*,const char*);
CachedScriptObject*PyObject_GetAttrString(CachedScriptObject*,const char*);
extern const char lbl_80378658[5];
extern const char lbl_80378660[8];
extern const char lbl_80378668[6];
extern const char lbl_80378670[7];
extern const char lbl_80378678[7];
extern const char lbl_80378680[8];
extern const char lbl_80378688[7];
extern const char lbl_80378690[6];
extern const char lbl_80378698[4];
extern const char lbl_8037869C[8];
}
#endif

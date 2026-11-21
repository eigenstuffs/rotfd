/* Shared Python dictionaries, object caches, and the native binding receiver. */
struct EventPyObject;
unsigned short lbl_80377556;
unsigned short lbl_80377554;
struct EventPyObject* lbl_80377550;
struct EventPyObject* lbl_8037754C;
void* volatile lbl_80377548;
struct EventPyObject* lbl_80377544;
struct EventPyObject* lbl_80377540;

typedef char PythonDictionaryPointerSizeCheck[sizeof(void*) == 4 ? 1 : -1];
typedef char PythonDictionaryControlSizeCheck[sizeof(unsigned short) == 2 ? 1 : -1];

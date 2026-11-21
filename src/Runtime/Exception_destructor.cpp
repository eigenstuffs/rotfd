/* Retained std::exception lifetime metadata. See docs/notes/runtime-exception.md. */
#pragma exceptions on
#pragma internal on

extern const char std_exception_type_name[];

struct RuntimeTypeInfo {
    const char* name;
    const void* baseClasses;
};

/* The original name remains in the shared allocation-runtime string pool.
 * Declaring this record before the class prevents a duplicate generated name. */
extern "C" RuntimeTypeInfo __RTTI__Q23std9exception = {
    std_exception_type_name, 0
};

namespace std {
class exception {
public:
    exception() {}
    virtual ~exception();
    virtual const char* what() const;
};

__declspec(weak) exception::~exception()
{
}
}

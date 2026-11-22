#pragma exceptions on
#pragma internal on

namespace std {
class exception {
public:
    exception() {}
    virtual ~exception();
    virtual const char* what() const;
};

__declspec(weak) const char* exception::what() const
{
    return "exception";
}
}

// Register the three native ContainerInVolume member callbacks.
// The member records at lbl_802C1590 remain owned by the original data split.
typedef unsigned long u32;

struct ContainerInVolume {
    union { double alignment; char storage[0x68]; };
    ContainerInVolume();
    ~ContainerInVolume();
};

typedef void (ContainerInVolume::*MemberFunction)();

extern "C" {
void fn_8025E31C();
void fn_8025E714(void*, const MemberFunction&);
extern const MemberFunction lbl_802C1590[3];
extern u32 lbl_80377878;
}

inline void registerMember(ContainerInVolume* object, MemberFunction member) {
    fn_8025E714(object, member);
}

extern "C" void fn_800C9EC8() {
    const MemberFunction* members = lbl_802C1590;
    lbl_80377878 = 0;
    fn_8025E31C();
    ContainerInVolume object;
    registerMember(&object, members[0]);
    registerMember(&object, members[1]);
    registerMember(&object, members[2]);
}

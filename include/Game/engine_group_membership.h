#ifndef GAME_ENGINE_GROUP_MEMBERSHIP_H
#define GAME_ENGINE_GROUP_MEMBERSHIP_H

struct Handle_801F7F10 {
    unsigned long value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct MembershipManager;
struct MembershipContext {
    char unknown00[0x114];
    char *groups;
    MembershipManager *manager;
};
extern "C" {
extern MembershipContext lbl_801E9D24;
void fn_801F86C8(MembershipManager *, const Handle_801F7F10 *, short);
void fn_802139D8(void *);
void fn_80213A18(void *);
void fn_801E1F3C(void *, const Handle_801F7F10 &);
void fn_801E2074(void *, const Handle_801F7F10 &, int);
}
struct MembershipHandleLayer : Handle_801F7F10 {
    MembershipHandleLayer() { value = 0; }
};
struct MembershipHandleInit : MembershipHandleLayer {
    MembershipHandleInit() { value = 0; }
};
struct MembershipHandle : MembershipHandleInit {
    MembershipHandle(const Handle_801F7F10 &handle) {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};
struct MembershipOwner {
    unsigned long key;
    Handle_801F7F10 handle;
    char unknown08[0x34 - 8];
    unsigned char group;
};

extern "C" {
void fn_8021AB88(MembershipOwner *);
void fn_8021AC2C(MembershipOwner *, unsigned char);
}

#endif

#include "Game/early_controller_restart_peer_views.h"

extern "C" void fn_8005D854(RestartPeerObject* self) {
    fn_8005C6F0(self);
    if (fn_8025E9FC(self, 0x82)
        && !fn_8007D604((char*)resolveRestartPeer(self->controller) + 0x318, 3)
        && !fn_8007D604((char*)resolveRestartPeer(self->controller) + 0x318, 4))
        fn_8007D6A0((char*)resolveRestartPeer(self->controller) + 0x318, 3);
}

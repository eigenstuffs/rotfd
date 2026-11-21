#include "Game/platform_audio_update_internal.h"
inline Activable_Z* resolve(const OwnerHandle& handle) {
    int index = handle.bits.index;
    Manager* manager = lbl_801E9D24.manager;
    int actual = manager->entries[index].getGeneration();
    int expected = handle.bits.generation;
    if (actual == expected) return manager->entries[index].object;
    return 0;
}

inline int inputLevel(float volume) {
    float input;
    if (volume > lbl_8037B89C) input = lbl_8037B898;
    else if (volume <= lbl_8037B898) input = lbl_8037B8A4;
    else input = lbl_8037B8AC * fn_80284DB4(volume);
    return (int)input;
}
extern "C" void fn_80286398(PlatformAudioUpdateOwner* self, float dt) {
    int muted = (int)lbl_8037B8A4;
    for (int i = 0; i < 32; ++i) {
        PlatformAudioChannel* channel = &self->channels[i];
        PlatformAudioTrack* track = &self->tracks[i];
        if (channel->flags & 1) {
            if (track->running) track->timer += dt;
            if (fn_801F7EB8(&track->first)) {
                Activable_Z* first = resolve(track->first);
                fn_80286830(self, first, resolve(track->second), channel);
                MIXSetPan(channel->voice, (u32)(lbl_8037B8A8 * channel->field08 + lbl_8037B8A8));
                first = resolve(track->first);
                if (fn_8023B508(self, first, resolve(track->second))) {
                    channel->flags &= ~0x400UL;
                    AXSetVoiceState(channel->voice, 0);
                    channel->flags |= 8;
                }
            }
            if (channel->flags & 0x400) {
                channel->field18 -= channel->field14 * dt;
                if (channel->field18 < lbl_8037B898) {
                    channel->flags &= ~0x400UL;
                    AXSetVoiceState(channel->voice, 0);
                    channel->flags |= 8;
                }
                channel->field00 *= self->channels[i].field18;
                MIXSetInput(channel->voice, inputLevel(self->field418 * channel->field00));
            } else {
                if ((self->flags & 4) || (channel->flags & 2)) MIXSetInput(channel->voice, muted);
                else MIXSetInput(channel->voice, inputLevel(self->field418 * channel->field00));
            }
            if (channel->flags & 4) {
                AXSetVoiceSrcRatio(channel->voice, channel->field04 / lbl_8037B8B0);
                AXSetVoiceState(channel->voice, 1);
                channel->flags &= ~4UL;
            } else self->channelDone(i);
        }
    }
    fn_8028970C(self->secondary);
}

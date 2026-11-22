/* Merged translation unit: native platform audio owner, .text 0x80286288-0x80287A48,
 * .sdata2 0x8037B898-0x8037B8E0.  All float constants are compiler-pooled literals
 * (the former lbl_8037B898..8B0, 8D0, 8D4 extern names are now inline literals); pool order is
 * first use in address order.  "DSP"/"WAV"/".sgc" are named const arrays. */
#include "Game/platform_audio_update_internal.h"
#include "Game/audio_system_start.h"
/* ---- Game/platform_audio_reset.cpp ---- */
extern "C" float fn_80286288(PlatformAudioOwner*self){return self->field418;}
extern "C" float fn_80286290(PlatformAudioOwner*self){return self->field414;}
extern "C" void fn_80286298(PlatformAudioOwner*self){
 for(int i=0;i<32;++i){
  if(self->channels[i].flags&1){
   AXVPB*voice=self->channels[i].voice;
   if(voice&&voice->pb.state==1)AXSetVoiceState(voice,0);
   self->channels[i].field04=0.0f;
   self->channels[i].field08=0.0f;
   self->channels[i].field0C=1.0f;
   self->channels[i].field00=0.0f;
   self->channels[i].flags=0;
   self->channels[i].field14=0.0f;
   self->channels[i].field18=-1.0f;
  }
  fn_8023B720(self,i);
 }
 fn_80285730(lbl_801E9D24.item);
}

/* ---- Game/platform_audio_update.cpp ---- */
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
    if (volume > 1.0f) input = 0.0f;
    else if (volume <= 0.0f) input = -900.0f;
    else input = 150.0f * fn_80284DB4(volume);
    return (int)input;
}
extern "C" void fn_80286398(PlatformAudioUpdateOwner* self, float dt) {
    for (int i = 0; i < 32; ++i) {
        PlatformAudioChannel* channel = &self->channels[i];
        PlatformAudioTrack* track = &self->tracks[i];
        if (channel->flags & 1) {
            if (track->running) track->timer += dt;
            if (fn_801F7EB8(&track->first)) {
                Activable_Z* first = resolve(track->first);
                fn_80286830(self, first, resolve(track->second), channel);
                MIXSetPan(channel->voice, (u32)(64.0f * channel->field08 + 64.0f));
                first = resolve(track->first);
                if (fn_8023B508(self, first, resolve(track->second))) {
                    channel->flags &= ~0x400UL;
                    AXSetVoiceState(channel->voice, 0);
                    channel->flags |= 8;
                }
            }
            if (channel->flags & 0x400) {
                channel->field18 -= channel->field14 * dt;
                if (channel->field18 < 0.0f) {
                    channel->flags &= ~0x400UL;
                    AXSetVoiceState(channel->voice, 0);
                    channel->flags |= 8;
                }
                channel->field00 *= self->channels[i].field18;
                MIXSetInput(channel->voice, inputLevel(self->field418 * channel->field00));
            } else {
                if ((self->flags & 4) || (channel->flags & 2)) MIXSetInput(channel->voice, inputLevel(0.0f));
                else MIXSetInput(channel->voice, inputLevel(self->field418 * channel->field00));
            }
            if (channel->flags & 4) {
                AXSetVoiceSrcRatio(channel->voice, channel->field04 / 32000.0f);
                AXSetVoiceState(channel->voice, 1);
                channel->flags &= ~4UL;
            } else self->channelDone(i);
        }
    }
    fn_8028970C(self->secondary);
}

/* ---- Game/platform_audio_channel_cleanup.cpp ---- */
extern "C" void fn_80286738(PlatformAudioOwner*self,int i){
 if(i<0)return;
 signed char done=0;
 if(self->channels[i].flags&0x200)done=!fn_8028A6C4(self->secondary,self->channels[i].field1C);
 else if(self->channels[i].voice->pb.state==0)done=1;
 if(done){
  fn_8023B720(self,i);
  self->channels[i].field04=0.0f;
  self->channels[i].field08=0.0f;
  self->channels[i].field0C=1.0f;
  self->channels[i].field00=0.0f;
  self->channels[i].flags=0;
  self->channels[i].field1C=-1;
 }
}

/* ---- part_80286830 ---- */
namespace part_80286830 {
/* fn_80286830: per-listener 3D sound attenuation / pan.  Position is node a's
 * world translation (plus node b's when given, which also composes the two
 * bases into an unused frame temp via fn_801F2170 -- that is the 0x2C-byte
 * {pos, 3x3} stack slot at 0x8).  For each listener in the same group the
 * volume falls off linearly between the near/far radii and pan/depth are the
 * offset projected on the listener's right/forward axes over the planar
 * distance.
 *
 * Matching notes (wave 11):
 *  - The listener basis must NOT be common-subexpression-eliminated by the
 *    front end between `right` and `forward` (the back end merges the loads
 *    instead, which makes the nine basis values back-end temporaries and gives
 *    the target's FPR colouring and schedule).  This is achieved by reading
 *    the basis through two differently typed access paths: Mat3 (rows of Vec3)
 *    for `right`, float[3][3] for `forward`.
 *  - `d` is computed after right/forward (its loads must be numbered after
 *    the basis temporaries).
 *  - one Vec3 `d` at function scope (scalarised first => colours above pos);
 *    `pos` has a dead (0,0,0) init so its fields number x,y,z; group/count
 *    come from inline getters; listener->local124 is a named local.
 * Matching notes (wave 12), b-branch:
 *  - the never-read 12 bytes at sp+8 are a SEPARATE temporary Vec3 (b's
 *    translation), not a member of the object whose address goes to
 *    fn_801F2170: only then do the pointer loads not alias its stores, so the
 *    scheduler may issue `stfs x` one cycle before `fadds x` (a store into an
 *    escaping local depends on every earlier pointer load).  The temporary is
 *    kept alive by reading it back through a reference.
 *  - the six translation loads are named locals (declared bx, ax, ay, by, az,
 *    bz => vreg order b.x > a.x > a.y > b.y > a.z > b.z); the stores into the
 *    temporary pin their evaluation points so they stay front-end variables. */
typedef unsigned int u32;

inline float fastSqrt(register float x) {
    register float r = 0.0f;
    if (x != r) {
        asm {
            frsqrte f4, x
            fres r, f4
        }
    }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
};
inline float lengthOf(Vec3 c) { return fastSqrt(c.dot(c)); }
struct Matrix {
    float m[4][4];
    const Vec3& translation() const { return *(const Vec3*)m[3]; }
    Vec3 column(int i) const { return Vec3(m[0][i], m[1][i], m[2][i]); }
};
struct Mat3 {
    Vec3 r[3];
};
inline void xf3(Vec3& o, const Mat3& m, const Vec3& v) {
    o.x = m.r[0].x * v.x + m.r[1].x * v.y + m.r[2].x * v.z;
    o.y = m.r[0].y * v.x + m.r[1].y * v.y + m.r[2].y * v.z;
    o.z = m.r[0].z * v.x + m.r[1].z * v.y + m.r[2].z * v.z;
}
struct Basis { float m[3][3]; };
inline void xf3b(Vec3& o, const Basis& m, const Vec3& v) {
    o.x = m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z;
    o.y = m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z;
    o.z = m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z;
}
inline void xf3c(Vec3& o, const float* m, const Vec3& v) {
    o.x = m[0] * v.x + m[3] * v.y + m[6] * v.z;
    o.y = m[1] * v.x + m[4] * v.y + m[7] * v.z;
    o.z = m[2] * v.x + m[5] * v.y + m[8] * v.z;
}
struct Handle {
    signed int tag : 8, index : 24;
};
struct Node {
    char unknown00[0x30];
    Mat3 basis30;
    char unknown54[0x94];
    float nearSqE8;
    float farSqEC;
    char unknownF0[0x34];
    Matrix* local124;
    char unknown128[0xC];
    int group134;
    int getGroup() const { return group134; }
};
struct Entry {
    Node* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};
struct Manager {
    int count, capacity;
    Entry* entries;
};
struct ListenerSlot {
    Handle handle;
    char unknown04[0x48];
};
struct Listeners {
    char unknown00[0x14];
    ListenerSlot slots[6];
    char unknown1DC[0x214 - 0x14 - 6 * 0x4c];
    signed char count214;
    int getCount() const { return count214; }
};
struct Global {
    char unknown00[0x114];
    Listeners* listeners114;
    Manager* manager;
};
struct Self {
    char unknown00[0x408];
    u32 flags408;
};
struct Out {
    float volume0;
    float unknown04;
    float pan8;
    float depthC;
    u32 flags10;
};

extern "C" {
extern Global lbl_801E9D24;
void fn_801F2170(Basis*, const Mat3*, const Mat3*);
float fn_800A8E8C(float, float, float);
}

inline Node* resolve(const Handle& h) {
    Entry* e = &lbl_801E9D24.manager->entries[h.index];
    return e->tag == h.tag ? e->object : 0;
}

extern "C" void fn_80286830(Self* self, Node* a, Node* b, Out* out) {
    int group = a->getGroup();
    Vec3 d;
    Vec3 pos(0.0f, 0.0f, 0.0f);
    float scale;
    if (b) {
        Basis rot;
        Matrix* am = a->local124;
        Matrix* bm = b->local124;
        float bx, ax, ay, by, az, bz;
        bz = bm->translation().z;
        az = am->translation().z;
        by = bm->translation().y;
        ay = am->translation().y;
        bx = bm->translation().x;
        ax = am->translation().x;
        const Vec3& tp = Vec3(bx, by, bz);
        pos.z = tp.z + az;
        pos.y = tp.y + ay;
        pos.x = tp.x + ax;
        fn_801F2170(&rot, &a->basis30, &b->basis30);
        scale = lengthOf(b->local124->column(0));
    } else {
        pos.z = a->local124->translation().z;
        pos.x = a->local124->translation().x;
        pos.y = a->local124->translation().y;
        scale = lengthOf(a->local124->column(0));
    }
    float nearDist;
    float farDist;
    if (0.0f == a->nearSqE8 && 0.0f == a->farSqEC) {
        nearDist = 1.0f;
        farDist = 24.0f;
    } else {
        nearDist = scale * fastSqrt(a->nearSqE8);
        farDist = scale * fastSqrt(a->farSqEC);
    }
    float range = farDist - nearDist;
    float best = 0.0f;
    out->volume0 = best;
    out->pan8 = best;
    out->depthC = best;
    int count = lbl_801E9D24.listeners114->getCount();
    for (int i = 0; i < count; i++) {
        Node* listener = resolve(lbl_801E9D24.listeners114->slots[i].handle);
        if (listener && group == listener->group134) {
            Vec3 right; xf3(right, listener->basis30, Vec3(1.0f, 0.0f, 0.0f));
            Vec3 forward; xf3b(forward, *(const Basis*)&listener->basis30, Vec3(0.0f, 0.0f, 1.0f));
            Matrix* lm = listener->local124;
            d = Vec3(pos.x - lm->translation().x, pos.y - lm->translation().y, pos.z - lm->translation().z);
            float dist = fastSqrt(d.x * d.x + d.y * d.y + d.z * d.z);
            float planar = fastSqrt(d.x * d.x + d.z * d.z);
            float volume = 1.0f;
            if (!(out->flags10 & 0x40)) {
                volume = 1.0f - (dist - nearDist) / range;
                fn_800A8E8C(volume, 0.0f, 1.0f);
            }
            if (volume > best) best = volume;
            float pan;
            float depth;
            if ((self->flags408 & 2) || (out->flags10 & 0x20)) {
                pan = 0.0f;
                depth = 1.0f;
            } else {
                pan = d.dot(right) / planar;
                if (!(out->flags10 & 0x100)) {
                    depth = d.dot(forward) / planar;
                } else {
                    depth = 1.0f;
                }
            }
            out->pan8 += pan;
            out->depthC += depth;
        }
    }
    out->volume0 = best;
    out->pan8 /= count;
    out->depthC /= count;
}

}

/* ---- Game/platform_audio_paths.cpp ---- */
extern "C" {
void fn_802077B4(const char*,char*,char*,char*,char*);
char*strcat(char*,const char*);
void fn_801F459C(char*);
signed char fn_8028A6DC(void*,const char*);
int fn_80289968(void*,const char*);
void fn_80286CD8(PlatformAudioOwner*self,const char*name){
 char path[128];char extension[16];
 fn_802077B4(name,0,0,path,extension);strcat(path,extension);fn_801F459C(path);fn_8028A6DC(self->secondary,path);
}
void fn_80286D38(PlatformAudioOwner*self,const char*name){
 char path[128];char extension[16];
 fn_802077B4(name,0,0,path,extension);strcat(path,extension);fn_801F459C(path);if(fn_80289968(self->secondary,path))return;
}
}

/* ---- Game/platform_audio_load.cpp ---- */
struct AudioResourceName {char normalized[128];char basename[16];};
extern "C" {
extern const char lbl_8037B8C0[4]="DSP";
extern const char lbl_8037B8C4[4]="WAV";
extern const char lbl_802AF448[];
unsigned long strlen(const char*);char*strcat(char*,const char*);
int fn_801F4520(const char*,const char*);
void fn_801F2A4C(const char*,char*);
void fn_802077B4(const char*,char*,char*,char*,char*);
void fn_801F459C(char*);
int fn_8028A31C(void*,const char*,int,int,int);
int fn_8023B864(PlatformAudioUpdateOwner*);
void fn_801FA014(void*,const char*,...);
int fn_80289968(void*,const char*);
void fn_80286D9C(PlatformAudioUpdateOwner*self,const char*name,u32 flags,const OwnerHandle&first,const OwnerHandle&second){
 AudioResourceName resource;char suffix[16];char*basename;
 const char*extension=name+strlen(name)-3;int kind;
 if(!fn_801F4520(extension,lbl_8037B8C0))kind=1;
 else if(!fn_801F4520(extension,lbl_8037B8C4))kind=2;
 else kind=0;
 basename=resource.basename;
 fn_801F2A4C(name,resource.normalized);
 fn_802077B4(name,0,0,basename,suffix);
 strcat(basename,suffix);fn_801F459C(basename);
 int stream=fn_8028A31C(self->secondary,resource.normalized,kind,(flags>>1)&1,0);
 if(stream>=0&&kind==1){
  int index=fn_8023B864(self);
  if(index<0){
   fn_801FA014(*reinterpret_cast<void**>(reinterpret_cast<char*>(&lbl_801E9D24)+0x110),lbl_802AF448,resource);
   fn_80289968(self->secondary,basename);
  }else{
   self->tracks[index].running=1;self->tracks[index].timer=0.0f;
   {OwnerHandle empty;empty.value=0;self->tracks[index].owner=empty;}
   self->tracks[index].first=first;self->tracks[index].second=second;
   self->channels[index].flags=0x381;
   self->channels[index].field04=0.0f;
   self->channels[index].field08=0.0f;
   self->channels[index].field0C=1.0f;
   self->channels[index].field00=1.0f;
   self->channels[index].field1C=stream;
  }
 }
}
}

/* ---- Game/platform_audio_stream_flush.cpp ---- */
extern "C" int fn_8028A7DC(void*);
extern "C" void fn_80286FF8(PlatformAudioOwner*self){fn_8028A7DC(self->secondary);}

/* ---- Game/platform_audio_stream_path.cpp ---- */
extern "C" {
extern const char lbl_8037B8C8[5]=".sgc";
void fn_801F2A4C(const char*,char*);char*strcat(char*,const char*);
void fn_8028A88C(void*,const char*,int);
void fn_8028701C(PlatformAudioUpdateOwner*self,const char*name,int mode){if(name){char path[128];fn_801F2A4C(name,path);strcat(path,lbl_8037B8C8);fn_8028A88C(self->secondary,path,mode);}}
}

/* ---- Game/platform_audio_fade.cpp ---- */
extern "C" int fn_8023AF08(PlatformAudioUpdateOwner*,const OwnerHandle&,const OwnerHandle&,float);
extern "C" int fn_80287080(PlatformAudioUpdateOwner*self,const OwnerHandle&handle,const OwnerHandle&first,float duration){
 if(!fn_801F7EB8(&handle))return -1;
 int index=fn_8023AF08(self,handle,first,duration);if(index<0)return -1;
 if(duration>=0.0f){
  self->channels[index].flags|=0x400;
  self->channels[index].field14=1.0f/duration;
  self->channels[index].field18=1.0f;
 }else AXSetVoiceState(self->channels[index].voice,0);
 return index;
}

/* ---- part_80287178 ---- */


struct Sound_80287178 {
    char unknown00[0xC];
    unsigned char flags0C;
    char unknown0D[3];
    int rate10;
    char unknown14[8];
    int field1C;
    char* data20;
};

struct Pool_80287178 {
    u32 available;
    u32 getAvailable() const { return available; }
    bool fits(u32 n) const { return available >= n; }
};
inline u32 getSize(char* data) { return (*(unsigned short*)(data + 4) << 16) | *(unsigned short*)(data + 6); }

struct ZeroHandle_80287178 : Handle_801F7F10 {
    ZeroHandle_80287178() { value = 0; }
};
struct CopyHandle_80287178 : ZeroHandle_80287178 {
    CopyHandle_80287178(const Handle_801F7F10& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};

extern "C" {
extern const char lbl_802AF470[];
void fn_801FA014(void*, const char*, ...);
int fn_8023B03C(PlatformAudioUpdateOwner*, const Handle_801F7F10&, u32, const Handle_801F7F10&, const Handle_801F7F10&);
}

inline Sound_80287178* resolveSound(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int generation = m->entries[index].getGeneration();
    return generation == h.bits.generation ? (Sound_80287178*)m->entries[index].object : 0;
}

inline Pool_80287178* pool() { return (Pool_80287178*)lbl_801E9D24.item; }
inline u32 halfSize(char* data) { return getSize(data) >> 1; }
inline bool poolFits(u32 n) { return pool()->fits(n); }
inline bool poolFits2(char* data) { return pool()->fits(halfSize(data)); }
extern "C" int fn_80287178(PlatformAudioUpdateOwner* self, const Handle_801F7F10& resource, u32 flags,
                           const Handle_801F7F10& first, const Handle_801F7F10& second) {
    Sound_80287178* sound = resolveSound(resource);
    if (sound == 0) {
        return -1;
    }
    if (sound->field1C == -1) {
        return -1;
    }
    char* data = sound->data20;
    u32 half = (u32)((*(unsigned short*)(data + 4) << 16) | *(unsigned short*)(data + 6)) >> 1;
    u32 avail = ((Pool_80287178*)lbl_801E9D24.item)->available;
    if (avail < half) {
        fn_801FA014(*(void**)((char*)&lbl_801E9D24 + 0x110), lbl_802AF470, avail, half);
        return -1;
    }
    int index = fn_8023B03C(self, resource, flags, first, CopyHandle_80287178(second));
    if (index < 0) {
        return -1;
    }
    if (index >= 32) {
        index -= 32;
    }
    AXVPB* voice = self->channels[index].voice;
    AXSetVoiceAddr(voice, (AXPBADDR*)data);
    AXSetVoiceSrcType(voice, 1);
    AXSetVoiceSrc(voice, (AXPBSRC*)(data + 0x10));
    AXSetVoiceAdpcm(voice, (AXPBADPCM*)(data + 0x1E));
    AXSetVoiceAdpcmLoop(voice, (AXPBADPCMLOOP*)(data + 0x46));
    self->channels[index].flags = 5;
    self->channels[index].field04 = (float)sound->rate10;
    self->channels[index].field08 = 0.0f;
    self->channels[index].field0C = 1.0f;
    self->channels[index].field00 = 1.0f;
    if (sound->flags0C & 2) {
        self->channels[index].flags |= 0x10;
    }
    if (!(flags & 1)) {
        self->channels[index].flags |= 0x20;
    }
    if (!(flags & 2)) {
        self->channels[index].flags |= 0x40;
    }
    if (!(flags & 4)) {
        self->channels[index].flags |= 0x80;
    }
    self->tracks[index].timer = 0.0f;
    AXSetVoiceSrcRatio(self->channels[index].voice, self->channels[index].field04 / 32000.0f);
    AXSetVoiceAddr(self->channels[index].voice, (AXPBADDR*)data);
    AXSetVoiceState(self->channels[index].voice, 1);
    return index;
}

/* ---- Game/platform_audio_levels.cpp ---- */
extern "C" float fn_800A8E8C(float,float,float);
extern "C" void fn_802897BC(void*,float);
extern "C" void fn_80289730(void*,float);
inline float attenuation(float level){if(level>1.0f)return 0.0f;else if(level<=0.0f)return -900.0f;else return 150.0f*fn_80284DB4(level);}
extern "C" void fn_80287454(PlatformAudioUpdateOwner*self,float level){self->field414=level;fn_800A8E8C(self->field414,0.0f,1.0f);fn_802897BC(self->secondary,attenuation(self->field414));}
extern "C" void fn_802874D4(PlatformAudioUpdateOwner*self,float level){self->field418=level;fn_800A8E8C(self->field418,0.0f,1.0f);fn_80289730(self->secondary,attenuation(self->field418));}

/* ---- Game/platform_audio_mute.cpp ---- */
extern "C" void fn_80289828(void*,u32);
extern "C" void fn_80287554(PlatformAudioUpdateOwner*self,u32 flags){
 u32 secondary=0;
 for(int i=0;i<32;++i){
  if(self->channels[i].flags&1){
   if(self->channels[i].flags&0x200){if(flags&4)secondary|=1;else secondary&=~1UL;}
   else if(self->channels[i].flags&0x10){if(flags&2)self->channels[i].flags|=2;else self->channels[i].flags&=~2UL;}
   else{if(flags&1)self->channels[i].flags|=2;else self->channels[i].flags&=~2UL;}
  }
 }
 if(flags&8)secondary|=2;else secondary&=~2UL;
 fn_80289828(self->secondary,secondary);
}

/* ---- Game/platform_audio_sound_mode.cpp ---- */
extern "C" u32 OSGetSoundMode();
extern "C" void OSSetSoundMode(u32);
extern "C" signed char fn_802876AC(PlatformAudioUpdateOwner*){return OSGetSoundMode()==1;}
extern "C" void fn_802876DC(PlatformAudioUpdateOwner*,int stereo){if(stereo)OSSetSoundMode(1);else OSSetSoundMode(0);}
extern "C" void fn_80287714(PlatformAudioUpdateOwner*){}

/* ---- Game/audio_voice_shutdown.cpp ---- */
namespace audio_voice_shutdown {
struct AudioChannel{char unknown00[0x24];void*voice;};struct AudioOwner{char unknown00[0x410];AudioChannel*channels;};struct AudioContext{char unknown00[0x110];void*logger;};
extern "C"{void AXSetVoiceState(void*,unsigned short);void MIXReleaseChannel(void*);void AXFreeVoice(void*);void AXQuit();void fn_8023BAF8(void*);void fn_801FA014(void*,const char*,...);extern AudioContext lbl_801E9D24;extern const char lbl_802AF49C[];}
extern "C" void fn_80287718(AudioOwner*self){for(int i=0;i<32;++i){AXSetVoiceState(self->channels[i].voice,0);MIXReleaseChannel(self->channels[i].voice);AXFreeVoice(self->channels[i].voice);self->channels[i].voice=0;}AXQuit();fn_8023BAF8(self);fn_801FA014(lbl_801E9D24.logger,lbl_802AF49C);}

}

/* ---- Game/audio_system_start.cpp ---- */
namespace audio_system_start {

typedef unsigned int u32;
struct Voice;
struct AudioPrefix {char unknown00[0x7C];};
struct AudioSystemOwner:AudioPrefix {
    virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
    virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
    virtual void slot28();virtual void slot2C();virtual void setLevel(float);virtual void slot34();virtual void setBalance(float);
    char unknown80[0x388];
    u32 flags408;
    int unknown40C;
    char*voices410;
    char unknown414[0xC];
    char pool420[4];
};
struct Globals {char unknown00[0x110];void*console;};
extern "C" {
extern Globals lbl_801E9D24;
extern const char lbl_802AF448[];
extern float lbl_8035E758[];
signed char fn_8023BAF0(AudioSystemOwner*);
float fn_80284DB4(float);
void AIInit(void*);
void AXInit();
void MIXInit();
void fn_80287B50();
void fn_80287B88(Voice*);
void AXRegisterCallback(void(*)());
Voice*AXAcquireVoice(u32,void(*)(Voice*),u32);
void MIXInitChannel(Voice*,u32,u32,int,int,int,int,u32);
void fn_8028AC20(void*);
u32 OSGetSoundMode();
void AXSetMode(u32);
u32 AXGetMaxDspCycles();
void fn_801FA014(void*,const char*,...);
}
static inline void fillAudioTable()
{
    float phase=0.0f;
    float scale=150.0f;
    float step=0.0078125f;
    for(int i=0;i<128;++i){
        lbl_8035E758[i]=scale*fn_80284DB4(phase);
        phase+=step;
    }
}
extern "C" int fn_802877DC(AudioSystemOwner*self)
{
    const char*strings=lbl_802AF448;
    if(!fn_8023BAF0(self))return 0;
    fillAudioTable();
    AIInit(0);
    AXInit();
    MIXInit();
    AXRegisterCallback(fn_80287B50);
    for(int i=0;i<32;++i){
        *(Voice**)(self->voices410+i*40+36)=AXAcquireVoice(30,fn_80287B88,0);
        Voice*voice=*(Voice**)(self->voices410+i*40+36);
        if(!voice)return -1;
        MIXInitChannel(voice,0,0,-904,-904,64,127,0);
        *(float*)(self->voices410+i*40)=0.0f;
        *(float*)(self->voices410+i*40+4)=0.0f;
        *(float*)(self->voices410+i*40+8)=0.0f;
        *(float*)(self->voices410+i*40+12)=1.0f;
        *(u32*)(self->voices410+i*40+16)=0;
        *(float*)(self->voices410+i*40+20)=0.0f;
        *(float*)(self->voices410+i*40+24)=-1.0f;
    }
    fn_8028AC20(self->pool420);
    self->setLevel(1.0f);
    self->setBalance(1.0f);
    u32 mode=OSGetSoundMode();
    AXSetMode(0);
    float cycles=AXGetMaxDspCycles();
    fn_801FA014(lbl_801E9D24.console,strings+0x60,(float)cycles/1000.0f);
    if(mode==0){
        fn_801FA014(lbl_801E9D24.console,strings+0x7C);
        self->flags408|=2;
    }else{
        fn_801FA014(lbl_801E9D24.console,strings+0x94);
        self->flags408&=~2;
    }
    return 1;
}

typedef char AudioSystemOwnerFlagsOffset[((unsigned int)&((AudioSystemOwner*)0)->flags408==0x408)?1:-1];
typedef char AudioSystemOwnerVoicesOffset[((unsigned int)&((AudioSystemOwner*)0)->voices410==0x410)?1:-1];
typedef char AudioSystemOwnerPoolOffset[((unsigned int)&((AudioSystemOwner*)0)->pool420==0x420)?1:-1];

}

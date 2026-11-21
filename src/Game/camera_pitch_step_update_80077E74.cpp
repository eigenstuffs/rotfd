/* Camera pitch step update (fn_80077E74): when the camera is active (0x175),
   reads the current pitch (fn_800785E0); in mode 0 any of five target control
   states (9, 5, 26, 10, 11) forces the pitch target at 0xEC to lbl_80378A00.
   The step toward the target is rate-limited by delta (down rate
   lbl_803789D4; up rate lbl_803789B8 when forced, else lbl_80378A04), capped
   with a log message at lbl_80378A08 in mode 0, applied through fn_80078284,
   and the segment from the camera point (0xF4) to the raised context position
   is tested (fn_800793D0), falling back to fn_8007A2FC when blocked.
   Register allocation of the two clamps is shape-sensitive: the downward clamp
   assigns the negated limit to the step first and reassigns the same
   expression in the taken arm (so the negated limit is coalesced with the
   step, leaving the original empty arm), and the upward clamp selects its
   limit with if/else into a separate local before the if/else copy. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};
struct Handle { union { unsigned long value; struct { signed int tag : 8; signed int index : 24; } bits; }; };
struct Node { char unknown00[0x318]; char stateData; };
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
struct Context { char unknown00[0x110]; void* logger; char unknown114[4]; Manager* manager; };
extern "C" Context lbl_801E9D24;
inline Node* resolve(const Handle& h) { Entry* e = &lbl_801E9D24.manager->entries[h.bits.index]; if (e->tag == h.bits.tag) return e->object; return 0; }
struct Camera {
    char unknown00[0x24];
    Handle target;
    char unknown28[0xD0 - 0x28];
    int kind;
    char unknownD4[0xEC - 0xD4];
    float pitchTarget;
    char unknownF0[4];
    Vec3 current;
    char unknown100[0x175 - 0x100];
    signed char active;
    char unknown176[0x21C - 0x176];
    float height;
};
extern "C" {
signed char fn_8007D604(void*, int);
float fn_800785E0(Camera*);
void fn_80078284(Camera*, float);
void fn_80076D98(Camera*, Vec3*);
signed char fn_800793D0(Camera*, const Vec3*, const Vec3*);
void fn_8007A2FC(Camera*);
void fn_801F9D68(void*, const char*, ...);
extern const char lbl_8029CCC8[];
extern const float lbl_8037899C, lbl_80378A00, lbl_803789D4, lbl_803789B8, lbl_80378A04, lbl_80378A08;
}
extern "C" void fn_80077E74(Camera* self, float delta)
{
    signed char forced = 0;
    if (!self->active) return;
    float pitch = fn_800785E0(self);
    if (self->kind == 0) {
        if (fn_8007D604(&resolve(self->target)->stateData, 9) ||
            fn_8007D604(&resolve(self->target)->stateData, 5) ||
            fn_8007D604(&resolve(self->target)->stateData, 26) ||
            fn_8007D604(&resolve(self->target)->stateData, 10) ||
            fn_8007D604(&resolve(self->target)->stateData, 11)) {
            forced = 1;
            self->pitchTarget = lbl_80378A00;
        }
    }
    float difference = self->pitchTarget - pitch;
    float step = lbl_8037899C;
    if (difference < step) {
        step = -(lbl_803789D4 * delta);
        if (step >= difference)
            step = -(lbl_803789D4 * delta);
        else
            step = difference;
    } else if (difference > step) {
        float limit;
        if (forced)
            limit = lbl_803789B8 * delta;
        else
            limit = lbl_80378A04 * delta;
        if (limit <= difference)
            step = limit;
        else
            step = difference;
    }
    if (self->kind == 0 && step > lbl_80378A08) {
        fn_801F9D68(lbl_801E9D24.logger, lbl_8029CCC8);
        step = lbl_80378A08;
    }
    if (lbl_8037899C != step) fn_80078284(self, step);
    Vec3 position;
    fn_80076D98(self, &position);
    position.y += self->height;
    if (!fn_800793D0(self, &self->current, &position)) fn_8007A2FC(self);
}

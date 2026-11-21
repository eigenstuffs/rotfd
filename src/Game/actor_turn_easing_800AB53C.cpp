/* Actor turn easing (fn_800AB53C): advances an angle (+0x14) by an eased
 * speed (+0x18) over time (+0x10), wraps it at 2*pi, builds a rotation
 * quaternion from two trig helpers of half the angle about (0, 0, 1) and passes
 * it with the point to the actor's transform virtual (slot 0xC0). When the
 * angle is near pi after 0.75 time units it snaps to pi, clears the actor
 * record (fn_8007D6A0) and signals the related object (fn_80072684).
 *
 * Matching notes: the absolute value goes through a float inline over the
 * __fabs intrinsic; the 2*pi subtraction uses a second read form of the
 * pooled label (pooled-literal emulation), which fixes the FPR colouring. */
extern "C" {
extern const float lbl_80379048, lbl_80379058, lbl_80379064, lbl_80379078, lbl_8037907C,
    lbl_80379080, lbl_80379084, lbl_80379088, lbl_8037908C;
extern const double lbl_80379068, lbl_80379070;
float fn_8028506C(float);
float fn_80284FA8(float);
double __fabs(double);
void fn_8007D6A0(void*, int);
void fn_80072684(void*);
}

inline float turnAbs(float x) { return (float)__fabs(x); }
struct TurnVector { float x, y, z; };
struct TurnQuat {
    float w, x, y, z;
    void set(float angle) {
        float c = fn_8028506C(angle);
        float s = fn_80284FA8(angle);
        w = c;
        x = lbl_80379048 * s;
        y = lbl_80379048 * s;
        z = lbl_80379058 * s;
    }
};

struct TurnPrefix { char unknown00[8]; };
struct TurnActor : TurnPrefix {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45();
    virtual void set(const TurnVector&, const TurnQuat&, int);
    char unknown0C[0x15C];
    char record;
};
struct TurnRelated { char unknown00[0x94]; void* object; };
struct TurnOwner {
    char unknown00[8];
    TurnActor* actor;
    TurnRelated* related;
    float time, angle, speed;
};

extern "C" void fn_800AB53C(TurnOwner* self, void*, const TurnVector* point, float delta) {
    TurnQuat rotation;
    if (self->time >= lbl_80379064) {
        if (self->angle < lbl_80379068 && self->angle > lbl_80379070 && self->time >= lbl_80379078) {
            self->angle = lbl_8037907C;
            rotation.set(self->angle * lbl_80379064);
            self->actor->set(*point, rotation, 0);
            fn_8007D6A0(&self->actor->record, 0);
            fn_80072684(self->related->object);
            return;
        }
        if (self->speed > lbl_80379080)
            self->speed -= lbl_80379084 * delta;
        self->angle += delta * (lbl_8037907C * self->speed);
        if (turnAbs(self->angle) >= lbl_80379088)
            self->angle -= *(const float*)&lbl_80379088;
        rotation.set(self->angle * lbl_80379064);
    } else if (self->time > lbl_8037908C) {
        if (self->speed < lbl_80379088)
            self->speed += lbl_80379084 * delta;
        if (turnAbs(self->angle) >= lbl_80379088)
            self->angle -= *(const float*)&lbl_80379088;
        else
            self->angle += delta * (lbl_8037907C * self->speed);
        rotation.set(self->angle * lbl_80379064);
    } else {
        rotation.set(lbl_80379048);
    }
    self->time += delta;
    self->actor->set(*point, rotation, 0);
}

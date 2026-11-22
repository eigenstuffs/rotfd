#pragma fp_contract off
extern "C" const float lbl_80378D60;
struct InterpolationVector {
    float x,y,z;
    InterpolationVector() {}
    InterpolationVector(float a,float b,float c):x(a),y(b),z(c) {}
    const InterpolationVector& get()const { return *this; }
    InterpolationVector operator/(float divisor)const { float reciprocal=lbl_80378D60/divisor; InterpolationVector result(x*reciprocal,y*reciprocal,z*reciprocal);return result.get(); }
    InterpolationVector operator*(float scale)const {
        return InterpolationVector(x*scale,y*scale,z*scale);
    }
    InterpolationVector operator+(const InterpolationVector& other)const {
        return InterpolationVector(x+other.x,y+other.y,z+other.z);
    }
};
struct InterpolationActor {
    char unknown00[0x144]; InterpolationVector position;
    char unknown150[0xC]; InterpolationVector start;
    char unknown168[0x354-0x168]; float duration; InterpolationVector delta;
};
extern "C" const float lbl_80378D60;
extern "C" void slot194__10CActorMoveFv(InterpolationActor* self,float elapsed)
{
    InterpolationVector velocity=self->delta/self->duration;
    self->position=self->start+velocity*elapsed;
}

static inline float dot(float x0,float x1,float x2,float y0,float y1,float y2) { return x0*y0+x1*y1+x2*y2; }
struct Matrix3 { float m[9]; };
static inline void multiply(Matrix3 *out,const Matrix3 *left,const Matrix3 *right)
{
    Matrix3 temp;
    for(int i=0;i<3;++i) {
        temp.m[i]=dot(right->m[0],left->m[i+3],left->m[i+6],left->m[i],right->m[1],right->m[2]);
        temp.m[i+3]=dot(right->m[3],left->m[i+3],left->m[i+6],left->m[i],right->m[4],right->m[5]);
        temp.m[i+6]=dot(right->m[6],left->m[i+3],left->m[i+6],left->m[i],right->m[7],right->m[8]);
    }
    *out=temp;
}
extern "C" {
void fn_801F2124(const Matrix3 *self,Matrix3 *out)
{
    out->m[0]=self->m[0];
    out->m[1]=self->m[3];
    out->m[2]=self->m[6];
    out->m[3]=self->m[1];
    out->m[4]=self->m[4];
    out->m[5]=self->m[7];
    out->m[6]=self->m[2];
    out->m[7]=self->m[5];
    out->m[8]=self->m[8];
}
void fn_801F2170(Matrix3 *out,const Matrix3 *left,const Matrix3 *right) { multiply(out,left,right); }
void fn_801F223C(Matrix3 *self,const Matrix3 *right) { multiply(self,self,right); }
}

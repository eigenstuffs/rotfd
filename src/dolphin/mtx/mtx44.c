typedef float f32;
typedef f32 Mtx[4][4];
extern f32 tanf(f32);

extern const f32 MtxOne;
extern const f32 MtxTwo;
extern const f32 MtxZero;
extern const f32 MtxNegativeOne;
extern const f32 MtxHalf;
extern const f32 MtxDegreesToRadians;

void MTXPerspective(Mtx m, f32 fovY, f32 aspect, f32 n, f32 f)
{
    f32 angle;
    f32 cot;
    f32 tmp;


    angle = (MtxHalf * fovY);
    angle = MtxDegreesToRadians * angle;
    cot = MtxOne / tanf(angle);
    m[0][0] = (cot / aspect);
    m[0][1] = MtxZero;
    m[0][2] = MtxZero;
    m[0][3] = MtxZero;
    m[1][0] = MtxZero;
    m[1][1] = (cot);
    m[1][2] = MtxZero;
    m[1][3] = MtxZero;
    m[2][0] = MtxZero;
    m[2][1] = MtxZero;
    tmp = MtxOne / (f - n);
    m[2][2] = (-n * tmp);
    m[2][3] = (tmp * -(f * n));
    m[3][0] = MtxZero;
    m[3][1] = MtxZero;
    m[3][2] = MtxNegativeOne;
    m[3][3] = MtxZero;
}

void MTXOrtho(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
    f32 tmp;

    tmp = MtxOne / (r - l);
    m[0][0] = MtxTwo * tmp;
    m[0][1] = MtxZero;
    m[0][2] = MtxZero;
    m[0][3] = (tmp * -(r + l));
    tmp = MtxOne / (t - b);
    m[1][0] = MtxZero;
    m[1][1] = MtxTwo * tmp;
    m[1][2] = MtxZero;
    m[1][3] = (tmp * -(t + b));
    m[2][0] = MtxZero;
    m[2][1] = MtxZero;
    tmp = MtxOne / (f - n);
    m[2][2] = (MtxNegativeOne * tmp);
    m[2][3] = (-f * tmp);
    m[3][0] = MtxZero;
    m[3][1] = MtxZero;
    m[3][2] = MtxZero;
    m[3][3] = MtxOne;
}

const f32 MtxOne = 1.0f;
const f32 MtxTwo = 2.0f;
const f32 MtxZero = 0.0f;
const f32 MtxNegativeOne = -1.0f;
const f32 MtxHalf = 0.5f;
const f32 MtxDegreesToRadians = 0.017453293f;

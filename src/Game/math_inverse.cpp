/* Scalar game math reconstructed from GSQE78.
 * Original names and full translation-unit extent are not established.
 * See docs/notes/game-scalar-math.md.
 */
extern "C" { extern const float game_math_zero, game_math_one; }
struct Vec3 { float x,y,z; };
struct Vec4 { float x,y,z,w; };
struct Matrix4 { float m[4][4]; };
extern "C" {
void fn_801F230C(const Matrix4 *a, Matrix4 *b)
{
    float d=game_math_zero;
    d+=a->m[0][0]*a->m[1][1]*a->m[2][2];
    d+=a->m[1][0]*a->m[2][1]*a->m[0][2];
    d+=a->m[2][0]*a->m[0][1]*a->m[1][2];
    d-=a->m[2][0]*a->m[1][1]*a->m[0][2];
    d-=a->m[1][0]*a->m[0][1]*a->m[2][2];
    d-=a->m[0][0]*a->m[2][1]*a->m[1][2];
    float inv=game_math_one/d;
    b->m[0][0]=inv*(a->m[1][1]*a->m[2][2]-a->m[2][1]*a->m[1][2]);
    b->m[0][1]=inv*-(a->m[0][1]*a->m[2][2]-a->m[2][1]*a->m[0][2]);
    b->m[0][2]=inv*(a->m[0][1]*a->m[1][2]-a->m[1][1]*a->m[0][2]);
    b->m[1][0]=inv*-(a->m[1][0]*a->m[2][2]-a->m[2][0]*a->m[1][2]);
    b->m[1][1]=inv*(a->m[0][0]*a->m[2][2]-a->m[2][0]*a->m[0][2]);
    b->m[1][2]=inv*-(a->m[0][0]*a->m[1][2]-a->m[1][0]*a->m[0][2]);
    b->m[2][0]=inv*(a->m[1][0]*a->m[2][1]-a->m[2][0]*a->m[1][1]);
    b->m[2][1]=inv*-(a->m[0][0]*a->m[2][1]-a->m[2][0]*a->m[0][1]);
    b->m[2][2]=inv*(a->m[0][0]*a->m[1][1]-a->m[1][0]*a->m[0][1]);
    b->m[3][0]=-(b->m[0][0]*a->m[3][0]+b->m[1][0]*a->m[3][1]+b->m[2][0]*a->m[3][2]);
    b->m[3][1]=-(b->m[0][1]*a->m[3][0]+b->m[1][1]*a->m[3][1]+b->m[2][1]*a->m[3][2]);
    b->m[3][2]=-(b->m[0][2]*a->m[3][0]+b->m[1][2]*a->m[3][1]+b->m[2][2]*a->m[3][2]);
    b->m[0][3]=game_math_zero;b->m[1][3]=game_math_zero;b->m[2][3]=game_math_zero;b->m[3][3]=game_math_one;
}
void fn_801F250C(const Matrix4 *a, Matrix4 *b)
{
for(int i=0;i<3;++i) for(int j=0;j<3;++j) b->m[i][j]=a->m[j][i];
    b->m[3][0]=-(b->m[0][0]*a->m[3][0]+b->m[1][0]*a->m[3][1]+b->m[2][0]*a->m[3][2]);
    b->m[3][1]=-(b->m[0][1]*a->m[3][0]+b->m[1][1]*a->m[3][1]+b->m[2][1]*a->m[3][2]);
    b->m[3][2]=-(b->m[0][2]*a->m[3][0]+b->m[1][2]*a->m[3][1]+b->m[2][2]*a->m[3][2]);
    b->m[0][3]=game_math_zero;b->m[1][3]=game_math_zero;b->m[2][3]=game_math_zero;b->m[3][3]=game_math_one;
}
}

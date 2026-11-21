/* Scalar game math reconstructed from GSQE78.
 * Original names and full translation-unit extent are not established.
 * See docs/notes/game-scalar-math.md.
 */
extern "C" { extern const float game_math_zero, game_math_one; }
struct Vec3 { float x,y,z; };
struct Vec4 { float x,y,z,w; };
struct Matrix4 { float m[4][4]; };
extern "C" {
void fn_801F295C(Vec4 *dst,const Matrix4 *m,const Vec3 *v)
{
    float x=m->m[0][0]*v->x+m->m[1][0]*v->y+m->m[2][0]*v->z+m->m[3][0];
    float y=m->m[0][1]*v->x+m->m[1][1]*v->y+m->m[2][1]*v->z+m->m[3][1];
    float z=m->m[0][2]*v->x+m->m[1][2]*v->y+m->m[2][2]*v->z+m->m[3][2];
    dst->x=x;dst->y=y;dst->z=z;dst->w=game_math_one;
}
}

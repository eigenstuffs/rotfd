/* Scalar game math reconstructed from GSQE78.
 * Original names and full translation-unit extent are not established.
 * See docs/notes/game-scalar-math.md.
 */
extern "C" { extern const float game_math_zero, game_math_one; }
struct Vec3 { float x,y,z; };
struct Vec4 { float x,y,z,w; };
struct Matrix4 { float m[4][4]; };
extern "C" {
void fn_801F1080(Matrix4 *,const Matrix4 *,Matrix4 *);
Matrix4 *fn_801F2788(Matrix4 *dst,const Matrix4 *rhs)
{
    fn_801F1080(dst,rhs,dst);
    return dst;
}
}

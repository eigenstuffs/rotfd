/* Scalar game math reconstructed from GSQE78.
 * Original names and full translation-unit extent are not established.
 * See docs/notes/game-scalar-math.md.
 */
struct Vec3 { float x,y,z; };
struct Quat { float w; Vec3 v; };
struct Matrix3 { float m[3][3]; };
extern "C" void fn_801F1E78(Quat *,const Matrix3 *);
extern "C" Quat *fn_801F20F4(Quat *q,const Matrix3 *m)
{
    fn_801F1E78(q,m);
    return q;
}

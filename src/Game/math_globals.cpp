/* Scalar game math reconstructed from GSQE78.
 * Original names and full translation-unit extent are not established.
 * See docs/notes/game-scalar-math.md.
 */
extern "C" { extern const float game_math_zero,game_math_one; }
struct Int3 { int x,y,z; Int3(int a,int b,int c):x(a),y(b),z(c){} };
struct Vec2 { float x,y; Vec2(float a,float b):x(a),y(b){} };
struct Vec3 { float x,y,z; Vec3(float a,float b,float c):x(a),y(b),z(c){} };
struct Vec4 { float x,y,z,w; Vec4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){} };
struct Quat { float w,x,y,z; Quat(float a,float b,float c,float d):w(a),x(b),y(c),z(d){} };
Int3 game_int3_zero(0,0,0);
Vec2 game_vec2_zero(game_math_zero,game_math_zero);
Vec3 game_vec3_zero(game_math_zero,game_math_zero,game_math_zero);
Vec4 game_vec4_zero(game_math_zero,game_math_zero,game_math_zero,game_math_zero);
Quat game_quat_identity(game_math_one,game_math_zero,game_math_zero,game_math_zero);

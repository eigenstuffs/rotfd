/* Bicubic grid value and tangent reconstruction; see docs/notes/game-bicubic-grid-sample.md. */
struct Vec3 {
    float x, y, z;
};
struct Vector3_801D5330 : Vec3 {
    Vector3_801D5330();
};
struct Vector2 {
    float x, y;
};
struct GridRecord {
    char bytes[0x90];
};
struct Surface {
    char prefix[0x7C];
    int stride;
    char prefix80[0x2C];
    GridRecord* records;
};
extern "C" {
    void fn_801D8458(Surface*, GridRecord*, Vector3_801D5330*, int);
    void fn_801D9C20(Vec3*, Vec3, Vec3, Vec3, Vec3, float);
    void fn_801D9964(Vec3*, Vec3, Vec3, Vec3, Vec3, float);
}
extern "C"    void fn_801D9304(Vec3* result, Surface* self, int index,
                           const Vector2& uv, Vec3* du, Vec3* dv) {
    Vector3_801D5330 grid[16];
    fn_801D8458(self, &self->records[index], grid, self->stride);
    Vec3 a, b, c, d, point;
    // Evaluate the four columns, then the horizontal tangent.
    fn_801D9C20(&a, grid[0], grid[4], grid[8], grid[12], uv.y);
    fn_801D9C20(&b, grid[1], grid[5], grid[9], grid[13], uv.y);
    fn_801D9C20(&c, grid[2], grid[6], grid[10], grid[14], uv.y);
    fn_801D9C20(&d, grid[3], grid[7], grid[11], grid[15], uv.y);
    fn_801D9C20(&point, a, b, c, d, uv.x);
    fn_801D9964(du, a, b, c, d, uv.x);

    // Evaluate the four rows, then the vertical tangent.
    fn_801D9C20(&a, grid[0], grid[1], grid[2], grid[3], uv.x);
    fn_801D9C20(&b, grid[4], grid[5], grid[6], grid[7], uv.x);
    fn_801D9C20(&c, grid[8], grid[9], grid[10], grid[11], uv.x);
    fn_801D9C20(&d, grid[12], grid[13], grid[14], grid[15], uv.x);
    fn_801D9C20(&point, a, b, c, d, uv.y);
    fn_801D9964(dv, a, b, c, d, uv.y);
    result->x = point.x;
    result->y = point.y;
    result->z = point.z;
}
